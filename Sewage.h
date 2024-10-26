#ifndef SEWAGE_H
#define SEWAGE_H

#include "Utilities.h"
#include <string>
using namespace std;

class Sewage : public Utilities {

private:
	string name;
	double capacity;
	double operationalCost;

public:

	// Constructor to initialize Sewage specifics
    Sewage(string name, double capacity, double operationalCost);

	void displayInfo();

	void generateResources();

	void requestMaintenance(int Utilities_util);
};

#endif
