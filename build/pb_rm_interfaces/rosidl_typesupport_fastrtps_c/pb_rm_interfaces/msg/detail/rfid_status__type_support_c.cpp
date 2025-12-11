// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from pb_rm_interfaces:msg/RfidStatus.idl
// generated code does not contain a copyright notice
#include "pb_rm_interfaces/msg/detail/rfid_status__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "pb_rm_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "pb_rm_interfaces/msg/detail/rfid_status__struct.h"
#include "pb_rm_interfaces/msg/detail/rfid_status__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _RfidStatus__ros_msg_type = pb_rm_interfaces__msg__RfidStatus;

static bool _RfidStatus__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _RfidStatus__ros_msg_type * ros_message = static_cast<const _RfidStatus__ros_msg_type *>(untyped_ros_message);
  // Field name: friendly_base_gain_point
  {
    cdr << ros_message->friendly_base_gain_point;
  }

  // Field name: friendly_central_highland_gain_point
  {
    cdr << ros_message->friendly_central_highland_gain_point;
  }

  // Field name: enemy_central_highland_gain_point
  {
    cdr << ros_message->enemy_central_highland_gain_point;
  }

  // Field name: friendly_trapezoidal_gain_point
  {
    cdr << ros_message->friendly_trapezoidal_gain_point;
  }

  // Field name: enemy_trapezoidal_gain_point
  {
    cdr << ros_message->enemy_trapezoidal_gain_point;
  }

  // Field name: friendly_fly_slope_pre_gain
  {
    cdr << ros_message->friendly_fly_slope_pre_gain;
  }

  // Field name: friendly_fly_slope_post_gain
  {
    cdr << ros_message->friendly_fly_slope_post_gain;
  }

  // Field name: enemy_fly_slope_pre_gain
  {
    cdr << ros_message->enemy_fly_slope_pre_gain;
  }

  // Field name: enemy_fly_slope_post_gain
  {
    cdr << ros_message->enemy_fly_slope_post_gain;
  }

  // Field name: friendly_central_highland_under
  {
    cdr << ros_message->friendly_central_highland_under;
  }

  // Field name: friendly_central_highland_upper
  {
    cdr << ros_message->friendly_central_highland_upper;
  }

  // Field name: enemy_central_highland_under
  {
    cdr << ros_message->enemy_central_highland_under;
  }

  // Field name: enemy_central_highland_upper
  {
    cdr << ros_message->enemy_central_highland_upper;
  }

  // Field name: friendly_highway_under
  {
    cdr << ros_message->friendly_highway_under;
  }

  // Field name: friendly_highway_upper
  {
    cdr << ros_message->friendly_highway_upper;
  }

  // Field name: enemy_highway_under
  {
    cdr << ros_message->enemy_highway_under;
  }

  // Field name: enemy_highway_upper
  {
    cdr << ros_message->enemy_highway_upper;
  }

  // Field name: friendly_fortress_gain
  {
    cdr << ros_message->friendly_fortress_gain;
  }

  // Field name: friendly_outpost_gain
  {
    cdr << ros_message->friendly_outpost_gain;
  }

  // Field name: friendly_supply_zone_non_overlap
  {
    cdr << ros_message->friendly_supply_zone_non_overlap;
  }

  // Field name: friendly_supply_zone_overlap
  {
    cdr << ros_message->friendly_supply_zone_overlap;
  }

  // Field name: friendly_energy_mechanism_gain
  {
    cdr << ros_message->friendly_energy_mechanism_gain;
  }

  // Field name: enemy_energy_mechanism_gain
  {
    cdr << ros_message->enemy_energy_mechanism_gain;
  }

  // Field name: center_gain_point_rmul
  {
    cdr << ros_message->center_gain_point_rmul;
  }

  // Field name: enemy_fortress_gain
  {
    cdr << ros_message->enemy_fortress_gain;
  }

  // Field name: enemy_outpost_gain
  {
    cdr << ros_message->enemy_outpost_gain;
  }

  // Field name: friendly_tunnel_highway_under
  {
    cdr << ros_message->friendly_tunnel_highway_under;
  }

  // Field name: friendly_tunnel_highway_upper
  {
    cdr << ros_message->friendly_tunnel_highway_upper;
  }

  // Field name: friendly_tunnel_trapezoid_low
  {
    cdr << ros_message->friendly_tunnel_trapezoid_low;
  }

  // Field name: friendly_tunnel_trapezoid_high
  {
    cdr << ros_message->friendly_tunnel_trapezoid_high;
  }

  // Field name: enemy_tunnel_highway_under
  {
    cdr << ros_message->enemy_tunnel_highway_under;
  }

  // Field name: enemy_tunnel_highway_upper
  {
    cdr << ros_message->enemy_tunnel_highway_upper;
  }

  // Field name: enemy_tunnel_trapezoid_low
  {
    cdr << ros_message->enemy_tunnel_trapezoid_low;
  }

  // Field name: enemy_tunnel_trapezoid_high
  {
    cdr << ros_message->enemy_tunnel_trapezoid_high;
  }

  return true;
}

static bool _RfidStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _RfidStatus__ros_msg_type * ros_message = static_cast<_RfidStatus__ros_msg_type *>(untyped_ros_message);
  // Field name: friendly_base_gain_point
  {
    cdr >> ros_message->friendly_base_gain_point;
  }

  // Field name: friendly_central_highland_gain_point
  {
    cdr >> ros_message->friendly_central_highland_gain_point;
  }

  // Field name: enemy_central_highland_gain_point
  {
    cdr >> ros_message->enemy_central_highland_gain_point;
  }

  // Field name: friendly_trapezoidal_gain_point
  {
    cdr >> ros_message->friendly_trapezoidal_gain_point;
  }

  // Field name: enemy_trapezoidal_gain_point
  {
    cdr >> ros_message->enemy_trapezoidal_gain_point;
  }

  // Field name: friendly_fly_slope_pre_gain
  {
    cdr >> ros_message->friendly_fly_slope_pre_gain;
  }

  // Field name: friendly_fly_slope_post_gain
  {
    cdr >> ros_message->friendly_fly_slope_post_gain;
  }

  // Field name: enemy_fly_slope_pre_gain
  {
    cdr >> ros_message->enemy_fly_slope_pre_gain;
  }

  // Field name: enemy_fly_slope_post_gain
  {
    cdr >> ros_message->enemy_fly_slope_post_gain;
  }

  // Field name: friendly_central_highland_under
  {
    cdr >> ros_message->friendly_central_highland_under;
  }

  // Field name: friendly_central_highland_upper
  {
    cdr >> ros_message->friendly_central_highland_upper;
  }

  // Field name: enemy_central_highland_under
  {
    cdr >> ros_message->enemy_central_highland_under;
  }

  // Field name: enemy_central_highland_upper
  {
    cdr >> ros_message->enemy_central_highland_upper;
  }

  // Field name: friendly_highway_under
  {
    cdr >> ros_message->friendly_highway_under;
  }

  // Field name: friendly_highway_upper
  {
    cdr >> ros_message->friendly_highway_upper;
  }

  // Field name: enemy_highway_under
  {
    cdr >> ros_message->enemy_highway_under;
  }

  // Field name: enemy_highway_upper
  {
    cdr >> ros_message->enemy_highway_upper;
  }

  // Field name: friendly_fortress_gain
  {
    cdr >> ros_message->friendly_fortress_gain;
  }

  // Field name: friendly_outpost_gain
  {
    cdr >> ros_message->friendly_outpost_gain;
  }

  // Field name: friendly_supply_zone_non_overlap
  {
    cdr >> ros_message->friendly_supply_zone_non_overlap;
  }

  // Field name: friendly_supply_zone_overlap
  {
    cdr >> ros_message->friendly_supply_zone_overlap;
  }

  // Field name: friendly_energy_mechanism_gain
  {
    cdr >> ros_message->friendly_energy_mechanism_gain;
  }

  // Field name: enemy_energy_mechanism_gain
  {
    cdr >> ros_message->enemy_energy_mechanism_gain;
  }

  // Field name: center_gain_point_rmul
  {
    cdr >> ros_message->center_gain_point_rmul;
  }

  // Field name: enemy_fortress_gain
  {
    cdr >> ros_message->enemy_fortress_gain;
  }

  // Field name: enemy_outpost_gain
  {
    cdr >> ros_message->enemy_outpost_gain;
  }

  // Field name: friendly_tunnel_highway_under
  {
    cdr >> ros_message->friendly_tunnel_highway_under;
  }

  // Field name: friendly_tunnel_highway_upper
  {
    cdr >> ros_message->friendly_tunnel_highway_upper;
  }

  // Field name: friendly_tunnel_trapezoid_low
  {
    cdr >> ros_message->friendly_tunnel_trapezoid_low;
  }

  // Field name: friendly_tunnel_trapezoid_high
  {
    cdr >> ros_message->friendly_tunnel_trapezoid_high;
  }

  // Field name: enemy_tunnel_highway_under
  {
    cdr >> ros_message->enemy_tunnel_highway_under;
  }

  // Field name: enemy_tunnel_highway_upper
  {
    cdr >> ros_message->enemy_tunnel_highway_upper;
  }

  // Field name: enemy_tunnel_trapezoid_low
  {
    cdr >> ros_message->enemy_tunnel_trapezoid_low;
  }

  // Field name: enemy_tunnel_trapezoid_high
  {
    cdr >> ros_message->enemy_tunnel_trapezoid_high;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pb_rm_interfaces
size_t get_serialized_size_pb_rm_interfaces__msg__RfidStatus(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _RfidStatus__ros_msg_type * ros_message = static_cast<const _RfidStatus__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name friendly_base_gain_point
  {
    size_t item_size = sizeof(ros_message->friendly_base_gain_point);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name friendly_central_highland_gain_point
  {
    size_t item_size = sizeof(ros_message->friendly_central_highland_gain_point);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name enemy_central_highland_gain_point
  {
    size_t item_size = sizeof(ros_message->enemy_central_highland_gain_point);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name friendly_trapezoidal_gain_point
  {
    size_t item_size = sizeof(ros_message->friendly_trapezoidal_gain_point);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name enemy_trapezoidal_gain_point
  {
    size_t item_size = sizeof(ros_message->enemy_trapezoidal_gain_point);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name friendly_fly_slope_pre_gain
  {
    size_t item_size = sizeof(ros_message->friendly_fly_slope_pre_gain);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name friendly_fly_slope_post_gain
  {
    size_t item_size = sizeof(ros_message->friendly_fly_slope_post_gain);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name enemy_fly_slope_pre_gain
  {
    size_t item_size = sizeof(ros_message->enemy_fly_slope_pre_gain);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name enemy_fly_slope_post_gain
  {
    size_t item_size = sizeof(ros_message->enemy_fly_slope_post_gain);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name friendly_central_highland_under
  {
    size_t item_size = sizeof(ros_message->friendly_central_highland_under);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name friendly_central_highland_upper
  {
    size_t item_size = sizeof(ros_message->friendly_central_highland_upper);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name enemy_central_highland_under
  {
    size_t item_size = sizeof(ros_message->enemy_central_highland_under);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name enemy_central_highland_upper
  {
    size_t item_size = sizeof(ros_message->enemy_central_highland_upper);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name friendly_highway_under
  {
    size_t item_size = sizeof(ros_message->friendly_highway_under);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name friendly_highway_upper
  {
    size_t item_size = sizeof(ros_message->friendly_highway_upper);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name enemy_highway_under
  {
    size_t item_size = sizeof(ros_message->enemy_highway_under);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name enemy_highway_upper
  {
    size_t item_size = sizeof(ros_message->enemy_highway_upper);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name friendly_fortress_gain
  {
    size_t item_size = sizeof(ros_message->friendly_fortress_gain);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name friendly_outpost_gain
  {
    size_t item_size = sizeof(ros_message->friendly_outpost_gain);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name friendly_supply_zone_non_overlap
  {
    size_t item_size = sizeof(ros_message->friendly_supply_zone_non_overlap);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name friendly_supply_zone_overlap
  {
    size_t item_size = sizeof(ros_message->friendly_supply_zone_overlap);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name friendly_energy_mechanism_gain
  {
    size_t item_size = sizeof(ros_message->friendly_energy_mechanism_gain);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name enemy_energy_mechanism_gain
  {
    size_t item_size = sizeof(ros_message->enemy_energy_mechanism_gain);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name center_gain_point_rmul
  {
    size_t item_size = sizeof(ros_message->center_gain_point_rmul);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name enemy_fortress_gain
  {
    size_t item_size = sizeof(ros_message->enemy_fortress_gain);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name enemy_outpost_gain
  {
    size_t item_size = sizeof(ros_message->enemy_outpost_gain);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name friendly_tunnel_highway_under
  {
    size_t item_size = sizeof(ros_message->friendly_tunnel_highway_under);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name friendly_tunnel_highway_upper
  {
    size_t item_size = sizeof(ros_message->friendly_tunnel_highway_upper);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name friendly_tunnel_trapezoid_low
  {
    size_t item_size = sizeof(ros_message->friendly_tunnel_trapezoid_low);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name friendly_tunnel_trapezoid_high
  {
    size_t item_size = sizeof(ros_message->friendly_tunnel_trapezoid_high);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name enemy_tunnel_highway_under
  {
    size_t item_size = sizeof(ros_message->enemy_tunnel_highway_under);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name enemy_tunnel_highway_upper
  {
    size_t item_size = sizeof(ros_message->enemy_tunnel_highway_upper);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name enemy_tunnel_trapezoid_low
  {
    size_t item_size = sizeof(ros_message->enemy_tunnel_trapezoid_low);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name enemy_tunnel_trapezoid_high
  {
    size_t item_size = sizeof(ros_message->enemy_tunnel_trapezoid_high);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _RfidStatus__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_pb_rm_interfaces__msg__RfidStatus(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pb_rm_interfaces
size_t max_serialized_size_pb_rm_interfaces__msg__RfidStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: friendly_base_gain_point
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: friendly_central_highland_gain_point
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: enemy_central_highland_gain_point
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: friendly_trapezoidal_gain_point
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: enemy_trapezoidal_gain_point
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: friendly_fly_slope_pre_gain
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: friendly_fly_slope_post_gain
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: enemy_fly_slope_pre_gain
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: enemy_fly_slope_post_gain
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: friendly_central_highland_under
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: friendly_central_highland_upper
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: enemy_central_highland_under
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: enemy_central_highland_upper
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: friendly_highway_under
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: friendly_highway_upper
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: enemy_highway_under
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: enemy_highway_upper
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: friendly_fortress_gain
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: friendly_outpost_gain
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: friendly_supply_zone_non_overlap
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: friendly_supply_zone_overlap
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: friendly_energy_mechanism_gain
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: enemy_energy_mechanism_gain
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: center_gain_point_rmul
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: enemy_fortress_gain
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: enemy_outpost_gain
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: friendly_tunnel_highway_under
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: friendly_tunnel_highway_upper
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: friendly_tunnel_trapezoid_low
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: friendly_tunnel_trapezoid_high
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: enemy_tunnel_highway_under
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: enemy_tunnel_highway_upper
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: enemy_tunnel_trapezoid_low
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: enemy_tunnel_trapezoid_high
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = pb_rm_interfaces__msg__RfidStatus;
    is_plain =
      (
      offsetof(DataType, enemy_tunnel_trapezoid_high) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _RfidStatus__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_pb_rm_interfaces__msg__RfidStatus(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_RfidStatus = {
  "pb_rm_interfaces::msg",
  "RfidStatus",
  _RfidStatus__cdr_serialize,
  _RfidStatus__cdr_deserialize,
  _RfidStatus__get_serialized_size,
  _RfidStatus__max_serialized_size
};

static rosidl_message_type_support_t _RfidStatus__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_RfidStatus,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, pb_rm_interfaces, msg, RfidStatus)() {
  return &_RfidStatus__type_support;
}

#if defined(__cplusplus)
}
#endif
