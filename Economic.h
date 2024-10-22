#ifndef ECONOMIC_H
#define ECONOMIC_H

#include "GrowthHandler.h"
#include <string>
using namespace std;

class Economic : public GrowthHandler {

private:
	int jobCreationRate;
	double economicGrowthRate;

public:
	Economic(int jobs, double growthRate);

	void handleRequest();
};

#endif
