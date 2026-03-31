#include "rm_behavior_tree/plugins/action/hp_decision_patrol.hpp"
#include "behaviortree_cpp/bt_factory.h"
#include <rclcpp/rclcpp.hpp>

namespace rm_behavior_tree
{

HpDecisionPatrol::HpDecisionPatrol(const std::string& name, const BT::NodeConfig& config)
: BT::SyncActionNode(name, config)
{
}

void HpDecisionPatrol::initRos(
  rclcpp::Node::SharedPtr ros_node,
  const std::string & rc_topic,
  const std::string & hp_topic,
  int hp_threshold, int max_hp)
{
  hp_threshold_ = hp_threshold;
  max_hp_ = max_hp;

  rc_pub_ = ros_node->create_publisher<rm_decision_interfaces::msg::RobotControl>(
    rc_topic, rclcpp::QoS(10));

  // 订阅血量话题 —— 仅保留订阅以维持 ROS 连接
  hp_sub_ = ros_node->create_subscription<rm_decision_interfaces::msg::Sefdefined>(
    hp_topic, rclcpp::QoS(10),
    [](const rm_decision_interfaces::msg::Sefdefined::SharedPtr /*msg*/) {
      // HP 决策由 tick() 中的三态状态机处理
    });

  // 5Hz 定时器，持续发布 robot_control（降频以减少队列压力）
  rc_timer_ = ros_node->create_wall_timer(
    std::chrono::milliseconds(100),
    [this]() {
      std::lock_guard<std::mutex> lock(rc_mutex_);
      rc_pub_->publish(cached_rc_msg_);
    });
}

BT::PortsList HpDecisionPatrol::providedPorts()
{
  return {
    BT::InputPort<rm_decision_interfaces::msg::Sefdefined>("hp_input"),
    BT::InputPort<double>("high_hp_x", 0.0, "X when HP > threshold"),
    BT::InputPort<double>("high_hp_y", 0.0, "Y when HP > threshold"),
    BT::InputPort<double>("low_hp_x", 0.0, "X when HP <= threshold"),
    BT::InputPort<double>("low_hp_y", 0.0, "Y when HP <= threshold"),
    BT::InputPort<int>("hp_threshold", 400, "HP threshold to trigger retreat (e.g. 50%)"),
    BT::InputPort<int>("max_hp", 600, "HP threshold to exit recovery (e.g. 90%)"),
    BT::InputPort<bool>("goal_reached", false, "Nav2 navigation succeeded signal from SendGoal"),
    BT::OutputPort<bool>("goal_reached_out", "Reset goal_reached when starting new navigation"),
    BT::InputPort<float>("chassis_spin_vel", 0.5f, "Chassis spin velocity"),
    BT::InputPort<bool>("stop_gimbal_scan", false, "Whether to stop gimbal scan"),
    BT::OutputPort<geometry_msgs::msg::PoseStamped>("target_pose"),
    BT::OutputPort<bool>("is_recovering")
  };
}

BT::NodeStatus HpDecisionPatrol::tick()
{
  // 1. 从黑板读取血量数据
  auto hp_msg = getInput<rm_decision_interfaces::msg::Sefdefined>("hp_input");
  if (!hp_msg) {
    return BT::NodeStatus::FAILURE;
  }

  // 2. 提取当前血量
  int current_hp = hp_msg.value().current_hp;

  int hp_threshold = 400;
  getInput("hp_threshold", hp_threshold);

  int max_hp = 600;
  getInput("max_hp", max_hp);

  // 3. 读取 SendGoal 写入的 goal_reached（Nav2 导航成功信号）
  bool goal_reached = false;
  getInput("goal_reached", goal_reached);

  // 4. 三态状态机
  //    NORMAL      —— 正常巡逻（high_hp 点位），is_recovering=0
  //    GOING_HOME  —— 半血撤退（low_hp 点位），is_recovering=0（撤退途中保持战斗模式）
  //    RECOVERING  —— Nav2 确认到达回血点，is_recovering=1（下位机可据此降功耗/停旋加速回血）
  switch (state_) {
    case PatrolState::NORMAL:
      if (current_hp <= hp_threshold) {
        state_ = PatrolState::GOING_HOME;
        // 重置 goal_reached，避免残留的上一次导航成功信号误触发 RECOVERING
        setOutput("goal_reached_out", false);
      }
      break;

    case PatrolState::GOING_HOME:
      if (goal_reached) {
        // Nav2 确认已到达 low_hp 回血点 → 正式进入回血
        state_ = PatrolState::RECOVERING;
      } else if (current_hp >= max_hp) {
        // 撤退途中 HP 已恢复（极少出现），直接回归正常巡逻
        state_ = PatrolState::NORMAL;
      }
      break;

    case PatrolState::RECOVERING:
      if (current_hp >= max_hp) {
        // 回血完成（≥90%），回归正常巡逻
        state_ = PatrolState::NORMAL;
      }
      break;
  }

  // is_recovering 仅在 RECOVERING 状态为 true
  is_recovering_ = (state_ == PatrolState::RECOVERING);

  // 5. 根据状态选择导航目标
  double tx = 0.0, ty = 0.0;
  if (state_ == PatrolState::NORMAL) {
    getInput("high_hp_x", tx);
    getInput("high_hp_y", ty);
  } else {
    // GOING_HOME 或 RECOVERING：目标是 low_hp 回血点
    getInput("low_hp_x", tx);
    getInput("low_hp_y", ty);
  }

  // 6. 检测目标是否变化（用于在 ReactiveSequence 中中途切换导航目标）
  bool goal_changed = false;
  if (first_goal_set_) {
    constexpr double eps = 0.01;  // 1cm 容差
    if (std::abs(tx - last_goal_x_) > eps || std::abs(ty - last_goal_y_) > eps) {
      goal_changed = true;
    }
  } else {
    first_goal_set_ = true;
  }
  last_goal_x_ = tx;
  last_goal_y_ = ty;

  // 7. 组装 Pose 并输出到黑板
  geometry_msgs::msg::PoseStamped goal;
  goal.header.frame_id = "map";
  goal.header.stamp = rclcpp::Clock().now();
  goal.pose.position.x = tx;
  goal.pose.position.y = ty;
  goal.pose.orientation.w = 1.0;

  setOutput("target_pose", goal);
  setOutput("is_recovering", is_recovering_);

  // 8. 更新 robot_control 缓存（含 is_recovering，由定时器持续发布）
  {
    std::lock_guard<std::mutex> lock(rc_mutex_);

    cached_rc_msg_.is_recovering = is_recovering_;

    float spin_vel = 0.5f;
    getInput("chassis_spin_vel", spin_vel);
    cached_rc_msg_.chassis_spin_vel = spin_vel;

    bool stop_scan = false;
    getInput("stop_gimbal_scan", stop_scan);
    cached_rc_msg_.stop_gimbal_scan = stop_scan;
  }

  // 9. 如果目标发生变化，返回 FAILURE 使 ReactiveSequence 中断当前 SendGoal（取消导航）
  //     下一次 tick 时目标未变，返回 SUCCESS，SendGoal 用新目标重新启动导航
  if (goal_changed) {
    return BT::NodeStatus::FAILURE;
  }
  return BT::NodeStatus::SUCCESS;
}

} // namespace rm_behavior_tree

BT_REGISTER_NODES(factory)
{
  factory.registerNodeType<rm_behavior_tree::HpDecisionPatrol>("HpDecisionPatrol");
}