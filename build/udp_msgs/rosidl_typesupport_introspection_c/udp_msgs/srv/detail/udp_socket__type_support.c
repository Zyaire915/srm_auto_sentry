// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from udp_msgs:srv/UdpSocket.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "udp_msgs/srv/detail/udp_socket__rosidl_typesupport_introspection_c.h"
#include "udp_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "udp_msgs/srv/detail/udp_socket__functions.h"
#include "udp_msgs/srv/detail/udp_socket__struct.h"


// Include directives for member types
// Member `local_address`
// Member `remote_address`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void udp_msgs__srv__UdpSocket_Request__rosidl_typesupport_introspection_c__UdpSocket_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  udp_msgs__srv__UdpSocket_Request__init(message_memory);
}

void udp_msgs__srv__UdpSocket_Request__rosidl_typesupport_introspection_c__UdpSocket_Request_fini_function(void * message_memory)
{
  udp_msgs__srv__UdpSocket_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember udp_msgs__srv__UdpSocket_Request__rosidl_typesupport_introspection_c__UdpSocket_Request_message_member_array[5] = {
  {
    "local_address",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(udp_msgs__srv__UdpSocket_Request, local_address),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "local_port",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(udp_msgs__srv__UdpSocket_Request, local_port),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "remote_address",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(udp_msgs__srv__UdpSocket_Request, remote_address),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "remote_port",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(udp_msgs__srv__UdpSocket_Request, remote_port),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "is_broadcast",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(udp_msgs__srv__UdpSocket_Request, is_broadcast),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers udp_msgs__srv__UdpSocket_Request__rosidl_typesupport_introspection_c__UdpSocket_Request_message_members = {
  "udp_msgs__srv",  // message namespace
  "UdpSocket_Request",  // message name
  5,  // number of fields
  sizeof(udp_msgs__srv__UdpSocket_Request),
  udp_msgs__srv__UdpSocket_Request__rosidl_typesupport_introspection_c__UdpSocket_Request_message_member_array,  // message members
  udp_msgs__srv__UdpSocket_Request__rosidl_typesupport_introspection_c__UdpSocket_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  udp_msgs__srv__UdpSocket_Request__rosidl_typesupport_introspection_c__UdpSocket_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t udp_msgs__srv__UdpSocket_Request__rosidl_typesupport_introspection_c__UdpSocket_Request_message_type_support_handle = {
  0,
  &udp_msgs__srv__UdpSocket_Request__rosidl_typesupport_introspection_c__UdpSocket_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_udp_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, udp_msgs, srv, UdpSocket_Request)() {
  if (!udp_msgs__srv__UdpSocket_Request__rosidl_typesupport_introspection_c__UdpSocket_Request_message_type_support_handle.typesupport_identifier) {
    udp_msgs__srv__UdpSocket_Request__rosidl_typesupport_introspection_c__UdpSocket_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &udp_msgs__srv__UdpSocket_Request__rosidl_typesupport_introspection_c__UdpSocket_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "udp_msgs/srv/detail/udp_socket__rosidl_typesupport_introspection_c.h"
// already included above
// #include "udp_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "udp_msgs/srv/detail/udp_socket__functions.h"
// already included above
// #include "udp_msgs/srv/detail/udp_socket__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void udp_msgs__srv__UdpSocket_Response__rosidl_typesupport_introspection_c__UdpSocket_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  udp_msgs__srv__UdpSocket_Response__init(message_memory);
}

void udp_msgs__srv__UdpSocket_Response__rosidl_typesupport_introspection_c__UdpSocket_Response_fini_function(void * message_memory)
{
  udp_msgs__srv__UdpSocket_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember udp_msgs__srv__UdpSocket_Response__rosidl_typesupport_introspection_c__UdpSocket_Response_message_member_array[1] = {
  {
    "socket_created",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(udp_msgs__srv__UdpSocket_Response, socket_created),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers udp_msgs__srv__UdpSocket_Response__rosidl_typesupport_introspection_c__UdpSocket_Response_message_members = {
  "udp_msgs__srv",  // message namespace
  "UdpSocket_Response",  // message name
  1,  // number of fields
  sizeof(udp_msgs__srv__UdpSocket_Response),
  udp_msgs__srv__UdpSocket_Response__rosidl_typesupport_introspection_c__UdpSocket_Response_message_member_array,  // message members
  udp_msgs__srv__UdpSocket_Response__rosidl_typesupport_introspection_c__UdpSocket_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  udp_msgs__srv__UdpSocket_Response__rosidl_typesupport_introspection_c__UdpSocket_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t udp_msgs__srv__UdpSocket_Response__rosidl_typesupport_introspection_c__UdpSocket_Response_message_type_support_handle = {
  0,
  &udp_msgs__srv__UdpSocket_Response__rosidl_typesupport_introspection_c__UdpSocket_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_udp_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, udp_msgs, srv, UdpSocket_Response)() {
  if (!udp_msgs__srv__UdpSocket_Response__rosidl_typesupport_introspection_c__UdpSocket_Response_message_type_support_handle.typesupport_identifier) {
    udp_msgs__srv__UdpSocket_Response__rosidl_typesupport_introspection_c__UdpSocket_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &udp_msgs__srv__UdpSocket_Response__rosidl_typesupport_introspection_c__UdpSocket_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "udp_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "udp_msgs/srv/detail/udp_socket__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers udp_msgs__srv__detail__udp_socket__rosidl_typesupport_introspection_c__UdpSocket_service_members = {
  "udp_msgs__srv",  // service namespace
  "UdpSocket",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // udp_msgs__srv__detail__udp_socket__rosidl_typesupport_introspection_c__UdpSocket_Request_message_type_support_handle,
  NULL  // response message
  // udp_msgs__srv__detail__udp_socket__rosidl_typesupport_introspection_c__UdpSocket_Response_message_type_support_handle
};

static rosidl_service_type_support_t udp_msgs__srv__detail__udp_socket__rosidl_typesupport_introspection_c__UdpSocket_service_type_support_handle = {
  0,
  &udp_msgs__srv__detail__udp_socket__rosidl_typesupport_introspection_c__UdpSocket_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, udp_msgs, srv, UdpSocket_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, udp_msgs, srv, UdpSocket_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_udp_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, udp_msgs, srv, UdpSocket)() {
  if (!udp_msgs__srv__detail__udp_socket__rosidl_typesupport_introspection_c__UdpSocket_service_type_support_handle.typesupport_identifier) {
    udp_msgs__srv__detail__udp_socket__rosidl_typesupport_introspection_c__UdpSocket_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)udp_msgs__srv__detail__udp_socket__rosidl_typesupport_introspection_c__UdpSocket_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, udp_msgs, srv, UdpSocket_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, udp_msgs, srv, UdpSocket_Response)()->data;
  }

  return &udp_msgs__srv__detail__udp_socket__rosidl_typesupport_introspection_c__UdpSocket_service_type_support_handle;
}
