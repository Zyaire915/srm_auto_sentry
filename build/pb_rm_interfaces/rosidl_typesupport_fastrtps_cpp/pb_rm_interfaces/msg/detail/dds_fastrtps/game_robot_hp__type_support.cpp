// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from pb_rm_interfaces:msg/GameRobotHP.idl
// generated code does not contain a copyright notice
#include "pb_rm_interfaces/msg/detail/game_robot_hp__rosidl_typesupport_fastrtps_cpp.hpp"
#include "pb_rm_interfaces/msg/detail/game_robot_hp__struct.hpp"

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
  const pb_rm_interfaces::msg::GameRobotHP & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: red_1_robot_hp
  cdr << ros_message.red_1_robot_hp;
  // Member: red_2_robot_hp
  cdr << ros_message.red_2_robot_hp;
  // Member: red_3_robot_hp
  cdr << ros_message.red_3_robot_hp;
  // Member: red_4_robot_hp
  cdr << ros_message.red_4_robot_hp;
  // Member: red_5_robot_hp
  cdr << ros_message.red_5_robot_hp;
  // Member: red_7_robot_hp
  cdr << ros_message.red_7_robot_hp;
  // Member: red_outpost_hp
  cdr << ros_message.red_outpost_hp;
  // Member: red_base_hp
  cdr << ros_message.red_base_hp;
  // Member: blue_1_robot_hp
  cdr << ros_message.blue_1_robot_hp;
  // Member: blue_2_robot_hp
  cdr << ros_message.blue_2_robot_hp;
  // Member: blue_3_robot_hp
  cdr << ros_message.blue_3_robot_hp;
  // Member: blue_4_robot_hp
  cdr << ros_message.blue_4_robot_hp;
  // Member: blue_5_robot_hp
  cdr << ros_message.blue_5_robot_hp;
  // Member: blue_7_robot_hp
  cdr << ros_message.blue_7_robot_hp;
  // Member: blue_outpost_hp
  cdr << ros_message.blue_outpost_hp;
  // Member: blue_base_hp
  cdr << ros_message.blue_base_hp;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pb_rm_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  pb_rm_interfaces::msg::GameRobotHP & ros_message)
{
  // Member: red_1_robot_hp
  cdr >> ros_message.red_1_robot_hp;

  // Member: red_2_robot_hp
  cdr >> ros_message.red_2_robot_hp;

  // Member: red_3_robot_hp
  cdr >> ros_message.red_3_robot_hp;

  // Member: red_4_robot_hp
  cdr >> ros_message.red_4_robot_hp;

  // Member: red_5_robot_hp
  cdr >> ros_message.red_5_robot_hp;

  // Member: red_7_robot_hp
  cdr >> ros_message.red_7_robot_hp;

  // Member: red_outpost_hp
  cdr >> ros_message.red_outpost_hp;

  // Member: red_base_hp
  cdr >> ros_message.red_base_hp;

  // Member: blue_1_robot_hp
  cdr >> ros_message.blue_1_robot_hp;

  // Member: blue_2_robot_hp
  cdr >> ros_message.blue_2_robot_hp;

  // Member: blue_3_robot_hp
  cdr >> ros_message.blue_3_robot_hp;

  // Member: blue_4_robot_hp
  cdr >> ros_message.blue_4_robot_hp;

  // Member: blue_5_robot_hp
  cdr >> ros_message.blue_5_robot_hp;

  // Member: blue_7_robot_hp
  cdr >> ros_message.blue_7_robot_hp;

  // Member: blue_outpost_hp
  cdr >> ros_message.blue_outpost_hp;

  // Member: blue_base_hp
  cdr >> ros_message.blue_base_hp;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pb_rm_interfaces
get_serialized_size(
  const pb_rm_interfaces::msg::GameRobotHP & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: red_1_robot_hp
  {
    size_t item_size = sizeof(ros_message.red_1_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: red_2_robot_hp
  {
    size_t item_size = sizeof(ros_message.red_2_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: red_3_robot_hp
  {
    size_t item_size = sizeof(ros_message.red_3_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: red_4_robot_hp
  {
    size_t item_size = sizeof(ros_message.red_4_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: red_5_robot_hp
  {
    size_t item_size = sizeof(ros_message.red_5_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: red_7_robot_hp
  {
    size_t item_size = sizeof(ros_message.red_7_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: red_outpost_hp
  {
    size_t item_size = sizeof(ros_message.red_outpost_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: red_base_hp
  {
    size_t item_size = sizeof(ros_message.red_base_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: blue_1_robot_hp
  {
    size_t item_size = sizeof(ros_message.blue_1_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: blue_2_robot_hp
  {
    size_t item_size = sizeof(ros_message.blue_2_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: blue_3_robot_hp
  {
    size_t item_size = sizeof(ros_message.blue_3_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: blue_4_robot_hp
  {
    size_t item_size = sizeof(ros_message.blue_4_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: blue_5_robot_hp
  {
    size_t item_size = sizeof(ros_message.blue_5_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: blue_7_robot_hp
  {
    size_t item_size = sizeof(ros_message.blue_7_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: blue_outpost_hp
  {
    size_t item_size = sizeof(ros_message.blue_outpost_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: blue_base_hp
  {
    size_t item_size = sizeof(ros_message.blue_base_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pb_rm_interfaces
max_serialized_size_GameRobotHP(
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


  // Member: red_1_robot_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: red_2_robot_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: red_3_robot_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: red_4_robot_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: red_5_robot_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: red_7_robot_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: red_outpost_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: red_base_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: blue_1_robot_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: blue_2_robot_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: blue_3_robot_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: blue_4_robot_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: blue_5_robot_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: blue_7_robot_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: blue_outpost_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: blue_base_hp
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
    using DataType = pb_rm_interfaces::msg::GameRobotHP;
    is_plain =
      (
      offsetof(DataType, blue_base_hp) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _GameRobotHP__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const pb_rm_interfaces::msg::GameRobotHP *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _GameRobotHP__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<pb_rm_interfaces::msg::GameRobotHP *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _GameRobotHP__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const pb_rm_interfaces::msg::GameRobotHP *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _GameRobotHP__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_GameRobotHP(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _GameRobotHP__callbacks = {
  "pb_rm_interfaces::msg",
  "GameRobotHP",
  _GameRobotHP__cdr_serialize,
  _GameRobotHP__cdr_deserialize,
  _GameRobotHP__get_serialized_size,
  _GameRobotHP__max_serialized_size
};

static rosidl_message_type_support_t _GameRobotHP__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_GameRobotHP__callbacks,
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
get_message_type_support_handle<pb_rm_interfaces::msg::GameRobotHP>()
{
  return &pb_rm_interfaces::msg::typesupport_fastrtps_cpp::_GameRobotHP__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, pb_rm_interfaces, msg, GameRobotHP)() {
  return &pb_rm_interfaces::msg::typesupport_fastrtps_cpp::_GameRobotHP__handle;
}

#ifdef __cplusplus
}
#endif
