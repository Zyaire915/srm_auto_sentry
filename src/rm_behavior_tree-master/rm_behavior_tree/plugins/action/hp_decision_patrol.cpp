#include "rm_behavior_tree/plugins/action/hp_decision_patrol.hpp"
#include "behaviortree_cpp/bt_factory.h"

namespace rm_behavior_tree
{

HpDecisionPatrol::HpDecisionPatrol(const std::string& name, const BT::NodeConfig& config)
: BT::SyncActionNode(name, config)
{
}

BT::PortsList HpDecisionPatrol::providedPorts()
{
  return {
    // 输入：从 SubAllyRobotHP 那里拿到的血量数据
    BT::InputPort<rm_decision_interfaces::msg::AllyRobotHP>("hp_input"),
    
    // 参数：两个巡逻点
    BT::InputPort<double>("high_hp_x", 0.0, "X when HP > threshold"),
    BT::InputPort<double>("high_hp_y", 0.0, "Y when HP > threshold"),
    BT::InputPort<double>("low_hp_x", 0.0, "X when HP <= threshold"),
    BT::InputPort<double>("low_hp_y", 0.0, "Y when HP <= threshold"),

    // 新增：从 XML 配置或黑板传入的血量阈值（默认 400）
    BT::InputPort<int>("hp_threshold", 400, "HP threshold for decision"),

    // 输出：计算出的目标点，传给 SendGoal
    BT::OutputPort<geometry_msgs::msg::PoseStamped>("target_pose")
  };
}

BT::NodeStatus HpDecisionPatrol::tick()
{
  // 1. 从黑板读取血量数据
  auto hp_msg = getInput<rm_decision_interfaces::msg::AllyRobotHP>("hp_input");
  
  // 如果还没收到数据，返回 FAILURE 或者 RUNNING
  if (!hp_msg) {
    return BT::NodeStatus::FAILURE; 
  }

  // 2. 提取哨兵血量 (ally_7)
  int current_hp = hp_msg.value().ally_7_robot_hp;

  // 读取阈值（端口默认值为 400，可由 XML 或外部黑板覆盖）
  int hp_threshold = 400;
  getInput("hp_threshold", hp_threshold);

  // 3. 决策逻辑（基于可配置阈值）
  double tx = 0.0, ty = 0.0;
  if (current_hp > hp_threshold) {
    getInput("high_hp_x", tx);
    getInput("high_hp_y", ty);
  } else {
    getInput("low_hp_x", tx);
    getInput("low_hp_y", ty);
  }

  // 4. 组装 Pose 并输出
  geometry_msgs::msg::PoseStamped goal;
  goal.header.frame_id = "map";
  goal.header.stamp = rclcpp::Clock().now(); // 注意：如果没有节点句柄，这里可能需要传入时钟
  goal.pose.position.x = tx;
  goal.pose.position.y = ty;
  goal.pose.orientation.w = 1.0;

  setOutput("target_pose", goal);

  return BT::NodeStatus::SUCCESS;
}

} // namespace rm_behavior_tree

// 注册为普通插件（不是RosNodePlugin了，因为它不持有ROS句柄）
BT_REGISTER_NODES(factory)
{
  factory.registerNodeType<rm_behavior_tree::HpDecisionPatrol>("HpDecisionPatrol");
}