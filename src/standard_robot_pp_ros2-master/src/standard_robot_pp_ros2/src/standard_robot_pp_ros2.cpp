#include "standard_robot_pp_ros2.hpp"
#include <atomic>
#include <deque>
#include <iomanip>
#include <mutex>
#include <sstream>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <rm_decision_interfaces/msg/robot_control.hpp>

#include "crc_func.h"
#include "packet_typedef.hpp"

std::atomic<bool> is_usb_ok_{false};
std::mutex send_mutex_;

#define USB_NOT_OK_SLEEP_TIME 1000   // (ms)
#define USB_PROTECT_SLEEP_TIME 1000  // (ms)

namespace standard_robot_pp_ros2
{

StandardRobotPpRos2Node::StandardRobotPpRos2Node(const rclcpp::NodeOptions & options)
: Node("StandardRobotPpRos2Node", options),
  owned_ctx_{new IoContext(2)},
  serial_driver_{new drivers::serial_driver::SerialDriver(*owned_ctx_)}
{
  RCLCPP_INFO(get_logger(), "Start StandardRobotPpRos2Node!");

  getParams();
  createPublisher();
  createSubscription();

  serial_port_protect_thread_ = std::thread(&StandardRobotPpRos2Node::serialPortProtect, this);
  receive_thread_ = std::thread(&StandardRobotPpRos2Node::receiveData, this);
  send_thread_ = std::thread(&StandardRobotPpRos2Node::sendData, this);
}

StandardRobotPpRos2Node::~StandardRobotPpRos2Node()
{
  if (send_thread_.joinable()) send_thread_.join();
  if (receive_thread_.joinable()) receive_thread_.join();
  if (serial_port_protect_thread_.joinable()) serial_port_protect_thread_.join();
  if (serial_driver_->port()->is_open()) serial_driver_->port()->close();
  if (owned_ctx_) owned_ctx_->waitForExit();
}

void StandardRobotPpRos2Node::createPublisher()
{
  event_data_pub_ =
    this->create_publisher<rm_decision_interfaces::msg::EventData>("referee/event_data", 10);
  sefdefined_pub_ =
    this->create_publisher<rm_decision_interfaces::msg::Sefdefined>("/srm/sefdefined", 10);
  // all_robot_hp_pub_ = this->create_publisher<rm_decision_interfaces::msg::AllyRobotHP>("referee/ally_robot_hp", 10);
  all_robot_hp_pub_ =
    this->create_publisher<rm_decision_interfaces::msg::AllyRobotHP>("referee/ally_robot_hp", 10);
  game_status_pub_ =
    this->create_publisher<rm_decision_interfaces::msg::GameStatus>("referee/game_status", 10);
  ground_robot_position_pub_ = this->create_publisher<rm_decision_interfaces::msg::GroundRobotPosition>(
    "referee/ground_robot_position", 10);
  rfid_status_pub_ =
    this->create_publisher<rm_decision_interfaces::msg::RfidStatus>("referee/rfid_status", 10);
  robot_status_pub_ =
    this->create_publisher<rm_decision_interfaces::msg::RobotStatus>("referee/robot_status", 10);
}

void StandardRobotPpRos2Node::createSubscription()
{
  cmd_vel_sub_ = this->create_subscription<geometry_msgs::msg::Twist>(
    "cmd_vel_chassis", 10,
    std::bind(&StandardRobotPpRos2Node::CmdVelCallback, this, std::placeholders::_1));
  robot_control_sub_ = this->create_subscription<rm_decision_interfaces::msg::RobotControl>(
    "robot_control", 10,
    std::bind(&StandardRobotPpRos2Node::RobotControlCallback, this, std::placeholders::_1));
}

void StandardRobotPpRos2Node::getParams()
{
  using FlowControl = drivers::serial_driver::FlowControl;
  using Parity = drivers::serial_driver::Parity;
  using StopBits = drivers::serial_driver::StopBits;

  uint32_t baud_rate{};
  auto fc = FlowControl::NONE;
  auto pt = Parity::NONE;
  auto sb = StopBits::ONE;

  try {
    device_name_ = declare_parameter<std::string>("device_name", "");
  } catch (rclcpp::ParameterTypeException & ex) {
    RCLCPP_ERROR(get_logger(), "The device name provided was invalid");
    throw ex;
  }

  try {
    baud_rate = declare_parameter<int>("baud_rate", 0);
  } catch (rclcpp::ParameterTypeException & ex) {
    RCLCPP_ERROR(get_logger(), "The baud_rate provided was invalid");
    throw ex;
  }

  try {
    const auto fc_string = declare_parameter<std::string>("flow_control", "");
    if (fc_string == "none")
      fc = FlowControl::NONE;
    else if (fc_string == "hardware")
      fc = FlowControl::HARDWARE;
    else if (fc_string == "software")
      fc = FlowControl::SOFTWARE;
    else
      throw std::invalid_argument{
        "The flow_control parameter must be one of: none, software, or hardware."};
  } catch (rclcpp::ParameterTypeException & ex) {
    RCLCPP_ERROR(get_logger(), "The flow_control provided was invalid");
    throw ex;
  }

  try {
    const auto pt_string = declare_parameter<std::string>("parity", "");
    if (pt_string == "none")
      pt = Parity::NONE;
    else if (pt_string == "odd")
      pt = Parity::ODD;
    else if (pt_string == "even")
      pt = Parity::EVEN;
    else
      throw std::invalid_argument{"The parity parameter must be one of: none, odd, or even."};
  } catch (rclcpp::ParameterTypeException & ex) {
    RCLCPP_ERROR(get_logger(), "The parity provided was invalid");
    throw ex;
  }

  try {
    const auto sb_string = declare_parameter<std::string>("stop_bits", "");
    if (sb_string == "1" || sb_string == "1.0")
      sb = StopBits::ONE;
    else if (sb_string == "1.5")
      sb = StopBits::ONE_POINT_FIVE;
    else if (sb_string == "2" || sb_string == "2.0")
      sb = StopBits::TWO;
    else
      throw std::invalid_argument{"The stop_bits parameter must be one of: 1, 1.5, or 2."};
  } catch (rclcpp::ParameterTypeException & ex) {
    RCLCPP_ERROR(get_logger(), "The stop_bits provided was invalid");
    throw ex;
  }

  device_config_ =
    std::make_unique<drivers::serial_driver::SerialPortConfig>(baud_rate, fc, pt, sb);
}

void StandardRobotPpRos2Node::serialPortProtect()
{
  RCLCPP_INFO(get_logger(), "Start serialPortProtect!");
  serial_driver_->init_port(device_name_, *device_config_);
  try {
    if (!serial_driver_->port()->is_open()) {
      serial_driver_->port()->open();
      RCLCPP_INFO(get_logger(), "Serial port opened!");
      is_usb_ok_ = true;
    }
  } catch (const std::exception & ex) {
    RCLCPP_ERROR(get_logger(), "Open serial port failed : %s", ex.what());
    is_usb_ok_ = false;
  }
  is_usb_ok_ = true;
  std::this_thread::sleep_for(std::chrono::milliseconds(USB_PROTECT_SLEEP_TIME));

  while (rclcpp::ok()) {
    if (!is_usb_ok_) {
      try {
        if (serial_driver_->port()->is_open()) serial_driver_->port()->close();
        serial_driver_->port()->open();
        if (serial_driver_->port()->is_open()) {
          RCLCPP_INFO(get_logger(), "Serial port opened!");
          is_usb_ok_ = true;
        }
      } catch (const std::exception & ex) {
        is_usb_ok_ = false;
        RCLCPP_ERROR(get_logger(), "Open serial port failed : %s", ex.what());
      }
    };
    std::this_thread::sleep_for(std::chrono::milliseconds(USB_PROTECT_SLEEP_TIME));
  }
}

/********************************************************/
/* Receive data                                         */
/********************************************************/

void StandardRobotPpRos2Node::receiveData()
{
  RCLCPP_INFO(get_logger(), "Start receiveData with Sliding Window!");

  int retry_count = 0;
  std::deque<uint8_t> rx_buffer;
  std::vector<uint8_t> read_buf;
  read_buf.reserve(1024);

  while (rclcpp::ok()) {
    if (!is_usb_ok_) {
      RCLCPP_WARN(get_logger(), "receive: usb is not ok! Retry count: %d", retry_count++);
      std::this_thread::sleep_for(std::chrono::milliseconds(USB_NOT_OK_SLEEP_TIME));
      rx_buffer.clear();
      continue;
    }

    try {
      // 1. 从串口读取所有可用数据
      read_buf.resize(1024);
      int received_len = 0;
      try {
        received_len = serial_driver_->port()->receive(read_buf);
      } catch (const std::exception & ex) {
        RCLCPP_ERROR(get_logger(), "Error reading from serial port: %s", ex.what());
        is_usb_ok_ = false;
        continue;
      }

      if (received_len > 0) {
        // 高效插入 deque
        rx_buffer.insert(rx_buffer.end(), read_buf.begin(), read_buf.begin() + received_len);
      } else {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        continue;
      }

      // 2. 滑动窗口解析
      while (rx_buffer.size() >= 5) {
        // 查找帧头 SOF
        if (rx_buffer.front() != SOF_RECEIVE) {
          rx_buffer.pop_front();
          continue;
        }

        // 提取前5字节 Header 用于 CRC8 校验
        std::vector<uint8_t> header_bytes(rx_buffer.begin(), rx_buffer.begin() + 5);
        if (!verify_CRC8_check_sum(header_bytes.data(), 5)) {
          // 伪造包头，丢弃1个字节，继续滑动
          RCLCPP_WARN(get_logger(), "Receive Header CRC8 FAIL! Dropping 1 byte.");
          rx_buffer.pop_front();
          continue;
        }

        HeaderFrame header_frame = fromVector<HeaderFrame>(header_bytes);
        
        // 检查 data_length 是否合法，防止恶意数据耗尽内存
        if (header_frame.data_length > 2048) {
          RCLCPP_WARN(get_logger(), "Invalid data length: %d", header_frame.data_length);
          rx_buffer.pop_front();
          continue;
        }

        // 完整包所需长度：Header(5) + CmdID(2) + Data(data_length) + CRC16(2)
        size_t total_packet_len = 5 + 2 + header_frame.data_length + 2;

        // 断帧处理：长度不够，跳出循环等待更多数据
        if (rx_buffer.size() < total_packet_len) {
          break;
        }

        // 提取全包用于 CRC16 校验
        std::vector<uint8_t> full_packet(rx_buffer.begin(), rx_buffer.begin() + total_packet_len);
        if (!verify_CRC16_check_sum(full_packet.data(), total_packet_len)) {
          // 校验失败，可能是错位或者丢包，丢弃头部 1 个字节，继续滑动查找下一个 SOF
          RCLCPP_WARN(get_logger(), "Receive CRC16 FAIL! Dropping 1 byte and sliding.");
          rx_buffer.pop_front();
          continue;
        }

        // --- 成功解析出完整帧 ---
        // 从 rx_buffer 中移除已被解析的完整帧
        rx_buffer.erase(rx_buffer.begin(), rx_buffer.begin() + total_packet_len);

        // 获取 CmdID，小端序解析
        uint16_t cmd_id = static_cast<uint16_t>(full_packet[5]) | (static_cast<uint16_t>(full_packet[6]) << 8);

        // 打印调试信息
        printHex("RECV", cmd_id, full_packet);

        // 8. 解析数据
        switch (cmd_id) {
          case ID_EVENT_DATA: {
            ReceiveEventData event_data = fromVector<ReceiveEventData>(full_packet);
            publishEventData(event_data);
          } break;
          case ID_ALL_ROBOT_HP: {
            ReceiveAllRobotHpData all_robot_hp_data = fromVector<ReceiveAllRobotHpData>(full_packet);
            publishAllRobotHp(all_robot_hp_data);
          } break;
          case ID_GAME_STATUS: {
            ReceiveGameStatusData game_status_data = fromVector<ReceiveGameStatusData>(full_packet);
            publishGameStatus(game_status_data);
          } break;
          case ID_GROUND_ROBOT_POSITION: {
            ReceiveGroundRobotPosition ground_robot_position_data =
              fromVector<ReceiveGroundRobotPosition>(full_packet);
            publishGroundRobotPosition(ground_robot_position_data);
          } break;
          case ID_RFID_STATUS: {
            ReceiveRfidStatus rfid_status_data = fromVector<ReceiveRfidStatus>(full_packet);
            publishRfidStatus(rfid_status_data);
          } break;
          case ID_ROBOT_STATUS: {
            ReceiveRobotStatus robot_status_data = fromVector<ReceiveRobotStatus>(full_packet);
            publishRobotStatus(robot_status_data);
          } break;
          case ID_SEFDEFINED:
          case ID_ROBOT_STATUS_V1: {
            ReceiveSefdefinedData sefdefined_data = fromVector<ReceiveSefdefinedData>(full_packet);
            publishSefdefined(sefdefined_data);
          } break;
          default: {
            RCLCPP_DEBUG(get_logger(), "Unknown CmdID: 0x%04X", cmd_id);
          } break;
        }
      }
    } catch (const std::exception & ex) {
      RCLCPP_ERROR(get_logger(), "Error receiving data: %s", ex.what());
      is_usb_ok_ = false;
    }
  }
}

/********************************************************/
/* Publish data                                         */
/********************************************************/
void StandardRobotPpRos2Node::publishEventData(ReceiveEventData & event_data)
{
  rm_decision_interfaces::msg::EventData msg;
  // 获取 32位 事件数据
  uint32_t bits = event_data.data.event_data;

  // --- 补给区状态 (Bit 0-2) ---
  msg.supply_zone_non_overlap = (bits >> 0) & 1;  // bit 0: 己方与资源区不重叠的补给区 (1为已占领)
  msg.supply_zone_overlap = (bits >> 1) & 1;  // bit 1: 己方与资源区重叠的补给区 (1为已占领)
  msg.supply_zone_rmul = (bits >> 2) & 1;  // bit 2: 己方补给区占领状态 (仅 RMUL 适用)

  // --- 能量机关状态 (Bit 3-6) ---
  // 注意：此处占 2 个 bit，掩码应为 3 (二进制 11)
  // 状态：0为未激活，1为已激活，2为正在激活
  msg.small_energy_status = (bits >> 3) & 3;  // bit 3-4: 己方小能量机关状态
  msg.big_energy_status = (bits >> 5) & 3;    // bit 5-6: 己方大能量机关状态

  // --- 高地占领状态 (Bit 7-10) ---
  // bit 7-8: 1为被己方占领，2为被对方占领
  msg.central_highland_status = (bits >> 7) & 3;
  // bit 9-10: 己方梯形高地占领状态 (1为已占领)
  msg.trapezoidal_highland_status = (bits >> 9) & 3;

  // --- 飞镖相关 (Bit 11-22) ---
  // bit 11-19: 对方飞镖最后一次击中时间 (0-420)，共 9 bit，掩码 0x1FF (511)
  msg.dart_last_hit_time = (bits >> 11) & 0x1FF;

  // bit 20-22: 对方飞镖最后一次击中目标，共 3 bit，掩码 7 (二进制 111)
  // 0:无, 1:前哨站, 2:基地固定, 3:基地随机固定, 4:基地随机移动, 5:基地末端移动
  msg.dart_last_hit_target = (bits >> 20) & 7;

  // --- 增益点状态 (Bit 23-29) ---
  // bit 23-24: 中心增益点 (仅 RMUL) - 0:未占, 1:己方, 2:对方, 3:双方
  msg.center_gain_point_status = (bits >> 23) & 3;

  // bit 25-26: 己方堡垒增益点 - 0:未占, 1:己方, 2:对方, 3:双方
  msg.fortress_gain_point_status = (bits >> 25) & 3;

  // bit 27-28: 己方前哨站增益点 - 0:未占, 1:己方, 2:对方
  msg.outpost_gain_point_status = (bits >> 27) & 3;

  // bit 29: 己方基地增益点 - 1为已占领
  msg.base_gain_point_status = (bits >> 29) & 1;

  // bit 30-31: 保留位，无需读取

  event_data_pub_->publish(msg);
}

void StandardRobotPpRos2Node::publishAllRobotHp(ReceiveAllRobotHpData & all_robot_hp)
{
  // rm_decision_interfaces::msg::AllyRobotHP msg;  // 使用新消息类型
  rm_decision_interfaces::msg::AllyRobotHP msg;

  msg.ally_1_robot_hp = all_robot_hp.data.ally_1_robot_hp;
  msg.ally_2_robot_hp = all_robot_hp.data.ally_2_robot_hp;
  msg.ally_3_robot_hp = all_robot_hp.data.ally_3_robot_hp;
  msg.ally_4_robot_hp = all_robot_hp.data.ally_4_robot_hp;
  msg.ally_7_robot_hp = all_robot_hp.data.ally_7_robot_hp;  // 重点关注
  msg.ally_outpost_hp = all_robot_hp.data.ally_outpost_hp;
  msg.ally_base_hp = all_robot_hp.data.ally_base_hp;

  all_robot_hp_pub_->publish(msg);
}

void StandardRobotPpRos2Node::publishGameStatus(ReceiveGameStatusData & game_status)
{
  rm_decision_interfaces::msg::GameStatus msg;

  // 1. 比赛类型 (Byte 0, Bit 0-3)
  // 1: RMUC 超级对抗赛, 2: RMUL 高校单项赛, 3: ICRA, 4: RMUL 3V3, 5: RMUL 步兵对抗
  msg.game_type = game_status.data.game_type;

  // 2. 当前比赛阶段 (Byte 0, Bit 4-7)
  // 0: 未开始, 1: 准备阶段, 2: 自检阶段, 3: 5s倒计时, 4: 比赛中, 5: 结算中
  msg.game_progress = game_status.data.game_progress;

  // 3. 当前阶段剩余时间 (Byte 1-2)
  // 单位：秒
  msg.stage_remain_time = game_status.data.stage_remain_time;

  // 4. UNIX 时间戳 (Byte 3-10)
  // 当机器人正确连接到裁判系统的 NTP 服务器后生效
  msg.sync_time_stamp = game_status.data.sync_time_stamp;

  game_status_pub_->publish(msg);
}

void StandardRobotPpRos2Node::publishGroundRobotPosition(
  ReceiveGroundRobotPosition & ground_robot_position)
{
  rm_decision_interfaces::msg::GroundRobotPosition msg;
  msg.hero_x = ground_robot_position.data.hero_x;
  msg.hero_y = ground_robot_position.data.hero_y;
  msg.engineer_x = ground_robot_position.data.engineer_x;
  msg.engineer_y = ground_robot_position.data.engineer_y;
  msg.standard_3_x = ground_robot_position.data.standard_3_x;
  msg.standard_3_y = ground_robot_position.data.standard_3_y;
  msg.standard_4_x = ground_robot_position.data.standard_4_x;
  msg.standard_4_y = ground_robot_position.data.standard_4_y;
  msg.standard_5_x = 0;
  msg.standard_5_y = 0;

  ground_robot_position_pub_->publish(msg);
}

void StandardRobotPpRos2Node::publishRfidStatus(ReceiveRfidStatus & rfid_status)
{
  rm_decision_interfaces::msg::RfidStatus msg;

  // 获取协议包中的数据
  // 根据图3的结构体定义：rfid_status_t 包含 uint32_t rfid_status 和 uint8_t rfid_status_2
  uint32_t status_1 = rfid_status.data.rfid_status;   // 偏移量 0, 大小 4字节
  uint8_t status_2 = rfid_status.data.rfid_status_2;  // 偏移量 4, 大小 1字节

  // --- Byte Offset 0 (uint32_t status_1) ---

  // 基础增益
  msg.friendly_base_gain_point = (status_1 >> 0) & 1;              // bit 0: 己方基地增益点
  msg.friendly_central_highland_gain_point = (status_1 >> 1) & 1;  // bit 1: 己方中央高地增益点
  msg.enemy_central_highland_gain_point = (status_1 >> 2) & 1;  // bit 2: 对方中央高地增益点
  msg.friendly_trapezoidal_gain_point = (status_1 >> 3) & 1;  // bit 3: 己方梯形高地增益点
  msg.enemy_trapezoidal_gain_point = (status_1 >> 4) & 1;     // bit 4: 对方梯形高地增益点

  // 飞坡增益 (Fly Slope)
  msg.friendly_fly_slope_pre_gain =
    (status_1 >> 5) & 1;  // bit 5: 己方地形跨越增益点（飞坡）（靠近己方一侧飞坡前）
  msg.friendly_fly_slope_post_gain =
    (status_1 >> 6) & 1;  // bit 6: 己方地形跨越增益点（飞坡）（靠近己方一侧飞坡后）
  msg.enemy_fly_slope_pre_gain =
    (status_1 >> 7) & 1;  // bit 7: 对方地形跨越增益点（飞坡）（靠近对方一侧飞坡前）
  msg.enemy_fly_slope_post_gain =
    (status_1 >> 8) & 1;  // bit 8: 对方地形跨越增益点（飞坡）（靠近对方一侧飞坡后）

  // 中央高地上下方 (Central Highland)
  msg.friendly_central_highland_under =
    (status_1 >> 9) & 1;  // bit 9: 己方地形跨越增益点（中央高地下方）
  msg.friendly_central_highland_upper =
    (status_1 >> 10) & 1;  // bit 10: 己方地形跨越增益点（中央高地上方）
  msg.enemy_central_highland_under =
    (status_1 >> 11) & 1;  // bit 11: 对方地形跨越增益点（中央高地下方）
  msg.enemy_central_highland_upper =
    (status_1 >> 12) & 1;  // bit 12: 对方地形跨越增益点（中央高地上方）

  // 公路上下方 (Highway)
  msg.friendly_highway_under = (status_1 >> 13) & 1;  // bit 13: 己方地形跨越增益点（公路下方）
  msg.friendly_highway_upper = (status_1 >> 14) & 1;  // bit 14: 己方地形跨越增益点（公路上方）
  msg.enemy_highway_under = (status_1 >> 15) & 1;  // bit 15: 对方地形跨越增益点（公路下方）
  msg.enemy_highway_upper = (status_1 >> 16) & 1;  // bit 16: 对方地形跨越增益点（公路上方）

  // 建筑与特殊区域
  msg.friendly_fortress_gain = (status_1 >> 17) & 1;  // bit 17: 己方堡垒增益点
  msg.friendly_outpost_gain = (status_1 >> 18) & 1;   // bit 18: 己方前哨站增益点
  msg.friendly_supply_zone_non_overlap =
    (status_1 >> 19) & 1;  // bit 19: 己方与资源区不重叠的补给区/RMUL 补给区
  msg.friendly_supply_zone_overlap = (status_1 >> 20) & 1;  // bit 20: 己方与资源区重叠的补给区

  // 能量机关/装配点
  msg.friendly_energy_mechanism_gain = (status_1 >> 21) & 1;  // bit 21: 己方装配增益点
  msg.enemy_energy_mechanism_gain = (status_1 >> 22) & 1;     // bit 22: 对方装配增益点

  // 其他
  msg.center_gain_point_rmul = (status_1 >> 23) & 1;  // bit 23: 中心增益点（仅 RMUL 适用）
  msg.enemy_fortress_gain = (status_1 >> 24) & 1;     // bit 24: 对方堡垒增益点
  msg.enemy_outpost_gain = (status_1 >> 25) & 1;      // bit 25: 对方前哨站增益点

  // 隧道增益 (Tunnel) - 32位整数的最后部分
  msg.friendly_tunnel_highway_under =
    (status_1 >> 26) & 1;  // bit 26: 己方地形跨越增益点（隧道）（靠近己方一侧公路区下方）
  msg.friendly_tunnel_highway_upper =
    (status_1 >> 27) & 1;  // bit 27: 己方地形跨越增益点（隧道）（靠近己方一侧公路区上方）
  msg.friendly_tunnel_trapezoid_low =
    (status_1 >> 28) & 1;  // bit 28: 己方地形跨越增益点（隧道）（靠近己方梯形高地较低处）
  msg.friendly_tunnel_trapezoid_high =
    (status_1 >> 29) & 1;  // bit 29: 己方地形跨越增益点（隧道）（靠近己方梯形高地较高处）
  msg.enemy_tunnel_highway_under =
    (status_1 >> 30) & 1;  // bit 30: 对方地形跨越增益点（隧道）（靠近对方一侧公路区下方）
  msg.enemy_tunnel_highway_upper =
    (status_1 >> 31) & 1;  // bit 31: 对方地形跨越增益点（隧道）（靠近对方一侧公路区上方）

  // --- Byte Offset 4 (uint8_t status_2) ---

  // 隧道增益 (Tunnel) - 接续的1个字节
  msg.enemy_tunnel_trapezoid_low =
    (status_2 >> 0) & 1;  // bit 0: 对方地形跨越增益点（隧道）（靠近对方梯形高地较低处）
  msg.enemy_tunnel_trapezoid_high =
    (status_2 >> 1) & 1;  // bit 1: 对方地形跨越增益点（隧道）（靠近对方梯形高地较高处）

  rfid_status_pub_->publish(msg);
}

void StandardRobotPpRos2Node::publishRobotStatus(ReceiveRobotStatus & robot_status)
{
  rm_decision_interfaces::msg::RobotStatus msg;
  msg.robot_id = 0;
  msg.current_hp = 0;
  // msg.maximum_hp = 0;
  // msg.shooter_17mm_1_barrel_heat = robot_status.data.shooter_17mm_1_barrel_heat;
  robot_status_pub_->publish(msg);
}

void StandardRobotPpRos2Node::publishSefdefined(ReceiveSefdefinedData & sefdefined)
{
  rm_decision_interfaces::msg::Sefdefined msg;
  msg.robot_id = sefdefined.data.robot_id;
  msg.robot_level = sefdefined.data.robot_level;
  msg.current_hp = sefdefined.data.current_HP;
  msg.maximum_hp = sefdefined.data.maximum_HP;
  msg.shooter_barrel_cooling_value = sefdefined.data.shooter_barrel_cooling_value;
  msg.shooter_barrel_heat_limit = sefdefined.data.shooter_barrel_heat_limit;
  msg.chassis_power_limit = sefdefined.data.chassis_power_limit;
  msg.power_management_gimbal_output = sefdefined.data.power_management_gimbal_output;
  msg.power_management_chassis_output = sefdefined.data.power_management_chassis_output;
  msg.power_management_shooter_output = sefdefined.data.power_management_shooter_output;

  sefdefined_pub_->publish(msg);
}

/********************************************************/
/* Send data                                         */
/********************************************************/
void StandardRobotPpRos2Node::sendData()
{
  SendRobotCmdData local_data_copy;
  RCLCPP_INFO(get_logger(), "Start sendData!");

  // 更新发送帧头
  send_robot_cmd_data_.frame_header.sof = SOF_SEND;
  send_robot_cmd_data_.frame_header.seq = 0;
  // DataLength = Total - Header(5) - CRC16(2)
  send_robot_cmd_data_.frame_header.data_length = sizeof(SendRobotCmdData) - 5 - 2;
  // TEST
  // send_robot_cmd_data_.speed_vector.vx = 0f;
  // send_robot_cmd_data_.speed_vector.vy = 0.002f;
  // send_robot_cmd_data_.speed_vector.wz = 0.003f;
  int retry_count = 0;

  while (rclcpp::ok()) {
    if (!is_usb_ok_) {
      RCLCPP_WARN(get_logger(), "send: usb is not ok! Retry count: %d", retry_count++);
      std::this_thread::sleep_for(std::chrono::milliseconds(USB_NOT_OK_SLEEP_TIME));
      continue;
    }

    {  // FIX. 只在拷贝数据时加锁
      std::lock_guard<std::mutex> lk(send_mutex_);
      // FIX: 自增在拷贝前完成，避免循环开始后被拷贝覆盖
      send_robot_cmd_data_.frame_header.seq++;
      local_data_copy = send_robot_cmd_data_;
    }

    try {
      // 1. 帧头 CRC8 (HeaderFrame 5 bytes)
      append_CRC8_check_sum(
        reinterpret_cast<unsigned char *>(&local_data_copy), sizeof(HeaderFrame));

      // // --- DEBUG: 打印帧头校验信息 ---
      // RCLCPP_INFO(
      //   get_logger(), "Send Header CRC8 OK! SOF:0x%02X, DataLen:%d, ID:0x%04X, CRC8:0x%02X",
      //   local_data_copy.frame_header.sof, local_data_copy.frame_header.data_length, ID_ROBOT_CMD,
      //   local_data_copy.frame_header.crc);
      // // ----------------------------

      // 2. 整包 CRC16
      append_CRC16_check_sum(
        reinterpret_cast<uint8_t *>(&local_data_copy), sizeof(SendRobotCmdData));

      std::vector<uint8_t> send_data = toVector(local_data_copy);

      // // --- DEBUG: 打印 CRC16 和 Hex 数据 ---
      // uint16_t crc16_value = (static_cast<uint16_t>(send_data[send_data.size() - 1]) << 8) |
      //                        send_data[send_data.size() - 2];

      // RCLCPP_INFO(get_logger(), "Send CRC16: 0x%04X, TotalLen: %lu", crc16_value, send_data.size());
      // printHex("SEND", ID_ROBOT_CMD, send_data);
      // // -----------------------------------

      serial_driver_->port()->send(send_data);
    } catch (const std::exception & ex) {
      RCLCPP_ERROR(get_logger(), "Error sending data: %s", ex.what());
      is_usb_ok_ = false;
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(5));
  }
}

void StandardRobotPpRos2Node::CmdVelCallback(const geometry_msgs::msg::Twist::SharedPtr msg)
{
  std::lock_guard<std::mutex> lk(send_mutex_);
  send_robot_cmd_data_.speed_vector.vx = msg->linear.x;
  send_robot_cmd_data_.speed_vector.vy = msg->linear.y;
  send_robot_cmd_data_.speed_vector.wz = msg->angular.z;
}

void StandardRobotPpRos2Node::RobotControlCallback(
  const rm_decision_interfaces::msg::RobotControl::SharedPtr msg)
{
  std::lock_guard<std::mutex> lk(send_mutex_);
  send_robot_cmd_data_.is_recovering = msg->is_recovering ? 1u : 0u;
}

void StandardRobotPpRos2Node::printHex(
  const std::string & tag, uint16_t id, const std::vector<uint8_t> & data)
{
  std::stringstream ss;
  ss << "[" << tag << "] ID:0x" << std::hex << std::uppercase << std::setw(4) << std::setfill('0')
     << (int)id << " TotalLen:" << std::dec << data.size() << " Raw: ";
  for (auto b : data) {
    ss << std::hex << std::setw(2) << std::setfill('0') << (unsigned)b << " ";
  }
  RCLCPP_INFO(get_logger(), "%s", ss.str().c_str());
}

}  // namespace standard_robot_pp_ros2

#include "rclcpp_components/register_node_macro.hpp"
RCLCPP_COMPONENTS_REGISTER_NODE(standard_robot_pp_ros2::StandardRobotPpRos2Node)