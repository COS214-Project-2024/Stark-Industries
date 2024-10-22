#ifndef WATER_H
#define WATER_H

#include "Utilities.h"
#include <string>
using namespace std;

class Water : public Utilities {

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
