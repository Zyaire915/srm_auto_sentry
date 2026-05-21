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
  std::string current_goal_pose;
  if (hp_msg->current_hp >= hp_threshold && 
      ammo_msg->projectile_allowance_17mm > ammo_threshold) {
    // Above threshold: go to pose A
    current_goal_pose = pose_above_threshold;
  } else {
    // Below threshold: go to pose B
    current_goal_pose = pose_below_threshold;
  }
  
  // Only send goal if it changed, prevent duplicate preempts
  if (current_goal_pose != last_goal_pose_) {
    last_goal_pose_ = current_goal_pose;
    setOutput("goal_pose", current_goal_pose);
    return BT::NodeStatus::SUCCESS;
  } else {
    // Goal unchanged, skip sending
    return BT::NodeStatus::FAILURE;
  }
}

}  // namespace rm_behavior_tree

#include "behaviortree_cpp/bt_factory.h"
BT_REGISTER_NODES(factory)
{
  factory.registerNodeType<rm_behavior_tree::HpAmmoDcisionAction>("HpAmmoDecision");
}
