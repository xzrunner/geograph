#include "geograph/GeoGraph.h"

namespace geograph
{

CU_SINGLETON_DEFINITION(GeoGraph);

extern void regist_rttr();

GeoGraph::GeoGraph()
{
	regist_rttr();
}

}