#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include "Department.h"
#include "Citizen.h"
#include <string>
using namespace std;

class Government : public Department {

private:
	double incomeTaxRate;
	double propertyTaxRate;
	Government* subjectState;

public:
	Government();
	
	void increaseTax(int amount);

	void allocateTax(string dep, double amount);

	void collectTax(Citizen citizen);

	void get();

	void set();

	Government* getState();

	void setState();

	void add(Department* department);

	void remove(Department* department);

	Department* getChild(int index);

	void operate();

	void notifyCitizensTaxIncreased();
};

#endif
