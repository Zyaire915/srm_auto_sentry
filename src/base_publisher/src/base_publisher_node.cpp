#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/point.hpp>
#include <geometry_msgs/msg/point_stamped.hpp>
#include <tf2_ros/buffer.h>
#include <tf2_ros/transform_listener.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>

class BasePublisher : public rclcpp::Node
{
public:
  BasePublisher() : Node("base_publisher")
  {
    this->declare_parameter("base_map_x", 0.0);
    this->declare_parameter("base_map_y", 0.0);
    this->declare_parameter("base_map_z", 0.0);
    this->declare_parameter("publish_rate", 30.0);
    this->declare_parameter("tf_timeout", 0.1);

    tf_buffer_ = std::make_shared<tf2_ros::Buffer>(this->get_clock());
    tf_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);

    publisher_ = this->create_publisher<geometry_msgs::msg::Point>("location_sender", 10);

    double rate = this->get_parameter("publish_rate").as_double();
    timer_ = this->create_wall_timer(
      std::chrono::duration<double>(1.0 / rate),
      std::bind(&BasePublisher::publish, this));

    RCLCPP_INFO(this->get_logger(), "base_publisher node started.");
  }

private:
  void publish()
  {
    double x = this->get_parameter("base_map_x").as_double();
    double y = this->get_parameter("base_map_y").as_double();
    double z = this->get_parameter("base_map_z").as_double();
    double timeout = this->get_parameter("tf_timeout").as_double();

    geometry_msgs::msg::PointStamped in_map, in_base;
    in_map.header.frame_id = "map";
    in_map.header.stamp = this->get_clock()->now();
    in_map.point.x = x;
    in_map.point.y = y;
    in_map.point.z = z;

    try {
      tf_buffer_->transform(in_map, in_base, "base_link",
        tf2::durationFromSec(timeout));

      geometry_msgs::msg::Point msg;
      msg.x = in_base.point.x;
      msg.y = in_base.point.y;
      msg.z = in_base.point.z;
      publisher_->publish(msg);
    } catch (const tf2::TransformException & ex) {
      RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 2000,
        "TF map->base_link unavailable: %s", ex.what());
    }
  }

  std::shared_ptr<tf2_ros::Buffer> tf_buffer_;
  std::shared_ptr<tf2_ros::TransformListener> tf_listener_;
  rclcpp::Publisher<geometry_msgs::msg::Point>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<BasePublisher>());
  rclcpp::shutdown();
  return 0;
}
