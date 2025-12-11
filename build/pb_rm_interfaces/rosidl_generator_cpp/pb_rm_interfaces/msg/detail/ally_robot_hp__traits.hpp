// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pb_rm_interfaces:msg/AllyRobotHP.idl
// generated code does not contain a copyright notice

#ifndef PB_RM_INTERFACES__MSG__DETAIL__ALLY_ROBOT_HP__TRAITS_HPP_
#define PB_RM_INTERFACES__MSG__DETAIL__ALLY_ROBOT_HP__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "pb_rm_interfaces/msg/detail/ally_robot_hp__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace pb_rm_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const AllyRobotHP & msg,
  std::ostream & out)
{
  out << "{";
  // member: ally_1_robot_hp
  {
    out << "ally_1_robot_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.ally_1_robot_hp, out);
    out << ", ";
  }

  // member: ally_2_robot_hp
  {
    out << "ally_2_robot_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.ally_2_robot_hp, out);
    out << ", ";
  }

  // member: ally_3_robot_hp
  {
    out << "ally_3_robot_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.ally_3_robot_hp, out);
    out << ", ";
  }

  // member: ally_4_robot_hp
  {
    out << "ally_4_robot_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.ally_4_robot_hp, out);
    out << ", ";
  }

  // member: ally_7_robot_hp
  {
    out << "ally_7_robot_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.ally_7_robot_hp, out);
    out << ", ";
  }

  // member: ally_outpost_hp
  {
    out << "ally_outpost_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.ally_outpost_hp, out);
    out << ", ";
  }

  // member: ally_base_hp
  {
    out << "ally_base_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.ally_base_hp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AllyRobotHP & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: ally_1_robot_hp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ally_1_robot_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.ally_1_robot_hp, out);
    out << "\n";
  }

  // member: ally_2_robot_hp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ally_2_robot_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.ally_2_robot_hp, out);
    out << "\n";
  }

  // member: ally_3_robot_hp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ally_3_robot_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.ally_3_robot_hp, out);
    out << "\n";
  }

  // member: ally_4_robot_hp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ally_4_robot_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.ally_4_robot_hp, out);
    out << "\n";
  }

  // member: ally_7_robot_hp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ally_7_robot_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.ally_7_robot_hp, out);
    out << "\n";
  }

  // member: ally_outpost_hp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ally_outpost_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.ally_outpost_hp, out);
    out << "\n";
  }

  // member: ally_base_hp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ally_base_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.ally_base_hp, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AllyRobotHP & msg, bool use_flow_style = false)
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
  const pb_rm_interfaces::msg::AllyRobotHP & msg,
  std::ostream & out, size_t indentation = 0)
{
  pb_rm_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pb_rm_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const pb_rm_interfaces::msg::AllyRobotHP & msg)
{
  return pb_rm_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<pb_rm_interfaces::msg::AllyRobotHP>()
{
  return "pb_rm_interfaces::msg::AllyRobotHP";
}

template<>
inline const char * name<pb_rm_interfaces::msg::AllyRobotHP>()
{
  return "pb_rm_interfaces/msg/AllyRobotHP";
}

template<>
struct has_fixed_size<pb_rm_interfaces::msg::AllyRobotHP>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<pb_rm_interfaces::msg::AllyRobotHP>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<pb_rm_interfaces::msg::AllyRobotHP>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PB_RM_INTERFACES__MSG__DETAIL__ALLY_ROBOT_HP__TRAITS_HPP_
