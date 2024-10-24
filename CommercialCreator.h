#ifndef COMMERCIALCREATOR_H
#define COMMERCIALCREATOR_H

#include "BuildingCreator.h"
#include <string>
using namespace std;

class CommercialCreator : public BuildingCreator {

public:
	CommercialCreator();
protected:
	Building* createBuilding(string name, int satisfaction, double economicImpact, double resourceConsumption, bool constructionStatus, int improvementLevel, bool resourcesAvailable, int notificationRadius);
};

#endif
