// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rm_decision_interfaces:msg/RFID.idl
// generated code does not contain a copyright notice

#ifndef RM_DECISION_INTERFACES__MSG__DETAIL__RFID__STRUCT_HPP_
#define RM_DECISION_INTERFACES__MSG__DETAIL__RFID__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rm_decision_interfaces__msg__RFID __attribute__((deprecated))
#else
# define DEPRECATED__rm_decision_interfaces__msg__RFID __declspec(deprecated)
#endif

namespace rm_decision_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RFID_
{
  using Type = RFID_<ContainerAllocator>;

  explicit RFID_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->rfid_patrol_status = false;
    }
  }

  explicit RFID_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->rfid_patrol_status = false;
    }
  }

  // field types and members
  using _rfid_patrol_status_type =
    bool;
  _rfid_patrol_status_type rfid_patrol_status;

  // setters for named parameter idiom
  Type & set__rfid_patrol_status(
    const bool & _arg)
  {
    this->rfid_patrol_status = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rm_decision_interfaces::msg::RFID_<ContainerAllocator> *;
  using ConstRawPtr =
    const rm_decision_interfaces::msg::RFID_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rm_decision_interfaces::msg::RFID_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rm_decision_interfaces::msg::RFID_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rm_decision_interfaces::msg::RFID_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rm_decision_interfaces::msg::RFID_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rm_decision_interfaces::msg::RFID_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rm_decision_interfaces::msg::RFID_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rm_decision_interfaces::msg::RFID_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rm_decision_interfaces::msg::RFID_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rm_decision_interfaces__msg__RFID
    std::shared_ptr<rm_decision_interfaces::msg::RFID_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rm_decision_interfaces__msg__RFID
    std::shared_ptr<rm_decision_interfaces::msg::RFID_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RFID_ & other) const
  {
    if (this->rfid_patrol_status != other.rfid_patrol_status) {
      return false;
    }
    return true;
  }
  bool operator!=(const RFID_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RFID_

// alias to use template instance with default allocator
using RFID =
  rm_decision_interfaces::msg::RFID_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rm_decision_interfaces

#endif  // RM_DECISION_INTERFACES__MSG__DETAIL__RFID__STRUCT_HPP_
