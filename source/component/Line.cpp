#include "geograph/component/Line.h"
#include "geograph/CompHelper.h"
#include "geograph/ParamImpl.h"

namespace geograph
{
namespace comp
{

void Line::Execute(const std::shared_ptr<dag::Context>& ctx)
{
    auto a = CompHelper::GetInputParam(*this, static_cast<size_t>(InputID::A));
    auto b = CompHelper::GetInputParam(*this, static_cast<size_t>(InputID::B));
    if (a && b)
    {
        assert(a->Type() == ParamType::Point
            && b->Type() == ParamType::Point);
        auto& a_pts = std::static_pointer_cast<PointParam>(a)->GetPoints();
        auto& b_pts = std::static_pointer_cast<PointParam>(b)->GetPoints();
        m_vals[static_cast<size_t>(OutputID::L)] = BuildLineParam(a_pts, b_pts);
    }
    else if (a)
    {
        assert(a->Type() == ParamType::Point);
        auto& a_pts = std::static_pointer_cast<PointParam>(a)->GetPoints();
        m_vals[static_cast<size_t>(OutputID::L)] = BuildLineParam(a_pts, m_pts1);
    }
    else if (b)
    {
        assert(b->Type() == ParamType::Point);
        auto& b_pts = std::static_pointer_cast<PointParam>(b)->GetPoints();
        m_vals[static_cast<size_t>(OutputID::L)] = BuildLineParam(m_pts0, b_pts);
    }
    else
    {
        m_vals[static_cast<size_t>(OutputID::L)] = BuildLineParam(m_pts0, m_pts1);
    }
}

ParamPtr Line::BuildLineParam(const std::vector<sm::vec3>& a_pts,
                              const std::vector<sm::vec3>& b_pts)
{
    std::vector<LineParam::Line> lines;
    if (a_pts.empty() || b_pts.empty()) {
        return std::make_shared<LineParam>(lines);
    }

    size_t num = std::min(a_pts.size(), b_pts.size());
    for (size_t i = 0; i < num; ++i) {
        lines.push_back({ a_pts[i], b_pts[i] });
    }
    for (size_t i = num, n = a_pts.size(); i < n; ++i) {
        lines.push_back({ a_pts[i], b_pts[num - 1] });
    }
    for (size_t i = num, n = b_pts.size(); i < n; ++i) {
        lines.push_back({ a_pts[num - 1], b_pts[i] });
    }
    return std::make_shared<LineParam>(lines);
}

}
}