// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pb_rm_interfaces:msg/RfidStatus.idl
// generated code does not contain a copyright notice

#ifndef PB_RM_INTERFACES__MSG__DETAIL__RFID_STATUS__TRAITS_HPP_
#define PB_RM_INTERFACES__MSG__DETAIL__RFID_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "pb_rm_interfaces/msg/detail/rfid_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace pb_rm_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const RfidStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: friendly_base_gain_point
  {
    out << "friendly_base_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_base_gain_point, out);
    out << ", ";
  }

  // member: friendly_central_highland_gain_point
  {
    out << "friendly_central_highland_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_central_highland_gain_point, out);
    out << ", ";
  }

  // member: enemy_central_highland_gain_point
  {
    out << "enemy_central_highland_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_central_highland_gain_point, out);
    out << ", ";
  }

  // member: friendly_trapezoidal_gain_point
  {
    out << "friendly_trapezoidal_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_trapezoidal_gain_point, out);
    out << ", ";
  }

  // member: enemy_trapezoidal_gain_point
  {
    out << "enemy_trapezoidal_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_trapezoidal_gain_point, out);
    out << ", ";
  }

  // member: friendly_fly_slope_pre_gain
  {
    out << "friendly_fly_slope_pre_gain: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_fly_slope_pre_gain, out);
    out << ", ";
  }

  // member: friendly_fly_slope_post_gain
  {
    out << "friendly_fly_slope_post_gain: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_fly_slope_post_gain, out);
    out << ", ";
  }

  // member: enemy_fly_slope_pre_gain
  {
    out << "enemy_fly_slope_pre_gain: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_fly_slope_pre_gain, out);
    out << ", ";
  }

  // member: enemy_fly_slope_post_gain
  {
    out << "enemy_fly_slope_post_gain: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_fly_slope_post_gain, out);
    out << ", ";
  }

  // member: friendly_central_highland_under
  {
    out << "friendly_central_highland_under: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_central_highland_under, out);
    out << ", ";
  }

  // member: friendly_central_highland_upper
  {
    out << "friendly_central_highland_upper: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_central_highland_upper, out);
    out << ", ";
  }

  // member: enemy_central_highland_under
  {
    out << "enemy_central_highland_under: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_central_highland_under, out);
    out << ", ";
  }

  // member: enemy_central_highland_upper
  {
    out << "enemy_central_highland_upper: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_central_highland_upper, out);
    out << ", ";
  }

  // member: friendly_highway_under
  {
    out << "friendly_highway_under: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_highway_under, out);
    out << ", ";
  }

  // member: friendly_highway_upper
  {
    out << "friendly_highway_upper: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_highway_upper, out);
    out << ", ";
  }

  // member: enemy_highway_under
  {
    out << "enemy_highway_under: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_highway_under, out);
    out << ", ";
  }

  // member: enemy_highway_upper
  {
    out << "enemy_highway_upper: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_highway_upper, out);
    out << ", ";
  }

  // member: friendly_fortress_gain
  {
    out << "friendly_fortress_gain: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_fortress_gain, out);
    out << ", ";
  }

  // member: friendly_outpost_gain
  {
    out << "friendly_outpost_gain: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_outpost_gain, out);
    out << ", ";
  }

  // member: friendly_supply_zone_non_overlap
  {
    out << "friendly_supply_zone_non_overlap: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_supply_zone_non_overlap, out);
    out << ", ";
  }

  // member: friendly_supply_zone_overlap
  {
    out << "friendly_supply_zone_overlap: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_supply_zone_overlap, out);
    out << ", ";
  }

  // member: friendly_energy_mechanism_gain
  {
    out << "friendly_energy_mechanism_gain: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_energy_mechanism_gain, out);
    out << ", ";
  }

  // member: enemy_energy_mechanism_gain
  {
    out << "enemy_energy_mechanism_gain: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_energy_mechanism_gain, out);
    out << ", ";
  }

  // member: center_gain_point_rmul
  {
    out << "center_gain_point_rmul: ";
    rosidl_generator_traits::value_to_yaml(msg.center_gain_point_rmul, out);
    out << ", ";
  }

  // member: enemy_fortress_gain
  {
    out << "enemy_fortress_gain: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_fortress_gain, out);
    out << ", ";
  }

  // member: enemy_outpost_gain
  {
    out << "enemy_outpost_gain: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_outpost_gain, out);
    out << ", ";
  }

  // member: friendly_tunnel_highway_under
  {
    out << "friendly_tunnel_highway_under: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_tunnel_highway_under, out);
    out << ", ";
  }

  // member: friendly_tunnel_highway_upper
  {
    out << "friendly_tunnel_highway_upper: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_tunnel_highway_upper, out);
    out << ", ";
  }

  // member: friendly_tunnel_trapezoid_low
  {
    out << "friendly_tunnel_trapezoid_low: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_tunnel_trapezoid_low, out);
    out << ", ";
  }

  // member: friendly_tunnel_trapezoid_high
  {
    out << "friendly_tunnel_trapezoid_high: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_tunnel_trapezoid_high, out);
    out << ", ";
  }

  // member: enemy_tunnel_highway_under
  {
    out << "enemy_tunnel_highway_under: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_tunnel_highway_under, out);
    out << ", ";
  }

  // member: enemy_tunnel_highway_upper
  {
    out << "enemy_tunnel_highway_upper: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_tunnel_highway_upper, out);
    out << ", ";
  }

  // member: enemy_tunnel_trapezoid_low
  {
    out << "enemy_tunnel_trapezoid_low: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_tunnel_trapezoid_low, out);
    out << ", ";
  }

  // member: enemy_tunnel_trapezoid_high
  {
    out << "enemy_tunnel_trapezoid_high: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_tunnel_trapezoid_high, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RfidStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: friendly_base_gain_point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "friendly_base_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_base_gain_point, out);
    out << "\n";
  }

  // member: friendly_central_highland_gain_point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "friendly_central_highland_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_central_highland_gain_point, out);
    out << "\n";
  }

  // member: enemy_central_highland_gain_point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enemy_central_highland_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_central_highland_gain_point, out);
    out << "\n";
  }

  // member: friendly_trapezoidal_gain_point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "friendly_trapezoidal_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_trapezoidal_gain_point, out);
    out << "\n";
  }

  // member: enemy_trapezoidal_gain_point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enemy_trapezoidal_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_trapezoidal_gain_point, out);
    out << "\n";
  }

  // member: friendly_fly_slope_pre_gain
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "friendly_fly_slope_pre_gain: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_fly_slope_pre_gain, out);
    out << "\n";
  }

  // member: friendly_fly_slope_post_gain
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "friendly_fly_slope_post_gain: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_fly_slope_post_gain, out);
    out << "\n";
  }

  // member: enemy_fly_slope_pre_gain
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enemy_fly_slope_pre_gain: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_fly_slope_pre_gain, out);
    out << "\n";
  }

  // member: enemy_fly_slope_post_gain
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enemy_fly_slope_post_gain: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_fly_slope_post_gain, out);
    out << "\n";
  }

  // member: friendly_central_highland_under
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "friendly_central_highland_under: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_central_highland_under, out);
    out << "\n";
  }

  // member: friendly_central_highland_upper
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "friendly_central_highland_upper: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_central_highland_upper, out);
    out << "\n";
  }

  // member: enemy_central_highland_under
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enemy_central_highland_under: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_central_highland_under, out);
    out << "\n";
  }

  // member: enemy_central_highland_upper
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enemy_central_highland_upper: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_central_highland_upper, out);
    out << "\n";
  }

  // member: friendly_highway_under
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "friendly_highway_under: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_highway_under, out);
    out << "\n";
  }

  // member: friendly_highway_upper
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "friendly_highway_upper: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_highway_upper, out);
    out << "\n";
  }

  // member: enemy_highway_under
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enemy_highway_under: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_highway_under, out);
    out << "\n";
  }

  // member: enemy_highway_upper
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enemy_highway_upper: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_highway_upper, out);
    out << "\n";
  }

  // member: friendly_fortress_gain
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "friendly_fortress_gain: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_fortress_gain, out);
    out << "\n";
  }

  // member: friendly_outpost_gain
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "friendly_outpost_gain: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_outpost_gain, out);
    out << "\n";
  }

  // member: friendly_supply_zone_non_overlap
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "friendly_supply_zone_non_overlap: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_supply_zone_non_overlap, out);
    out << "\n";
  }

  // member: friendly_supply_zone_overlap
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "friendly_supply_zone_overlap: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_supply_zone_overlap, out);
    out << "\n";
  }

  // member: friendly_energy_mechanism_gain
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "friendly_energy_mechanism_gain: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_energy_mechanism_gain, out);
    out << "\n";
  }

  // member: enemy_energy_mechanism_gain
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enemy_energy_mechanism_gain: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_energy_mechanism_gain, out);
    out << "\n";
  }

  // member: center_gain_point_rmul
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "center_gain_point_rmul: ";
    rosidl_generator_traits::value_to_yaml(msg.center_gain_point_rmul, out);
    out << "\n";
  }

  // member: enemy_fortress_gain
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enemy_fortress_gain: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_fortress_gain, out);
    out << "\n";
  }

  // member: enemy_outpost_gain
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enemy_outpost_gain: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_outpost_gain, out);
    out << "\n";
  }

  // member: friendly_tunnel_highway_under
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "friendly_tunnel_highway_under: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_tunnel_highway_under, out);
    out << "\n";
  }

  // member: friendly_tunnel_highway_upper
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "friendly_tunnel_highway_upper: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_tunnel_highway_upper, out);
    out << "\n";
  }

  // member: friendly_tunnel_trapezoid_low
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "friendly_tunnel_trapezoid_low: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_tunnel_trapezoid_low, out);
    out << "\n";
  }

  // member: friendly_tunnel_trapezoid_high
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "friendly_tunnel_trapezoid_high: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_tunnel_trapezoid_high, out);
    out << "\n";
  }

  // member: enemy_tunnel_highway_under
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enemy_tunnel_highway_under: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_tunnel_highway_under, out);
    out << "\n";
  }

  // member: enemy_tunnel_highway_upper
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enemy_tunnel_highway_upper: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_tunnel_highway_upper, out);
    out << "\n";
  }

  // member: enemy_tunnel_trapezoid_low
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enemy_tunnel_trapezoid_low: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_tunnel_trapezoid_low, out);
    out << "\n";
  }

  // member: enemy_tunnel_trapezoid_high
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enemy_tunnel_trapezoid_high: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_tunnel_trapezoid_high, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RfidStatus & msg, bool use_flow_style = false)
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
  const pb_rm_interfaces::msg::RfidStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  pb_rm_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pb_rm_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const pb_rm_interfaces::msg::RfidStatus & msg)
{
  return pb_rm_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<pb_rm_interfaces::msg::RfidStatus>()
{
  return "pb_rm_interfaces::msg::RfidStatus";
}

template<>
inline const char * name<pb_rm_interfaces::msg::RfidStatus>()
{
  return "pb_rm_interfaces/msg/RfidStatus";
}

template<>
struct has_fixed_size<pb_rm_interfaces::msg::RfidStatus>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<pb_rm_interfaces::msg::RfidStatus>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<pb_rm_interfaces::msg::RfidStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PB_RM_INTERFACES__MSG__DETAIL__RFID_STATUS__TRAITS_HPP_
