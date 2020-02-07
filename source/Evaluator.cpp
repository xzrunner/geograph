#include "gh/Evaluator.h"
#include "gh/Component.h"
#include "gh/typedef.h"

#include <dag/Evaluator.h>

namespace gh
{

void Evaluator::ComponentChaged(const CompPtr& comp)
{
    dag::Evaluator::SetTreeDirty<ParamType>(comp);

    m_dirty = true;
}

void Evaluator::AddComponent(const CompPtr& comp)
{
    auto name = comp->GetName();
    while (name.empty() || m_comp_map.find(name) != m_comp_map.end())
    {
        if (comp->GetName().empty()) {
            name = "comp" + std::to_string(m_next_id++);
        } else {
            name = comp->GetName() + std::to_string(m_next_id++);
        }
    }
    comp->SetName(name);

    m_comp_map.insert({ name, comp });

    m_dirty = true;
}

void Evaluator::RemoveComponent(const CompPtr& comp)
{
    if (m_comp_map.empty()) {
        return;
    }

    auto itr = m_comp_map.find(comp->GetName());
    if (itr == m_comp_map.end()) {
        return;
    }

    dag::Evaluator::SetTreeDirty<ParamType>(comp);

    m_comp_map.erase(itr);

    m_dirty = true;
}

void Evaluator::ClearAllComponents()
{
    if (m_comp_map.empty()) {
        return;
    }

    m_comp_map.clear();

    m_dirty = true;
}

void Evaluator::PropChanged(const CompPtr& comp)
{
    dag::Evaluator::SetTreeDirty<ParamType>(comp);

    m_dirty = true;
}

void Evaluator::Connect(const dag::Node<ParamType>::PortAddr& from, const dag::Node<ParamType>::PortAddr& to)
{
    dag::make_connecting<ParamType>(from, to);

    auto comp = to.node.lock();
    assert(comp && comp->get_type().is_derived_from<Component>());
    dag::Evaluator::SetTreeDirty<ParamType>(std::static_pointer_cast<Component>(comp));

    m_dirty = true;
}

void Evaluator::Disconnect(const dag::Node<ParamType>::PortAddr& from, const dag::Node<ParamType>::PortAddr& to)
{
    dag::disconnect<ParamType>(from, to);

    auto comp = to.node.lock();
    assert(comp && comp->get_type().is_derived_from<Component>());
    dag::Evaluator::SetTreeDirty<ParamType>(std::static_pointer_cast<Component>(comp));

    m_dirty = true;
}

void Evaluator::RebuildConnections(const std::vector<std::pair<dag::Node<ParamType>::PortAddr, dag::Node<ParamType>::PortAddr>>& conns)
{
    // update dirty
    for (auto itr : m_comp_map) {
        if (dag::Evaluator::HasNodeConns<ParamType>(itr.second)) {
            dag::Evaluator::SetTreeDirty<ParamType>(itr.second);
        }
    }

    // remove conns
    for (auto itr : m_comp_map) {
        itr.second->ClearConnections();
    }

    // add conns
    for (auto& conn : conns)
    {
        auto comp = conn.second.node.lock();
        assert(comp && comp->get_type().is_derived_from<Component>());
        dag::Evaluator::SetTreeDirty<ParamType>(std::static_pointer_cast<Component>(comp));
        dag::make_connecting<ParamType>(conn.first, conn.second);
    }

    m_dirty = true;
}

void Evaluator::MakeDirty()
{
    m_dirty = true;

    for (auto& itr : m_comp_map) {
        itr.second->SetDirty(true);
    }
}

void Evaluator::Update()
{
    if (m_comp_map.empty()) {
        return;
    }

    std::vector<std::shared_ptr<dag::Node<ParamType>>> devices;
    devices.reserve(m_comp_map.size());
    for (auto itr : m_comp_map) {
        devices.push_back(itr.second);
    }
    auto sorted_idx = dag::Evaluator::TopologicalSorting(devices);

    for (auto& idx : sorted_idx)
    {
        auto comp = devices[idx];
        if (comp->IsDirty()) {
            std::static_pointer_cast<Component>(comp)->Execute();
            comp->SetDirty(false);
        }
    }
}

}