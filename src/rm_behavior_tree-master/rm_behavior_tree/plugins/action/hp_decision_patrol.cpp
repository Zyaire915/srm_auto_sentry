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

  // 10Hz 定时器，持续发布 robot_control
  rc_timer_ = ros_node->create_wall_timer(
    std::chrono::milliseconds(100),
    [this]() {
      std::lock_guard<std::mutex> lock(rc_mutex_);
      rc_pub_->publish(cached_rc_msg_);
    });

  // TF2：用于查询 map→base_link，计算机器人到 low_hp 点的实际距离
  auto clock = ros_node->get_clock();
  tf2::Duration buffer_duration(tf2::durationFromSec(10.0));
  tf_buffer_ = std::make_shared<tf2_ros::Buffer>(clock, buffer_duration, ros_node);
  tf_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);
}

double HpDecisionPatrol::distanceToPoint(double x, double y)
{
  try {
    auto t = tf_buffer_->lookupTransform("map", "base_link", tf2::TimePointZero);
    double dx = t.transform.translation.x - x;
    double dy = t.transform.translation.y - y;
    return std::sqrt(dx * dx + dy * dy);
  } catch (const tf2::TransformException &) {
    return -1.0;  // TF 查询失败，返回负数表示不可用
  }
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

  // 3. 读取 low_hp 坐标（状态机需要用来计算距离）
  double low_hp_x = 0.0, low_hp_y = 0.0;
  getInput("low_hp_x", low_hp_x);
  getInput("low_hp_y", low_hp_y);

  // 4. 三态状态机
  //    NORMAL      —— 正常巡逻（high_hp 点位），is_recovering=0
  //    GOING_HOME  —— 半血撤退（low_hp 点位），is_recovering=0（撤退途中保持战斗模式）
  //    RECOVERING  —— TF2 确认已到达 low_hp 回血点（距离<0.5m），is_recovering=1
  switch (state_) {
    case PatrolState::NORMAL:
      if (current_hp <= hp_threshold) {
        state_ = PatrolState::GOING_HOME;
      }
      break;

    case PatrolState::GOING_HOME: {
      // 用 TF2 查询机器人当前位置到 low_hp 点的距离
      double dist = distanceToPoint(low_hp_x, low_hp_y);
      if (dist >= 0.0 && dist < ARRIVE_DIST_THRESHOLD) {
        // 机器人物理上已到达 low_hp 回血点 → 进入回血
        state_ = PatrolState::RECOVERING;
      } else if (current_hp >= max_hp) {
        // 撤退途中 HP 已恢复（极少出现），直接回归正常巡逻
        state_ = PatrolState::NORMAL;
      }
      break;
    }

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
    tx = low_hp_x;
    ty = low_hp_y;
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