/**
  ****************************(C) COPYRIGHT 2023 Polarbear*************************
  * @file       rune_detector.cpp
  * @brief      能量机关检测模块检测图片中的能量机关靶标
  * @note
  * @history
  *  Version    Date            Author          Modification
  *  V1.0.0     2023-12-11      Penguin         
  *
  @verbatim
  =================================================================================

  =================================================================================
  @endverbatim
  ****************************(C) COPYRIGHT 2023 Polarbear*************************
  */
// OpenCV
#include <opencv2/core.hpp>
#include <opencv2/core/base.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc.hpp>

// STD
#include <algorithm>
#include <cmath>
#include <vector>

#include "rm_rune_detector/rune_detector.hpp"
#include "rm_rune_detector/rune.hpp"

namespace rm_rune_detector
{
    /**
     * @brief RuneDetector类的构造函数
     * @param bin_thres 二值化阈值
     * @param color 检测颜色
     * @param t 靶标识别相关参数
     * @param hsv 红色和蓝色HSV颜色空间阈值
     */
    RuneDetector::RuneDetector(const int &bin_thres, const int &color, const TargetParams &t, const HSVParams &hsv)
        : binary_thres(bin_thres), detect_color(color), t(t), hsv(hsv)
    {
    }

    /**
     * @brief 检测函数，用于检测输入图像中的目标
     * @param input 输入图像
     * @return 检测到的靶标列表
     */
    std::vector<Target> RuneDetector::Detect(const cv::Mat &input)
    {
        // TODO:完成能量机关靶标的检测与状态判别
        binary_img = PreprocessImage(input);
        std::vector<Target> res_tmp;
        targets_ = res_tmp;
        return targets_;
    }

    /**
     * @brief 对输入图像进行预处理
     * @param rgb_img 输入图像
     */
    cv::Mat RuneDetector::PreprocessImage(const cv::Mat &rgb_img)
    {
        cv::Mat gray_img;
        cv::cvtColor(rgb_img, gray_img, cv::COLOR_RGB2GRAY);

        cv::Mat binary_img;
        cv::threshold(gray_img, binary_img, binary_thres, 255, cv::THRESH_BINARY);

        return binary_img;
    }

    /**
     * @brief 在输入图像中寻找可能的靶标
     * @param rbg_img rgb图像
     * @param binary_img 二值化图像
     * @return 可能的靶标列表
     */
    std::vector<Ellipse> RuneDetector::FindPossibleTargets(const cv::Mat &rbg_img, const cv::Mat &binary_img)
    {
        using std::vector;
        vector<vector<cv::Point>> contours;
        vector<cv::Vec4i> hierarchy;
        cv::findContours(binary_img, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

        return vector<Ellipse>();
    }
} // namespace rm_rune_detector
