#ifndef RM_BEHAVIOR_TREE__PLUGINS__ACTION__SUB_ALLY_ROBOT_HP_HPP_
#define RM_BEHAVIOR_TREE__PLUGINS__ACTION__SUB_ALLY_ROBOT_HP_HPP_

#include "behaviortree_ros2/bt_topic_sub_node.hpp"
#include "rm_decision_interfaces/msg/ally_robot_hp.hpp"

namespace rm_behavior_tree
{

class SubAllyRobotHPAction : public BT::RosTopicSubNode<rm_decision_interfaces::msg::AllyRobotHP>
{
public:
  SubAllyRobotHPAction(
    const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params);

  // 【关键修改】必须声明这个函数，否则 XML 里的端口会报错
  static BT::PortsList providedPorts();

  BT::NodeStatus onTick(const std::shared_ptr<rm_decision_interfaces::msg::AllyRobotHP>& last_msg) override;
};

}  // namespace rm_behavior_tree

#endif