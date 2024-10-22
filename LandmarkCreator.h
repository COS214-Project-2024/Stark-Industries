#ifndef LANDMARKCREATOR_H
#define LANDMARKCREATOR_H

#include "BuildingCreator.h"
#include <string>
using namespace std;

class LandmarkCreator : public BuildingCreator {


protected:
	Building* createBuilding();
};

#endif
