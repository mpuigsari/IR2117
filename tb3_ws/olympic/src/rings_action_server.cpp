#include <inttypes.h>
#include <memory>
#include <cmath>
#include "olympic_interfaces/action/rings.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "turtlesim/srv/set_pen.hpp"
#include "turtlesim/srv/teleport_absolute.hpp"

using Rings = olympic_interfaces::action::Rings;
using namespace std::chrono_literals;
using turtlesim::srv::SetPen;
using turtlesim::srv::TeleportAbsolute;

using GoalHandleRings = rclcpp_action::ServerGoalHandle<Rings>;

rclcpp::Node::SharedPtr node = nullptr;

// callback accept goals
rclcpp_action::GoalResponse handle_goal(const rclcpp_action::GoalUUID & uuid, std::shared_ptr<const Rings::Goal> goal){
  RCLCPP_INFO(rclcpp::get_logger("server"), "Got goal request with radius %.*f",2, goal->radius);
  (void)uuid;
  return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
}
//Callback cancellations
rclcpp_action::CancelResponse handle_cancel(  const std::shared_ptr<GoalHandleRings> goal_handle){
  RCLCPP_INFO(rclcpp::get_logger("server"), 
    "Got request to cancel goal");
  (void)goal_handle;
  return rclcpp_action::CancelResponse::ACCEPT;
}

void execute(const std::shared_ptr<GoalHandleRings>);

void handle_accepted(  const std::shared_ptr<GoalHandleRings> goal_handle)
{
  std::thread{execute, goal_handle}.detach();
}

void execute(  const std::shared_ptr<GoalHandleRings> goal_handle)
{
  RCLCPP_INFO(rclcpp::get_logger("server"), 
    "Executing goal");
  rclcpp::WallRate loop_rate(100ms);
  
  const auto goal = goal_handle->get_goal();
  auto feedback = std::make_shared<Rings::Feedback>();
  auto & ring_num = feedback->drawing_ring;
  auto & ring_angle = feedback->ring_angle;
  
  auto result = std::make_shared<Rings::Result>();
  
  float radius = goal->radius, v_lin = radius, v_ang = 1;
  auto publisher = node->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel",10);
  geometry_msgs::msg::Twist message;
  int iter = M_PI * 100;
  int red[5] = {0,0,255,255,0};
  int green[5] = {0,0,0,255,255};
  int blue[5] = {255,0,0,0,0};
  double pos_x[5] = {- radius*2.16,0,0,- radius*1.08, radius*1.08};
  double pos_y[5] = {-radius,-radius,-radius,-radius*2, -radius*2};
  
  rclcpp::Client<SetPen>::SharedPtr client_pen = node->create_client<SetPen>("/turtle1/set_pen");
  auto request_pen = std::make_shared<SetPen::Request>();
  auto result_pen = client_pen->async_send_request(request_pen);
  
  rclcpp::Client<TeleportAbsolute>::SharedPtr client_tp = node->create_client<TeleportAbsolute>("/turtle1/teleport_absolute");
  auto request_tp = std::make_shared<TeleportAbsolute::Request>();
  auto result_tp = client_tp->async_send_request(request_tp);
  
  for(int i = 0; i < 5; i++){
      if(goal_handle->is_canceling()){
          goal_handle->canceled(result);
          RCLCPP_INFO(rclcpp::get_logger("server"),"Goal Canceled");
          return;
    }
    request_pen->r = red[i];
    request_pen->g = green[i];
    request_pen->b = blue[i];
    request_pen->width = 5;
    request_pen->off = 255;
    
    result_pen = client_pen->async_send_request(request_pen);
    
    request_tp = std::make_shared<Teleport_Absolute::Request>();
    request_tp->x = 5.5 + pos_x[i];
    request_tp->y = 5.5 + pos_y[i];
    
    ring_num = i+1;
    ring_angle = 0;
    goal_handle->publish_feedback(feedback);
    RCLCPP_INFO(rclcpp::get_logger("server"),"Publish feedback");
    
    request_pen->off = 0;
    result_pen = client_pen->async_send_request(request_pen);
    
    int j = 0;
    while(rclcpp::ok() && (j<=iter)){
        switch(j){
            case iter/4:
                ring_angle = 90;
                goal_handle->publish_feedback(feedback);
                RCLCPP_INFO(rclcpp::get_logger("server"),"Publish feedback");
                break;
            case iter/2:
                ring_angle = 90;
                goal_handle->publish_feedback(feedback);
                RCLCPP_INFO(rclcpp::get_logger("server"),"Publish feedback");
                break;
            case 3*iter/4:
                ring_angle = 270;
                goal_handle->publish_feedback(feedback);
                RCLCPP_INFO(rclcpp::get_logger("server"),"Publish feedback");
                break;
            default:
                //nothing
                break;
        }
        
        message.linear.x = 0.0;
        message.angular.z = 0.0;
        publisher->publish(message);
        loop_rate.sleep();

}
  
 if (rclcpp::ok()) {
    result->rings_completed = ring_num;
    goal_handle->succeed(result);
    RCLCPP_INFO(rclcpp::get_logger("server"), 
      "Goal Succeeded");
  }
}

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("rings_server");
  auto rings_server = 
    rclcpp_action::create_server<Rings>(node,
      "rings",
      handle_goal,
      handle_cancel,
      handle_accepted);
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
 
