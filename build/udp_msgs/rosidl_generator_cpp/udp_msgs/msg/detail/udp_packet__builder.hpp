// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from udp_msgs:msg/UdpPacket.idl
// generated code does not contain a copyright notice

#ifndef UDP_MSGS__MSG__DETAIL__UDP_PACKET__BUILDER_HPP_
#define UDP_MSGS__MSG__DETAIL__UDP_PACKET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "udp_msgs/msg/detail/udp_packet__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace udp_msgs
{

namespace msg
{

namespace builder
{

class Init_UdpPacket_data
{
public:
  explicit Init_UdpPacket_data(::udp_msgs::msg::UdpPacket & msg)
  : msg_(msg)
  {}
  ::udp_msgs::msg::UdpPacket data(::udp_msgs::msg::UdpPacket::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::udp_msgs::msg::UdpPacket msg_;
};

class Init_UdpPacket_src_port
{
public:
  explicit Init_UdpPacket_src_port(::udp_msgs::msg::UdpPacket & msg)
  : msg_(msg)
  {}
  Init_UdpPacket_data src_port(::udp_msgs::msg::UdpPacket::_src_port_type arg)
  {
    msg_.src_port = std::move(arg);
    return Init_UdpPacket_data(msg_);
  }

private:
  ::udp_msgs::msg::UdpPacket msg_;
};

class Init_UdpPacket_address
{
public:
  explicit Init_UdpPacket_address(::udp_msgs::msg::UdpPacket & msg)
  : msg_(msg)
  {}
  Init_UdpPacket_src_port address(::udp_msgs::msg::UdpPacket::_address_type arg)
  {
    msg_.address = std::move(arg);
    return Init_UdpPacket_src_port(msg_);
  }

private:
  ::udp_msgs::msg::UdpPacket msg_;
};

class Init_UdpPacket_header
{
public:
  Init_UdpPacket_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UdpPacket_address header(::udp_msgs::msg::UdpPacket::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_UdpPacket_address(msg_);
  }

private:
  ::udp_msgs::msg::UdpPacket msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::udp_msgs::msg::UdpPacket>()
{
  return udp_msgs::msg::builder::Init_UdpPacket_header();
}

}  // namespace udp_msgs

#endif  // UDP_MSGS__MSG__DETAIL__UDP_PACKET__BUILDER_HPP_
