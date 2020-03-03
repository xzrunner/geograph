#pragma once

#include "geograph/typedef.h"

namespace geograph
{

class CompHelper
{
public:
    static CompPtr GetInputComp(const Component& comp, size_t idx);
    static ParamPtr  GetInputParam(const Component& comp, size_t idx);

}; // CompHelper

}