/**
  ****************************(C) COPYRIGHT 2024 Polarbear*************************
  * @file       standard_robot_pp_ros2.hpp
  * @brief      上下位机通信模块 (Adapted for RoboMaster 2026 Protocol V1.0.0)
  * @history
  * Version    Date            Author          Modification
  * V1.0.0     Jul-18-2024     Penguin         1. done
  * V1.1.0     Nov-28-2025     AI              2. Update to new RM2026 Protocol
  @verbatim
  =================================================================================

  =================================================================================
  @endverbatim
  ****************************(C) COPYRIGHT 2024 Polarbear*************************
  */
#ifndef STANDARD_ROBOT_PP_ROS2__ROS2_STANDARD_ROBOT_HPP_
#define STANDARD_ROBOT_PP_ROS2__ROS2_STANDARD_ROBOT_HPP_

// 移除了 tf2_ros/transform_broadcaster.h (IMU 功能已移除)
// 移除了 float64, u_int8, imu, joint_state 等旧消息头文件

#include <geometry_msgs/msg/twist.hpp>
#include <rm_decision_interfaces/msg/event_data.hpp>
#include <rm_decision_interfaces/msg/game_robot_hp.hpp>
#include <rm_decision_interfaces/msg/game_status.hpp>
#include <rm_decision_interfaces/msg/ground_robot_position.hpp>
#include <rm_decision_interfaces/msg/rfid_status.hpp>
// #include "rm_decision_interfaces/msg/ally_robot_hp.hpp"
#include "rm_decision_interfaces/msg/ally_robot_hp.hpp"
#include <rm_decision_interfaces/msg/robot_status.hpp> // 注意：这里对应的是 0x0202 能量热量数据
#include <rclcpp/rclcpp.hpp>
#include <serial_driver/serial_driver.hpp>

#include "packet_typedef.hpp"
// 移除了 "robot_info.hpp" (RobotModels 依赖已移除)

namespace standard_robot_pp_ros2
{
class StandardRobotPpRos2Node : public rclcpp::Node
{
public:
  explicit StandardRobotPpRos2Node(const rclcpp::NodeOptions & options);

  ~StandardRobotPpRos2Node() override;

private:
  bool is_usb_ok_;
  std::unique_ptr<IoContext> owned_ctx_;
  std::string device_name_;
  std::unique_ptr<drivers::serial_driver::SerialPortConfig> device_config_;
  std::unique_ptr<drivers::serial_driver::SerialDriver> serial_driver_;

  std::thread receive_thread_;
  std::thread send_thread_;
  std::thread serial_port_protect_thread_;

  // Publish (仅保留新协议需要的发布者)
  rclcpp::Publisher<rm_decision_interfaces::msg::EventData>::SharedPtr event_data_pub_;             // 0x0101
  rclcpp::Publisher<rm_decision_interfaces::msg::AllyRobotHP>::SharedPtr all_robot_hp_pub_;  
  // ✅ 正确：修改为 AllyRobotHP
  rclcpp::Publisher<rm_decision_interfaces::msg::GameStatus>::SharedPtr game_status_pub_;           // 0x0001
  rclcpp::Publisher<rm_decision_interfaces::msg::GroundRobotPosition>::SharedPtr ground_robot_position_pub_; // 0x020B
  rclcpp::Publisher<rm_decision_interfaces::msg::RfidStatus>::SharedPtr rfid_status_pub_;           // 0x0209
  rclcpp::Publisher<rm_decision_interfaces::msg::RobotStatus>::SharedPtr robot_status_pub_;         // 0x0202
  // 移除了 imu_pub_, robot_state_info_pub_, robot_motion_pub_, joint_state_pub_

  // Subscribe
  rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_sub_;
  // 移除了 cmd_gimbal_joint_sub_, cmd_shoot_sub_

  // 移除了 robot_models_, debug_pub_map_
  // 移除了 imu_tf_broadcaster_

  SendRobotCmdData send_robot_cmd_data_;

  void getParams();
  void createPublisher();
  void createSubscription();
  // 移除了 createNewDebugPublisher
  void receiveData();
  void sendData();
  void serialPortProtect();

  // Data Process Functions (仅保留新协议对应的处理函数)
  void publishEventData(ReceiveEventData & data);           // 0x0101
  void publishAllRobotHp(ReceiveAllRobotHpData & data);     // 0x0003
  void publishGameStatus(ReceiveGameStatusData & data);     // 0x0001
  void publishGroundRobotPosition(ReceiveGroundRobotPosition & data); // 0x020B
  void publishRfidStatus(ReceiveRfidStatus & data);         // 0x0209
  void publishRobotStatus(ReceiveRobotStatus & data);       // 0x0202
  // 移除了 publishDebugData, publishImuData, publishRobotInfo, publishRobotMotion, publishJointState

  // Callbacks
  void CmdVelCallback(const geometry_msgs::msg::Twist::SharedPtr msg);
  // 移除了 CmdGimbalJointCallback, CmdShootCallback

  // debug (ID 类型修正为 uint16_t 以匹配 2 字节 ID)
  void printHex(const std::string& tag, uint16_t id, const std::vector<uint8_t>& data);
};
}  // namespace standard_robot_pp_ros2

#endif  // STANDARD_ROBOT_PP_ROS2__ROS2_STANDARD_ROBOT_HPP_