// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from pb_rm_interfaces:msg/AllyRobotHP.idl
// generated code does not contain a copyright notice
#include "pb_rm_interfaces/msg/detail/ally_robot_hp__rosidl_typesupport_fastrtps_cpp.hpp"
#include "pb_rm_interfaces/msg/detail/ally_robot_hp__struct.hpp"

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

namespace pb_rm_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pb_rm_interfaces
cdr_serialize(
  const pb_rm_interfaces::msg::AllyRobotHP & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: ally_1_robot_hp
  cdr << ros_message.ally_1_robot_hp;
  // Member: ally_2_robot_hp
  cdr << ros_message.ally_2_robot_hp;
  // Member: ally_3_robot_hp
  cdr << ros_message.ally_3_robot_hp;
  // Member: ally_4_robot_hp
  cdr << ros_message.ally_4_robot_hp;
  // Member: ally_7_robot_hp
  cdr << ros_message.ally_7_robot_hp;
  // Member: ally_outpost_hp
  cdr << ros_message.ally_outpost_hp;
  // Member: ally_base_hp
  cdr << ros_message.ally_base_hp;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pb_rm_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  pb_rm_interfaces::msg::AllyRobotHP & ros_message)
{
  // Member: ally_1_robot_hp
  cdr >> ros_message.ally_1_robot_hp;

  // Member: ally_2_robot_hp
  cdr >> ros_message.ally_2_robot_hp;

  // Member: ally_3_robot_hp
  cdr >> ros_message.ally_3_robot_hp;

  // Member: ally_4_robot_hp
  cdr >> ros_message.ally_4_robot_hp;

  // Member: ally_7_robot_hp
  cdr >> ros_message.ally_7_robot_hp;

  // Member: ally_outpost_hp
  cdr >> ros_message.ally_outpost_hp;

  // Member: ally_base_hp
  cdr >> ros_message.ally_base_hp;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pb_rm_interfaces
get_serialized_size(
  const pb_rm_interfaces::msg::AllyRobotHP & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: ally_1_robot_hp
  {
    size_t item_size = sizeof(ros_message.ally_1_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ally_2_robot_hp
  {
    size_t item_size = sizeof(ros_message.ally_2_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ally_3_robot_hp
  {
    size_t item_size = sizeof(ros_message.ally_3_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ally_4_robot_hp
  {
    size_t item_size = sizeof(ros_message.ally_4_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ally_7_robot_hp
  {
    size_t item_size = sizeof(ros_message.ally_7_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ally_outpost_hp
  {
    size_t item_size = sizeof(ros_message.ally_outpost_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ally_base_hp
  {
    size_t item_size = sizeof(ros_message.ally_base_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pb_rm_interfaces
max_serialized_size_AllyRobotHP(
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


  // Member: ally_1_robot_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: ally_2_robot_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: ally_3_robot_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: ally_4_robot_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: ally_7_robot_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: ally_outpost_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: ally_base_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = pb_rm_interfaces::msg::AllyRobotHP;
    is_plain =
      (
      offsetof(DataType, ally_base_hp) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _AllyRobotHP__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const pb_rm_interfaces::msg::AllyRobotHP *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _AllyRobotHP__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<pb_rm_interfaces::msg::AllyRobotHP *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _AllyRobotHP__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const pb_rm_interfaces::msg::AllyRobotHP *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _AllyRobotHP__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_AllyRobotHP(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _AllyRobotHP__callbacks = {
  "pb_rm_interfaces::msg",
  "AllyRobotHP",
  _AllyRobotHP__cdr_serialize,
  _AllyRobotHP__cdr_deserialize,
  _AllyRobotHP__get_serialized_size,
  _AllyRobotHP__max_serialized_size
};

static rosidl_message_type_support_t _AllyRobotHP__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_AllyRobotHP__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace pb_rm_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_pb_rm_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<pb_rm_interfaces::msg::AllyRobotHP>()
{
  return &pb_rm_interfaces::msg::typesupport_fastrtps_cpp::_AllyRobotHP__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, pb_rm_interfaces, msg, AllyRobotHP)() {
  return &pb_rm_interfaces::msg::typesupport_fastrtps_cpp::_AllyRobotHP__handle;
}

#ifdef __cplusplus
}
#endif
