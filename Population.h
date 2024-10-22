#ifndef POPULATION_H
#define POPULATION_H

#include "GrowthHandler.h"
#include <string>
using namespace std;

class Population : public GrowthHandler {

public:
	int populationGrowthRate;

	Population(int rate);

	void handleRequest();
};

#endif
