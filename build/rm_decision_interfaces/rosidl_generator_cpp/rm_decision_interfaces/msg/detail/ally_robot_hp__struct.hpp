// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rm_decision_interfaces:msg/AllyRobotHP.idl
// generated code does not contain a copyright notice

#ifndef RM_DECISION_INTERFACES__MSG__DETAIL__ALLY_ROBOT_HP__STRUCT_HPP_
#define RM_DECISION_INTERFACES__MSG__DETAIL__ALLY_ROBOT_HP__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rm_decision_interfaces__msg__AllyRobotHP __attribute__((deprecated))
#else
# define DEPRECATED__rm_decision_interfaces__msg__AllyRobotHP __declspec(deprecated)
#endif

namespace rm_decision_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct AllyRobotHP_
{
  using Type = AllyRobotHP_<ContainerAllocator>;

  explicit AllyRobotHP_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ally_1_robot_hp = 0;
      this->ally_2_robot_hp = 0;
      this->ally_3_robot_hp = 0;
      this->ally_4_robot_hp = 0;
      this->ally_7_robot_hp = 0;
      this->ally_outpost_hp = 0;
      this->ally_base_hp = 0;
    }
  }

  explicit AllyRobotHP_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ally_1_robot_hp = 0;
      this->ally_2_robot_hp = 0;
      this->ally_3_robot_hp = 0;
      this->ally_4_robot_hp = 0;
      this->ally_7_robot_hp = 0;
      this->ally_outpost_hp = 0;
      this->ally_base_hp = 0;
    }
  }

  // field types and members
  using _ally_1_robot_hp_type =
    uint16_t;
  _ally_1_robot_hp_type ally_1_robot_hp;
  using _ally_2_robot_hp_type =
    uint16_t;
  _ally_2_robot_hp_type ally_2_robot_hp;
  using _ally_3_robot_hp_type =
    uint16_t;
  _ally_3_robot_hp_type ally_3_robot_hp;
  using _ally_4_robot_hp_type =
    uint16_t;
  _ally_4_robot_hp_type ally_4_robot_hp;
  using _ally_7_robot_hp_type =
    uint16_t;
  _ally_7_robot_hp_type ally_7_robot_hp;
  using _ally_outpost_hp_type =
    uint16_t;
  _ally_outpost_hp_type ally_outpost_hp;
  using _ally_base_hp_type =
    uint16_t;
  _ally_base_hp_type ally_base_hp;

  // setters for named parameter idiom
  Type & set__ally_1_robot_hp(
    const uint16_t & _arg)
  {
    this->ally_1_robot_hp = _arg;
    return *this;
  }
  Type & set__ally_2_robot_hp(
    const uint16_t & _arg)
  {
    this->ally_2_robot_hp = _arg;
    return *this;
  }
  Type & set__ally_3_robot_hp(
    const uint16_t & _arg)
  {
    this->ally_3_robot_hp = _arg;
    return *this;
  }
  Type & set__ally_4_robot_hp(
    const uint16_t & _arg)
  {
    this->ally_4_robot_hp = _arg;
    return *this;
  }
  Type & set__ally_7_robot_hp(
    const uint16_t & _arg)
  {
    this->ally_7_robot_hp = _arg;
    return *this;
  }
  Type & set__ally_outpost_hp(
    const uint16_t & _arg)
  {
    this->ally_outpost_hp = _arg;
    return *this;
  }
  Type & set__ally_base_hp(
    const uint16_t & _arg)
  {
    this->ally_base_hp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rm_decision_interfaces::msg::AllyRobotHP_<ContainerAllocator> *;
  using ConstRawPtr =
    const rm_decision_interfaces::msg::AllyRobotHP_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rm_decision_interfaces::msg::AllyRobotHP_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rm_decision_interfaces::msg::AllyRobotHP_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rm_decision_interfaces::msg::AllyRobotHP_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rm_decision_interfaces::msg::AllyRobotHP_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rm_decision_interfaces::msg::AllyRobotHP_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rm_decision_interfaces::msg::AllyRobotHP_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rm_decision_interfaces::msg::AllyRobotHP_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rm_decision_interfaces::msg::AllyRobotHP_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rm_decision_interfaces__msg__AllyRobotHP
    std::shared_ptr<rm_decision_interfaces::msg::AllyRobotHP_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rm_decision_interfaces__msg__AllyRobotHP
    std::shared_ptr<rm_decision_interfaces::msg::AllyRobotHP_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AllyRobotHP_ & other) const
  {
    if (this->ally_1_robot_hp != other.ally_1_robot_hp) {
      return false;
    }
    if (this->ally_2_robot_hp != other.ally_2_robot_hp) {
      return false;
    }
    if (this->ally_3_robot_hp != other.ally_3_robot_hp) {
      return false;
    }
    if (this->ally_4_robot_hp != other.ally_4_robot_hp) {
      return false;
    }
    if (this->ally_7_robot_hp != other.ally_7_robot_hp) {
      return false;
    }
    if (this->ally_outpost_hp != other.ally_outpost_hp) {
      return false;
    }
    if (this->ally_base_hp != other.ally_base_hp) {
      return false;
    }
    return true;
  }
  bool operator!=(const AllyRobotHP_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AllyRobotHP_

// alias to use template instance with default allocator
using AllyRobotHP =
  rm_decision_interfaces::msg::AllyRobotHP_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rm_decision_interfaces

#endif  // RM_DECISION_INTERFACES__MSG__DETAIL__ALLY_ROBOT_HP__STRUCT_HPP_
