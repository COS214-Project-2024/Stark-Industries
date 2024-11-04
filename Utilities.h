#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
using namespace std;

class Utilities {

private:
	string name;
	double capacity;
	double operationalCost;

public:

	// Constructor for initializing utility details
    Utilities(string name, double capacity, double operationalCost)
        : name(name), capacity(capacity), operationalCost(operationalCost) {}


	virtual void generateResources() = 0;

	virtual void displayInfo() = 0;

	virtual void requestMaintenance(int Utilities_util) = 0;

	virtual ~Utilities() = default;  // Virtual destructor for cleanup

};

#endif
