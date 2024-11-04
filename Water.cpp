/**
 * @file Water.h
 * @brief Implementation of the Water class, representing a water utility.
 * 
 * The Water class provides specific functionality for a water utility, 
 * including displaying information, generating resources, and requesting maintenance.
 */

#include "Water.h"
#include <iostream>

/**
 * @brief Constructs a Water utility object.
 * 
 * Initializes the Water object with the specified name, capacity, and operational cost.
 * 
 * @param name The name of the water utility.
 * @param capacity The water capacity in liters.
 * @param operationalCost The operational cost per hour in dollars.
 */
Water::Water(string name, double capacity, double operationalCost) : Utilities(name, capacity, operationalCost) 
{
	this->name=name;
	this->capacity=capacity;
	this->operationalCost=operationalCost;
}


/**
 * @brief Displays information about the water utility.
 * 
 * Prints the name, capacity, and operational cost of the water utility to the console.
 */
void Water::displayInfo() {
    cout << "Water Utility Name: " << name << endl;
    cout << "Capacity: " << capacity << " liters" << endl;
    cout << "Operational Cost: $" << operationalCost << " per hour" << endl;
}

/**
 * @brief Simulates the generation of water resources.
 * 
 * Outputs the amount of water being supplied based on the utility's capacity.
 */
void Water::generateResources() {
    cout << "Supplying " << capacity << " liters of water." << endl;
}

/**
 * @brief Requests maintenance for the water utility.
 * 
 * Outputs a maintenance request message that includes the specified maintenance ID.
 * 
 * @param Utilities_util The maintenance ID associated with the water utility.
 */
void Water::requestMaintenance(int Utilities_util) {
    cout << "Requesting maintenance for water utility. Maintenance ID: " << Utilities_util << endl;
}
