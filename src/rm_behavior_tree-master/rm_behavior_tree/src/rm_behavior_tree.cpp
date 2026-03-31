#include "rm_behavior_tree/rm_behavior_tree.h"

#include "behaviortree_cpp/bt_factory.h"
#include "behaviortree_cpp/loggers/groot2_publisher.h"
#include "behaviortree_cpp/utils/shared_library.h"
#include "behaviortree_ros2/plugins.hpp"
#include "rm_behavior_tree/bt_conversions.hpp"
#include "rm_behavior_tree/plugins/action/hp_decision_patrol.hpp"
#include <thread>
#include <stdexcept>
#include <rclcpp_action/exceptions.hpp>

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

  BT::RosNodeParams params_send_goal;
  params_send_goal.nh = std::make_shared<rclcpp::Node>("send_goal");
  params_send_goal.default_port_value = "navigate_to_pose";
  params_send_goal.server_timeout = std::chrono::milliseconds(500);
  params_send_goal.wait_for_server_timeout = std::chrono::milliseconds(1000);

  BT::RosNodeParams params_sub_sefdefined;
  params_sub_sefdefined.nh = std::make_shared<rclcpp::Node>("sub_sefdefined");
  params_sub_sefdefined.default_port_value = "/srm/sefdefined";

  // HpDecisionPatrol 用于发布 robot_control 的 ROS 节点
  auto hp_patrol_ros_node = std::make_shared<rclcpp::Node>("hp_patrol_rc_pub");

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
  RegisterRosNode(factory, BT::SharedLibrary::getOSName("sub_sefdefined"), params_sub_sefdefined);

  // 注册 HpDecisionPatrol（普通插件，不是 ROS 插件）
  factory.registerFromPlugin(BT::SharedLibrary::getOSName("hp_decision_patrol"));

  auto tree = factory.createTreeFromFile(bt_xml_path);

  // 遍历树，找到 HpDecisionPatrol 节点并注入 ROS 节点
  // initRos 会创建：1) /srm/sefdefined 订阅者（实时更新 is_recovering）  2) robot_control publisher + 10Hz 定时器
  for (auto & subtree : tree.subtrees) {
    for (auto & bt_node : subtree->nodes) {
      if (auto * hp_node = dynamic_cast<rm_behavior_tree::HpDecisionPatrol *>(bt_node.get())) {
        hp_node->initRos(hp_patrol_ros_node, "robot_control", "/srm/sefdefined", 200, 360);
        RCLCPP_INFO(node->get_logger(), "HpDecisionPatrol: initRos done, subscribing HP & publishing robot_control at 10Hz");
      }
    }
  }

  // Connect the Groot2Publisher
  const unsigned port = 1667;
  BT::Groot2Publisher publisher(tree, port);

  // 在独立线程中 spin hp_patrol_ros_node，使定时器能以 10Hz 持续发布 robot_control
  rclcpp::executors::SingleThreadedExecutor hp_executor;
  hp_executor.add_node(hp_patrol_ros_node);
  std::thread hp_spin_thread([&hp_executor]() {
    hp_executor.spin();
  });

  while (rclcpp::ok()) {
    try {
      tree.tickWhileRunning(std::chrono::milliseconds(10));
    } catch (const rclcpp_action::exceptions::UnknownGoalHandleError & e) {
      RCLCPP_WARN(node->get_logger(), "Goal handle lost (nav server may have restarted): %s. Retrying...", e.what());
      tree.haltTree();
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    } catch (const std::exception & e) {
      RCLCPP_ERROR(node->get_logger(), "BT tick exception: %s. Retrying...", e.what());
      tree.haltTree();
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
  }

  hp_executor.cancel();
  if (hp_spin_thread.joinable()) {
    hp_spin_thread.join();
  }

  rclcpp::shutdown();
  return 0;
}