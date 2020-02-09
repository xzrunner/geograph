#define EXE_FILEPATH "gh/comp_include_gen.h"
#include "gh/comp_regist_cfg.h"
#undef EXE_FILEPATH

#include <rttr/registration>

RTTR_REGISTRATION
{

// base

rttr::registration::class_<dag::Node<gh::ParamType>::Port>("gh::Component::Port")
	.property("var", &dag::Node<gh::ParamType>::Port::var)
;

rttr::registration::class_<gh::Component>("gh::Component")
	.method("GetImports", &gh::Component::GetImports)
	.method("GetExports", &gh::Component::GetExports)
;

#define EXE_FILEPATH "gh/comp_rttr_gen.h"
#include "gh/comp_regist_cfg.h"
#undef EXE_FILEPATH

}

namespace gh
{

void regist_rttr()
{
}

}