// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pb_rm_interfaces:msg/EventData.idl
// generated code does not contain a copyright notice

#ifndef PB_RM_INTERFACES__MSG__DETAIL__EVENT_DATA__STRUCT_H_
#define PB_RM_INTERFACES__MSG__DETAIL__EVENT_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/EventData in the package pb_rm_interfaces.
/**
  * EventData.msg
 */
typedef struct pb_rm_interfaces__msg__EventData
{
  /// --- 补给区状态 ---
  /// 己方与资源区不重叠的补给区
  uint8_t supply_zone_non_overlap;
  /// 己方与资源区重叠的补给区
  uint8_t supply_zone_overlap;
  /// 己方补给区占领状态 (仅 RMUL)
  uint8_t supply_zone_rmul;
  /// --- 能量机关状态 ---
  /// 己方小能量机关状态
  uint8_t small_energy_status;
  /// 己方大能量机关状态
  uint8_t big_energy_status;
  /// --- 高地占领状态 ---
  /// 环形/中央高地占领状态
  uint8_t central_highland_status;
  /// 己方梯形高地占领状态
  uint8_t trapezoidal_highland_status;
  /// --- 飞镖相关 ---
  /// 对方飞镖最后一次击中时间
  uint16_t dart_last_hit_time;
  /// 对方飞镖最后一次击中目标
  uint8_t dart_last_hit_target;
  /// --- 增益点状态 ---
  /// 中心增益点 (仅 RMUL)
  uint8_t center_gain_point_status;
  /// 己方堡垒增益点
  uint8_t fortress_gain_point_status;
  /// 己方前哨站增益点
  uint8_t outpost_gain_point_status;
  /// 己方基地增益点
  uint8_t base_gain_point_status;
} pb_rm_interfaces__msg__EventData;

// Struct for a sequence of pb_rm_interfaces__msg__EventData.
typedef struct pb_rm_interfaces__msg__EventData__Sequence
{
  pb_rm_interfaces__msg__EventData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pb_rm_interfaces__msg__EventData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PB_RM_INTERFACES__MSG__DETAIL__EVENT_DATA__STRUCT_H_
