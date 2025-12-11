// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from udp_msgs:srv/UdpSocket.idl
// generated code does not contain a copyright notice

#ifndef UDP_MSGS__SRV__DETAIL__UDP_SOCKET__TRAITS_HPP_
#define UDP_MSGS__SRV__DETAIL__UDP_SOCKET__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "udp_msgs/srv/detail/udp_socket__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace udp_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const UdpSocket_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: local_address
  {
    out << "local_address: ";
    rosidl_generator_traits::value_to_yaml(msg.local_address, out);
    out << ", ";
  }

  // member: local_port
  {
    out << "local_port: ";
    rosidl_generator_traits::value_to_yaml(msg.local_port, out);
    out << ", ";
  }

  // member: remote_address
  {
    out << "remote_address: ";
    rosidl_generator_traits::value_to_yaml(msg.remote_address, out);
    out << ", ";
  }

  // member: remote_port
  {
    out << "remote_port: ";
    rosidl_generator_traits::value_to_yaml(msg.remote_port, out);
    out << ", ";
  }

  // member: is_broadcast
  {
    out << "is_broadcast: ";
    rosidl_generator_traits::value_to_yaml(msg.is_broadcast, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const UdpSocket_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: local_address
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "local_address: ";
    rosidl_generator_traits::value_to_yaml(msg.local_address, out);
    out << "\n";
  }

  // member: local_port
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "local_port: ";
    rosidl_generator_traits::value_to_yaml(msg.local_port, out);
    out << "\n";
  }

  // member: remote_address
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "remote_address: ";
    rosidl_generator_traits::value_to_yaml(msg.remote_address, out);
    out << "\n";
  }

  // member: remote_port
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "remote_port: ";
    rosidl_generator_traits::value_to_yaml(msg.remote_port, out);
    out << "\n";
  }

  // member: is_broadcast
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_broadcast: ";
    rosidl_generator_traits::value_to_yaml(msg.is_broadcast, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const UdpSocket_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace udp_msgs

namespace rosidl_generator_traits
{

[[deprecated("use udp_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const udp_msgs::srv::UdpSocket_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  udp_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use udp_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const udp_msgs::srv::UdpSocket_Request & msg)
{
  return udp_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<udp_msgs::srv::UdpSocket_Request>()
{
  return "udp_msgs::srv::UdpSocket_Request";
}

template<>
inline const char * name<udp_msgs::srv::UdpSocket_Request>()
{
  return "udp_msgs/srv/UdpSocket_Request";
}

template<>
struct has_fixed_size<udp_msgs::srv::UdpSocket_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<udp_msgs::srv::UdpSocket_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<udp_msgs::srv::UdpSocket_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace udp_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const UdpSocket_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: socket_created
  {
    out << "socket_created: ";
    rosidl_generator_traits::value_to_yaml(msg.socket_created, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const UdpSocket_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: socket_created
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "socket_created: ";
    rosidl_generator_traits::value_to_yaml(msg.socket_created, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const UdpSocket_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace udp_msgs

namespace rosidl_generator_traits
{

[[deprecated("use udp_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const udp_msgs::srv::UdpSocket_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  udp_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use udp_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const udp_msgs::srv::UdpSocket_Response & msg)
{
  return udp_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<udp_msgs::srv::UdpSocket_Response>()
{
  return "udp_msgs::srv::UdpSocket_Response";
}

template<>
inline const char * name<udp_msgs::srv::UdpSocket_Response>()
{
  return "udp_msgs/srv/UdpSocket_Response";
}

template<>
struct has_fixed_size<udp_msgs::srv::UdpSocket_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<udp_msgs::srv::UdpSocket_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<udp_msgs::srv::UdpSocket_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<udp_msgs::srv::UdpSocket>()
{
  return "udp_msgs::srv::UdpSocket";
}

template<>
inline const char * name<udp_msgs::srv::UdpSocket>()
{
  return "udp_msgs/srv/UdpSocket";
}

template<>
struct has_fixed_size<udp_msgs::srv::UdpSocket>
  : std::integral_constant<
    bool,
    has_fixed_size<udp_msgs::srv::UdpSocket_Request>::value &&
    has_fixed_size<udp_msgs::srv::UdpSocket_Response>::value
  >
{
};

template<>
struct has_bounded_size<udp_msgs::srv::UdpSocket>
  : std::integral_constant<
    bool,
    has_bounded_size<udp_msgs::srv::UdpSocket_Request>::value &&
    has_bounded_size<udp_msgs::srv::UdpSocket_Response>::value
  >
{
};

template<>
struct is_service<udp_msgs::srv::UdpSocket>
  : std::true_type
{
};

template<>
struct is_service_request<udp_msgs::srv::UdpSocket_Request>
  : std::true_type
{
};

template<>
struct is_service_response<udp_msgs::srv::UdpSocket_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // UDP_MSGS__SRV__DETAIL__UDP_SOCKET__TRAITS_HPP_
