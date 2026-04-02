/**
  ****************************(C) COPYRIGHT 2023 Polarbear*************************
  * @file       rune.hpp
  * @brief      用于能量机关的相关描述
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

#ifndef RUNE_DETECTOR__ARMOR_HPP_
#define RUNE_DETECTOR__ARMOR_HPP_

#include <opencv2/core.hpp>

// STL
#include <string>

/**
 * @brief 包含了与符文检测相关的结构体和枚举类型的命名空间
 */
namespace rm_rune_detector
{

    /**
     * @brief 靶标状态的类型枚举类
     */
    enum class TargetType
    {
        DISACTIVED, /* 未激活的目标 */
        ACTIVED,    /* 激活的目标 */
        INVALID     /* 无效的目标 */
    };

    const int RED = 0;  /* 红色 */
    const int BLUE = 1; /* 蓝色 */

    const std::string ARMOR_TYPE_STR[3] = {"disactived", "actived", "invalid"}; /* 靶标类型的字符串表示 */

    /**
     * @brief 符文检测中的椭圆结构体，继承自cv::RotatedRect
     */
    struct Ellipse : public cv::RotatedRect
    {
        /**
         * @brief 默认构造函数
         */
        Ellipse() = default;

        /**
         * @brief 构造函数，根据给定的旋转矩形构造椭圆
         * @param box 给定的旋转矩形
         */
        explicit Ellipse(cv::RotatedRect box) : cv::RotatedRect(box)
        {
            // 获取椭圆的主轴和副轴的长度
            major_axis = std::max(box.size.width, box.size.height);
            minor_axis = std::min(box.size.width, box.size.height);
        }

        float major_axis; /* 椭圆的主轴长度 */
        float minor_axis; /* 椭圆的副轴长度 */
        int color;        /* 椭圆的颜色 */
    };

    /**
     * @brief 能量机关检测中的靶标结构体
     */
    struct Target
    {
        /**
         * @brief 默认构造函数
         */
        Target() = default;

        /**
         * @brief 构造函数，根据给定的椭圆构造目标
         * @param ellipse 给定的椭圆
         */
        Target(Ellipse &ellipse)
        {
            target_ellipse = ellipse;
        }

        Ellipse target_ellipse; /* 目标的椭圆 */
        TargetType type;        /* 目标的类型 */
    };
} // namespace rm_rune_detector

#endif // RUNE_DETECTOR__ARMOR_HPP_