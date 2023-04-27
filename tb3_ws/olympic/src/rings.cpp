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
 rclcpp::WallRate loop_rate(10ms);
 double radius = 0.03;
 int iter = (2* M_PI * radius)/(0.01*0.1); /* iter = 2piR / v*t */
 while (rclcpp::ok()) {
    for(int i = 0; i < iter ; i++){
        vel.angular.z = 3.33;
        vel.linear.x = 0.1;
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
