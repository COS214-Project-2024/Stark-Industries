#ifndef SERVICES_H
#define SERVICES_H

#include "Department.h"
#include <string>
using namespace std;

class Services : public Department {

private:
	int healthcareFacilities;
	int educationalInstitutions;

	int emergencyResponseUnits;

public:
	void operate();

	void addServiceProgram(std::string program);
};

#endif
