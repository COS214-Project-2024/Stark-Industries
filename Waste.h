#ifndef WASTE_H
#define WASTE_H

#include "Utilities.h"
#include <string>
using namespace std;

class Waste : public Utilities {

private:
	string name;
	double capacity;
	double operationalCost;

public:

	 // Constructor to initialize Waste specifics
    Waste(string name, double capacity, double operationalCost);
		
	void displayInfo();

	void generateResources();

	void requestMaintenance(int Utilities_util);
};

#endif
