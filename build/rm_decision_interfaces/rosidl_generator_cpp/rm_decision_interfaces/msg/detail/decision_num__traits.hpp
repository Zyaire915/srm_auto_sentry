// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rm_decision_interfaces:msg/DecisionNum.idl
// generated code does not contain a copyright notice

#ifndef RM_DECISION_INTERFACES__MSG__DETAIL__DECISION_NUM__TRAITS_HPP_
#define RM_DECISION_INTERFACES__MSG__DETAIL__DECISION_NUM__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rm_decision_interfaces/msg/detail/decision_num__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rm_decision_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const DecisionNum & msg,
  std::ostream & out)
{
  out << "{";
  // member: decision_num
  {
    out << "decision_num: ";
    rosidl_generator_traits::value_to_yaml(msg.decision_num, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DecisionNum & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: decision_num
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "decision_num: ";
    rosidl_generator_traits::value_to_yaml(msg.decision_num, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DecisionNum & msg, bool use_flow_style = false)
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
  const rm_decision_interfaces::msg::DecisionNum & msg,
  std::ostream & out, size_t indentation = 0)
{
  rm_decision_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rm_decision_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const rm_decision_interfaces::msg::DecisionNum & msg)
{
  return rm_decision_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rm_decision_interfaces::msg::DecisionNum>()
{
  return "rm_decision_interfaces::msg::DecisionNum";
}

template<>
inline const char * name<rm_decision_interfaces::msg::DecisionNum>()
{
  return "rm_decision_interfaces/msg/DecisionNum";
}

template<>
struct has_fixed_size<rm_decision_interfaces::msg::DecisionNum>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rm_decision_interfaces::msg::DecisionNum>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rm_decision_interfaces::msg::DecisionNum>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RM_DECISION_INTERFACES__MSG__DETAIL__DECISION_NUM__TRAITS_HPP_
