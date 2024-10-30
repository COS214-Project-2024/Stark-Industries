#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include "Department.h"
#include "Citizen.h"
#include "Visitor.h"
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
	Visitor* visitor;
	double taxCollected;

public:
    Government(double incomeTaxRate = 0.0, double propertyTaxRate = 0.0);

    void add(Department* department) override;
    void remove(Department* department) override;
    Department* getChild(int index) override;
	Government();
	
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
