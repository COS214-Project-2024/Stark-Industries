#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

#include "Building.h"
#include <string>
using namespace std;

class Residential : public Building {


public:
	string getType();

	int calculateSatisfaction();

	double calculateEconomicImpact();

	double calculateResourceConsumption();

	bool constructionComplete();

	void doImprovments();

	void checkReasourceAvailability();

	void notifyCitizens();

	//command functions
	void performAction(int type);
	//visitor functions
	void payTax(float taxRate);
};

#endif
