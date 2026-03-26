/*********************************************************************
 *
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2026, TU Dortmund
 *  All rights reserved.
 *
 *********************************************************************/

#include "teb_local_planner/obstacle_tracker.h"
#include <algorithm>
#include <cmath>

namespace teb_local_planner
{

ObstacleTracker::ObstacleTracker(std::shared_ptr<tf2_ros::Buffer> tf, const std::string& tracking_frame)
  : tf_(tf), tracking_frame_(tracking_frame), next_id_(0), logger_(rclcpp::get_logger("obstacle_tracker"))
{
}

KalmanState ObstacleTracker::initializeTrack(const Eigen::Vector2d& pos)
{
  KalmanState state;
  state.x.setZero();
  state.x.head<2>() = pos;

  state.P.setIdentity();
  state.P.diagonal() << 0.1, 0.1, 1.0, 1.0, 2.0, 2.0;

  state.id = next_id_++;
  state.last_update_time = 0.0;
  state.missed_frames = 0;

  return state;
}

int ObstacleTracker::associate(const Eigen::Vector2d& obs_pos, double threshold)
{
  int best_id = -1;
  double min_dist = threshold;

  for (const auto& [id, state] : tracked_obstacles_)
  {
    double dist = (state.x.head<2>() - obs_pos).norm();
    if (dist < min_dist)
    {
      min_dist = dist;
      best_id = id;
    }
  }

  return best_id;
}

void ObstacleTracker::predict(KalmanState& state, double dt, const TebConfig& cfg)
{
  Eigen::Matrix<double, 6, 6> F = Eigen::Matrix<double, 6, 6>::Identity();
  F(0, 2) = dt;
  F(1, 3) = dt;
  F(0, 4) = 0.5 * dt * dt;
  F(1, 5) = 0.5 * dt * dt;
  F(2, 4) = dt;
  F(3, 5) = dt;

  state.x = F * state.x;

  Eigen::Matrix<double, 6, 6> Q = Eigen::Matrix<double, 6, 6>::Identity();
  Q.diagonal() << 0.1, 0.1, 0.5, 0.5, 1.0, 1.0;
  Q *= dt;

  state.P = F * state.P * F.transpose() + Q;
}

void ObstacleTracker::correct(KalmanState& state, const Eigen::Vector2d& measurement)
{
  Eigen::Matrix<double, 2, 6> H = Eigen::Matrix<double, 2, 6>::Zero();
  H(0, 0) = 1.0;
  H(1, 1) = 1.0;

  Eigen::Matrix2d R = Eigen::Matrix2d::Identity() * 0.1;

  Eigen::Vector2d y = measurement - H * state.x;
  Eigen::Matrix2d S = H * state.P * H.transpose() + R;
  Eigen::Matrix<double, 6, 2> K = state.P * H.transpose() * S.inverse();

  state.x = state.x + K * y;
  state.P = (Eigen::Matrix<double, 6, 6>::Identity() - K * H) * state.P;
}

bool ObstacleTracker::hasTrack(int id) const
{
  return tracked_obstacles_.find(id) != tracked_obstacles_.end();
}

void ObstacleTracker::update(ObstContainer& obstacles, double dt, const std::string& obstacle_frame,
                              const TebConfig& cfg)
{
  std::set<int> matched_tracks;

  // Predict all existing tracks
  for (auto& [id, state] : tracked_obstacles_)
  {
    predict(state, dt, cfg);
  }

  // Associate observations with tracks
  for (auto& obs : obstacles)
  {
    if (!obs) continue;

    Eigen::Vector2d obs_pos = obs->getCentroid();

    // Transform to tracking frame if needed
    if (obstacle_frame != tracking_frame_ && tf_)
    {
      try
      {
        geometry_msgs::msg::PointStamped obs_point, transformed_point;
        obs_point.header.frame_id = obstacle_frame;
        obs_point.point.x = obs_pos.x();
        obs_point.point.y = obs_pos.y();

        transformed_point = tf_->transform(obs_point, tracking_frame_);
        obs_pos.x() = transformed_point.point.x;
        obs_pos.y() = transformed_point.point.y;
      }
      catch (const tf2::TransformException& ex)
      {
        RCLCPP_WARN(logger_, "TF transform failed: %s", ex.what());
        continue;
      }
    }

    int track_id = associate(obs_pos, cfg.obstacles.tracking_dist_threshold);

    if (track_id >= 0)
    {
      correct(tracked_obstacles_[track_id], obs_pos);
      tracked_obstacles_[track_id].missed_frames = 0;
      matched_tracks.insert(track_id);
      obs->setTrackId(track_id);
    }
    else
    {
      KalmanState new_state = initializeTrack(obs_pos);
      tracked_obstacles_[new_state.id] = new_state;
      obs->setTrackId(new_state.id);
    }
  }

  // Handle unmatched tracks (coasting logic)
  std::vector<int> tracks_to_delete;
  for (auto& [id, state] : tracked_obstacles_)
  {
    if (matched_tracks.find(id) == matched_tracks.end())
    {
      state.missed_frames++;
      if (state.missed_frames > cfg.obstacles.max_coasting_frames)
      {
        tracks_to_delete.push_back(id);
      }
    }
  }

  for (int id : tracks_to_delete)
  {
    tracked_obstacles_.erase(id);
  }
}

Eigen::Vector2d ObstacleTracker::getPredictedPosition(int id, double t, const TebConfig& cfg) const
{
  if (!hasTrack(id))
  {
    return Eigen::Vector2d::Zero();
  }

  const KalmanState& state = tracked_obstacles_.at(id);

  Eigen::Vector2d pos = state.x.head<2>();
  Eigen::Vector2d vel = state.x.segment<2>(2);
  Eigen::Vector2d acc = state.x.tail<2>();

  // Clamp acceleration
  acc.x() = std::clamp(acc.x(), -cfg.obstacles.max_obstacle_acceleration, cfg.obstacles.max_obstacle_acceleration);
  acc.y() = std::clamp(acc.y(), -cfg.obstacles.max_obstacle_acceleration, cfg.obstacles.max_obstacle_acceleration);

  // Predict velocity and clamp
  Eigen::Vector2d pred_vel = vel + acc * t;
  double vel_norm = pred_vel.norm();
  if (vel_norm > cfg.obstacles.max_obstacle_velocity)
  {
    pred_vel = pred_vel * (cfg.obstacles.max_obstacle_velocity / vel_norm);
  }

  // Compute position with clamped values
  Eigen::Vector2d pred_pos = pos + vel * t + 0.5 * acc * t * t;

  // Limit prediction distance
  Eigen::Vector2d delta = pred_pos - pos;
  if (delta.norm() > cfg.obstacles.max_prediction_distance)
  {
    pred_pos = pos + delta * (cfg.obstacles.max_prediction_distance / delta.norm());
  }

  return pred_pos;
}

} // namespace teb_local_planner
