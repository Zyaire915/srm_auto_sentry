#include "rm_behavior_tree/plugins/condition/hp_ammo_decision.hpp"

namespace rm_behavior_tree
{

HpAmmoDcisionAction::HpAmmoDcisionAction(const std::string & name, const BT::NodeConfig & config)
: BT::SimpleConditionNode(name, std::bind(&HpAmmoDcisionAction::checkHpAmmoAndDecide, this), config)
{
}

BT::NodeStatus HpAmmoDcisionAction::checkHpAmmoAndDecide()
{
  int hp_threshold, ammo_threshold;
  std::string pose_above_threshold, pose_below_threshold;
  
  auto hp_msg = getInput<rm_decision_interfaces::msg::Sefdefined>("hp_message");
  auto ammo_msg = getInput<pb_rm_interfaces::msg::ProjectileAllowance>("ammo_message");
  getInput("hp_threshold", hp_threshold);
  getInput("ammo_threshold", ammo_threshold);
  getInput("pose_above_threshold", pose_above_threshold);
  getInput("pose_below_threshold", pose_below_threshold);

  if (!hp_msg || !ammo_msg) {
    return BT::NodeStatus::FAILURE;
  }

  // Judge based on HP and ammo thresholds
  if (hp_msg->current_hp >= hp_threshold && 
      ammo_msg->projectile_allowance_17mm >= ammo_threshold) {
    // Above threshold: go to pose A
    setOutput("goal_pose", pose_above_threshold);
    return BT::NodeStatus::SUCCESS;
  } else {
    // Below threshold: go to pose B
    setOutput("goal_pose", pose_below_threshold);
    return BT::NodeStatus::SUCCESS;
  }
}

}  // namespace rm_behavior_tree

#include "behaviortree_cpp/bt_factory.h"
BT_REGISTER_NODES(factory)
{
  factory.registerNodeType<rm_behavior_tree::HpAmmoDcisionAction>("HpAmmoDecision");
}
