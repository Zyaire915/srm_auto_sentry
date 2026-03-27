#include "rm_behavior_tree/plugins/action/hp_decision_patrol.hpp"
#include "behaviortree_cpp/bt_factory.h"
#include <rclcpp/rclcpp.hpp>
#include <cmath>

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

  // 订阅血量话题，在 ROS 回调中实时更新 is_recovering（不依赖行为树 tick）
  hp_sub_ = ros_node->create_subscription<rm_decision_interfaces::msg::Sefdefined>(
    hp_topic, rclcpp::QoS(10),
    [this, ros_node](const rm_decision_interfaces::msg::Sefdefined::SharedPtr msg) {
      std::lock_guard<std::mutex> lock(rc_mutex_);
      int current_hp = msg->current_hp;
      if (current_hp <= hp_threshold_) {
        is_recovering_ = true;
      } else if (current_hp >= max_hp_) {
        is_recovering_ = false;
      }
      cached_rc_msg_.is_recovering = is_recovering_;
      RCLCPP_INFO_THROTTLE(ros_node->get_logger(), *ros_node->get_clock(), 2000,
        "[HpDecisionPatrol] HP=%d, is_recovering=%s", current_hp,
        is_recovering_ ? "true" : "false");
    });

  // 10Hz 定时器，持续发布 robot_control
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
    BT::InputPort<int>("hp_threshold", 400, "HP threshold to trigger recovery"),
    BT::InputPort<int>("max_hp", 600, "HP threshold to exit recovery"),
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

  // 3. 迟滞决策
  if (current_hp <= hp_threshold) {
    is_recovering_ = true;
  } else if (current_hp >= max_hp) {
    is_recovering_ = false;
  }

  double tx = 0.0, ty = 0.0;
  if (!is_recovering_) {
    getInput("high_hp_x", tx);
    getInput("high_hp_y", ty);
  } else {
    getInput("low_hp_x", tx);
    getInput("low_hp_y", ty);
  }

  // 4. 检测目标是否变化（用于在 ReactiveSequence 中中途切换导航目标）
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

  // 5. 组装 Pose 并输出到黑板
  geometry_msgs::msg::PoseStamped goal;
  goal.header.frame_id = "map";
  goal.header.stamp = rclcpp::Clock().now();
  goal.pose.position.x = tx;
  goal.pose.position.y = ty;
  goal.pose.orientation.w = 1.0;

  setOutput("target_pose", goal);
  setOutput("is_recovering", is_recovering_);

  // 6. 更新 robot_control 缓存中的非血量字段（spin_vel, stop_scan）
  //    is_recovering 由 ROS 订阅回调实时更新，不在这里设置
  {
    std::lock_guard<std::mutex> lock(rc_mutex_);

    float spin_vel = 0.5f;
    getInput("chassis_spin_vel", spin_vel);
    cached_rc_msg_.chassis_spin_vel = spin_vel;

    bool stop_scan = false;
    getInput("stop_gimbal_scan", stop_scan);
    cached_rc_msg_.stop_gimbal_scan = stop_scan;
  }

  // 7. 如果目标发生变化，返回 FAILURE 使 ReactiveSequence 中断当前 SendGoal（取消导航）
  //    下一次 tick 时目标未变，返回 SUCCESS，SendGoal 用新目标重新启动导航
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