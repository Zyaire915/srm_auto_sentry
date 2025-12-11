// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from pb_rm_interfaces:msg/GroundRobotPosition.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "pb_rm_interfaces/msg/detail/ground_robot_position__rosidl_typesupport_introspection_c.h"
#include "pb_rm_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "pb_rm_interfaces/msg/detail/ground_robot_position__functions.h"
#include "pb_rm_interfaces/msg/detail/ground_robot_position__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void pb_rm_interfaces__msg__GroundRobotPosition__rosidl_typesupport_introspection_c__GroundRobotPosition_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  pb_rm_interfaces__msg__GroundRobotPosition__init(message_memory);
}

void pb_rm_interfaces__msg__GroundRobotPosition__rosidl_typesupport_introspection_c__GroundRobotPosition_fini_function(void * message_memory)
{
  pb_rm_interfaces__msg__GroundRobotPosition__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember pb_rm_interfaces__msg__GroundRobotPosition__rosidl_typesupport_introspection_c__GroundRobotPosition_message_member_array[10] = {
  {
    "hero_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pb_rm_interfaces__msg__GroundRobotPosition, hero_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "hero_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pb_rm_interfaces__msg__GroundRobotPosition, hero_y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "engineer_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pb_rm_interfaces__msg__GroundRobotPosition, engineer_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "engineer_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pb_rm_interfaces__msg__GroundRobotPosition, engineer_y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "standard_3_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pb_rm_interfaces__msg__GroundRobotPosition, standard_3_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "standard_3_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pb_rm_interfaces__msg__GroundRobotPosition, standard_3_y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "standard_4_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pb_rm_interfaces__msg__GroundRobotPosition, standard_4_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "standard_4_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pb_rm_interfaces__msg__GroundRobotPosition, standard_4_y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "standard_5_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pb_rm_interfaces__msg__GroundRobotPosition, standard_5_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "standard_5_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pb_rm_interfaces__msg__GroundRobotPosition, standard_5_y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers pb_rm_interfaces__msg__GroundRobotPosition__rosidl_typesupport_introspection_c__GroundRobotPosition_message_members = {
  "pb_rm_interfaces__msg",  // message namespace
  "GroundRobotPosition",  // message name
  10,  // number of fields
  sizeof(pb_rm_interfaces__msg__GroundRobotPosition),
  pb_rm_interfaces__msg__GroundRobotPosition__rosidl_typesupport_introspection_c__GroundRobotPosition_message_member_array,  // message members
  pb_rm_interfaces__msg__GroundRobotPosition__rosidl_typesupport_introspection_c__GroundRobotPosition_init_function,  // function to initialize message memory (memory has to be allocated)
  pb_rm_interfaces__msg__GroundRobotPosition__rosidl_typesupport_introspection_c__GroundRobotPosition_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t pb_rm_interfaces__msg__GroundRobotPosition__rosidl_typesupport_introspection_c__GroundRobotPosition_message_type_support_handle = {
  0,
  &pb_rm_interfaces__msg__GroundRobotPosition__rosidl_typesupport_introspection_c__GroundRobotPosition_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_pb_rm_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pb_rm_interfaces, msg, GroundRobotPosition)() {
  if (!pb_rm_interfaces__msg__GroundRobotPosition__rosidl_typesupport_introspection_c__GroundRobotPosition_message_type_support_handle.typesupport_identifier) {
    pb_rm_interfaces__msg__GroundRobotPosition__rosidl_typesupport_introspection_c__GroundRobotPosition_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &pb_rm_interfaces__msg__GroundRobotPosition__rosidl_typesupport_introspection_c__GroundRobotPosition_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
