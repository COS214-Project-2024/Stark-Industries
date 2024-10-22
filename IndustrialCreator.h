#ifndef INDUSTRIALCREATOR_H
#define INDUSTRIALCREATOR_H

#include "BuildingCreator.h"
#include <string>
using namespace std;

class IndustrialCreator : public BuildingCreator {


protected:
	Building* createBuilding();
};

#endif
