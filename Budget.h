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
	Budget(const std::string& name, double budget);
	void operate();
	std::string name = "Budget";
	void allocateFunds(double amount);
	void receiveTax(double tax);
	virtual void execute();
	virtual void addCommand(Command* command);
	virtual void removeCommand(int i);
	double getAvailableBudget() const;
};

#endif
