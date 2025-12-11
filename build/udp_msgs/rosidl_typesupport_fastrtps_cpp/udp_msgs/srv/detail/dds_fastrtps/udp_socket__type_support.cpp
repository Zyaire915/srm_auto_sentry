// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from udp_msgs:srv/UdpSocket.idl
// generated code does not contain a copyright notice
#include "udp_msgs/srv/detail/udp_socket__rosidl_typesupport_fastrtps_cpp.hpp"
#include "udp_msgs/srv/detail/udp_socket__struct.hpp"

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

namespace udp_msgs
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_udp_msgs
cdr_serialize(
  const udp_msgs::srv::UdpSocket_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: local_address
  cdr << ros_message.local_address;
  // Member: local_port
  cdr << ros_message.local_port;
  // Member: remote_address
  cdr << ros_message.remote_address;
  // Member: remote_port
  cdr << ros_message.remote_port;
  // Member: is_broadcast
  cdr << (ros_message.is_broadcast ? true : false);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_udp_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  udp_msgs::srv::UdpSocket_Request & ros_message)
{
  // Member: local_address
  cdr >> ros_message.local_address;

  // Member: local_port
  cdr >> ros_message.local_port;

  // Member: remote_address
  cdr >> ros_message.remote_address;

  // Member: remote_port
  cdr >> ros_message.remote_port;

  // Member: is_broadcast
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.is_broadcast = tmp ? true : false;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_udp_msgs
get_serialized_size(
  const udp_msgs::srv::UdpSocket_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: local_address
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.local_address.size() + 1);
  // Member: local_port
  {
    size_t item_size = sizeof(ros_message.local_port);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: remote_address
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.remote_address.size() + 1);
  // Member: remote_port
  {
    size_t item_size = sizeof(ros_message.remote_port);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: is_broadcast
  {
    size_t item_size = sizeof(ros_message.is_broadcast);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_udp_msgs
max_serialized_size_UdpSocket_Request(
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


  // Member: local_address
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: local_port
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: remote_address
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: remote_port
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: is_broadcast
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
    using DataType = udp_msgs::srv::UdpSocket_Request;
    is_plain =
      (
      offsetof(DataType, is_broadcast) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _UdpSocket_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const udp_msgs::srv::UdpSocket_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _UdpSocket_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<udp_msgs::srv::UdpSocket_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _UdpSocket_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const udp_msgs::srv::UdpSocket_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _UdpSocket_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_UdpSocket_Request(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _UdpSocket_Request__callbacks = {
  "udp_msgs::srv",
  "UdpSocket_Request",
  _UdpSocket_Request__cdr_serialize,
  _UdpSocket_Request__cdr_deserialize,
  _UdpSocket_Request__get_serialized_size,
  _UdpSocket_Request__max_serialized_size
};

static rosidl_message_type_support_t _UdpSocket_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_UdpSocket_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace udp_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_udp_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<udp_msgs::srv::UdpSocket_Request>()
{
  return &udp_msgs::srv::typesupport_fastrtps_cpp::_UdpSocket_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, udp_msgs, srv, UdpSocket_Request)() {
  return &udp_msgs::srv::typesupport_fastrtps_cpp::_UdpSocket_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace udp_msgs
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_udp_msgs
cdr_serialize(
  const udp_msgs::srv::UdpSocket_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: socket_created
  cdr << (ros_message.socket_created ? true : false);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_udp_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  udp_msgs::srv::UdpSocket_Response & ros_message)
{
  // Member: socket_created
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.socket_created = tmp ? true : false;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_udp_msgs
get_serialized_size(
  const udp_msgs::srv::UdpSocket_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: socket_created
  {
    size_t item_size = sizeof(ros_message.socket_created);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_udp_msgs
max_serialized_size_UdpSocket_Response(
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


  // Member: socket_created
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
    using DataType = udp_msgs::srv::UdpSocket_Response;
    is_plain =
      (
      offsetof(DataType, socket_created) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _UdpSocket_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const udp_msgs::srv::UdpSocket_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _UdpSocket_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<udp_msgs::srv::UdpSocket_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _UdpSocket_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const udp_msgs::srv::UdpSocket_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _UdpSocket_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_UdpSocket_Response(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _UdpSocket_Response__callbacks = {
  "udp_msgs::srv",
  "UdpSocket_Response",
  _UdpSocket_Response__cdr_serialize,
  _UdpSocket_Response__cdr_deserialize,
  _UdpSocket_Response__get_serialized_size,
  _UdpSocket_Response__max_serialized_size
};

static rosidl_message_type_support_t _UdpSocket_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_UdpSocket_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace udp_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_udp_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<udp_msgs::srv::UdpSocket_Response>()
{
  return &udp_msgs::srv::typesupport_fastrtps_cpp::_UdpSocket_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, udp_msgs, srv, UdpSocket_Response)() {
  return &udp_msgs::srv::typesupport_fastrtps_cpp::_UdpSocket_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace udp_msgs
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _UdpSocket__callbacks = {
  "udp_msgs::srv",
  "UdpSocket",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, udp_msgs, srv, UdpSocket_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, udp_msgs, srv, UdpSocket_Response)(),
};

static rosidl_service_type_support_t _UdpSocket__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_UdpSocket__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace udp_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_udp_msgs
const rosidl_service_type_support_t *
get_service_type_support_handle<udp_msgs::srv::UdpSocket>()
{
  return &udp_msgs::srv::typesupport_fastrtps_cpp::_UdpSocket__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, udp_msgs, srv, UdpSocket)() {
  return &udp_msgs::srv::typesupport_fastrtps_cpp::_UdpSocket__handle;
}

#ifdef __cplusplus
}
#endif
