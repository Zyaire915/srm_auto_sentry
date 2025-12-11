// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from udp_msgs:msg/UdpPacket.idl
// generated code does not contain a copyright notice

#ifndef UDP_MSGS__MSG__DETAIL__UDP_PACKET__STRUCT_HPP_
#define UDP_MSGS__MSG__DETAIL__UDP_PACKET__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__udp_msgs__msg__UdpPacket __attribute__((deprecated))
#else
# define DEPRECATED__udp_msgs__msg__UdpPacket __declspec(deprecated)
#endif

namespace udp_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct UdpPacket_
{
  using Type = UdpPacket_<ContainerAllocator>;

  explicit UdpPacket_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->address = "";
      this->src_port = 0;
    }
  }

  explicit UdpPacket_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    address(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->address = "";
      this->src_port = 0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _address_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _address_type address;
  using _src_port_type =
    uint16_t;
  _src_port_type src_port;
  using _data_type =
    std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>>;
  _data_type data;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__address(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->address = _arg;
    return *this;
  }
  Type & set__src_port(
    const uint16_t & _arg)
  {
    this->src_port = _arg;
    return *this;
  }
  Type & set__data(
    const std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>> & _arg)
  {
    this->data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    udp_msgs::msg::UdpPacket_<ContainerAllocator> *;
  using ConstRawPtr =
    const udp_msgs::msg::UdpPacket_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<udp_msgs::msg::UdpPacket_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<udp_msgs::msg::UdpPacket_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      udp_msgs::msg::UdpPacket_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<udp_msgs::msg::UdpPacket_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      udp_msgs::msg::UdpPacket_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<udp_msgs::msg::UdpPacket_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<udp_msgs::msg::UdpPacket_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<udp_msgs::msg::UdpPacket_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__udp_msgs__msg__UdpPacket
    std::shared_ptr<udp_msgs::msg::UdpPacket_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__udp_msgs__msg__UdpPacket
    std::shared_ptr<udp_msgs::msg::UdpPacket_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UdpPacket_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->address != other.address) {
      return false;
    }
    if (this->src_port != other.src_port) {
      return false;
    }
    if (this->data != other.data) {
      return false;
    }
    return true;
  }
  bool operator!=(const UdpPacket_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UdpPacket_

// alias to use template instance with default allocator
using UdpPacket =
  udp_msgs::msg::UdpPacket_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace udp_msgs

#endif  // UDP_MSGS__MSG__DETAIL__UDP_PACKET__STRUCT_HPP_
