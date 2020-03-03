#pragma once

#include "geograph/Component.h"

#include <SM_Vector.h>

namespace geograph
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

    virtual void Execute(const std::shared_ptr<dag::Context>& ctx = nullptr) override;

    RTTR_ENABLE(Component)

#define PARM_FILEPATH "geograph/component/param/Point.parm.h"
#include <dag/node_parms_gen.h>
#undef PARM_FILEPATH

}; // Point

}
}
}