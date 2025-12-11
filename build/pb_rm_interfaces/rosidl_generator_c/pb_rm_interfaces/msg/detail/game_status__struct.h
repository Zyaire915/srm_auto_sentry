// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pb_rm_interfaces:msg/GameStatus.idl
// generated code does not contain a copyright notice

#ifndef PB_RM_INTERFACES__MSG__DETAIL__GAME_STATUS__STRUCT_H_
#define PB_RM_INTERFACES__MSG__DETAIL__GAME_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/GameStatus in the package pb_rm_interfaces.
typedef struct pb_rm_interfaces__msg__GameStatus
{
  /// 新增：比赛类型
  uint8_t game_type;
  /// 现有：比赛阶段
  uint8_t game_progress;
  /// 现有：剩余时间
  uint16_t stage_remain_time;
  /// 新增：UNIX 时间戳 (注意使用 uint64)
  uint64_t sync_time_stamp;
} pb_rm_interfaces__msg__GameStatus;

// Struct for a sequence of pb_rm_interfaces__msg__GameStatus.
typedef struct pb_rm_interfaces__msg__GameStatus__Sequence
{
  pb_rm_interfaces__msg__GameStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pb_rm_interfaces__msg__GameStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PB_RM_INTERFACES__MSG__DETAIL__GAME_STATUS__STRUCT_H_
