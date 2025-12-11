// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from udp_msgs:msg/UdpPacket.idl
// generated code does not contain a copyright notice

#ifndef UDP_MSGS__MSG__DETAIL__UDP_PACKET__TRAITS_HPP_
#define UDP_MSGS__MSG__DETAIL__UDP_PACKET__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "udp_msgs/msg/detail/udp_packet__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace udp_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const UdpPacket & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: address
  {
    out << "address: ";
    rosidl_generator_traits::value_to_yaml(msg.address, out);
    out << ", ";
  }

  // member: src_port
  {
    out << "src_port: ";
    rosidl_generator_traits::value_to_yaml(msg.src_port, out);
    out << ", ";
  }

  // member: data
  {
    if (msg.data.size() == 0) {
      out << "data: []";
    } else {
      out << "data: [";
      size_t pending_items = msg.data.size();
      for (auto item : msg.data) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const UdpPacket & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: address
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "address: ";
    rosidl_generator_traits::value_to_yaml(msg.address, out);
    out << "\n";
  }

  // member: src_port
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "src_port: ";
    rosidl_generator_traits::value_to_yaml(msg.src_port, out);
    out << "\n";
  }

  // member: data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.data.size() == 0) {
      out << "data: []\n";
    } else {
      out << "data:\n";
      for (auto item : msg.data) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const UdpPacket & msg, bool use_flow_style = false)
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

}  // namespace udp_msgs

namespace rosidl_generator_traits
{

[[deprecated("use udp_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const udp_msgs::msg::UdpPacket & msg,
  std::ostream & out, size_t indentation = 0)
{
  udp_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use udp_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const udp_msgs::msg::UdpPacket & msg)
{
  return udp_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<udp_msgs::msg::UdpPacket>()
{
  return "udp_msgs::msg::UdpPacket";
}

template<>
inline const char * name<udp_msgs::msg::UdpPacket>()
{
  return "udp_msgs/msg/UdpPacket";
}

template<>
struct has_fixed_size<udp_msgs::msg::UdpPacket>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<udp_msgs::msg::UdpPacket>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<udp_msgs::msg::UdpPacket>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UDP_MSGS__MSG__DETAIL__UDP_PACKET__TRAITS_HPP_
