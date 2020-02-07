//#pragma once
//
//#include "gh/Component.h"
//
//#include <SM_Vector.h>
//
//namespace gh
//{
//namespace comp
//{
//
//class CircleCNR : public Component
//{
//public:
//    enum class InputID
//    {
//        C = 0,
//        N,
//        R,
//    };
//
//    enum class OutputID
//    {
//        C = 0,
//    };
//
//public:
//    CircleCNR()
//        : Component(1)
//    {
//        m_imports = {
//            {{ ParamType::Point,  "Center", "C" }}, // Center point
//            {{ ParamType::Vector, "Normal", "N" }}, // Normal vector of circle plane
//            {{ ParamType::Number, "Radius", "R" }}, // Radius of circle
//        };
//        m_exports = {
//            {{ ParamType::Circle, "Circle", "C" }}, // Resulting circle
//        };
//    }
//
//    virtual void Execute() override;
//
//private:
//    static ParamPtr BuildCircleParam(
//        const std::vector<sm::vec3>& centers,
//        const std::vector<sm::vec3>& normals,
//        const std::vector<float>& radius
//    );
//
//    RTTR_ENABLE(Component)
//
//#define PARM_FILEPATH "gh/component/CircleCNR.parm.h"
//#include <dag/node_parms_gen.h>
//#undef PARM_FILEPATH
//
//}; // CircleCNR
//
//}
//}