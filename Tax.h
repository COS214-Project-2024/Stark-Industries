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


	//command functions
	void execute();
	void addCommand(Command* command);
	void removeCommand(int i);
};

#endif
