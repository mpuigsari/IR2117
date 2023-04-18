#include "rclcpp/rclcpp.hpp"
#include <chrono>
#include "geometry_msgs/msg/twist.hpp"
#include "example_interfaces/msg/bool.hpp"
#include <stdlib.h>

using namespace std::chrono_literals;
bool izq,der,fr, mov, turn_left, turn_right, rd;

void callback_front(const example_interfaces::msg::Bool::SharedPtr msg){
     if(msg)
         rd = true;
}

void callback_left(const example_interfaces::msg::Bool::SharedPtr msg){
    if(msg)
         turn_left = true;
}

void callback_right(const example_interfaces::msg::Bool::SharedPtr msg){
    if(msg)
         turn_right = true;
}

int main(int argc, char *argv[]){
    rclcpp::init(argc,argv);
    auto node = rclcpp::Node::make_shared("avoidance");
    auto publisher = node->create_publisher<geometry_msgs::msg::Twist>("cmd_vel",10);
    auto subs_front = node->create_subscription<example_interfaces::msg::Bool>("/front/obstacle", 10,callback_front);
    auto subs_left = node->create_subscription<example_interfaces::msg::Bool>("/left/obstacle", 10,callback_left);
    auto subs_right = node->create_subscription<example_interfaces::msg::Bool>("/right/obstacle", 10,callback_right);
    int randint;
    geometry_msgs::msg::Twist message;
    rclcpp::WallRate loop_rate(50ms);
    
    while(rclcpp::ok()){
        mov = (turn_right or turn_left or rd);
        switch(mov){
            case true:
                if(rd)
                    randint = rand() %10+1;
                message.linear.x = 0.0;
                break;
            case false:
                turn_left = false, turn_right=false, rd = false;
                message.linear.x = 1.0;
                message.angular.z = 0.0;
                break;
        }
        if(turn_left or (rd and randint <= 5))
            message.angular.z = 0.157;
        if(turn_right or (rd and randint > 5))
            message.angular.z = -0.157;
        
        publisher->publish(message);
        rclcpp::spin_some(node);
        loop_rate.sleep();
        
    }
    rclcpp::shutdown();
    return 0;
}
