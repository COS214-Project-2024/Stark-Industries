#ifndef TAX_H
#define TAX_H

#include "Department.h"
#include <string>
using namespace std;

class Tax : public Department {

private:
	double totalRevenue;
	float taxRate;
	string taxType;

public:
	Tax(double totalRevenue, float initialTaxRate, string taxType);
	void setTaxRate(float rate);
	float getTaxRate();
	void collectTaxes(double revenue);
	void operate();
	//getaxType
	string getTaxType();

	std::string name = "Tax";
	//command functions
	void execute();
	void addCommand(Command* command);
	void removeCommand(int i);
};

//order of commands is 0: Collect, 1: Increase

#endif
