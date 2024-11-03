#ifndef POPULATION_H
#define POPULATION_H

#include "City.h"

#include "GrowthHandler.h"
#include <string>
using namespace std;

class Population : public GrowthHandler {

public:
	double populationGrowthRate;

	Population(double rate);

	void handleRequest(int growthFactor, City* city);
};

#endif
