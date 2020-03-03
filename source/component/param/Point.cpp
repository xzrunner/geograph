#include "geograph/component/param/Point.h"
#include "geograph/CompHelper.h"
#include "geograph/ParamImpl.h"

namespace geograph
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