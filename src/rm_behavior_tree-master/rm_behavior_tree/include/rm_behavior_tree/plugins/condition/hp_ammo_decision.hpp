#include <string>
#include "behaviortree_cpp/condition_node.h"
#include "rm_decision_interfaces/msg/sefdefined.hpp"
#include "pb_rm_interfaces/msg/projectile_allowance.hpp"
#include "geometry_msgs/msg/pose.hpp"

namespace rm_behavior_tree
{

class HpAmmoDcisionAction : public BT::SimpleConditionNode
{
public:
  explicit HpAmmoDcisionAction(const std::string & name, const BT::NodeConfig & config);

  static BT::PortsList providedPorts()
  {
    return {
      BT::InputPort<rm_decision_interfaces::msg::Sefdefined>("hp_message"),
      BT::InputPort<pb_rm_interfaces::msg::ProjectileAllowance>("ammo_message"),
      BT::InputPort<int>("hp_threshold", 250, "HP threshold"),
      BT::InputPort<int>("ammo_threshold", 40, "Ammo threshold"),
      BT::InputPort<std::string>("pose_above_threshold", "7.89;5.76;0; 0;0;0;1", "Pose when HP and ammo above thresholds"),
      BT::InputPort<std::string>("pose_below_threshold", "5.24;2.26;0; 0;0;0;1", "Pose when HP or ammo below thresholds"),
      BT::OutputPort<std::string>("goal_pose", "Goal position based on HP and ammo status"),
    };
  }

private:
  std::string last_goal_pose_ = ""; // Cache last goal to avoid duplicate sends
  BT::NodeStatus checkHpAmmoAndDecide();
};

}  // namespace rm_behavior_tree
