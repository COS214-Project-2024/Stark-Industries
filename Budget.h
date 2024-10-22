#ifndef BUDGET_H
#define BUDGET_H

#include "Department.h"
#include <string>
using namespace std;

class Budget : public Department {

private:
	double totalBudget;
	double allocatedBudget;

public:
	void operate();

	void allocateFunds(double amount);
};

#endif
