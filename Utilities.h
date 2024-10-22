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
	virtual void generateResources() = 0;

	virtual void displayInfo() = 0;

	virtual void requestMaintenance(int Utilities_util) = 0;
};

#endif
