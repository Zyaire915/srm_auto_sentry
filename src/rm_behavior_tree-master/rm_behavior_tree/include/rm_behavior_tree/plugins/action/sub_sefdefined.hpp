#ifndef RM_BEHAVIOR_TREE__PLUGINS__ACTION__SUB_SEFDEFINED_HPP_
#define RM_BEHAVIOR_TREE__PLUGINS__ACTION__SUB_SEFDEFINED_HPP_

#include "behaviortree_ros2/bt_topic_sub_node.hpp"
#include "rm_decision_interfaces/msg/sefdefined.hpp"

namespace rm_behavior_tree
{

class SubSefdefinedAction : public BT::RosTopicSubNode<rm_decision_interfaces::msg::Sefdefined>
{
public:
  SubSefdefinedAction(
    const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params);

  // 【关键修改】必须声明这个函数，否则 XML 里的端口会报错
  static BT::PortsList providedPorts();

  BT::NodeStatus onTick(const std::shared_ptr<rm_decision_interfaces::msg::Sefdefined>& last_msg) override;
};

}  // namespace rm_behavior_tree

#endif