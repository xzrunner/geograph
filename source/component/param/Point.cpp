#include "gh/component/param/Point.h"
#include "gh/CompHelper.h"
#include "gh/ParamImpl.h"

namespace gh
{
namespace comp
{
namespace param
{

void Point::Execute()
{
    auto in = CompHelper::GetInputParam(*this, 0);
    if (in)
    {
        assert(in->Type() == ParamType::Point);
        m_vals[0] = std::make_shared<PointParam>(
            *std::static_pointer_cast<PointParam>(in)
        );
    }
    else
    {
        m_vals[0] = std::make_shared<PointParam>(m_pts);
    }
}

}
}
}