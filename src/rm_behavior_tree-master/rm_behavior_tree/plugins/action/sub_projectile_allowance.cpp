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
    BT::OutputPort<pb_rm_interfaces::msg::ProjectileAllowance>("projectile_allowance")
  };
}

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
