// navigate_through_waypoints.cpp
#include "rm_nav_bringup/navigate_through_waypoints.hpp"
#include "rclcpp/rclcpp.hpp"

namespace rm_nav_bringup
{

NavigateThroughWaypoints::NavigateThroughWaypoints(
  const std::string & name,
  const BT::NodeConfig & config,
  rclcpp::Node::SharedPtr node)
: BT::SyncActionNode(name, config), node_(node)
{
  nav_client_ = rclcpp_action::create_client<nav2_msgs::action::NavigateToPose>(
    node, "navigate_to_pose");
}

void NavigateThroughWaypoints::setGoalCheckerTolerance(double tolerance)
{
  auto client = std::make_shared<rclcpp::Client<rcl_interfaces::srv::SetParameters>>(
    node_, "/controller_server/set_parameters");
  
  if (!client->wait_for_service(std::chrono::seconds(1))) {
    RCLCPP_WARN(node_->get_logger(), "Goal checker service not available");
    return;
  }

  auto request = std::make_shared<rcl_interfaces::srv::SetParameters::Request>();
  rcl_interfaces::msg::Parameter param;
  param.name = "general_goal_checker.xy_goal_tolerance";
  param.value.double_value = tolerance;
  request->parameters.push_back(param);

  client->async_send_request(request);
}

bool NavigateThroughWaypoints::navigateToGoal(
  const geometry_msgs::msg::PoseStamped & goal)
{
  if (!nav_client_->action_server_is_ready()) {
    RCLCPP_ERROR(node_->get_logger(), "navigate_to_pose action server not ready");
    return false;
  }

  auto goal_msg = nav2_msgs::action::NavigateToPose::Goal();
  goal_msg.pose = goal;

  auto future_handle = nav_client_->async_send_goal(goal_msg);

  // 等待目标完成
  if (rclcpp::spin_until_future_complete(
      node_, future_handle, std::chrono::seconds(300)) !=
    rclcpp::FutureReturnCode::SUCCESS)
  {
    RCLCPP_ERROR(node_->get_logger(), "Failed to navigate to goal");
    return false;
  }

  return true;
}

BT::NodeStatus NavigateThroughWaypoints::tick()
{
  auto poses = getInput<std::vector<geometry_msgs::msg::PoseStamped>>("poses");
  if (!poses) {
    return BT::NodeStatus::FAILURE;
  }

  auto waypoint_tolerance = getInput<double>("waypoint_tolerance");
  auto final_goal_tolerance = getInput<double>("final_goal_tolerance");

  if (!waypoint_tolerance || !final_goal_tolerance) {
    return BT::NodeStatus::FAILURE;
  }

  // 导航到所有途径点
  for (size_t i = 0; i < poses.value().size() - 1; ++i) {
    // 设置途径点容差
    setGoalCheckerTolerance(waypoint_tolerance.value());
    
    RCLCPP_INFO(node_->get_logger(), "Navigating to waypoint %zu/%zu", 
                i + 1, poses.value().size() - 1);
    
    if (!navigateToGoal(poses.value()[i])) {
      return BT::NodeStatus::FAILURE;
    }
  }

  // 导航到最终目标
  setGoalCheckerTolerance(final_goal_tolerance.value());
  RCLCPP_INFO(node_->get_logger(), "Navigating to final goal");
  
  if (!navigateToGoal(poses.value().back())) {
    return BT::NodeStatus::FAILURE;
  }

  setOutput("success", true);
  return BT::NodeStatus::SUCCESS;
}

}  // namespace rm_nav_bringup

#include "behaviortree_ros2/plugins.hpp"
CreateRosNodePlugin(rm_nav_bringup::NavigateThroughWaypoints, "NavigateThroughWaypoints");
