#pragma once

#include "geograph/Component.h"

#include <SM_Vector.h>

namespace geograph
{
namespace comp
{

class Line : public Component
{
public:
    enum class InputID
    {
        A = 0,
        B,
    };

    enum class OutputID
    {
        L = 0,
    };

public:
    Line()
        : Component(1)
    {
        m_imports = {
            {{ ParamType::Point, "Start Point", "A" }}, // Line start point
            {{ ParamType::Point, "End Point",   "B" }}, // Line end point
        };
        m_exports = {
            {{ ParamType::Line, "Line", "L" }},  // Line segment
        };
    }

    virtual void Execute(const std::shared_ptr<dag::Context>& ctx = nullptr) override;

private:
    static ParamPtr BuildLineParam(
        const std::vector<sm::vec3>& a_pts,
        const std::vector<sm::vec3>& b_pts
    );

    RTTR_ENABLE(Component)

#define PARM_FILEPATH "geograph/component/Line.parm.h"
#include <dag/node_parms_gen.h>
#undef PARM_FILEPATH

}; // Line

}
}