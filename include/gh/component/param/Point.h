#pragma once

#include "gh/Component.h"

#include <SM_Vector.h>

namespace gh
{
namespace comp
{
namespace param
{

class Point : public Component
{
public:
    Point()
        : Component(1)
    {
        m_imports = {
            {{ ParamType::Point, "in" }},
        };
        m_exports = {
            {{ ParamType::Point, "out" }},
        };
    }

    virtual void Execute() override;

    RTTR_ENABLE(Component)

#define PARM_FILEPATH "gh/component/param/Point.parm.h"
#include <dag/node_parms_gen.h>
#undef PARM_FILEPATH

}; // Point

}
}
}