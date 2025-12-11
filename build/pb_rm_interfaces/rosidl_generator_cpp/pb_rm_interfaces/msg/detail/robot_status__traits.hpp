// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pb_rm_interfaces:msg/RobotStatus.idl
// generated code does not contain a copyright notice

#ifndef PB_RM_INTERFACES__MSG__DETAIL__ROBOT_STATUS__TRAITS_HPP_
#define PB_RM_INTERFACES__MSG__DETAIL__ROBOT_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "pb_rm_interfaces/msg/detail/robot_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace pb_rm_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const RobotStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: robot_id
  {
    out << "robot_id: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_id, out);
    out << ", ";
  }

  // member: current_hp
  {
    out << "current_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.current_hp, out);
    out << ", ";
  }

  // member: maximum_hp
  {
    out << "maximum_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.maximum_hp, out);
    out << ", ";
  }

  // member: shooter_17mm_1_barrel_heat
  {
    out << "shooter_17mm_1_barrel_heat: ";
    rosidl_generator_traits::value_to_yaml(msg.shooter_17mm_1_barrel_heat, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: robot_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot_id: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_id, out);
    out << "\n";
  }

  // member: current_hp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.current_hp, out);
    out << "\n";
  }

  // member: maximum_hp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "maximum_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.maximum_hp, out);
    out << "\n";
  }

  // member: shooter_17mm_1_barrel_heat
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "shooter_17mm_1_barrel_heat: ";
    rosidl_generator_traits::value_to_yaml(msg.shooter_17mm_1_barrel_heat, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotStatus & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace pb_rm_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use pb_rm_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const pb_rm_interfaces::msg::RobotStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  pb_rm_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pb_rm_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const pb_rm_interfaces::msg::RobotStatus & msg)
{
  return pb_rm_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<pb_rm_interfaces::msg::RobotStatus>()
{
  return "pb_rm_interfaces::msg::RobotStatus";
}

template<>
inline const char * name<pb_rm_interfaces::msg::RobotStatus>()
{
  return "pb_rm_interfaces/msg/RobotStatus";
}

template<>
struct has_fixed_size<pb_rm_interfaces::msg::RobotStatus>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<pb_rm_interfaces::msg::RobotStatus>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<pb_rm_interfaces::msg::RobotStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PB_RM_INTERFACES__MSG__DETAIL__ROBOT_STATUS__TRAITS_HPP_
