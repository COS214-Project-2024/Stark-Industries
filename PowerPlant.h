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
	void displayInfo();

	void generateResources();

	void requestMaintenance(int Utilities_util);
};

#endif
