/**
  ****************************(C) COPYRIGHT 2023 Polarbear*************************
  * @file       rm_rune_detector_node.hpp
  * @brief      能量机关检测模块
  * @note
  * @history
  *  Version    Date            Author          Modification
  *  V1.0.0     2023-12-11      Penguin         1. done
  *
  @verbatim
  =================================================================================

  =================================================================================
  @endverbatim
  ****************************(C) COPYRIGHT 2023 Polarbear*************************
  */

#ifndef RM_RUNE_DETECTOR__RM_RUNE_DETECTOR_HPP_
#define RM_RUNE_DETECTOR__RM_RUNE_DETECTOR_HPP_

// ROS
#include <rclcpp/publisher.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp/subscription.hpp>
#include <sensor_msgs/msg/camera_info.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <image_transport/publisher.hpp>

#include "rm_rune_detector/pnp_solver.hpp"
#include "rm_rune_detector/rune.hpp"
#include "rm_rune_detector/rune_detector.hpp"
namespace rm_rune_detector
{
    class RMRuneDetectorNode : public rclcpp::Node
    {
    public:
        explicit RMRuneDetectorNode(const rclcpp::NodeOptions &options);

        ~RMRuneDetectorNode() override;

    private:
        void ImageCallback(const sensor_msgs::msg::Image::ConstSharedPtr img_msg);

        std::vector<Target> DetectRunes(const sensor_msgs::msg::Image::ConstSharedPtr &img_msg);

        std::unique_ptr<RuneDetector> InitDetector();

        void CreateDebugPublishers();

        void DestroyDebugPublishers();

        bool is_detect_rune_;

        // Rune Detector
        std::unique_ptr<RuneDetector> detector_;

        // Image subscrpition
        rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr img_sub_;

        // Camera info part
        rclcpp::Subscription<sensor_msgs::msg::CameraInfo>::SharedPtr cam_info_sub_;
        cv::Point2f cam_center_;
        std::shared_ptr<sensor_msgs::msg::CameraInfo> cam_info_;
        std::unique_ptr<PnPSolver> pnp_solver_;

        // Debug information
        bool debug_;
        std::shared_ptr<rclcpp::ParameterEventHandler> debug_param_sub_;
        std::shared_ptr<rclcpp::ParameterCallbackHandle> debug_cb_handle_;
        // rclcpp::Publisher<auto_aim_interfaces::msg::DebugLights>::SharedPtr lights_data_pub_;
        // rclcpp::Publisher<auto_aim_interfaces::msg::DebugArmors>::SharedPtr armors_data_pub_;
        image_transport::Publisher binary_img_pub_;
        image_transport::Publisher number_img_pub_;
        image_transport::Publisher result_img_pub_;
    };
} // namespace rm_rune_detector

#endif // RM_RUNE_DETECTOR__RM_RUNE_DETECTOR_HPP_