#define _USE_MATH_DEFINES
#include <cmath>
#include <chrono>
#include <cstdlib>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "turtlesim/srv/set_pen.hpp"
#include "turtlesim/srv/teleport_absolute.hpp"

using namespace std::chrono_literals;
using turtlesim::srv::SetPen;
using turtlesim::srv::TeleportAbsolute;

int service_pen(std::shared_ptr<rclcpp::Node> node , int red, int green, int blue, int w, float o){
 rclcpp::Client<SetPen>::SharedPtr client = node->create_client<SetPen>("/turtle1/set_pen");
    
 auto request = std::make_shared<SetPen::Request>();
 request->r = red;
 request->g = green;
 request->b = blue;
 request->width = w;
 request->off = o;
 while (!client->wait_for_service(500ms)) {
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

int service_tp(std::shared_ptr<rclcpp::Node> node , float x, float y, float t){
 rclcpp::Client<TeleportAbsolute>::SharedPtr client = node->create_client<TeleportAbsolute>("/turtle1/teleport_absolute");
    
 auto request = std::make_shared<TeleportAbsolute::Request>();
 request->x = x;
 request->y = y;
 request->theta = t;

 while (!client->wait_for_service(500ms)) {
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
     "Success teleport_relative");
    
  } else {
    RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), 
     "Failed to call service teleport_relative");
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
 double radius = node->get_parameter("radius").get_parameter_value().get<double>();
 int rd,gr,bl,pen,tp, iter = 100 * M_PI;
 float p_x,p_y;

 while (rclcpp::ok()) {
     
     for(int r = 0; r < 5; r++){
         switch(r){
             case 0:
                 rd = 0,gr = 0,bl = 255, p_x = 5.5 - radius*2.16,p_y = 5.5 - radius;
                 break;
            case 1:
                rd = 0,gr = 0,bl = 0, p_x = 5.5 ,p_y = 5.5 - radius;
                 break;
            case 2:
                rd = 255,gr = 0,bl = 0, p_x = 5.5 + radius*2.16,p_y = 5.5 - radius;
                 break;
                 
            case 3:
                rd = 255,gr = 255,bl = 0, p_x = 5.5 - radius*1.08,p_y = 5.5 - radius*2;
                 break;
            case 4:
                rd = 0,gr = 255,bl = 0, p_x = 5.5 + radius*1.08,p_y = 5.5 - radius*2;
                 break;
        
        }
        pen = service_pen(node,0,0,0,0,255);
        tp = service_tp(node, p_x, p_y,0.0);
        if(tp == 1 or pen == 1){
            rclcpp::shutdown();
        return 1;}
        pen = service_pen(node,rd,gr,bl,5,0);
        for(int i = 0; i < iter ; i++){
            vel.angular.z = 1;
            vel.linear.x = radius;
            publisher->publish(vel);
            rclcpp::spin_some(node);
            loop_rate.sleep();}
        
        vel.angular.z = 0.0;
        vel.linear.x = 0.0;
        publisher->publish(vel);
        rclcpp::spin_some(node);
        loop_rate.sleep();
        
    }
    rclcpp::shutdown();
    return 0;
     /* 
     pen = service_pen(node,0,0,255,5,0);
     for(int i = 0; i < iter ; i++){
        vel.angular.z = 1;
        vel.linear.x = radius;
        publisher->publish(vel);
        rclcpp::spin_some(node);
        loop_rate.sleep();}
        
    vel.angular.z = 0.0;
    vel.linear.x = 0.0;
    publisher->publish(vel);
    rclcpp::spin_some(node);
    loop_rate.sleep();
    pen = service_pen(node,0,0,0,0,255);
    tp = service_tp(node, 5.5, 5.5-radius,0.0);
    if(tp == 1 or pen == 1){
        rclcpp::shutdown();
        return 1;}
    
    pen = service_pen(node,0,0,0,5,0);
     for(int i = 0; i < iter ; i++){
        vel.angular.z = 1;
        vel.linear.x = radius;
        publisher->publish(vel);
        rclcpp::spin_some(node);
        loop_rate.sleep();}
        
    vel.angular.z = 0.0;
    vel.linear.x = 0.0;
    publisher->publish(vel);
    rclcpp::spin_some(node);
    loop_rate.sleep();
    pen = service_pen(node,0,0,0,0,255);
    tp = service_tp(node, 5.5 + radius*2.16, 5.5-radius,0.0);
    if(tp == 1 or pen == 1){
        rclcpp::shutdown();
        return 1;}
    pen = service_pen(node,255,0,0,5,0);
     for(int i = 0; i < iter ; i++){
        vel.angular.z = 1;
        vel.linear.x = radius;
        publisher->publish(vel);
        rclcpp::spin_some(node);
        loop_rate.sleep();}
        
    vel.angular.z = 0.0;
    vel.linear.x = 0.0;
    publisher->publish(vel);
    rclcpp::spin_some(node);
    loop_rate.sleep();
    pen = service_pen(node,0,0,0,0,255);
    tp = service_tp(node, 5.5 - radius*1.08, 5.5-radius*2,0.0);
    if(tp == 1 or pen == 1){
        rclcpp::shutdown();
        return 1;}
    pen = service_pen(node,255,255,0,5,0);
     for(int i = 0; i < iter ; i++){
        vel.angular.z = 1;
        vel.linear.x = radius;
        publisher->publish(vel);
        rclcpp::spin_some(node);
        loop_rate.sleep();}
        
    vel.angular.z = 0.0;
    vel.linear.x = 0.0;
    publisher->publish(vel);
    rclcpp::spin_some(node);
    loop_rate.sleep();
    pen = service_pen(node,0,0,0,0,255);
    tp = service_tp(node, 5.5 + radius*1.08, 5.5-radius*2,0.0);
    if(tp == 1 or pen == 1){
        rclcpp::shutdown();
        return 1;}
    pen = service_pen(node,0,255,0,5,0);
     for(int i = 0; i < iter ; i++){
        vel.angular.z = 1;
        vel.linear.x = radius;
        publisher->publish(vel);
        rclcpp::spin_some(node);
        loop_rate.sleep();}
        
    vel.angular.z = 0.0;
    vel.linear.x = 0.0;
    publisher->publish(vel);
    rclcpp::spin_some(node);
    loop_rate.sleep();*/
    
}
 rclcpp::shutdown();
 return 0;
}


