#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "tf/transform_broadcaster.hpp"

using namespace std::chrono_literals;

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("odom");
  auto odom_publi = node->create_publisher<nav_msgs::msg::Odometry>("odom", 50);
  nav_msgs::msg::Odometry odom;
  rclcpp::WallRate loop_rate(100ms);

  while (rclcpp::ok()){
    tf:Quaternion q(x,y,z,w);
    double yaw,pitch,roll;
    btMatrix3x3(q).getEulerYPR(yaw,pitch,roll);
    
    odom_publi->publish(odom);
    rclcpp::spin_some(node);
    loop_rate.sleep();
      
}
  rclcpp::shutdown();
  return 0;
}

