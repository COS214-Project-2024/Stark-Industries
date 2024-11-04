/**
 * @file Waste.h
 * @brief Implementation of the Waste class representing a waste management utility.
 * 
 * The Waste class provides functionality to display information, generate resources,
 * and request maintenance for waste management operations.
 */
#include "Waste.h"
#include <iostream>

/**
 * @brief Constructs a Waste utility object with the specified name, capacity, and operational cost.
 * 
 * @param name The name of the waste management utility.
 * @param capacity The capacity of waste management in tons.
 * @param operationalCost The operational cost of the utility per hour in dollars.
 */
Waste::Waste(string name, double capacity, double operationalCost)
        : Utilities(name, capacity, operationalCost) 
{
	this->name=name;
	this->capacity=capacity;
	this->operationalCost=operationalCost;
}

/**
 * @brief Displays information about the waste utility.
 * 
 * Prints the name, capacity, and operational cost of the waste management utility to the console.
 */
void Waste::displayInfo() {
    cout << "Waste Utility Name: " << name << endl;
    cout << "Capacity: " << capacity << " tons" << endl;
    cout << "Operational Cost: $" << operationalCost << " per hour" << endl;
}

/**
 * @brief Generates resources by processing waste.
 * 
 * Simulates the waste processing operation by printing the capacity of waste being processed.
 */
void Waste::generateResources() {
    cout << "Processing " << capacity << " tons of waste." << endl;
}

/**
 * @brief Requests maintenance for the waste utility.
 * 
 * @param Utilities_util An identifier for the maintenance request.
 * 
 * Prints a maintenance request message with a unique Maintenance ID for tracking.
 */
void Waste::requestMaintenance(int Utilities_util) {
    cout << "Requesting maintenance for waste utility. Maintenance ID: " << Utilities_util << endl;
}
