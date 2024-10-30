#ifndef SERVICES_H
#define SERVICES_H

#include "Department.h"
#include <string>
#include <vector>
using namespace std;

class Services : public Department {

private:
	int healthcareFacilities;
	int educationalInstitutions;
	int emergencyResponseUnits;
	std::vector<std::string> servicePrograms;

public:
 	Services(const std::string& name, int healthcare, int education, int emergencyUnits);
	std::string name = "Services";
	void operate() override;
 	void addServiceProgram(const std::string& program);
	virtual void execute();
	virtual void addCommand(Command* command);
	virtual void removeCommand(int i);
};

#endif
