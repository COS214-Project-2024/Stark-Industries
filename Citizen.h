#ifndef CITIZEN_H
#define CITIZEN_H

#include "CitizenPrototype.h"
// #include "Building.h"
#include <string>
#include "Visitor.h"
using namespace std;


class Citizen : CitizenPrototype {

private:
	// Building* observerList; //Building is abstract
	string name;
	double income;
	double propertyValue;
	double commuteTime;
	int isSatisfiedTrans;
	bool hasPaid;
	double taxRate = 0.15;

public:
	void get();
	void set();
	CitizenPrototype* clone();
	void observerUpdate();
	int calculateSatisfaction();
	void requestBuilding(int City_city, int String_buildtype);
	void recieveMoveinDate();
	void choseTransport(int Transport_trans);
	void requestUtilitieService();
	void getPaid(double income);
	Citizen(string name, double baseIncome);
	string getName();
	//command functions
	void performAction(int type);
	//visitor functions
	void payTax();
	void setTaxRate();
	double taxPaid;
	virtual void acceptTaxCollector(Visitor * taxCollector);

};

#endif
