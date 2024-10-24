#ifndef INDUSTRIALCREATOR_H
#define INDUSTRIALCREATOR_H

#include "BuildingCreator.h"
#include <string>
using namespace std;

class IndustrialCreator : public BuildingCreator {

public:
	IndustrialCreator();
protected:
	Building* createBuilding(string name, int satisfaction, double economicImpact, double resourceConsumption, bool constructionStatus, int improvementLevel, bool resourcesAvailable, int notificationRadius);
};

#endif
