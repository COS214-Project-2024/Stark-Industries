#ifndef BUDGET_H
#define BUDGET_H

#include "Department.h"
#include <string>
#include <iostream>
using namespace std;

class Budget : public Department {

private:
	double totalBudget;
	double allocatedBudget;

public:
	void operate();
	std::string name = "Budget";
	void allocateFunds();
	void receiveTax(double tax);
};

#endif
