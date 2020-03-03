#pragma once

#include "geograph/ParamType.h"
#include "geograph/typedef.h"

#include <dag/Node.h>

namespace geograph
{

class Component : public dag::Node<ParamType>
{
public:
    Component(size_t out_num) { m_vals.resize(out_num); }

    virtual void Execute() = 0;

    ParamPtr GetValue(size_t idx) const {
        return idx < m_vals.size() ? m_vals[idx] : nullptr;
    }

protected:
    std::vector<ParamPtr> m_vals;

    RTTR_ENABLE(dag::Node<ParamType>)

}; // Component

}