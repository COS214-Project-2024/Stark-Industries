#include "Government.h"
#include <iostream>
#include <algorithm>
#include <vector>

Government::Government(double incomeTaxRate, double propertyTaxRate)
    : Department("Government"), incomeTaxRate(incomeTaxRate), propertyTaxRate(propertyTaxRate) {}

void Government::add(Department* department) {
    departments.push_back(department);
}

void Government::remove(Department* department) {
    auto it = std::remove(departments.begin(), departments.end(), department);
    if (it != departments.end()) {
        departments.erase(it, departments.end()); 
    }
}


Department* Government::getChild(int index) {
    if (index >= 0 && index < departments.size()) {
        return departments[index];
    }
    return nullptr;
}

void Government::operate() {
    std::cout << "Government is operating and managing departments.\n";
    for (Department* dep : departments) {
        dep->operate(); 
    }
}

// Notify citizens about tax changes (delegated to Command)
void Government::notifyCitizensTaxIncreased() {
    std::cout << "Notifying citizens: Taxes have been increased.\n";
}
