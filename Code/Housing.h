#ifndef HOUSING_H
#define HOUSING_H

#include "GrowthHandler.h"
#include "Residential.h"
#include <string>
using namespace std;

class Housing : public GrowthHandler {

private:
	double rate;
	Residential* prototype;
	//int housingDemand;

public:
	Housing(double growthRate, Residential* prototypeBuilding);

	void handleRequest(int growthFactor, City* city);

	double getGrowthFactor();
};

#endif
