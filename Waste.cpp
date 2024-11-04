#include "Waste.h"
#include <iostream>

Waste::Waste(string name, double capacity, double operationalCost)
        : Utilities(name, capacity, operationalCost) 
{
	this->name=name;
	this->capacity=capacity;
	this->operationalCost=operationalCost;
}

void Waste::displayInfo() {
    cout << "Waste Utility Name: " << name << endl;
    cout << "Capacity: " << capacity << " tons" << endl;
    cout << "Operational Cost: $" << operationalCost << " per hour" << endl;
}

void Waste::generateResources() {
    cout << "Processing " << capacity << " tons of waste." << endl;
}

void Waste::requestMaintenance(int Utilities_util) {
    cout << "Requesting maintenance for waste utility. Maintenance ID: " << Utilities_util << endl;
}
