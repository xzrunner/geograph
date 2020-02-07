#pragma once

#include "gh/ParamType.h"

namespace gh
{

class Param
{
public:
    virtual ParamType Type() const = 0;

}; // Param

}