#ifndef RM_BEHAVIOR_TREE__PLUGINS__ACTION__HP_DECISION_PATROL_HPP_
#define RM_BEHAVIOR_TREE__PLUGINS__ACTION__HP_DECISION_PATROL_HPP_

#include "behaviortree_cpp/action_node.h"
#include "rm_decision_interfaces/msg/ally_robot_hp.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "rclcpp/rclcpp.hpp"

namespace rm_behavior_tree
{
// 注意：改为继承 SyncActionNode，因为我们不需要自己管理订阅了
class HpDecisionPatrol : public BT::SyncActionNode
{
public:
  HpDecisionPatrol(const std::string& name, const BT::NodeConfig& config);

  static BT::PortsList providedPorts();

  BT::NodeStatus tick() override;
};

}  // namespace rm_behavior_tree

#endif