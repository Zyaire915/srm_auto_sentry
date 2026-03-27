/*********************************************************************
 *
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2026, TU Dortmund
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the institute nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *
 * Author: TEB Enhancement Team
 *********************************************************************/

#ifndef OBSTACLE_TRACKER_H
#define OBSTACLE_TRACKER_H

#include <map>
#include <memory>
#include <string>
#include <Eigen/Core>
#include <rclcpp/rclcpp.hpp>
#include <tf2_ros/buffer.h>
#include <geometry_msgs/msg/point_stamped.hpp>

#include "teb_local_planner/obstacles.h"
#include "teb_local_planner/teb_config.h"

namespace teb_local_planner
{

/**
 * @struct KalmanState
 * @brief Kalman filter state for tracking a single obstacle
 */
struct KalmanState
{
  Eigen::Matrix<double, 6, 1> x;  //!< State vector [x, y, vx, vy, ax, ay]
  Eigen::Matrix<double, 6, 6> P;  //!< Covariance matrix
  int id;                          //!< Unique tracking ID
  double last_update_time;         //!< Timestamp of last update
  int missed_frames;               //!< Number of consecutive frames without measurement

  EIGEN_MAKE_ALIGNED_OPERATOR_NEW
};

/**
 * @class ObstacleTracker
 * @brief Tracks dynamic obstacles using Kalman filtering with acceleration awareness
 */
class ObstacleTracker
{
public:
  /**
   * @brief Constructor
   * @param tf Shared pointer to TF2 buffer for coordinate transformations
   * @param tracking_frame Frame ID for tracking (e.g., "odom")
   */
  ObstacleTracker(std::shared_ptr<tf2_ros::Buffer> tf, const std::string& tracking_frame);

  /**
   * @brief Update tracker with new obstacle observations
   * @param obstacles Container of observed obstacles
   * @param dt Time step since last update
   * @param obstacle_frame Frame ID of obstacle observations
   * @param cfg Configuration parameters
   */
  void update(ObstContainer& obstacles, double dt, const std::string& obstacle_frame,
              const TebConfig& cfg);

  /**
   * @brief Get predicted position of tracked obstacle at time t
   * @param id Tracking ID
   * @param t Prediction time (seconds from current state)
   * @return Predicted 2D position
   */
  Eigen::Vector2d getPredictedPosition(int id, double t, const TebConfig& cfg) const;

  /**
   * @brief Check if a tracking ID exists
   * @param id Tracking ID to check
   * @return true if ID exists in tracker
   */
  bool hasTrack(int id) const;

private:
  /**
   * @brief Associate observation with existing track
   * @param obs_pos Observed obstacle position
   * @return Tracking ID if match found, -1 otherwise
   */
  int associate(const Eigen::Vector2d& obs_pos, double threshold);

  /**
   * @brief Kalman filter prediction step
   * @param state State to predict
   * @param dt Time step
   */
  void predict(KalmanState& state, double dt, const TebConfig& cfg);

  /**
   * @brief Kalman filter correction step
   * @param state State to correct
   * @param measurement Observed position
   */
  void correct(KalmanState& state, const Eigen::Vector2d& measurement);

  /**
   * @brief Initialize new track from observation
   * @param pos Initial position
   * @return Initialized Kalman state
   */
  KalmanState initializeTrack(const Eigen::Vector2d& pos);

  std::map<int, KalmanState> tracked_obstacles_;  //!< Map of tracking ID to state
  int next_id_;                                    //!< Next available tracking ID
  std::string tracking_frame_;                     //!< Frame for tracking
  std::shared_ptr<tf2_ros::Buffer> tf_;           //!< TF2 buffer
  rclcpp::Logger logger_;                          //!< Logger
};

} // namespace teb_local_planner

#endif // OBSTACLE_TRACKER_H
