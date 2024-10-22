#ifndef BUILDING_H
#define BUILDING_H

#include "Element.h"
#include "Utilities.h"
#include "Citizen.h"
#include <string>
#include <vector>
using namespace std;

class Building : public Element {

private:
	vector<Utilities*> utilities;
	Citizen* observerList;

public:
	Building();

	void get();

	void set();

	virtual string getType() = 0;

	virtual int calculateSatisfaction() = 0;

	virtual double calculateEconomicImpact() = 0;

	virtual double calculateResourceConsumption() = 0;

	virtual bool constructionComplete() = 0;

	virtual void doImprovemets() = 0;

	virtual void checkReasourceAvailability() = 0;

	virtual void notifyCitizens() = 0;
};

#endif
