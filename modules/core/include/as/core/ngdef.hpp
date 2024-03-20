#ifndef _AS_CORE_NG_DEF_HPP_
#define _AS_CORE_NG_DEF_HPP_

#include <string>
#include "as/core/def.h"

namespace as
{
    enum class SPI_NG
    {
        Bridge,         // 连桥
        Insufficient,   // 少锡
        Excessive,      // 多锡
        Shape,          // 形状不良
        Position,       // 位置不良
        GoldTab,        // 金手指
        UpperHeight,    // 超过高度上界
        LowerHeight,    // 低于高度下界
        HighArea,       // 超过面积上界
        LowArea,        // 低于面积下界
        Coplanarity,    // 共面性
        Smear           // 污渍
    };

    std::string SPI_NG2Name(SPI_NG _ng)
    {
        std::string ng_name;
        switch (_ng)
        {
        case SPI_NG::Bridge:
        {    
            ng_name = "Bridge";
            break;
        }
        case SPI_NG::Insufficient:
        {
            ng_name = "Bridge";
            break;
        }
        case SPI_NG::Excessive:
        {
            ng_name = "Excessive";
            break;
        }
        case SPI_NG::Shape:
        {
            ng_name = "Shape";
            break;
        }
        case SPI_NG::Position:
        {
            ng_name = "Position";
            break;
        }
        case SPI_NG::GoldTab:
        {
            ng_name = "GoldTab";
            break;
        }
        case SPI_NG::UpperHeight:
        {
            ng_name = "UpperHeight";
            break;
        }
        case SPI_NG::LowerHeight:
        {
            ng_name = "LowerHeight";
            break;
        }
        case SPI_NG::HighArea:
        {
            ng_name = "HighArea";
            break;
        }
        case SPI_NG::LowArea:
        {
            ng_name = "LowArea";
            break;
        }
        case SPI_NG::Coplanarity:
        {
            ng_name = "Coplanarity";
            break;
        }
        case SPI_NG::Smear:
        {
            ng_name = "Smear";
            break;
        }
        default:
            ng_name = "";
            break;
        }
        return ng_name;
    }
} // namespace as


#endif // _AS_CORE_NG_DEF_HPP_