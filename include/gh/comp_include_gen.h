#define XSTR(s) STR(s)
#define STR(s) #s

#ifndef PARM_COMP_CLASS
#error "You must define PARM_COMP_CLASS macro before include this file"
#endif

#ifndef PARM_FILEPATH_H
#ifdef NAMESPACE_PARAM
#define PARM_FILEPATH_H gh/component/param/##PARM_COMP_CLASS##.h
#else
#define PARM_FILEPATH_H gh/component/##PARM_COMP_CLASS##.h
#endif // NAMESPACE_PARAM
#endif // PARM_FILEPATH_H

#include XSTR(PARM_FILEPATH_H)

#undef PARM_COMP_NAME
#undef PARM_COMP_CLASS
#undef PARM_FILEPATH_H
