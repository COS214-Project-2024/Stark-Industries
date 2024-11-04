#ifndef BUILDINGCREATOR_H
#define BUILDINGCREATOR_H

#include "Building.h"
#include <string>
using namespace std;

class BuildingCreator {

protected:
    Building* buildings;

public:
    virtual Building* createBuilding(string name, int satisfaction, double economicImpact, 
                                      double resourceConsumption, bool constructionStatus, 
                                      int improvementLevel, bool resourcesAvailable, 
                                      int capacity, string area) = 0;
    virtual ~BuildingCreator() = default;
};

#endif
