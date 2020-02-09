#ifndef EXE_FILEPATH
#error "You must define EXE_FILEPATH macro before include this file"
#endif

// params

#define NAMESPACE_PARAM

#define PARM_COMP_CLASS Point
#define PARM_COMP_NAME point
#include EXE_FILEPATH

#undef NAMESPACE_PARAM

// curve

#define PARM_COMP_CLASS Line
#define PARM_COMP_NAME line
#include EXE_FILEPATH
