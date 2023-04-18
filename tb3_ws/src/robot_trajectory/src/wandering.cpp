#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"

using namespace std::chrono_literals;

double min_izq, min_der;

void topic_callback(const sensor_msgs::msg::LaserScan::SharedPtr msg){
    auto nums = msg->ranges;
    min_izq = nums[171], min_der = nums[181]; /*i=0/171 j=350/181 gazeebo/weebots*/
    for(int i=171,j=181;i<180;i++,j++){
        if(nums[i]< min_izq)
            min_izq = nums[i];
        if(nums[j]< min_der)
            min_der = nums[j];
    }
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("wandering");
  auto scan = node->create_subscription<sensor_msgs::msg::LaserScan>("/scan",10, topic_callback);
  auto publi = node->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 0);
  rclcpp::WallRate loop_rate(10ms);
  geometry_msgs::msg::Twist message;
  bool turn_left=false, turn_right=false;
  while(rclcpp::ok()){
    if( not turn_left and not turn_right ){
        message.linear.x = 0.1;
        message.angular.z = 0.0;
        if(min_izq < 0.4 or min_der < 0.4){
            message.linear.x = 0.0;
            if(min_izq > min_der)
                turn_left=true;
            else
                turn_right=true;
        }
    }
    if(turn_left){
        message.angular.z = 0.157;
        if(min_izq > 0.4){
            turn_left =false;
            message.linear.x = 0.1;
            message.angular.z = 0.0;


        }
    }
    if(turn_right){
        message.angular.z = -0.157;
        if(min_der > 0.4){
            turn_right =false;
            message.linear.x = 0.1;
            message.angular.z = 0.0;
      
        }
    }

        
    publi->publish(message);
    rclcpp::spin_some(node);
    loop_rate.sleep();
}
  
  rclcpp::shutdown();
  return 0;
}

