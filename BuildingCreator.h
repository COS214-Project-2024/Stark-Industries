#ifndef BUILDINGCREATOR_H
#define BUILDINGCREATOR_H

#include "Building.h"
#include <string>
using namespace std;

class BuildingCreator {

protected:
	Building* buildings;

public:
	void create();

protected:
	virtual Building* createBuilding() = 0;
};

#endif
