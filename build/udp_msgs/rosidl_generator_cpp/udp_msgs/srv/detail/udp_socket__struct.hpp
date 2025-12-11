// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from udp_msgs:srv/UdpSocket.idl
// generated code does not contain a copyright notice

#ifndef UDP_MSGS__SRV__DETAIL__UDP_SOCKET__STRUCT_HPP_
#define UDP_MSGS__SRV__DETAIL__UDP_SOCKET__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__udp_msgs__srv__UdpSocket_Request __attribute__((deprecated))
#else
# define DEPRECATED__udp_msgs__srv__UdpSocket_Request __declspec(deprecated)
#endif

namespace udp_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct UdpSocket_Request_
{
  using Type = UdpSocket_Request_<ContainerAllocator>;

  explicit UdpSocket_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->local_address = "";
      this->local_port = 0;
      this->remote_address = "";
      this->remote_port = 0;
      this->is_broadcast = false;
    }
  }

  explicit UdpSocket_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : local_address(_alloc),
    remote_address(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->local_address = "";
      this->local_port = 0;
      this->remote_address = "";
      this->remote_port = 0;
      this->is_broadcast = false;
    }
  }

  // field types and members
  using _local_address_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _local_address_type local_address;
  using _local_port_type =
    uint16_t;
  _local_port_type local_port;
  using _remote_address_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _remote_address_type remote_address;
  using _remote_port_type =
    uint16_t;
  _remote_port_type remote_port;
  using _is_broadcast_type =
    bool;
  _is_broadcast_type is_broadcast;

  // setters for named parameter idiom
  Type & set__local_address(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->local_address = _arg;
    return *this;
  }
  Type & set__local_port(
    const uint16_t & _arg)
  {
    this->local_port = _arg;
    return *this;
  }
  Type & set__remote_address(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->remote_address = _arg;
    return *this;
  }
  Type & set__remote_port(
    const uint16_t & _arg)
  {
    this->remote_port = _arg;
    return *this;
  }
  Type & set__is_broadcast(
    const bool & _arg)
  {
    this->is_broadcast = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    udp_msgs::srv::UdpSocket_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const udp_msgs::srv::UdpSocket_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<udp_msgs::srv::UdpSocket_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<udp_msgs::srv::UdpSocket_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      udp_msgs::srv::UdpSocket_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<udp_msgs::srv::UdpSocket_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      udp_msgs::srv::UdpSocket_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<udp_msgs::srv::UdpSocket_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<udp_msgs::srv::UdpSocket_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<udp_msgs::srv::UdpSocket_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__udp_msgs__srv__UdpSocket_Request
    std::shared_ptr<udp_msgs::srv::UdpSocket_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__udp_msgs__srv__UdpSocket_Request
    std::shared_ptr<udp_msgs::srv::UdpSocket_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UdpSocket_Request_ & other) const
  {
    if (this->local_address != other.local_address) {
      return false;
    }
    if (this->local_port != other.local_port) {
      return false;
    }
    if (this->remote_address != other.remote_address) {
      return false;
    }
    if (this->remote_port != other.remote_port) {
      return false;
    }
    if (this->is_broadcast != other.is_broadcast) {
      return false;
    }
    return true;
  }
  bool operator!=(const UdpSocket_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UdpSocket_Request_

// alias to use template instance with default allocator
using UdpSocket_Request =
  udp_msgs::srv::UdpSocket_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace udp_msgs


#ifndef _WIN32
# define DEPRECATED__udp_msgs__srv__UdpSocket_Response __attribute__((deprecated))
#else
# define DEPRECATED__udp_msgs__srv__UdpSocket_Response __declspec(deprecated)
#endif

namespace udp_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct UdpSocket_Response_
{
  using Type = UdpSocket_Response_<ContainerAllocator>;

  explicit UdpSocket_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->socket_created = false;
    }
  }

  explicit UdpSocket_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->socket_created = false;
    }
  }

  // field types and members
  using _socket_created_type =
    bool;
  _socket_created_type socket_created;

  // setters for named parameter idiom
  Type & set__socket_created(
    const bool & _arg)
  {
    this->socket_created = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    udp_msgs::srv::UdpSocket_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const udp_msgs::srv::UdpSocket_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<udp_msgs::srv::UdpSocket_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<udp_msgs::srv::UdpSocket_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      udp_msgs::srv::UdpSocket_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<udp_msgs::srv::UdpSocket_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      udp_msgs::srv::UdpSocket_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<udp_msgs::srv::UdpSocket_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<udp_msgs::srv::UdpSocket_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<udp_msgs::srv::UdpSocket_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__udp_msgs__srv__UdpSocket_Response
    std::shared_ptr<udp_msgs::srv::UdpSocket_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__udp_msgs__srv__UdpSocket_Response
    std::shared_ptr<udp_msgs::srv::UdpSocket_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UdpSocket_Response_ & other) const
  {
    if (this->socket_created != other.socket_created) {
      return false;
    }
    return true;
  }
  bool operator!=(const UdpSocket_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UdpSocket_Response_

// alias to use template instance with default allocator
using UdpSocket_Response =
  udp_msgs::srv::UdpSocket_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace udp_msgs

namespace udp_msgs
{

namespace srv
{

struct UdpSocket
{
  using Request = udp_msgs::srv::UdpSocket_Request;
  using Response = udp_msgs::srv::UdpSocket_Response;
};

}  // namespace srv

}  // namespace udp_msgs

#endif  // UDP_MSGS__SRV__DETAIL__UDP_SOCKET__STRUCT_HPP_
