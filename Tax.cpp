#include "Tax.h"
#include <iostream>

Tax::Tax(const std::string& name, float initialTaxRate)
    : Department(name), totalRevenue(0.0), taxRate(initialTaxRate) {}

void Tax::setTaxRate(float rate) {
    taxRate = rate;
}

float Tax::getTaxRate() const {
    return taxRate;
}

void Tax::trackRevenue(double revenue) {
    totalRevenue += revenue;
    std::cout << "Tracked revenue: " << revenue << ". Total revenue: " << totalRevenue << "\n";
}

void Tax::operate() {
    std::cout << "Operating Tax Department: Current Tax Rate = " << taxRate 
              << ", Total Revenue = " << totalRevenue << "\n";
}
