#pragma once

#include "gh/Param.h"

#include <SM_Vector.h>
#include <SM_Plane.h>

#include <string>
#include <vector>

namespace gh
{

//////////////////////////////////////////////////////////////////////////
// geometry
//////////////////////////////////////////////////////////////////////////

class PointParam : public Param
{
public:
    explicit PointParam(const std::vector<sm::vec3>& points)
        : m_points(points) {}

    virtual ParamType Type() const override {
        return ParamType::Point;
    }

    auto& GetPoints() const { return m_points; }

private:
    std::vector<sm::vec3> m_points;

}; // PointParam

class VectorParam : public Param
{
public:
    explicit VectorParam(const std::vector<sm::vec3>& vectors)
        : m_vectors(vectors) {}

    virtual ParamType Type() const override {
        return ParamType::Vector;
    }

    auto& GetVectors() const { return m_vectors; }

private:
    std::vector<sm::vec3> m_vectors;

}; // VectorParam

class CircleParam : public Param
{
public:
    struct Circle
    {
        sm::vec3 center;
        sm::vec3 normal;
        float    radius = 1.0f;
    };

public:
    explicit CircleParam(const std::vector<Circle>& circles)
        : m_circles(circles) {}

    virtual ParamType Type() const override {
        return ParamType::Circle;
    }

    auto& GetCircles() const { return m_circles; }

private:
    std::vector<Circle> m_circles;

}; // CircleParam

class LineParam : public Param
{
public:
    struct Line
    {
        sm::vec3 begin;
        sm::vec3 end;
    };

public:
    explicit LineParam(const std::vector<Line>& lines)
        : m_lines(lines) {}

    virtual ParamType Type() const override {
        return ParamType::Line;
    }

    auto& GetLines() const { return m_lines; }

private:
    std::vector<Line> m_lines;

}; // LineParam

class PlaneParam : public Param
{
public:
    explicit PlaneParam(const std::vector<sm::Plane>& planes)
        : m_planes(planes) {}

    virtual ParamType Type() const override {
        return ParamType::Plane;
    }

    auto& GetPlanes() const { return m_planes; }

private:
    std::vector<sm::Plane> m_planes;

}; // PlaneParam

//////////////////////////////////////////////////////////////////////////
// primitive
//////////////////////////////////////////////////////////////////////////

class BooleanParam : public Param
{
public:
    explicit BooleanParam(const std::vector<bool>& values)
        : m_values(values) {}

    virtual ParamType Type() const override {
        return ParamType::Boolean;
    }

    auto& GetValues() const { return m_values; }

private:
    std::vector<bool> m_values;

}; // BooleanParam

class IntegerParam : public Param
{
public:
    explicit IntegerParam(const std::vector<int>& values)
        : m_values(values) {}

    virtual ParamType Type() const override {
        return ParamType::Integer;
    }

    auto& GetValues() const { return m_values; }

private:
    std::vector<int> m_values;

}; // IntegerParam

class NumberParam : public Param
{
public:
    explicit NumberParam(const std::vector<float>& values)
        : m_values(values) {}

    virtual ParamType Type() const override {
        return ParamType::Number;
    }

    auto& GetValues() const { return m_values; }

private:
    std::vector<float> m_values;

}; // NumberParam

//bool check_bool(const std::shared_ptr<Param>& var);
//float check_float(const std::shared_ptr<Param>& var);
//std::string check_string(const std::shared_ptr<Param>& var);

}