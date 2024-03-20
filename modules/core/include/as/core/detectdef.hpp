#ifndef _AS_CORE_DETECT_DEF_HPP_
#define _AS_CORE_DETECT_DEF_HPP_

#include "as/core/def.h"
#include "as/core/ngdef.hpp"

namespace as
{
    // 检测项：体积；参数单位：百分比
    struct SPI_VOLUME_PARAM
    {
        double ErrInstPct;         // 少锡错误阈值
        double WarnInstPct;        // 少锡警告阈值,使用呢时应注意，Warning参数为相对Err参数的基础上进行加减得到,实际为ErrInst到ErrInst+WarnInst
        double ErrExcvPct;         // 多锡错误阈值
        double WarnExcvPct;        // 多锡警告阈值,使用呢时应注意，Warning参数为相对Err参数的基础上进行加减得到,实际为ErrExcv到ErrExcv-WarnExcv
        bool Detect;            // 是否进行检测

        SPI_VOLUME_PARAM()
        {
            ErrInstPct = 0.5;
            WarnInstPct = 0.2;
            ErrExcvPct = 1.7;
            WarnExcvPct = 0.2;
            Detect = false;
        }
    };

    // 检测项：位置偏移；参数单位：mm
    struct SPI_POSITION_PARAM
    {
        double ErrX;            // X方向偏移错误阈值
        double ErrY;            // Y方向偏移错误阈值
        double Warn;            // 预警量
        bool Detect;            // 是否进行检测

        SPI_POSITION_PARAM()
        {
            ErrX = 0.5;
            ErrY = 0.5;
            Warn = 0.01;
            Detect = false;
        }
    };

    // 检测项：位置偏移；参数单位：um
    struct SPI_BRIDGE_PARAM
    {
        double ErrH;            // 高度错误阈值
        double ErrDist;         // 距离错误阈值
        bool Detect;            // 是否进行检测

        SPI_BRIDGE_PARAM()
        {
            ErrH = 80;
            ErrDist = 300;
            Detect = false;
        }
    };

    // 检测项：位置偏移；参数单位：um
    struct SPI_HEIGHT_PARAM
    {
        double ErrLowerH;       // 高度下限错误阈值
        double ErrUpperH;       // 高度上限错误阈值
        double Warn;            // 预警量
        bool Detect;            // 是否进行检测

        SPI_HEIGHT_PARAM()
        {
            ErrLowerH = 50;
            ErrUpperH = 250;
            Warn = 20;
            Detect = false;
        }
    };

    // 检测项：形状；参数单位：um
    struct SPI_SHAPE_PARAM
    {
        double Balance;         // 容差阈值
        bool Detect;            // 是否进行检测

        SPI_SHAPE_PARAM()
        {
            Balance = 180;
            Detect = false;
        }
    };

    // 检测项：面积；参数单位：百分比
    struct SPI_AREA_PARAM
    {
        double ErrMinAreaPct;   // 最小面积百分比
        double ErrMaxAreaPct;   // 最大面积百分比
        bool Detect;            // 是否进行检测

        SPI_AREA_PARAM()
        {
            ErrMinAreaPct = 0.5;
            ErrMaxAreaPct = 2.0;
            Detect = false;
        }
    };

     // 检测项：共面性；参数单位：百分比
    struct SPI_COPLANARITY_PARAM
    {
        double ErrVoluePct;
        double WarnVoluePct;
        double ErrPosPct;
        double WarnPosPct;
        bool Detect;

        SPI_COPLANARITY_PARAM()
        {
            ErrVoluePct = 0.2;
            WarnVoluePct = 0.04;
            ErrPosPct = 0.1;
            WarnPosPct = 0.02;
            Detect = false;
        }
    };

} // namespace as


#endif // _AS_CORE_DETECT_DEF_HPP_