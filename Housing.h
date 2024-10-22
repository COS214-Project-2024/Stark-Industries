#ifndef HOUSING_H
#define HOUSING_H

#include "GrowthHandler.h"
#include <string>
using namespace std;

class Housing : public GrowthHandler {

private:
	int housingCapacity;
	int housingDemand;

public:
	Housing(int capacity, int demand);

	void handleRequest();
};

#endif
