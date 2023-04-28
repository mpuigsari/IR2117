#include "rclcpp/rclcpp.hpp"
#include "turtlesim/srv/set_pen.hpp"
#include <memory>


int main(int argc, char **argv){
    rclcpp::init(argc,argv);
    if (4 > argc or argc > 6) {
  	RCLCPP_INFO(rclcpp::get_logger("rclcpp"), 
     "usage: add_two_ints_client X Y");
  	return 1;
  }

    std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("set_pen_service");
    
    rclcpp::Service<turtlesim::srv::SetPen>SharedPtr client = node->create_client<turtlesim::srv::SetPen>("set_pen");
    
    auto request = std::make_shared<turtlesim::srv::SetPen::Request>();
    request->r = atoll(argv[1]);
    request->g = atoll(argv[2]);
    request->b = atoll(argv[3]);
    request->width = atoll(argv[4]);
    while (!client->wait_for_service(1s)) {
    if (!rclcpp::ok()) {
      RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), 
       "Interrupted while waiting for the service.");
      return 0;
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
  }
  rclcpp::shutdown();
  return 0;

    
}
