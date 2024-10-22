#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include "Building.h"
#include <string>
using namespace std;

class Commercial : public Building {


public:
	string getType();

	int calculateSatisfaction();

	double calculateEconomicImpact();

	double calculateResourceConsumption();

	bool constructionComplete();

	void doImprovments();

	void checkReasourceAvailability();

	void notifyCitizens();
};

#endif
