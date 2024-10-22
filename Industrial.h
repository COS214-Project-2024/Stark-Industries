#ifndef INDUSTRIAL_H
#define INDUSTRIAL_H

#include "Building.h"
#include <string>
using namespace std;

class Industrial : public Building {


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
