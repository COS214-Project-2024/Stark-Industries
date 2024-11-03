#ifndef ECONOMIC_H
#define ECONOMIC_H

#include "GrowthHandler.h"
#include "City.h"
#include <string>
using namespace std;

class Economic : public GrowthHandler {

private:
	double economicGrowthRate;

public:
	Economic(double growthRate);

	void handleRequest(int growthFactor, City* city);
};

#endif
