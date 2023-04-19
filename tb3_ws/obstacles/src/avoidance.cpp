#include "rclcpp/rclcpp.hpp"
#include <chrono>
#include "geometry_msgs/msg/twist.hpp"
#include "example_interfaces/msg/bool.hpp"
#include <stdlib.h>

using namespace std::chrono_literals;
bool izq,der,fr;

void callback_front(const example_interfaces::msg::Bool::SharedPtr msg){
     fr = msg->data;
}

void callback_left(const example_interfaces::msg::Bool::SharedPtr msg){
    izq = msg->data;
}

void callback_right(const example_interfaces::msg::Bool::SharedPtr msg){
    der = msg->data;
}

int main(int argc, char *argv[]){
    rclcpp::init(argc,argv);
    auto node = rclcpp::Node::make_shared("avoidance");
    auto publisher = node->create_publisher<geometry_msgs::msg::Twist>("cmd_vel",10);
    auto subs_front = node->create_subscription<example_interfaces::msg::Bool>("/front/obstacle", 10,callback_front);
    auto subs_left = node->create_subscription<example_interfaces::msg::Bool>("/left/obstacle", 10,callback_left);
    auto subs_right = node->create_subscription<example_interfaces::msg::Bool>("/right/obstacle", 10,callback_right);
    int randint;
    bool turn_left, turn_right,rd;
    geometry_msgs::msg::Twist message;
    rclcpp::WallRate loop_rate(100ms);
    
    while(rclcpp::ok()){
        rd = false, turn_left = false, turn_right = false;
        if(fr){
            message.linear.x = 0.0;
            if(der)
                turn_left = true;
            else {
                if(izq)
                    turn_right = true;
                else{
                    rd = true;
                    randint = rand() %10+1;}
            }
        }
        else{
            message.linear.x = 0.5;
            message.angular.z = 0.0;
        }
        
        if(turn_left or (rd and randint >= 5))
            message.angular.z = 0.157;
        if(turn_right or (rd and randint < 5))
            message.angular.z = -0.157;
        
        publisher->publish(message);
        rclcpp::spin_some(node);
        loop_rate.sleep();
        
    }
    rclcpp::shutdown();
    return 0;
}
