#define _USE_MATH_DEFINES
#include <cmath>
#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "turtlesim/msg/pose.hpp"
using namespace std::chrono_literals;

int main(int argc, char * argv[])
{
 rclcpp::init(argc, argv);
 auto node = rclcpp::Node::make_shared("rings");
 auto publisher = node->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);
 geometry_msgs::msg::Twist vel;
 rclcpp::WallRate loop_rate(20ms);
 double radius = 2;
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
