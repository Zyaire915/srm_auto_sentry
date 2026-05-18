#include "rm_behavior_tree/plugins/condition/is_healthy_ammo.hpp"

namespace rm_behavior_tree
{

IsHealthyAmmoAction::IsHealthyAmmoAction(const std::string & name, const BT::NodeConfig & config)
: BT::SimpleConditionNode(name, std::bind(&IsHealthyAmmoAction::checkHealthyAmmo, this), config)
{
}

//getInput<rm_decision_interfaces::msg::Sefdefined>("hp_message");
//getInput<pb_rm_interfaces::msg::ProjectileAllowance>("ammo_message");
BT::NodeStatus IsHealthyAmmoAction::checkHealthyAmmo()
{
  int hp_threshold, ammo_threshold;
  auto hp_msg = getInput<rm_decision_interfaces::msg::Sefdefined>("hp_message");
  auto ammo_msg = getInput<pb_rm_interfaces::msg::ProjectileAllowance>("ammo_message");
  getInput("hp_threshold", hp_threshold);
  getInput("ammo_threshold", ammo_threshold);

  if (!hp_msg || !ammo_msg) {
    return BT::NodeStatus::FAILURE;
  }

  // Check if both HP and ammo are healthy (above thresholds)
  if (hp_msg->current_hp < hp_threshold || 
      ammo_msg->projectile_allowance_17mm < ammo_threshold) {
    return BT::NodeStatus::FAILURE;
  } else {
    return BT::NodeStatus::SUCCESS;
  }
}

}  // namespace rm_behavior_tree

#include "behaviortree_cpp/bt_factory.h"
BT_REGISTER_NODES(factory)
{
  factory.registerNodeType<rm_behavior_tree::IsHealthyAmmoAction>("IsHealthyAmmo");
}
