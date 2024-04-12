#include <rclcpp/rclcpp.hpp>
#if __has_include(<cv_bridge/cv_bridge.hpp>)
#include <cv_bridge/cv_bridge.hpp>
#else
#include <cv_bridge/cv_bridge.h>
#endif
#include <std_msgs/mgs/




#include <chrono> 
using std::chrono_literalls::operator""ms;  // 1ms
using std::placeholders::_1;

const auto period_ns = rclcpp::Rate(10).period();
// timer
void classname::on_timer();
rclcpp::TimerBase::SharedPtr timer_;
timer_ = rclcpp::create_time(
  this, get_clock(), 100ms/period_ns, std::bind(&classname::on_timer, this));

// publisher
rclcpp::Publisher<std_msgs::msg::String>::SharedPtr msg_pub_;
this->msg_pub_ = this->create_publisher<std_msgs::msg::String>("~/topic_name", 1);

// subscriber
void classname::sub_callback(const std_msgs::msg::String::ConstSharedPtr msg ){}; // const std_msgs::msg::String::SharedPtr & msg
rclcpp::Subscription<std_msgs::msg::String>  msg_sub_;
msg_sub_ = this->create_subscription<std_msgs::msg::String>(
  "~/input_topic_name", rclcpp::Qos{1}, // rclcpp::Qos(1)
  std::bind(&&classname::sub_callback, this, _1));

// Extract data from received messages
cv_bridge::CvImagePtr in_image_ptr;
try{
  auto desired_encoding = sensor_msgs::image_encodings::BGR8;
  in_image_ptr = cv_bridge::toCvCopy(image_msg, desired_encoding);
} catch (cv_bridge::Exception & e) {
  RCLCPP_ERROR(get_logger(), "cv_bridge exception: %s", e.what());
  return;
}


// QoS & rmw
rmw_qos_profile_sensor_data
rclcpp::QoS{1}.get_rmw_qos_profile()
rclcpp::SensorDataQoS()
rclcpp::QoS{1}
