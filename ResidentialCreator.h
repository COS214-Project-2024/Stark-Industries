#ifndef RESIDENTIALCREATOR_H
#define RESIDENTIALCREATOR_H

#include "BuildingCreator.h"
#include <string>
using namespace std;

class ResidentialCreator : public BuildingCreator {


protected:
	Building* createBuilding();
};

#endif
