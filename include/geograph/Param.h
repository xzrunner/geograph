#pragma once

#include "geograph/ParamType.h"

namespace geograph
{

class Param
{
public:
    virtual ParamType Type() const = 0;

}; // Param

}