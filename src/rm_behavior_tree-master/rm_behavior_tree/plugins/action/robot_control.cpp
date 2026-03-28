#include "rm_behavior_tree/plugins/action/robot_control.hpp"

namespace rm_behavior_tree
{

RobotControlAction::RobotControlAction(
  const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params)
: RosTopicPubNode<rm_decision_interfaces::msg::RobotControl>(name, conf, params)
{
  // 创建独立的 publisher，使用与基类相同的话题名
  auto ros_node = params.nh;
  keep_alive_pub_ = ros_node->create_publisher<rm_decision_interfaces::msg::RobotControl>(
    params.default_port_value, rclcpp::QoS(10));

  // 以 5Hz 定时持续发布最新的 is_recovering 状态，避免 Sequence 记忆跳过本节点时话题断更（降频以减少队列压力）
  keep_alive_timer_ = ros_node->create_wall_timer(
    std::chrono::milliseconds(200),
    [this]() {
      keep_alive_pub_->publish(last_msg_);
    });
}

bool RobotControlAction::setMessage(rm_decision_interfaces::msg::RobotControl & msg)
{
  getInput("stop_gimbal_scan", msg.stop_gimbal_scan);
  getInput("chassis_spin_vel", msg.chassis_spin_vel);
  getInput("is_recovering", msg.is_recovering);

  // 更新缓存，供定时器持续发布
  last_msg_ = msg;

  return true;
}

}  // namespace rm_behavior_tree

#include "behaviortree_ros2/plugins.hpp"
CreateRosNodePlugin(rm_behavior_tree::RobotControlAction, "RobotControl");