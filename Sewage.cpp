#include "Sewage.h"
#include <iostream>

Sewage::Sewage(string name, double capacity, double operationalCost)
        : Utilities(name, capacity, operationalCost) 
{
	this->name=name;
	this->capacity=capacity;
	this->operationalCost=operationalCost;
}

void Sewage::displayInfo() {
    cout << "Sewage Utility Name: " << name << endl;
    cout << "Capacity: " << capacity << " cubic meters" << endl;
    cout << "Operational Cost: $" << operationalCost << " per hour" << endl;
}

void Sewage::generateResources() {
    cout << "Processing " << capacity << " cubic meters of sewage." << endl;
}

void Sewage::requestMaintenance(int Utilities_util) {
    cout << "Requesting maintenance for sewage utility. Maintenance ID: " << Utilities_util << endl;
}
