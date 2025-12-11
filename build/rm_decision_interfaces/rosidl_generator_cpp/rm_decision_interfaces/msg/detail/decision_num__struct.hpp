// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rm_decision_interfaces:msg/DecisionNum.idl
// generated code does not contain a copyright notice

#ifndef RM_DECISION_INTERFACES__MSG__DETAIL__DECISION_NUM__STRUCT_HPP_
#define RM_DECISION_INTERFACES__MSG__DETAIL__DECISION_NUM__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rm_decision_interfaces__msg__DecisionNum __attribute__((deprecated))
#else
# define DEPRECATED__rm_decision_interfaces__msg__DecisionNum __declspec(deprecated)
#endif

namespace rm_decision_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DecisionNum_
{
  using Type = DecisionNum_<ContainerAllocator>;

  explicit DecisionNum_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->decision_num = 0;
    }
  }

  explicit DecisionNum_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->decision_num = 0;
    }
  }

  // field types and members
  using _decision_num_type =
    uint8_t;
  _decision_num_type decision_num;

  // setters for named parameter idiom
  Type & set__decision_num(
    const uint8_t & _arg)
  {
    this->decision_num = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rm_decision_interfaces::msg::DecisionNum_<ContainerAllocator> *;
  using ConstRawPtr =
    const rm_decision_interfaces::msg::DecisionNum_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rm_decision_interfaces::msg::DecisionNum_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rm_decision_interfaces::msg::DecisionNum_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rm_decision_interfaces::msg::DecisionNum_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rm_decision_interfaces::msg::DecisionNum_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rm_decision_interfaces::msg::DecisionNum_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rm_decision_interfaces::msg::DecisionNum_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rm_decision_interfaces::msg::DecisionNum_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rm_decision_interfaces::msg::DecisionNum_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rm_decision_interfaces__msg__DecisionNum
    std::shared_ptr<rm_decision_interfaces::msg::DecisionNum_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rm_decision_interfaces__msg__DecisionNum
    std::shared_ptr<rm_decision_interfaces::msg::DecisionNum_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DecisionNum_ & other) const
  {
    if (this->decision_num != other.decision_num) {
      return false;
    }
    return true;
  }
  bool operator!=(const DecisionNum_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DecisionNum_

// alias to use template instance with default allocator
using DecisionNum =
  rm_decision_interfaces::msg::DecisionNum_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rm_decision_interfaces

#endif  // RM_DECISION_INTERFACES__MSG__DETAIL__DECISION_NUM__STRUCT_HPP_
