#include "Waste.h"
#include <iostream>

/**
 * @brief Constructs a Waste object with specified attributes.
 * 
 * This constructor initializes a Waste object by calling the base 
 * class constructor with the given name, capacity, and operational cost.
 * 
 * @param name The name of the waste utility.
 * @param capacity The maximum capacity of the waste utility.
 * @param operationalCost The operational cost of the waste utility.
 */
Waste::Waste(string name, double capacity, double operationalCost)
        : Utilities(name, capacity, operationalCost) 
{
    this->name = name;
    this->capacity = capacity;
    this->operationalCost = operationalCost;
}

/**
 * @brief Displays information about the waste utility.
 * 
 * This method outputs the name, capacity, and operational cost of 
 * the waste utility to the console.
 */
void Waste::displayInfo() {
    cout << "Waste Utility Name: " << name << endl;
    cout << "Capacity: " << capacity << " tons" << endl;
    cout << "Operational Cost: $" << operationalCost << " per hour" << endl;
}

/**
 * @brief Generates resources from the waste utility.
 * 
 * This method simulates processing the specified amount of waste 
 * and outputs the operation to the console.
 */
void Waste::generateResources() {
    cout << "Processing " << capacity << " tons of waste." << endl;
}

/**
 * @brief Requests maintenance for the waste utility.
 * 
 * This method outputs a maintenance request for the waste utility,
 * including a unique maintenance ID.
 * 
 * @param Utilities_util An integer identifier for the type of utility
 *                       requesting maintenance.
 */
void Waste::requestMaintenance(int Utilities_util) {
    cout << "Requesting maintenance for waste utility. Maintenance ID: " << Utilities_util << endl;
}
