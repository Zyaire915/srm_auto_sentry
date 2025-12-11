// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from udp_msgs:srv/UdpSend.idl
// generated code does not contain a copyright notice

#ifndef UDP_MSGS__SRV__DETAIL__UDP_SEND__BUILDER_HPP_
#define UDP_MSGS__SRV__DETAIL__UDP_SEND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "udp_msgs/srv/detail/udp_send__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace udp_msgs
{

namespace srv
{

namespace builder
{

class Init_UdpSend_Request_data
{
public:
  explicit Init_UdpSend_Request_data(::udp_msgs::srv::UdpSend_Request & msg)
  : msg_(msg)
  {}
  ::udp_msgs::srv::UdpSend_Request data(::udp_msgs::srv::UdpSend_Request::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::udp_msgs::srv::UdpSend_Request msg_;
};

class Init_UdpSend_Request_remote_port
{
public:
  explicit Init_UdpSend_Request_remote_port(::udp_msgs::srv::UdpSend_Request & msg)
  : msg_(msg)
  {}
  Init_UdpSend_Request_data remote_port(::udp_msgs::srv::UdpSend_Request::_remote_port_type arg)
  {
    msg_.remote_port = std::move(arg);
    return Init_UdpSend_Request_data(msg_);
  }

private:
  ::udp_msgs::srv::UdpSend_Request msg_;
};

class Init_UdpSend_Request_remote_address
{
public:
  explicit Init_UdpSend_Request_remote_address(::udp_msgs::srv::UdpSend_Request & msg)
  : msg_(msg)
  {}
  Init_UdpSend_Request_remote_port remote_address(::udp_msgs::srv::UdpSend_Request::_remote_address_type arg)
  {
    msg_.remote_address = std::move(arg);
    return Init_UdpSend_Request_remote_port(msg_);
  }

private:
  ::udp_msgs::srv::UdpSend_Request msg_;
};

class Init_UdpSend_Request_local_port
{
public:
  explicit Init_UdpSend_Request_local_port(::udp_msgs::srv::UdpSend_Request & msg)
  : msg_(msg)
  {}
  Init_UdpSend_Request_remote_address local_port(::udp_msgs::srv::UdpSend_Request::_local_port_type arg)
  {
    msg_.local_port = std::move(arg);
    return Init_UdpSend_Request_remote_address(msg_);
  }

private:
  ::udp_msgs::srv::UdpSend_Request msg_;
};

class Init_UdpSend_Request_local_address
{
public:
  Init_UdpSend_Request_local_address()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UdpSend_Request_local_port local_address(::udp_msgs::srv::UdpSend_Request::_local_address_type arg)
  {
    msg_.local_address = std::move(arg);
    return Init_UdpSend_Request_local_port(msg_);
  }

private:
  ::udp_msgs::srv::UdpSend_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::udp_msgs::srv::UdpSend_Request>()
{
  return udp_msgs::srv::builder::Init_UdpSend_Request_local_address();
}

}  // namespace udp_msgs


namespace udp_msgs
{

namespace srv
{

namespace builder
{

class Init_UdpSend_Response_sent
{
public:
  Init_UdpSend_Response_sent()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::udp_msgs::srv::UdpSend_Response sent(::udp_msgs::srv::UdpSend_Response::_sent_type arg)
  {
    msg_.sent = std::move(arg);
    return std::move(msg_);
  }

private:
  ::udp_msgs::srv::UdpSend_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::udp_msgs::srv::UdpSend_Response>()
{
  return udp_msgs::srv::builder::Init_UdpSend_Response_sent();
}

}  // namespace udp_msgs

#endif  // UDP_MSGS__SRV__DETAIL__UDP_SEND__BUILDER_HPP_
