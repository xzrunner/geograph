#define XSTR(s) STR(s)
#define STR(s) #s

#ifndef PARM_COMP_CLASS
#error "You must define PARM_COMP_CLASS macro before include this file"
#endif

#ifndef PARM_COMP_NAME
#error "You must define PARM_COMP_NAME macro before include this file"
#endif

#ifndef PARM_FILEPATH_PARM
#ifdef NAMESPACE_PARAM
#define PARM_FILEPATH_PARM gh/component/param/##PARM_COMP_CLASS##.parm.h
#else
#define PARM_FILEPATH_PARM gh/component/##PARM_COMP_CLASS##.parm.h
#endif // NAMESPACE_PARAM
#endif // PARM_FILEPATH_PARM

#ifdef NAMESPACE_PARAM
#define RTTR_NAME "gh::param_"##XSTR(PARM_COMP_NAME)
#define PARM_NODE_CLASS gh::comp::param::##PARM_COMP_CLASS
#else
#define RTTR_NAME "gh::"##XSTR(PARM_COMP_NAME)
#define PARM_NODE_CLASS gh::comp::##PARM_COMP_CLASS
#endif // NAMESPACE_PARAM

rttr::registration::class_<PARM_NODE_CLASS>(RTTR_NAME)
.constructor<>()
#define PARM_FILEPATH XSTR(PARM_FILEPATH_PARM)
#include <dag/rttr_prop_gen.h>
#undef PARM_FILEPATH
;

#undef PARM_COMP_NAME
#undef PARM_COMP_CLASS
#undef PARM_FILEPATH_PARM
#undef RTTR_NAME
#undef PARM_NODE_CLASS
