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
	Tax(const std::string& name, float initialTaxRate);
	void setTaxRate(float rate);
	float getTaxRate() const;
	void trackRevenue(double revenue);
	void operate() override;
};

#endif
