#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include "Department.h"
#include "Citizen.h"
#include <string>
#include <vector>
using namespace std;

class Government : public Department {

private:
	double incomeTaxRate;
	double propertyTaxRate;
	std::vector<Department*> departments;

public:
    Government(double incomeTaxRate = 0.0, double propertyTaxRate = 0.0);

    void add(Department* department) override;
    void remove(Department* department) override;
    Department* getChild(int index) override;

    void operate() override;

    void notifyCitizensTaxIncreased(); //delegate to Command
};

#endif
