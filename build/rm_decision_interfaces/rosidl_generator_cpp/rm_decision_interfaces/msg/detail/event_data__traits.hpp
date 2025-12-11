// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rm_decision_interfaces:msg/EventData.idl
// generated code does not contain a copyright notice

#ifndef RM_DECISION_INTERFACES__MSG__DETAIL__EVENT_DATA__TRAITS_HPP_
#define RM_DECISION_INTERFACES__MSG__DETAIL__EVENT_DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rm_decision_interfaces/msg/detail/event_data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rm_decision_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const EventData & msg,
  std::ostream & out)
{
  out << "{";
  // member: supply_zone_non_overlap
  {
    out << "supply_zone_non_overlap: ";
    rosidl_generator_traits::value_to_yaml(msg.supply_zone_non_overlap, out);
    out << ", ";
  }

  // member: supply_zone_overlap
  {
    out << "supply_zone_overlap: ";
    rosidl_generator_traits::value_to_yaml(msg.supply_zone_overlap, out);
    out << ", ";
  }

  // member: supply_zone_rmul
  {
    out << "supply_zone_rmul: ";
    rosidl_generator_traits::value_to_yaml(msg.supply_zone_rmul, out);
    out << ", ";
  }

  // member: small_energy_status
  {
    out << "small_energy_status: ";
    rosidl_generator_traits::value_to_yaml(msg.small_energy_status, out);
    out << ", ";
  }

  // member: big_energy_status
  {
    out << "big_energy_status: ";
    rosidl_generator_traits::value_to_yaml(msg.big_energy_status, out);
    out << ", ";
  }

  // member: central_highland_status
  {
    out << "central_highland_status: ";
    rosidl_generator_traits::value_to_yaml(msg.central_highland_status, out);
    out << ", ";
  }

  // member: trapezoidal_highland_status
  {
    out << "trapezoidal_highland_status: ";
    rosidl_generator_traits::value_to_yaml(msg.trapezoidal_highland_status, out);
    out << ", ";
  }

  // member: dart_last_hit_time
  {
    out << "dart_last_hit_time: ";
    rosidl_generator_traits::value_to_yaml(msg.dart_last_hit_time, out);
    out << ", ";
  }

  // member: dart_last_hit_target
  {
    out << "dart_last_hit_target: ";
    rosidl_generator_traits::value_to_yaml(msg.dart_last_hit_target, out);
    out << ", ";
  }

  // member: center_gain_point_status
  {
    out << "center_gain_point_status: ";
    rosidl_generator_traits::value_to_yaml(msg.center_gain_point_status, out);
    out << ", ";
  }

  // member: fortress_gain_point_status
  {
    out << "fortress_gain_point_status: ";
    rosidl_generator_traits::value_to_yaml(msg.fortress_gain_point_status, out);
    out << ", ";
  }

  // member: outpost_gain_point_status
  {
    out << "outpost_gain_point_status: ";
    rosidl_generator_traits::value_to_yaml(msg.outpost_gain_point_status, out);
    out << ", ";
  }

  // member: base_gain_point_status
  {
    out << "base_gain_point_status: ";
    rosidl_generator_traits::value_to_yaml(msg.base_gain_point_status, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const EventData & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: supply_zone_non_overlap
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "supply_zone_non_overlap: ";
    rosidl_generator_traits::value_to_yaml(msg.supply_zone_non_overlap, out);
    out << "\n";
  }

  // member: supply_zone_overlap
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "supply_zone_overlap: ";
    rosidl_generator_traits::value_to_yaml(msg.supply_zone_overlap, out);
    out << "\n";
  }

  // member: supply_zone_rmul
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "supply_zone_rmul: ";
    rosidl_generator_traits::value_to_yaml(msg.supply_zone_rmul, out);
    out << "\n";
  }

  // member: small_energy_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "small_energy_status: ";
    rosidl_generator_traits::value_to_yaml(msg.small_energy_status, out);
    out << "\n";
  }

  // member: big_energy_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "big_energy_status: ";
    rosidl_generator_traits::value_to_yaml(msg.big_energy_status, out);
    out << "\n";
  }

  // member: central_highland_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "central_highland_status: ";
    rosidl_generator_traits::value_to_yaml(msg.central_highland_status, out);
    out << "\n";
  }

  // member: trapezoidal_highland_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "trapezoidal_highland_status: ";
    rosidl_generator_traits::value_to_yaml(msg.trapezoidal_highland_status, out);
    out << "\n";
  }

  // member: dart_last_hit_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dart_last_hit_time: ";
    rosidl_generator_traits::value_to_yaml(msg.dart_last_hit_time, out);
    out << "\n";
  }

  // member: dart_last_hit_target
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dart_last_hit_target: ";
    rosidl_generator_traits::value_to_yaml(msg.dart_last_hit_target, out);
    out << "\n";
  }

  // member: center_gain_point_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "center_gain_point_status: ";
    rosidl_generator_traits::value_to_yaml(msg.center_gain_point_status, out);
    out << "\n";
  }

  // member: fortress_gain_point_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fortress_gain_point_status: ";
    rosidl_generator_traits::value_to_yaml(msg.fortress_gain_point_status, out);
    out << "\n";
  }

  // member: outpost_gain_point_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "outpost_gain_point_status: ";
    rosidl_generator_traits::value_to_yaml(msg.outpost_gain_point_status, out);
    out << "\n";
  }

  // member: base_gain_point_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "base_gain_point_status: ";
    rosidl_generator_traits::value_to_yaml(msg.base_gain_point_status, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const EventData & msg, bool use_flow_style = false)
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
  const rm_decision_interfaces::msg::EventData & msg,
  std::ostream & out, size_t indentation = 0)
{
  rm_decision_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rm_decision_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const rm_decision_interfaces::msg::EventData & msg)
{
  return rm_decision_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rm_decision_interfaces::msg::EventData>()
{
  return "rm_decision_interfaces::msg::EventData";
}

template<>
inline const char * name<rm_decision_interfaces::msg::EventData>()
{
  return "rm_decision_interfaces/msg/EventData";
}

template<>
struct has_fixed_size<rm_decision_interfaces::msg::EventData>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rm_decision_interfaces::msg::EventData>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rm_decision_interfaces::msg::EventData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RM_DECISION_INTERFACES__MSG__DETAIL__EVENT_DATA__TRAITS_HPP_
