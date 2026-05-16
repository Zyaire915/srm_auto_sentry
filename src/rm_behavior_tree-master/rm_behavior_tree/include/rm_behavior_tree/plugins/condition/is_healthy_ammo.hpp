#include <string>
#include "behaviortree_cpp/condition_node.h"
#include "rm_decision_interfaces/msg/sefdefined.hpp"
#include "pb_rm_interfaces/msg/projectile_allowance.hpp"

namespace rm_behavior_tree
{

class IsHealthyAmmoAction : public BT::SimpleConditionNode
{
public:
  explicit IsHealthyAmmoAction(const std::string & name, const BT::NodeConfig & config);

  static BT::PortsList providedPorts()
  {
    return {
      BT::InputPort<rm_decision_interfaces::msg::Sefdefined>("hp_message"),
      BT::InputPort<pb_rm_interfaces::msg::ProjectileAllowance>("ammo_message"),
      BT::InputPort<int>("hp_threshold", 250, "HP threshold"),
      BT::InputPort<int>("ammo_threshold", 40, "Ammo threshold"),
    };
  }

private:
  BT::NodeStatus checkHealthyAmmo();
};

}  // namespace rm_behavior_tree
