#include "rm_behavior_tree/plugins/action/sub_projectile_allowance.hpp"
#include "behaviortree_ros2/plugins.hpp"

namespace rm_behavior_tree
{

SubProjectileAllowanceAction::SubProjectileAllowanceAction(
  const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params)
: BT::RosTopicSubNode<pb_rm_interfaces::msg::ProjectileAllowance>(name, conf, params)
{
}

BT::PortsList SubProjectileAllowanceAction::providedPorts()
{
  return {
    BT::InputPort<std::string>("topic_name"),
    BT::OutputPort<pb_rm_interfaces::msg::ProjectileAllowance>("projectile_allowance")
  };
}

//setOutput is called in the onTick function, which is called when the node is ticked in the behavior tree. The onTick function receives the last message received from the subscribed topic as an argument. If a message is received, it sets the output port "projectile_allowance" with the received message and returns SUCCESS. If no message is received, it still returns SUCCESS but does not set the output port.
BT::NodeStatus SubProjectileAllowanceAction::onTick(
  const std::shared_ptr<pb_rm_interfaces::msg::ProjectileAllowance> & last_msg)
{
  if (last_msg) {
    RCLCPP_DEBUG(logger(), "[%s] Received Projectile Allowance Data", name().c_str());
    setOutput("projectile_allowance", *last_msg);
  }
  return BT::NodeStatus::SUCCESS;
}

}  // namespace rm_behavior_tree

// Register plugin
CreateRosNodePlugin(rm_behavior_tree::SubProjectileAllowanceAction, "SubProjectileAllowance");
