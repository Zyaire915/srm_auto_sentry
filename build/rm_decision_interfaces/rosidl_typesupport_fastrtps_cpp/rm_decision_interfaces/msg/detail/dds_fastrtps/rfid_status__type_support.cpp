// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from rm_decision_interfaces:msg/RfidStatus.idl
// generated code does not contain a copyright notice
#include "rm_decision_interfaces/msg/detail/rfid_status__rosidl_typesupport_fastrtps_cpp.hpp"
#include "rm_decision_interfaces/msg/detail/rfid_status__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace rm_decision_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rm_decision_interfaces
cdr_serialize(
  const rm_decision_interfaces::msg::RfidStatus & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: friendly_base_gain_point
  cdr << ros_message.friendly_base_gain_point;
  // Member: friendly_central_highland_gain_point
  cdr << ros_message.friendly_central_highland_gain_point;
  // Member: enemy_central_highland_gain_point
  cdr << ros_message.enemy_central_highland_gain_point;
  // Member: friendly_trapezoidal_gain_point
  cdr << ros_message.friendly_trapezoidal_gain_point;
  // Member: enemy_trapezoidal_gain_point
  cdr << ros_message.enemy_trapezoidal_gain_point;
  // Member: friendly_fly_slope_pre_gain
  cdr << ros_message.friendly_fly_slope_pre_gain;
  // Member: friendly_fly_slope_post_gain
  cdr << ros_message.friendly_fly_slope_post_gain;
  // Member: enemy_fly_slope_pre_gain
  cdr << ros_message.enemy_fly_slope_pre_gain;
  // Member: enemy_fly_slope_post_gain
  cdr << ros_message.enemy_fly_slope_post_gain;
  // Member: friendly_central_highland_under
  cdr << ros_message.friendly_central_highland_under;
  // Member: friendly_central_highland_upper
  cdr << ros_message.friendly_central_highland_upper;
  // Member: enemy_central_highland_under
  cdr << ros_message.enemy_central_highland_under;
  // Member: enemy_central_highland_upper
  cdr << ros_message.enemy_central_highland_upper;
  // Member: friendly_highway_under
  cdr << ros_message.friendly_highway_under;
  // Member: friendly_highway_upper
  cdr << ros_message.friendly_highway_upper;
  // Member: enemy_highway_under
  cdr << ros_message.enemy_highway_under;
  // Member: enemy_highway_upper
  cdr << ros_message.enemy_highway_upper;
  // Member: friendly_fortress_gain
  cdr << ros_message.friendly_fortress_gain;
  // Member: friendly_outpost_gain
  cdr << ros_message.friendly_outpost_gain;
  // Member: friendly_supply_zone_non_overlap
  cdr << ros_message.friendly_supply_zone_non_overlap;
  // Member: friendly_supply_zone_overlap
  cdr << ros_message.friendly_supply_zone_overlap;
  // Member: friendly_energy_mechanism_gain
  cdr << ros_message.friendly_energy_mechanism_gain;
  // Member: enemy_energy_mechanism_gain
  cdr << ros_message.enemy_energy_mechanism_gain;
  // Member: center_gain_point_rmul
  cdr << ros_message.center_gain_point_rmul;
  // Member: enemy_fortress_gain
  cdr << ros_message.enemy_fortress_gain;
  // Member: enemy_outpost_gain
  cdr << ros_message.enemy_outpost_gain;
  // Member: friendly_tunnel_highway_under
  cdr << ros_message.friendly_tunnel_highway_under;
  // Member: friendly_tunnel_highway_upper
  cdr << ros_message.friendly_tunnel_highway_upper;
  // Member: friendly_tunnel_trapezoid_low
  cdr << ros_message.friendly_tunnel_trapezoid_low;
  // Member: friendly_tunnel_trapezoid_high
  cdr << ros_message.friendly_tunnel_trapezoid_high;
  // Member: enemy_tunnel_highway_under
  cdr << ros_message.enemy_tunnel_highway_under;
  // Member: enemy_tunnel_highway_upper
  cdr << ros_message.enemy_tunnel_highway_upper;
  // Member: enemy_tunnel_trapezoid_low
  cdr << ros_message.enemy_tunnel_trapezoid_low;
  // Member: enemy_tunnel_trapezoid_high
  cdr << ros_message.enemy_tunnel_trapezoid_high;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rm_decision_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rm_decision_interfaces::msg::RfidStatus & ros_message)
{
  // Member: friendly_base_gain_point
  cdr >> ros_message.friendly_base_gain_point;

  // Member: friendly_central_highland_gain_point
  cdr >> ros_message.friendly_central_highland_gain_point;

  // Member: enemy_central_highland_gain_point
  cdr >> ros_message.enemy_central_highland_gain_point;

  // Member: friendly_trapezoidal_gain_point
  cdr >> ros_message.friendly_trapezoidal_gain_point;

  // Member: enemy_trapezoidal_gain_point
  cdr >> ros_message.enemy_trapezoidal_gain_point;

  // Member: friendly_fly_slope_pre_gain
  cdr >> ros_message.friendly_fly_slope_pre_gain;

  // Member: friendly_fly_slope_post_gain
  cdr >> ros_message.friendly_fly_slope_post_gain;

  // Member: enemy_fly_slope_pre_gain
  cdr >> ros_message.enemy_fly_slope_pre_gain;

  // Member: enemy_fly_slope_post_gain
  cdr >> ros_message.enemy_fly_slope_post_gain;

  // Member: friendly_central_highland_under
  cdr >> ros_message.friendly_central_highland_under;

  // Member: friendly_central_highland_upper
  cdr >> ros_message.friendly_central_highland_upper;

  // Member: enemy_central_highland_under
  cdr >> ros_message.enemy_central_highland_under;

  // Member: enemy_central_highland_upper
  cdr >> ros_message.enemy_central_highland_upper;

  // Member: friendly_highway_under
  cdr >> ros_message.friendly_highway_under;

  // Member: friendly_highway_upper
  cdr >> ros_message.friendly_highway_upper;

  // Member: enemy_highway_under
  cdr >> ros_message.enemy_highway_under;

  // Member: enemy_highway_upper
  cdr >> ros_message.enemy_highway_upper;

  // Member: friendly_fortress_gain
  cdr >> ros_message.friendly_fortress_gain;

  // Member: friendly_outpost_gain
  cdr >> ros_message.friendly_outpost_gain;

  // Member: friendly_supply_zone_non_overlap
  cdr >> ros_message.friendly_supply_zone_non_overlap;

  // Member: friendly_supply_zone_overlap
  cdr >> ros_message.friendly_supply_zone_overlap;

  // Member: friendly_energy_mechanism_gain
  cdr >> ros_message.friendly_energy_mechanism_gain;

  // Member: enemy_energy_mechanism_gain
  cdr >> ros_message.enemy_energy_mechanism_gain;

  // Member: center_gain_point_rmul
  cdr >> ros_message.center_gain_point_rmul;

  // Member: enemy_fortress_gain
  cdr >> ros_message.enemy_fortress_gain;

  // Member: enemy_outpost_gain
  cdr >> ros_message.enemy_outpost_gain;

  // Member: friendly_tunnel_highway_under
  cdr >> ros_message.friendly_tunnel_highway_under;

  // Member: friendly_tunnel_highway_upper
  cdr >> ros_message.friendly_tunnel_highway_upper;

  // Member: friendly_tunnel_trapezoid_low
  cdr >> ros_message.friendly_tunnel_trapezoid_low;

  // Member: friendly_tunnel_trapezoid_high
  cdr >> ros_message.friendly_tunnel_trapezoid_high;

  // Member: enemy_tunnel_highway_under
  cdr >> ros_message.enemy_tunnel_highway_under;

  // Member: enemy_tunnel_highway_upper
  cdr >> ros_message.enemy_tunnel_highway_upper;

  // Member: enemy_tunnel_trapezoid_low
  cdr >> ros_message.enemy_tunnel_trapezoid_low;

  // Member: enemy_tunnel_trapezoid_high
  cdr >> ros_message.enemy_tunnel_trapezoid_high;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rm_decision_interfaces
get_serialized_size(
  const rm_decision_interfaces::msg::RfidStatus & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: friendly_base_gain_point
  {
    size_t item_size = sizeof(ros_message.friendly_base_gain_point);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: friendly_central_highland_gain_point
  {
    size_t item_size = sizeof(ros_message.friendly_central_highland_gain_point);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: enemy_central_highland_gain_point
  {
    size_t item_size = sizeof(ros_message.enemy_central_highland_gain_point);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: friendly_trapezoidal_gain_point
  {
    size_t item_size = sizeof(ros_message.friendly_trapezoidal_gain_point);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: enemy_trapezoidal_gain_point
  {
    size_t item_size = sizeof(ros_message.enemy_trapezoidal_gain_point);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: friendly_fly_slope_pre_gain
  {
    size_t item_size = sizeof(ros_message.friendly_fly_slope_pre_gain);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: friendly_fly_slope_post_gain
  {
    size_t item_size = sizeof(ros_message.friendly_fly_slope_post_gain);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: enemy_fly_slope_pre_gain
  {
    size_t item_size = sizeof(ros_message.enemy_fly_slope_pre_gain);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: enemy_fly_slope_post_gain
  {
    size_t item_size = sizeof(ros_message.enemy_fly_slope_post_gain);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: friendly_central_highland_under
  {
    size_t item_size = sizeof(ros_message.friendly_central_highland_under);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: friendly_central_highland_upper
  {
    size_t item_size = sizeof(ros_message.friendly_central_highland_upper);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: enemy_central_highland_under
  {
    size_t item_size = sizeof(ros_message.enemy_central_highland_under);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: enemy_central_highland_upper
  {
    size_t item_size = sizeof(ros_message.enemy_central_highland_upper);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: friendly_highway_under
  {
    size_t item_size = sizeof(ros_message.friendly_highway_under);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: friendly_highway_upper
  {
    size_t item_size = sizeof(ros_message.friendly_highway_upper);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: enemy_highway_under
  {
    size_t item_size = sizeof(ros_message.enemy_highway_under);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: enemy_highway_upper
  {
    size_t item_size = sizeof(ros_message.enemy_highway_upper);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: friendly_fortress_gain
  {
    size_t item_size = sizeof(ros_message.friendly_fortress_gain);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: friendly_outpost_gain
  {
    size_t item_size = sizeof(ros_message.friendly_outpost_gain);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: friendly_supply_zone_non_overlap
  {
    size_t item_size = sizeof(ros_message.friendly_supply_zone_non_overlap);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: friendly_supply_zone_overlap
  {
    size_t item_size = sizeof(ros_message.friendly_supply_zone_overlap);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: friendly_energy_mechanism_gain
  {
    size_t item_size = sizeof(ros_message.friendly_energy_mechanism_gain);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: enemy_energy_mechanism_gain
  {
    size_t item_size = sizeof(ros_message.enemy_energy_mechanism_gain);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: center_gain_point_rmul
  {
    size_t item_size = sizeof(ros_message.center_gain_point_rmul);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: enemy_fortress_gain
  {
    size_t item_size = sizeof(ros_message.enemy_fortress_gain);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: enemy_outpost_gain
  {
    size_t item_size = sizeof(ros_message.enemy_outpost_gain);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: friendly_tunnel_highway_under
  {
    size_t item_size = sizeof(ros_message.friendly_tunnel_highway_under);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: friendly_tunnel_highway_upper
  {
    size_t item_size = sizeof(ros_message.friendly_tunnel_highway_upper);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: friendly_tunnel_trapezoid_low
  {
    size_t item_size = sizeof(ros_message.friendly_tunnel_trapezoid_low);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: friendly_tunnel_trapezoid_high
  {
    size_t item_size = sizeof(ros_message.friendly_tunnel_trapezoid_high);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: enemy_tunnel_highway_under
  {
    size_t item_size = sizeof(ros_message.enemy_tunnel_highway_under);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: enemy_tunnel_highway_upper
  {
    size_t item_size = sizeof(ros_message.enemy_tunnel_highway_upper);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: enemy_tunnel_trapezoid_low
  {
    size_t item_size = sizeof(ros_message.enemy_tunnel_trapezoid_low);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: enemy_tunnel_trapezoid_high
  {
    size_t item_size = sizeof(ros_message.enemy_tunnel_trapezoid_high);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rm_decision_interfaces
max_serialized_size_RfidStatus(
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


  // Member: friendly_base_gain_point
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: friendly_central_highland_gain_point
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: enemy_central_highland_gain_point
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: friendly_trapezoidal_gain_point
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: enemy_trapezoidal_gain_point
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: friendly_fly_slope_pre_gain
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: friendly_fly_slope_post_gain
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: enemy_fly_slope_pre_gain
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: enemy_fly_slope_post_gain
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: friendly_central_highland_under
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: friendly_central_highland_upper
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: enemy_central_highland_under
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: enemy_central_highland_upper
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: friendly_highway_under
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: friendly_highway_upper
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: enemy_highway_under
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: enemy_highway_upper
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: friendly_fortress_gain
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: friendly_outpost_gain
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: friendly_supply_zone_non_overlap
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: friendly_supply_zone_overlap
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: friendly_energy_mechanism_gain
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: enemy_energy_mechanism_gain
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: center_gain_point_rmul
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: enemy_fortress_gain
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: enemy_outpost_gain
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: friendly_tunnel_highway_under
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: friendly_tunnel_highway_upper
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: friendly_tunnel_trapezoid_low
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: friendly_tunnel_trapezoid_high
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: enemy_tunnel_highway_under
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: enemy_tunnel_highway_upper
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: enemy_tunnel_trapezoid_low
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: enemy_tunnel_trapezoid_high
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
    using DataType = rm_decision_interfaces::msg::RfidStatus;
    is_plain =
      (
      offsetof(DataType, enemy_tunnel_trapezoid_high) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _RfidStatus__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const rm_decision_interfaces::msg::RfidStatus *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _RfidStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<rm_decision_interfaces::msg::RfidStatus *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _RfidStatus__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const rm_decision_interfaces::msg::RfidStatus *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _RfidStatus__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_RfidStatus(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _RfidStatus__callbacks = {
  "rm_decision_interfaces::msg",
  "RfidStatus",
  _RfidStatus__cdr_serialize,
  _RfidStatus__cdr_deserialize,
  _RfidStatus__get_serialized_size,
  _RfidStatus__max_serialized_size
};

static rosidl_message_type_support_t _RfidStatus__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_RfidStatus__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace rm_decision_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_rm_decision_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<rm_decision_interfaces::msg::RfidStatus>()
{
  return &rm_decision_interfaces::msg::typesupport_fastrtps_cpp::_RfidStatus__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rm_decision_interfaces, msg, RfidStatus)() {
  return &rm_decision_interfaces::msg::typesupport_fastrtps_cpp::_RfidStatus__handle;
}

#ifdef __cplusplus
}
#endif
