#define EXE_FILEPATH "geograph/comp_include_gen.h"
#include "geograph/comp_regist_cfg.h"
#undef EXE_FILEPATH

#include <rttr/registration>

RTTR_REGISTRATION
{

// base

rttr::registration::class_<dag::Node<geograph::ParamType>::Port>("geograph::Component::Port")
	.property("var", &dag::Node<geograph::ParamType>::Port::var)
;

rttr::registration::class_<geograph::Component>("geograph::Component")
	.method("GetImports", &geograph::Component::GetImports)
	.method("GetExports", &geograph::Component::GetExports)
;

#define EXE_FILEPATH "geograph/comp_rttr_gen.h"
#include "geograph/comp_regist_cfg.h"
#undef EXE_FILEPATH

}

namespace geograph
{

void regist_rttr()
{
}

}