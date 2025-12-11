#include "rm_behavior_tree/rm_behavior_tree.h"

#include "behaviortree_cpp/bt_factory.h"
#include "behaviortree_cpp/loggers/groot2_publisher.h"
#include "behaviortree_cpp/utils/shared_library.h"
#include "behaviortree_ros2/plugins.hpp"
// 【新增 1】必须添加这个头文件，否则系统看不懂 XML 里的坐标字符串
#include "rm_behavior_tree/bt_conversions.hpp"
int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  BT::BehaviorTreeFactory factory;

  std::string bt_xml_path;
  auto node = std::make_shared<rclcpp::Node>("rm_behavior_tree");
  node->declare_parameter<std::string>(
    "style", "./rm_decision_ws/rm_behavior_tree/rm_behavior_tree.xml");
  node->get_parameter_or<std::string>(
    "style", bt_xml_path, "./rm_decision_ws/rm_behavior_tree/config/attack_left.xml");

  std::cout << "Start RM_Behavior_Tree" << '\n';
  RCLCPP_INFO(node->get_logger(), "Load bt_xml: \e[1;42m %s \e[0m", bt_xml_path.c_str());

  BT::RosNodeParams params_update_msg;
  params_update_msg.nh = std::make_shared<rclcpp::Node>("update_msg");

  BT::RosNodeParams params_robot_control;
  params_robot_control.nh = std::make_shared<rclcpp::Node>("robot_control");
  params_robot_control.default_port_value = "robot_control";

  BT::RosNodeParams params_send_goal;
  params_send_goal.nh = std::make_shared<rclcpp::Node>("send_goal");
  //FIX
  params_send_goal.default_port_value = "navigate_to_pose";

  // 【新增 2】定义 SubAllyRobotHP 的参数 (话题名)
  BT::RosNodeParams params_sub_ally;
  params_sub_ally.nh = std::make_shared<rclcpp::Node>("sub_ally_hp");
  // 确保这里的话题名和你 interfaces 转换后的实际话题一致
  params_sub_ally.default_port_value = "referee/ally_robot_hp";

  // clang-format off
  const std::vector<std::string> msg_update_plugin_libs = {
    "sub_all_robot_hp",
    "sub_robot_status",
    "sub_game_status",
    "sub_armors",
    "sub_decision_num",
  };

  const std::vector<std::string> bt_plugin_libs = {
    "rate_controller",
    "decision_switch",
    "is_game_time",
    "is_status_ok",
    "is_detect_enemy",
    "is_attacked",
    "is_friend_ok",
    "is_outpost_ok",
    "get_current_location",
    "move_around",
    "print_message",
  };
  // clang-format on

  for (const auto & p : msg_update_plugin_libs) {
    RegisterRosNode(factory, BT::SharedLibrary::getOSName(p), params_update_msg);
  }

  for (const auto & p : bt_plugin_libs) {
    factory.registerFromPlugin(BT::SharedLibrary::getOSName(p));
  }

  RegisterRosNode(factory, BT::SharedLibrary::getOSName("send_goal"), params_send_goal);

  RegisterRosNode(factory, BT::SharedLibrary::getOSName("robot_control"), params_robot_control);

  // 【新增 3】注册 SubAllyRobotHP (ROS 插件)
  RegisterRosNode(factory, BT::SharedLibrary::getOSName("sub_ally_robot_hp"), params_sub_ally);

  // 【新增 4】注册 HpDecisionPatrol (普通插件)
  factory.registerFromPlugin(BT::SharedLibrary::getOSName("hp_decision_patrol"));

  auto tree = factory.createTreeFromFile(bt_xml_path);

  // Connect the Groot2Publisher. This will allow Groot2 to get the tree and poll status updates.
  const unsigned port = 1667;
  BT::Groot2Publisher publisher(tree, port);

  while (rclcpp::ok()) {
    tree.tickWhileRunning(std::chrono::milliseconds(10));
  }

  rclcpp::shutdown();
  return 0;
}