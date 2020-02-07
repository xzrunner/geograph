#include "gh/GH.h"

namespace gh
{

CU_SINGLETON_DEFINITION(GH);

extern void regist_rttr();

GH::GH()
{
	regist_rttr();
}

}