#ifndef COMMERCIALCREATOR_H
#define COMMERCIALCREATOR_H

#include "BuildingCreator.h"
#include <string>
using namespace std;

class CommercialCreator : public BuildingCreator {


protected:
	Building* createBuilding();
};

#endif
