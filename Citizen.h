#ifndef CITIZEN_H
#define CITIZEN_H

#include "CitizenPrototype.h"
// #include "Building.h"
#include <string>
using namespace std;

class Citizen : CitizenPrototype {

private:
	// Building* observerList; //Building is abstract
	string name;
	int income;
	double propertyValue;
	double commuteTime;
	int isSatisfiedTrans;
	bool hasPaid;
	double satisfaction;

public:

	Citizen(const std::string& name, int income, double propertyValue);

	void get();

	void set();

	CitizenPrototype* clone();

	int calculateSatisfaction();

	void taxPaid();

	void requestBuilding(int City_city, int String_buildtype);

	void recieveMoveinDate();

	void choseTransport(int Transport_trans);

	void requestUtilitiesService();

	//Observer
	void observerUpdate();
};

#endif
