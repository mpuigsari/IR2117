#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"

using namespace std::chrono_literals;

void topic_callback(sensor_msgs::msg::LaserScan &msg){
    auto nums = msg.ranges;
    RCLCPP_INFO("list = %f", nums[360]);
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("wandering");
  auto scan = node->create_subscription<sensor_msgs::msg::LaserScan>("scan",10, &topic_callback);
  auto publi = node->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 0);
  rclcpp::WallRate loop_rate(10ms);
  
  rclcpp::spin_some(node);
  rclcpp::shutdown();
  return 0;
}

