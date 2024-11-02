// Infrastructure.h
#ifndef INFRASTRUCTURE_H
#define INFRASTRUCTURE_H

#include "GrowthHandler.h"
#include "Commercial.h"
#include "Industrial.h"
#include "Landmark.h"
#include <iostream>
using namespace std;

class Infrastructure : public GrowthHandler {
private:
    double growthRate;
    Commercial* prototypeC;
    Industrial* prototypeI;
    Landmark* prototypeL;

public:
    Infrastructure(double growthRate, Commercial* prototypeC, Industrial* prototypeI, Landmark* prototypeL);
    void handleRequest(int growthFactor);
    void increaseRoads(int numLanes, double roadLength);
    void increaseCommercial(int growthFactor, Commercial* prototypeC);
    void increaseIndustrial(int growthFactor, Industrial* prototypeI);
    void increaseLandmark(int growthFactor, Landmark* prototypeL);
    double getGrowthFactor();
};

#endif // INFRASTRUCTURE_H
