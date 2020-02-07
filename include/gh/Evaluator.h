#pragma once

#include "gh/typedef.h"
#include "gh/ParamType.h"

#include <dag/Node.h>

#include <map>

namespace gh
{

class Evaluator
{
public:
    // update comp
    void ComponentChaged(const CompPtr& comp);

    // update devices
    void AddComponent(const CompPtr& comp);
    void RemoveComponent(const CompPtr& comp);
    void ClearAllComponents();

    // update comp prop
    void PropChanged(const CompPtr& comp);

    // update comp conn
    void Connect(const dag::Node<ParamType>::PortAddr& from, const dag::Node<ParamType>::PortAddr& to);
    void Disconnect(const dag::Node<ParamType>::PortAddr& from, const dag::Node<ParamType>::PortAddr& to);
    void RebuildConnections(const std::vector<std::pair<dag::Node<ParamType>::PortAddr, dag::Node<ParamType>::PortAddr>>& conns);

    void MakeDirty();

    void Update();

    auto& GetAllComps() const { return m_comp_map; }

private:
    std::map<std::string, CompPtr> m_comp_map;

    bool m_dirty = false;

    size_t m_next_id = 0;

}; // Evaluator

}