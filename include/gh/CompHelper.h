#pragma once

#include "gh/typedef.h"

namespace gh
{

class CompHelper
{
public:
    static CompPtr GetInputComp(const Component& comp, size_t idx);
    static ParamPtr  GetInputParam(const Component& comp, size_t idx);

}; // CompHelper

}