#ifndef LANDMARKCREATOR_H
#define LANDMARKCREATOR_H

#include "BuildingCreator.h"
#include <string>
using namespace std;

class LandmarkCreator : public BuildingCreator {

public:
	LandmarkCreator();
public: //Should be protected
	Building* createBuilding(string name, int satisfaction, double economicImpact, double resourceConsumption, bool constructionStatus, int improvementLevel, bool resourcesAvailable, int notificationRadius);
};

#endif
