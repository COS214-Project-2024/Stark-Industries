#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include "Department.h"
#include "Citizen.h"
#include "Visitor.h"
#include "Tax.h"
#include "Budget.h"
#include "Policies.h"
#include "Services.h"
#include <string>
#include <vector>
#include <vector>
using namespace std;

class Government : public Department {

private:
	double incomeTaxRate;
	double propertyTaxRate;
	Government* subjectState;
	std::vector<Department*> departments;
	Tax* taxDepartment = nullptr;
    Budget* budgetDepartment = nullptr;
    Policies* policiesDepartment = nullptr;
    Services* servicesDepartment = nullptr;
	Visitor* visitor;
	double taxCollected;

public:
    Government(double incomeTaxRate = 0.0, double propertyTaxRate = 0.0);

    void add(Department* department) override;
    void remove(Department* department) override;
    Department* getChild(int index) override;
	Government();

	Tax* getTaxDepartment() const { return taxDepartment; }
    Budget* getBudgetDepartment() const { return budgetDepartment; }
    Policies* getPoliciesDepartment() const { return policiesDepartment; }
    Services* getServicesDepartment() const { return servicesDepartment; }
	
	void increaseTax(int amount);

	void allocateTax();

	void collectTax();

	void get();

	void set();

	Government* getState();

	void setState();

    void operate() override;

    void notifyCitizensTaxIncreased(); //delegate to Command
	virtual void execute();
	virtual void addCommand(Command* command);
	virtual void removeCommand(int i);
};

#endif
