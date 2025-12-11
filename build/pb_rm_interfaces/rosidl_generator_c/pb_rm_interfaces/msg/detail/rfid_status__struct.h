// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pb_rm_interfaces:msg/RfidStatus.idl
// generated code does not contain a copyright notice

#ifndef PB_RM_INTERFACES__MSG__DETAIL__RFID_STATUS__STRUCT_H_
#define PB_RM_INTERFACES__MSG__DETAIL__RFID_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/RfidStatus in the package pb_rm_interfaces.
/**
  * RfidStatus.msg
  * 0: 未感应, 1: 已感应
 */
typedef struct pb_rm_interfaces__msg__RfidStatus
{
  /// --- 基础增益 ---
  uint8_t friendly_base_gain_point;
  uint8_t friendly_central_highland_gain_point;
  uint8_t enemy_central_highland_gain_point;
  uint8_t friendly_trapezoidal_gain_point;
  uint8_t enemy_trapezoidal_gain_point;
  /// --- 飞坡增益 (Fly Slope) ---
  uint8_t friendly_fly_slope_pre_gain;
  uint8_t friendly_fly_slope_post_gain;
  uint8_t enemy_fly_slope_pre_gain;
  uint8_t enemy_fly_slope_post_gain;
  /// --- 中央高地上下方 ---
  uint8_t friendly_central_highland_under;
  uint8_t friendly_central_highland_upper;
  uint8_t enemy_central_highland_under;
  uint8_t enemy_central_highland_upper;
  /// --- 公路上下方 (Highway) ---
  uint8_t friendly_highway_under;
  uint8_t friendly_highway_upper;
  uint8_t enemy_highway_under;
  uint8_t enemy_highway_upper;
  /// --- 建筑与特殊区域 ---
  uint8_t friendly_fortress_gain;
  uint8_t friendly_outpost_gain;
  uint8_t friendly_supply_zone_non_overlap;
  uint8_t friendly_supply_zone_overlap;
  /// --- 能量机关/装配点 ---
  uint8_t friendly_energy_mechanism_gain;
  uint8_t enemy_energy_mechanism_gain;
  /// --- 其他 ---
  uint8_t center_gain_point_rmul;
  uint8_t enemy_fortress_gain;
  uint8_t enemy_outpost_gain;
  /// --- 隧道增益 (Tunnel) ---
  uint8_t friendly_tunnel_highway_under;
  uint8_t friendly_tunnel_highway_upper;
  uint8_t friendly_tunnel_trapezoid_low;
  uint8_t friendly_tunnel_trapezoid_high;
  uint8_t enemy_tunnel_highway_under;
  uint8_t enemy_tunnel_highway_upper;
  uint8_t enemy_tunnel_trapezoid_low;
  uint8_t enemy_tunnel_trapezoid_high;
} pb_rm_interfaces__msg__RfidStatus;

// Struct for a sequence of pb_rm_interfaces__msg__RfidStatus.
typedef struct pb_rm_interfaces__msg__RfidStatus__Sequence
{
  pb_rm_interfaces__msg__RfidStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pb_rm_interfaces__msg__RfidStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PB_RM_INTERFACES__MSG__DETAIL__RFID_STATUS__STRUCT_H_
