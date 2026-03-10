// navigate_through_waypoints.hpp
#pragma once

#include <vector>
#include <memory>
#include "behaviortree_ros2/bt_action_node.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "nav2_msgs/action/navigate_to_pose.hpp"
#include "nav2_msgs/action/compute_path_to_pose.hpp"
#include "nav2_msgs/action/follow_path.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"

namespace rm_nav_bringup
{

class NavigateThroughWaypoints : public BT::SyncActionNode
{
public:
  explicit NavigateThroughWaypoints(
    const std::string & name,
    const BT::NodeConfig & config,
    rclcpp::Node::SharedPtr node);

  static BT::PortsList providedPorts()
  {
    return {
      BT::InputPort<std::vector<geometry_msgs::msg::PoseStamped>>("poses"),
      BT::InputPort<double>("waypoint_tolerance", 1.0, "容差（米）"),
      BT::InputPort<double>("final_goal_tolerance", 0.25, "最终目标容差（米）"),
      BT::OutputPort<bool>("success")
    };
  }

  BT::NodeStatus tick() override;

private:
  rclcpp::Node::SharedPtr node_;
  rclcpp_action::Client<nav2_msgs::action::NavigateToPose>::SharedPtr nav_client_;
  
  // 设置参数的方法
  void setGoalCheckerTolerance(double tolerance);
  
  // 导航到单个目标
  bool navigateToGoal(const geometry_msgs::msg::PoseStamped & goal);
};

}  // namespace rm_nav_bringup
