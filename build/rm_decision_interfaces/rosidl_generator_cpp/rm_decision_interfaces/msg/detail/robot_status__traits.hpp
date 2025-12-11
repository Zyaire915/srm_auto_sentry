// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rm_decision_interfaces:msg/RobotStatus.idl
// generated code does not contain a copyright notice

#ifndef RM_DECISION_INTERFACES__MSG__DETAIL__ROBOT_STATUS__TRAITS_HPP_
#define RM_DECISION_INTERFACES__MSG__DETAIL__ROBOT_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rm_decision_interfaces/msg/detail/robot_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rm_decision_interfaces
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

  // member: shooter_heat
  {
    out << "shooter_heat: ";
    rosidl_generator_traits::value_to_yaml(msg.shooter_heat, out);
    out << ", ";
  }

  // member: team_color
  {
    out << "team_color: ";
    rosidl_generator_traits::value_to_yaml(msg.team_color, out);
    out << ", ";
  }

  // member: is_attacked
  {
    out << "is_attacked: ";
    rosidl_generator_traits::value_to_yaml(msg.is_attacked, out);
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

  // member: shooter_heat
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "shooter_heat: ";
    rosidl_generator_traits::value_to_yaml(msg.shooter_heat, out);
    out << "\n";
  }

  // member: team_color
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "team_color: ";
    rosidl_generator_traits::value_to_yaml(msg.team_color, out);
    out << "\n";
  }

  // member: is_attacked
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_attacked: ";
    rosidl_generator_traits::value_to_yaml(msg.is_attacked, out);
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

}  // namespace rm_decision_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use rm_decision_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rm_decision_interfaces::msg::RobotStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  rm_decision_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rm_decision_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const rm_decision_interfaces::msg::RobotStatus & msg)
{
  return rm_decision_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rm_decision_interfaces::msg::RobotStatus>()
{
  return "rm_decision_interfaces::msg::RobotStatus";
}

template<>
inline const char * name<rm_decision_interfaces::msg::RobotStatus>()
{
  return "rm_decision_interfaces/msg/RobotStatus";
}

template<>
struct has_fixed_size<rm_decision_interfaces::msg::RobotStatus>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rm_decision_interfaces::msg::RobotStatus>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rm_decision_interfaces::msg::RobotStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RM_DECISION_INTERFACES__MSG__DETAIL__ROBOT_STATUS__TRAITS_HPP_
