#ifndef SEWAGE_H
#define SEWAGE_H

#include "Utilities.h"
#include <string>
using namespace std;

class Sewage : Utilities {

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
