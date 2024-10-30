#include "Water.h"
#include <iostream>

Water::Water(string name, double capacity, double operationalCost) : Utilities(name, capacity, operationalCost) 
{
	this->name=name;
	this->capacity=capacity;
	this->operationalCost=operationalCost;
}


void Water::displayInfo() {
    cout << "Water Utility Name: " << name << endl;
    cout << "Capacity: " << capacity << " liters" << endl;
    cout << "Operational Cost: $" << operationalCost << " per hour" << endl;
}

void Water::generateResources() {
    cout << "Supplying " << capacity << " liters of water." << endl;
}

void Water::requestMaintenance(int Utilities_util) {
    cout << "Requesting maintenance for water utility. Maintenance ID: " << Utilities_util << endl;
}
