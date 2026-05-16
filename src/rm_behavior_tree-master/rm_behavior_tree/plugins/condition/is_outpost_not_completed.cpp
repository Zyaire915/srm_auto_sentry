#include "rm_behavior_tree/plugins/condition/is_outpost_not_completed.hpp"

namespace rm_behavior_tree
{

IsOutpostNotCompletedAction::IsOutpostNotCompletedAction(const std::string & name, const BT::NodeConfig & config)
: BT::SimpleConditionNode(name, std::bind(&IsOutpostNotCompletedAction::checkOutpostStatus, this), config)
{
}

BT::NodeStatus IsOutpostNotCompletedAction::checkOutpostStatus()
{
  auto switch_position_msg = getInput<pb_rm_interfaces::msg::SwitchPosition>("switch_position");

  if (!switch_position_msg) {
    return BT::NodeStatus::FAILURE;
  }

  // Return SUCCESS if outpost NOT completed (switch_position == 0)
  // Return FAILURE if outpost completed (switch_position == 1)
  if (switch_position_msg->switch_position == 0) {
    return BT::NodeStatus::SUCCESS;
  } else {
    return BT::NodeStatus::FAILURE;
  }
}

}  // namespace rm_behavior_tree

#include "behaviortree_cpp/bt_factory.h"
BT_REGISTER_NODES(factory)
{
  factory.registerNodeType<rm_behavior_tree::IsOutpostNotCompletedAction>("IsOutpostNotCompleted");
}
