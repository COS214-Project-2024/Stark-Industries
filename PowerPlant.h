#ifndef POWERPLANT_H
#define POWERPLANT_H

#include "Utilities.h"
#include <string>
using namespace std;

class PowerPlant : public Utilities {

private:
	string name;
	double capacity;
	double operationalCost;

public:

	// Constructor to initialize PowerPlant specifics
    PowerPlant(string name, double capacity, double operationalCost);
	
	void displayInfo();

	void generateResources();

	void requestMaintenance(int Utilities_util);
};

#endif
