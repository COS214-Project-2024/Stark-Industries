// Infrastructure.h
#ifndef INFRASTRUCTURE_H
#define INFRASTRUCTURE_H

#include "GrowthHandler.h"
#include "Commercial.h"
#include "Industrial.h"
#include "Landmark.h"
#include "City.h"
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
    void handleRequest(int growthFactor, City* city);
    void increaseRoads(int numLanes, double roadLength);
    void increaseCommercial(int growthFactor, Commercial* prototypeC, City* city);
    void increaseIndustrial(int growthFactor, Industrial* prototypeI, City* city);
    void increaseLandmark(int growthFactor, Landmark* prototypeL, City* city);
};

#endif // INFRASTRUCTURE_H
