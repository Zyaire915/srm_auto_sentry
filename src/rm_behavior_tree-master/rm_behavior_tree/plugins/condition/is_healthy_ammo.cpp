#include "rm_behavior_tree/plugins/condition/is_healthy_ammo.hpp"

namespace rm_behavior_tree
{

IsHealthyAmmoAction::IsHealthyAmmoAction(const std::string & name, const BT::NodeConfig & config)
: BT::SimpleConditionNode(name, std::bind(&IsHealthyAmmoAction::checkHealthyAmmo, this), config)
{
}

BT::NodeStatus IsHealthyAmmoAction::checkHealthyAmmo()
{
  int hp_threshold, ammo_threshold;
  auto hp_msg = getInput<rm_decision_interfaces::msg::Sefdefined>("hp_message");
  getInput("hp_threshold", hp_threshold);
  getInput("ammo_threshold", ammo_threshold);

  if (!hp_msg) {
    return BT::NodeStatus::FAILURE;
  }

  if (hp_msg->current_hp < hp_threshold ||
      hp_msg->projectile_allowance_17mm < ammo_threshold) {
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
