// params
#include "gh/component/param/Point.h"
// curve
#include "gh/component/Line.h"

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

// params

rttr::registration::class_<gh::comp::param::Point>("gh::param_point")
.constructor<>()
#define PARM_FILEPATH "gh/component/param/Point.parm.h"
#define PARM_NODE_CLASS gh::comp::param::Point
#include <dag/rttr_prop_gen.h>
#undef PARM_NODE_CLASS
#undef PARM_FILEPATH
;

// curve

rttr::registration::class_<gh::comp::Line>("gh::line")
.constructor<>()
#define PARM_FILEPATH "gh/component/Line.parm.h"
#define PARM_NODE_CLASS gh::comp::Line
#include <dag/rttr_prop_gen.h>
#undef PARM_NODE_CLASS
#undef PARM_FILEPATH
;

}

namespace gh
{

void regist_rttr()
{
}

}