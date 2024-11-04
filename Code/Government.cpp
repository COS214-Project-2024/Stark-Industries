#include "Government.h"
#include "Department.h"
#include <iostream>
#include <algorithm>
#include <vector>

Government::Government(double incomeTaxRate, double propertyTaxRate)
    : Department("Government"), incomeTaxRate(incomeTaxRate), propertyTaxRate(propertyTaxRate) {}

Government::Government() : Department() {

}

void Government::increaseTax(int amount) {
	// TODO - implement Government::increaseTax
	throw "Not yet implemented";
}

void Government::allocateTax() {
	for (int i = 0; i < departments.size(); i++) {
		if (departments[i]->name == "Budget"){
			departments[i]->receiveTax(taxCollected);
			break;
		}
	}
}

void Government::collectTax() {
    if (visitor != NULL)
    {
        taxCollected = visitor->taxCollected;
    }
}

void Government::get() {
	// TODO - implement Government::get
	throw "Not yet implemented";
}

void Government::set() {
	// TODO - implement Government::set
	throw "Not yet implemented";
}

Government* Government::getState() {
	// TODO - implement Government::getState
	throw "Not yet implemented";
}

void Government::setState() {
	// TODO - implement Government::setState
	throw "Not yet implemented";
}

void Government::add(Department* department) {
        departments.push_back(department);

        // Check the type of department being added and assign it to the specific pointer
        if (Tax* tax = dynamic_cast<Tax*>(department)) {
            taxDepartment = tax;
        } else if (Budget* budget = dynamic_cast<Budget*>(department)) {
            budgetDepartment = budget;
        } else if (Policies* policies = dynamic_cast<Policies*>(department)) {
            policiesDepartment = policies;
        } else if (Services* services = dynamic_cast<Services*>(department)) {
            servicesDepartment = services;
        }
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

void Government::execute() {
    //Do nothing
}

void Government::addCommand(Command* command) {
    //Do nothing
}

void Government::removeCommand(int i) {
    //Do nothing
}
