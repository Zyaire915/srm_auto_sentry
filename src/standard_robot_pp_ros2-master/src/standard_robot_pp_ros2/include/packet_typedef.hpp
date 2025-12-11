#ifndef STANDARD_ROBOT_PP_ROS2__PACKET_TYPEDEF_HPP_
#define STANDARD_ROBOT_PP_ROS2__PACKET_TYPEDEF_HPP_

#include <cstdint>
#include <vector>
#include <iostream>
#include <algorithm>

namespace standard_robot_pp_ros2
{
// V1.0.0 协议规定 SOF 为 0xA5
const uint8_t SOF_RECEIVE = 0xA5;
const uint8_t SOF_SEND = 0xA5;

/********************************************************/
/* ID define (New Protocol 2-byte IDs)                  */
/********************************************************/
// Receive IDs
const uint16_t ID_GAME_STATUS = 0x0001;            // 比赛状态数据
const uint16_t ID_ALL_ROBOT_HP = 0x0003;           // 机器人血量数据 (文档表1-4定义0x0003为机器人血量)
const uint16_t ID_EVENT_DATA = 0x0101;             // 场地事件数据
const uint16_t ID_ROBOT_STATUS = 0x0202;           // 实时底盘缓冲能量和射击热量数据
const uint16_t ID_RFID_STATUS = 0x0209;            // 机器人RFID状态
const uint16_t ID_GROUND_ROBOT_POSITION = 0x020B;  // 地面机器人位置数据

// Send ID
// 0x0302: 自定义控制器与机器人交互数据
const uint16_t ID_ROBOT_CMD = 0x0302;

/********************************************************/
/* HeaderFrame                                           */
/********************************************************/

// 表1-2 frame_header 格式
// SOF(1) + data_length(2) + seq(1) + CRC8(1) = 5 bytes
struct HeaderFrame
{
  uint8_t sof;
  uint16_t data_length;
  uint8_t seq;
  uint8_t crc;
} __attribute__((packed));

/********************************************************/
/* Receive data Structures                              */
/********************************************************/

// 0x0001 比赛状态数据
struct ReceiveGameStatusData
{
  HeaderFrame frame_header;
  uint16_t cmd_id;

  struct
  {
    uint8_t game_type : 4;
    uint8_t game_progress : 4;
    uint16_t stage_remain_time;
    uint64_t sync_time_stamp;
  } __attribute__((packed)) data;

  uint16_t crc;
} __attribute__((packed));

// 0x0003 机器人血量数据
struct ReceiveAllRobotHpData
{
  HeaderFrame frame_header;
  uint16_t cmd_id;

  struct
  {
    uint16_t ally_1_robot_hp;
    uint16_t ally_2_robot_hp;
    uint16_t ally_3_robot_hp;
    uint16_t ally_4_robot_hp;
    uint16_t reserved;
    uint16_t ally_7_robot_hp;
    uint16_t ally_outpost_hp;
    uint16_t ally_base_hp;
  } __attribute__((packed)) data;

  uint16_t crc;
} __attribute__((packed));

// 0x0101 场地事件数据
struct ReceiveEventData
{
  HeaderFrame frame_header;
  uint16_t cmd_id;

  struct
  {
    uint32_t event_data;
  } __attribute__((packed)) data;

  uint16_t crc;
} __attribute__((packed));

// 0x0202 实时底盘缓冲能量和射击热量数据
// 替代旧的 0x0002/RobotStatus
struct ReceiveRobotStatus
{
  HeaderFrame frame_header;
  uint16_t cmd_id;

  struct
  {
    uint16_t reserved_1;
    uint16_t reserved_2;
    float reserved_3;
    uint16_t buffer_energy;
    uint16_t shooter_17mm_1_barrel_heat;
    uint16_t shooter_42mm_barrel_heat;
  } __attribute__((packed)) data;

  uint16_t crc;
} __attribute__((packed));

// 0x0209 机器人 RFID 模块状态
struct ReceiveRfidStatus
{
  HeaderFrame frame_header;
  uint16_t cmd_id;

  struct
  {
    uint32_t rfid_status;
    uint8_t rfid_status_2;
  } __attribute__((packed)) data;

  uint16_t crc;
} __attribute__((packed));

// 0x020B 地面机器人位置数据
struct ReceiveGroundRobotPosition
{
  HeaderFrame frame_header;
  uint16_t cmd_id;

  struct
  {
    float hero_x;
    float hero_y;
    float engineer_x;
    float engineer_y;
    float standard_3_x;
    float standard_3_y;
    float standard_4_x;
    float standard_4_y;
    float reserved_1;
    float reserved_2;
  } __attribute__((packed)) data;

  uint16_t crc;
} __attribute__((packed));

/********************************************************/
/* Send data                                            */
/********************************************************/

struct SendRobotCmdData
{
  HeaderFrame frame_header;

  // 自定义数据段
  struct
  {
    float vx;
    float vy;
    float wz;
  } __attribute__((packed)) speed_vector;

  uint16_t checksum;
} __attribute__((packed));

/********************************************************/
/* template                                             */
/********************************************************/

template <typename T>
inline T fromVector(const std::vector<uint8_t>& data)
{
  // 1. 初始化结构体：使用 {} 进行零初始化，防止部分拷贝导致的垃圾值
  T packet = {};

  // 或者使用 memset 强制清零（适用于纯 C 风格结构体）
  // std::memset(&packet, 0, sizeof(T));

  // 2. 计算拷贝长度：保护不越界
  size_t copy_len = std::min(data.size(), sizeof(T));

  // 3. 执行拷贝
  // 提示：如果 data.size() < sizeof(T)，这只是部分数据有效，最好加个日志警告
  if (data.size() < sizeof(T))
  {
    std::cerr << "Warning: Data size less than struct size!" << std::endl;
  }

  std::copy(data.begin(), data.begin() + copy_len, reinterpret_cast<uint8_t*>(&packet));

  return packet;
}

template <typename T>
inline std::vector<uint8_t> toVector(const T& data)
{
  std::vector<uint8_t> packet(sizeof(T));

  // 使用 const_cast 并非必须，但 reinterpret_cast<const uint8_t*> 是最准确的
  const uint8_t* ptr = reinterpret_cast<const uint8_t*>(&data);

  std::copy(ptr, ptr + sizeof(T), packet.begin());

  return packet;
}

}  // namespace standard_robot_pp_ros2

#endif  // STANDARD_ROBOT_PP_ROS2__PACKET_TYPEDEF_HPP_