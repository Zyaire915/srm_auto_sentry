// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rm_decision_interfaces:msg/FriendLocation.idl
// generated code does not contain a copyright notice

#ifndef RM_DECISION_INTERFACES__MSG__DETAIL__FRIEND_LOCATION__TRAITS_HPP_
#define RM_DECISION_INTERFACES__MSG__DETAIL__FRIEND_LOCATION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rm_decision_interfaces/msg/detail/friend_location__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rm_decision_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const FriendLocation & msg,
  std::ostream & out)
{
  out << "{";
  // member: hero_x
  {
    out << "hero_x: ";
    rosidl_generator_traits::value_to_yaml(msg.hero_x, out);
    out << ", ";
  }

  // member: hero_y
  {
    out << "hero_y: ";
    rosidl_generator_traits::value_to_yaml(msg.hero_y, out);
    out << ", ";
  }

  // member: engineer_x
  {
    out << "engineer_x: ";
    rosidl_generator_traits::value_to_yaml(msg.engineer_x, out);
    out << ", ";
  }

  // member: engineer_y
  {
    out << "engineer_y: ";
    rosidl_generator_traits::value_to_yaml(msg.engineer_y, out);
    out << ", ";
  }

  // member: standard_3_x
  {
    out << "standard_3_x: ";
    rosidl_generator_traits::value_to_yaml(msg.standard_3_x, out);
    out << ", ";
  }

  // member: standard_3_y
  {
    out << "standard_3_y: ";
    rosidl_generator_traits::value_to_yaml(msg.standard_3_y, out);
    out << ", ";
  }

  // member: standard_4_x
  {
    out << "standard_4_x: ";
    rosidl_generator_traits::value_to_yaml(msg.standard_4_x, out);
    out << ", ";
  }

  // member: standard_4_y
  {
    out << "standard_4_y: ";
    rosidl_generator_traits::value_to_yaml(msg.standard_4_y, out);
    out << ", ";
  }

  // member: standard_5_x
  {
    out << "standard_5_x: ";
    rosidl_generator_traits::value_to_yaml(msg.standard_5_x, out);
    out << ", ";
  }

  // member: standard_5_y
  {
    out << "standard_5_y: ";
    rosidl_generator_traits::value_to_yaml(msg.standard_5_y, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FriendLocation & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: hero_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hero_x: ";
    rosidl_generator_traits::value_to_yaml(msg.hero_x, out);
    out << "\n";
  }

  // member: hero_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hero_y: ";
    rosidl_generator_traits::value_to_yaml(msg.hero_y, out);
    out << "\n";
  }

  // member: engineer_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "engineer_x: ";
    rosidl_generator_traits::value_to_yaml(msg.engineer_x, out);
    out << "\n";
  }

  // member: engineer_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "engineer_y: ";
    rosidl_generator_traits::value_to_yaml(msg.engineer_y, out);
    out << "\n";
  }

  // member: standard_3_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "standard_3_x: ";
    rosidl_generator_traits::value_to_yaml(msg.standard_3_x, out);
    out << "\n";
  }

  // member: standard_3_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "standard_3_y: ";
    rosidl_generator_traits::value_to_yaml(msg.standard_3_y, out);
    out << "\n";
  }

  // member: standard_4_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "standard_4_x: ";
    rosidl_generator_traits::value_to_yaml(msg.standard_4_x, out);
    out << "\n";
  }

  // member: standard_4_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "standard_4_y: ";
    rosidl_generator_traits::value_to_yaml(msg.standard_4_y, out);
    out << "\n";
  }

  // member: standard_5_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "standard_5_x: ";
    rosidl_generator_traits::value_to_yaml(msg.standard_5_x, out);
    out << "\n";
  }

  // member: standard_5_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "standard_5_y: ";
    rosidl_generator_traits::value_to_yaml(msg.standard_5_y, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FriendLocation & msg, bool use_flow_style = false)
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
  const rm_decision_interfaces::msg::FriendLocation & msg,
  std::ostream & out, size_t indentation = 0)
{
  rm_decision_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rm_decision_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const rm_decision_interfaces::msg::FriendLocation & msg)
{
  return rm_decision_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rm_decision_interfaces::msg::FriendLocation>()
{
  return "rm_decision_interfaces::msg::FriendLocation";
}

template<>
inline const char * name<rm_decision_interfaces::msg::FriendLocation>()
{
  return "rm_decision_interfaces/msg/FriendLocation";
}

template<>
struct has_fixed_size<rm_decision_interfaces::msg::FriendLocation>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rm_decision_interfaces::msg::FriendLocation>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rm_decision_interfaces::msg::FriendLocation>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RM_DECISION_INTERFACES__MSG__DETAIL__FRIEND_LOCATION__TRAITS_HPP_
