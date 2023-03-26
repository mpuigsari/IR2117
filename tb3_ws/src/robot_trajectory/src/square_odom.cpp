#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "nav_msgs/msg/odometry.hpp"

using namespace std::chrono_literals;

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("odom");
  auto odom = node->create_publisher<nav_msgs::msg::Odometry>("odom", 10);
  nav_msgs::msg::Odometry message;
  rclcpp::WallRate loop_rate(10ms);

  while (rclcpp::ok()){
    odom->publish(message);
    rclcpp::spin_some(node);
    loop_rate.sleep();
      
}
  rclcpp::shutdown();
  return 0;
}

