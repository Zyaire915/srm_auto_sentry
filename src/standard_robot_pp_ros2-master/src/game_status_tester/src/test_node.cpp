#include <chrono>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "pb_rm_interfaces/msg/game_status.hpp"

using std::placeholders::_1;

class GameStatusTestNode : public rclcpp::Node
{
public:
  GameStatusTestNode() : Node("game_status_test_node")
  {
    RCLCPP_INFO(this->get_logger(), "Game Status Test Node Started!");

    // 1. 订阅裁判系统的 GameStatus
    game_status_sub_ = this->create_subscription<pb_rm_interfaces::msg::GameStatus>(
        "referee/game_status", 10, std::bind(&GameStatusTestNode::gameStatusCallback, this, _1));

    // 2. 发布 cmd_vel 给底盘驱动节点
    cmd_vel_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
  }

private:
  void gameStatusCallback(const pb_rm_interfaces::msg::GameStatus::SharedPtr msg)
  {
    auto twist_msg = geometry_msgs::msg::Twist();

    // 安全起见，线速度设为 0
    twist_msg.linear.x = 0.0;
    twist_msg.linear.y = 0.0;
    twist_msg.linear.z = 0.0;

    // 逻辑判断：根据剩余时间决定旋转方向
    // 假设阈值为 300 秒
    // 注意：您提供的 Hex 示例中数据段需要您确认对应位置的数值
    if (msg->stage_remain_time > 300)
    {
      // 情况 A: 逆时针旋转 (0.3 rad/s)
      twist_msg.linear.x = 0.4;
      twist_msg.linear.y = -0.5;
      twist_msg.angular.z = -0.3;
      RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 1000, "Time: %d (>300) -> Action: Rotate LEFT (CCW)",
                           msg->stage_remain_time);
    }
    else
    {
      // 情况 B: 顺时针旋转 (-0.3 rad/s)
      // 改过了
      twist_msg.linear.x = 0.4;
      twist_msg.linear.y = 0.5;
      twist_msg.angular.z = 0.3;
      RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 1000,
                           // 改过了
                           "Time: %d (>300) -> Action: Rotate RIGHT (CCW)", msg->stage_remain_time);
    }
    // "Time: %d (<=300) -> Action: Rotate RIGHT (CW)", msg->stage_remain_time);

    // 发布指令
    cmd_vel_pub_->publish(twist_msg);
  }

  rclcpp::Subscription<pb_rm_interfaces::msg::GameStatus>::SharedPtr game_status_sub_;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub_;
};

int main(int argc, char* argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<GameStatusTestNode>());
  rclcpp::shutdown();
  return 0;
}