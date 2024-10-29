#ifndef HOUSING_H
#define HOUSING_H

#include "GrowthHandler.h"
#include <string>
using namespace std;

class Housing : public GrowthHandler {

private:
	double rate;
	//int housingDemand;

public:
	Housing(double growthRate);

	void handleRequest(int growthFactor);
};

#endif
