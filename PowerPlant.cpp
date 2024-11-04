#include "PowerPlant.h"
#include <iostream>

PowerPlant::PowerPlant(string name, double capacity, double operationalCost): Utilities(name, capacity, operationalCost) 
{
	this->name=name;
	this->capacity=capacity;
	this->operationalCost=operationalCost;
}

void PowerPlant::displayInfo() {
    cout << "Power Plant Name: " << name << endl;
    cout << "Capacity: " << capacity << " MW" << endl;
    cout << "Operational Cost: $" << operationalCost << " per hour" << endl;
}

void PowerPlant::generateResources() {
    cout << "Generating " << capacity << " MW of power." << endl;
}

void PowerPlant::requestMaintenance(int Utilities_util) {
    cout << "Requesting maintenance for power plant. Maintenance ID: " << Utilities_util << endl;
}
