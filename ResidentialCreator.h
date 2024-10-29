#ifndef RESIDENTIALCREATOR_H
#define RESIDENTIALCREATOR_H

#include "BuildingCreator.h"
#include <string>
using namespace std;

class ResidentialCreator : public BuildingCreator {

public:
	ResidentialCreator();
public: //Should be protected
	Building* createBuilding(string name, int satisfaction, double economicImpact, double resourceConsumption, bool constructionStatus, int improvementLevel, bool resourcesAvailable, int notificationRadius);
};

#endif
