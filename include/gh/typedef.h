#pragma once

#include <memory>

namespace gh
{

class Component;
using CompPtr = std::shared_ptr<Component>;

class Param;
using ParamPtr = std::shared_ptr<Param>;

}