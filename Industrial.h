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

	void doImprovements();

	void checkReasourceAvailability();

	void notifyCitizens();

	//command functions
	void performAction(int type);
	//visitor functions
	void payTax(float taxRate);

	void acceptTaxCollector(Visitor * taxCollector);

private: 
	float propertyTaxRate = 0.015;
};

#endif
