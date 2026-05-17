#include "rm_behavior_tree/plugins/action/sub_switch_position.hpp"
#include "behaviortree_ros2/plugins.hpp"

namespace rm_behavior_tree
{

SubSwitchPositionAction::SubSwitchPositionAction(
  const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params)
: BT::RosTopicSubNode<pb_rm_interfaces::msg::SwitchPosition>(name, conf, params)
{
}

BT::PortsList SubSwitchPositionAction::providedPorts()
{
  return {
    BT::InputPort<std::string>("topic_name"),
    BT::OutputPort<pb_rm_interfaces::msg::SwitchPosition>("switch_position")
  };
}

BT::NodeStatus SubSwitchPositionAction::onTick(
  const std::shared_ptr<pb_rm_interfaces::msg::SwitchPosition> & last_msg)
{
  if (last_msg) {
    RCLCPP_DEBUG(logger(), "[%s] Received Switch Position Data", name().c_str());
    setOutput("switch_position", *last_msg);
  }
  return BT::NodeStatus::SUCCESS;
}

}  // namespace rm_behavior_tree

// Register plugin
CreateRosNodePlugin(rm_behavior_tree::SubSwitchPositionAction, "SubSwitchPosition");
