#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "turtlesim/msg/pose.hpp"
using namespace std::chrono_literals;


float volatile pos_x,pos_y, pos_vel;
void upd_pose(const turtlesim::msg::Pose::SharedPtr msg){
    pos_x = msg->x;
    pos_y = msg->y;
    pos_vel = msg->linear_velocity;
}

int main(int argc, char * argv[])
{
 rclcpp::init(argc, argv);
 auto node = rclcpp::Node::make_shared("rings");
 auto publisher = node->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);
 auto pose = node->create_subscription<turtlesim::msg::Pose>("/turtle1/pose" ,10, upd_pose);
 geometry_msgs::msg::Twist vel;
 rclcpp::WallRate loop_rate(1ms);
 float ini_x = pos_x, ini_y= pos_y;
 while (rclcpp::ok()) {
   
   while(((ini_x != pos_x) and (ini_y != pos_y)) or (pos_vel == 0.0)){
       vel.angular.z = 1.0;
       vel.linear.x = 1.0;
       publisher->publish(vel);
       rclcpp::spin_some(node);
       loop_rate.sleep();
 }
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
