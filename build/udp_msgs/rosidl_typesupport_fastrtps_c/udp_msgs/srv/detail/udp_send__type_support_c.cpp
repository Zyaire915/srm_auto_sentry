// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from udp_msgs:srv/UdpSend.idl
// generated code does not contain a copyright notice
#include "udp_msgs/srv/detail/udp_send__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "udp_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "udp_msgs/srv/detail/udp_send__struct.h"
#include "udp_msgs/srv/detail/udp_send__functions.h"
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

#include "rosidl_runtime_c/primitives_sequence.h"  // data
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // data
#include "rosidl_runtime_c/string.h"  // local_address, remote_address
#include "rosidl_runtime_c/string_functions.h"  // local_address, remote_address

// forward declare type support functions


using _UdpSend_Request__ros_msg_type = udp_msgs__srv__UdpSend_Request;

static bool _UdpSend_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _UdpSend_Request__ros_msg_type * ros_message = static_cast<const _UdpSend_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: local_address
  {
    const rosidl_runtime_c__String * str = &ros_message->local_address;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: local_port
  {
    cdr << ros_message->local_port;
  }

  // Field name: remote_address
  {
    const rosidl_runtime_c__String * str = &ros_message->remote_address;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: remote_port
  {
    cdr << ros_message->remote_port;
  }

  // Field name: data
  {
    size_t size = ros_message->data.size;
    auto array_ptr = ros_message->data.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _UdpSend_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _UdpSend_Request__ros_msg_type * ros_message = static_cast<_UdpSend_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: local_address
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->local_address.data) {
      rosidl_runtime_c__String__init(&ros_message->local_address);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->local_address,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'local_address'\n");
      return false;
    }
  }

  // Field name: local_port
  {
    cdr >> ros_message->local_port;
  }

  // Field name: remote_address
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->remote_address.data) {
      rosidl_runtime_c__String__init(&ros_message->remote_address);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->remote_address,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'remote_address'\n");
      return false;
    }
  }

  // Field name: remote_port
  {
    cdr >> ros_message->remote_port;
  }

  // Field name: data
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->data.data) {
      rosidl_runtime_c__uint8__Sequence__fini(&ros_message->data);
    }
    if (!rosidl_runtime_c__uint8__Sequence__init(&ros_message->data, size)) {
      fprintf(stderr, "failed to create array for field 'data'");
      return false;
    }
    auto array_ptr = ros_message->data.data;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_udp_msgs
size_t get_serialized_size_udp_msgs__srv__UdpSend_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _UdpSend_Request__ros_msg_type * ros_message = static_cast<const _UdpSend_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name local_address
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->local_address.size + 1);
  // field.name local_port
  {
    size_t item_size = sizeof(ros_message->local_port);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name remote_address
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->remote_address.size + 1);
  // field.name remote_port
  {
    size_t item_size = sizeof(ros_message->remote_port);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name data
  {
    size_t array_size = ros_message->data.size;
    auto array_ptr = ros_message->data.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _UdpSend_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_udp_msgs__srv__UdpSend_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_udp_msgs
size_t max_serialized_size_udp_msgs__srv__UdpSend_Request(
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

  // member: local_address
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
  // member: local_port
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: remote_address
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
  // member: remote_port
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: data
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = udp_msgs__srv__UdpSend_Request;
    is_plain =
      (
      offsetof(DataType, data) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _UdpSend_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_udp_msgs__srv__UdpSend_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_UdpSend_Request = {
  "udp_msgs::srv",
  "UdpSend_Request",
  _UdpSend_Request__cdr_serialize,
  _UdpSend_Request__cdr_deserialize,
  _UdpSend_Request__get_serialized_size,
  _UdpSend_Request__max_serialized_size
};

static rosidl_message_type_support_t _UdpSend_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_UdpSend_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, udp_msgs, srv, UdpSend_Request)() {
  return &_UdpSend_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "udp_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "udp_msgs/srv/detail/udp_send__struct.h"
// already included above
// #include "udp_msgs/srv/detail/udp_send__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

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


using _UdpSend_Response__ros_msg_type = udp_msgs__srv__UdpSend_Response;

static bool _UdpSend_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _UdpSend_Response__ros_msg_type * ros_message = static_cast<const _UdpSend_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: sent
  {
    cdr << (ros_message->sent ? true : false);
  }

  return true;
}

static bool _UdpSend_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _UdpSend_Response__ros_msg_type * ros_message = static_cast<_UdpSend_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: sent
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->sent = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_udp_msgs
size_t get_serialized_size_udp_msgs__srv__UdpSend_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _UdpSend_Response__ros_msg_type * ros_message = static_cast<const _UdpSend_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name sent
  {
    size_t item_size = sizeof(ros_message->sent);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _UdpSend_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_udp_msgs__srv__UdpSend_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_udp_msgs
size_t max_serialized_size_udp_msgs__srv__UdpSend_Response(
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

  // member: sent
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
    using DataType = udp_msgs__srv__UdpSend_Response;
    is_plain =
      (
      offsetof(DataType, sent) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _UdpSend_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_udp_msgs__srv__UdpSend_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_UdpSend_Response = {
  "udp_msgs::srv",
  "UdpSend_Response",
  _UdpSend_Response__cdr_serialize,
  _UdpSend_Response__cdr_deserialize,
  _UdpSend_Response__get_serialized_size,
  _UdpSend_Response__max_serialized_size
};

static rosidl_message_type_support_t _UdpSend_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_UdpSend_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, udp_msgs, srv, UdpSend_Response)() {
  return &_UdpSend_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "udp_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "udp_msgs/srv/udp_send.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t UdpSend__callbacks = {
  "udp_msgs::srv",
  "UdpSend",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, udp_msgs, srv, UdpSend_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, udp_msgs, srv, UdpSend_Response)(),
};

static rosidl_service_type_support_t UdpSend__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &UdpSend__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, udp_msgs, srv, UdpSend)() {
  return &UdpSend__handle;
}

#if defined(__cplusplus)
}
#endif
