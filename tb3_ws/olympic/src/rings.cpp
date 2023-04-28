#define _USE_MATH_DEFINES
#include <cmath>
#include <chrono>
#include <cstdlib>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "turtlesim/srv/set_pen.hpp"

using namespace std::chrono_literals;
using turtlesim::srv::SetPen;

int service_pen(std::shared_ptr<rclcpp::Node> node , int red, int green, int blue, int w){
 rclcpp::Client<SetPen>::SharedPtr client = node->create_client<SetPen>("/turtle1/set_pen");
    
 auto request = std::make_shared<SetPen::Request>();
 request->r = red;
 request->g = green;
 request->b = blue;
 request->width = w;
 while (!client->wait_for_service(1s)) {
    if (!rclcpp::ok()) {
      RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), 
       "Interrupted while waiting for the service.");
      return 1;
	 }
	 RCLCPP_INFO(rclcpp::get_logger("rclcpp"), 
     "service not available, waiting again...");
  }
    auto result = client->async_send_request(request);

  if (rclcpp::spin_until_future_complete(node, 
       result) ==	rclcpp::FutureReturnCode::SUCCESS)
  {
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), 
     "Success set_pen");
    
  } else {
    RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), 
     "Failed to call service set_pen");
    return 1;
  }
 return 0;
    
}

int main(int argc, char * argv[])
{
 rclcpp::init(argc, argv);
 auto node = rclcpp::Node::make_shared("rings");
 auto publisher = node->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);
 node->declare_parameter("radius", 1.0);
 geometry_msgs::msg::Twist vel;
 rclcpp::WallRate loop_rate(20ms);
 
int pen = service_pen(node,255,255,0,5);
if(pen == 1){
 rclcpp::shutdown();
 return 1;
}
 
 double radius = node->get_parameter("radius").get_parameter_value().get<double>();
 while (rclcpp::ok()) {
    for(int i = 0; i < 50 ; i++){
        vel.angular.z = 2* M_PI;
        vel.linear.x = 2* M_PI*radius;
        publisher->publish(vel);
        rclcpp::spin_some(node);
        loop_rate.sleep();}
        
    vel.angular.z = 0.0;
    vel.linear.x = 0.0;
    publisher->publish(vel);
    rclcpp::spin_some(node);
    loop_rate.sleep();
    break;
}
 rclcpp::shutdown();
 return 0;
}


