#include "rm_behavior_tree/plugins/action/sub_ally_robot_hp.hpp"
#include "behaviortree_ros2/plugins.hpp"

namespace rm_behavior_tree
{

SubAllyRobotHPAction::SubAllyRobotHPAction(
  const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params)
: BT::RosTopicSubNode<rm_decision_interfaces::msg::AllyRobotHP>(name, conf, params)
{
}

// 【关键修改】这里定义了 XML 中允许使用的端口名
BT::PortsList SubAllyRobotHPAction::providedPorts()
{
  return {
    // 这里的字符串 "ally_hp_data" 必须和 XML 里的属性名完全一致
    BT::OutputPort<rm_decision_interfaces::msg::AllyRobotHP>("ally_hp_data")
  };
}

BT::NodeStatus SubAllyRobotHPAction::onTick(
  const std::shared_ptr<rm_decision_interfaces::msg::AllyRobotHP> & last_msg)
{
  if (last_msg) {
    // 调试日志
    RCLCPP_DEBUG(logger(), "[%s] Received HP Data", name().c_str());
    
    // 将数据写入上面定义的端口
    setOutput("ally_hp_data", *last_msg);
  }
  return BT::NodeStatus::SUCCESS;
}

}  // namespace rm_behavior_tree

// 注册插件
CreateRosNodePlugin(rm_behavior_tree::SubAllyRobotHPAction, "SubAllyRobotHP");