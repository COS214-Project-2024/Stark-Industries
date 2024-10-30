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
	Budget(const std::string& name, double initialBudget);
	void operate() override;;
	double getAvailableBudget() const;
	void allocateFunds(double amount);
};

#endif
