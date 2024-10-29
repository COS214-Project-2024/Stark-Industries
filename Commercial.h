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

	void doImprovements();

	void checkReasourceAvailability();

	void notifyCitizens();

	//command functions
	void performAction(int type);
	//visitor functions
	void payTax(float taxRate);

private:
	float propertyTaxRate = 0.015;
	float salesTaxRate = 0.15;
};

#endif
