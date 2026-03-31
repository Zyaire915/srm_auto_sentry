#ifndef RM_BEHAVIOR_TREE__PLUGINS__ACTION__HP_DECISION_PATROL_HPP_
#define RM_BEHAVIOR_TREE__PLUGINS__ACTION__HP_DECISION_PATROL_HPP_

#include "behaviortree_cpp/action_node.h"
#include "rm_decision_interfaces/msg/ally_robot_hp.hpp"
#include "rm_decision_interfaces/msg/robot_control.hpp"
#include "rm_decision_interfaces/msg/sefdefined.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include <rclcpp/rclcpp.hpp>
#include <mutex>

namespace rm_behavior_tree
{

class HpDecisionPatrol : public BT::SyncActionNode
{
public:
  /// 巡逻状态机
  enum class PatrolState {
    NORMAL,       ///< 正常巡逻，前往 high_hp 点位
    GOING_HOME,   ///< 血量低于阈值，正在撤回 low_hp 点位（is_recovering=0）
    RECOVERING    ///< 已抵达 low_hp 点位（Nav2 导航成功），正在回血（is_recovering=1）
  };

  HpDecisionPatrol(const std::string& name, const BT::NodeConfig& config);

  /**
   * 外部在 main 中调用，注入 ROS 节点。
   * 会创建：
   *   1) /srm/sefdefined 订阅者（仅接收血量）
   *   2) robot_control publisher + 10Hz 定时器 —— 持续发布
   * 到达 low_hp 点位的判断通过 SendGoal 的 goal_reached blackboard 变量完成（Nav2 导航结果）。
   */
  void initRos(rclcpp::Node::SharedPtr ros_node,
               const std::string & rc_topic,
               const std::string & hp_topic,
               int hp_threshold, int max_hp);

  static BT::PortsList providedPorts();

  BT::NodeStatus tick() override;

private:
  PatrolState state_ = PatrolState::NORMAL;
  bool is_recovering_ = false;
  int hp_threshold_ = 400;
  int max_hp_ = 600;

  // 目标跟踪：检测目标是否变化，以便中途切换导航目标
  double last_goal_x_ = 0.0;
  double last_goal_y_ = 0.0;
  bool first_goal_set_ = false;

  // ROS 订阅 + 发布
  rclcpp::Subscription<rm_decision_interfaces::msg::Sefdefined>::SharedPtr hp_sub_;
  rclcpp::Publisher<rm_decision_interfaces::msg::RobotControl>::SharedPtr rc_pub_;
  rclcpp::TimerBase::SharedPtr rc_timer_;
  rm_decision_interfaces::msg::RobotControl cached_rc_msg_;
  std::mutex rc_mutex_;
};

}  // namespace rm_behavior_tree

#endif