#ifndef TAX_H
#define TAX_H

#include "Department.h"
#include <string>
using namespace std;

class Tax : public Department {

private:
	double totalRevenue;
	float taxRate;

public:
	Tax(std:: string name, float initialTaxRate);

	void setTaxRate(float rate);

	float getTaxRate();

	void collectTaxes(double revenue);

	void operate();
};

#endif
