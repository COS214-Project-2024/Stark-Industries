/**
 * @file Sewage.cpp
 * @brief Implementation of the Sewage class, representing a sewage utility.
 */
#include "Sewage.h"
#include <iostream>

/**
 * @brief Constructs a Sewage object with the specified attributes.
 * 
 * @param name Name of the sewage utility.
 * @param capacity Capacity of the sewage utility in cubic meters.
 * @param operationalCost Operational cost of the sewage utility per hour.
 */
Sewage::Sewage(string name, double capacity, double operationalCost)
        : Utilities(name, capacity, operationalCost) 
{
	this->name=name;
	this->capacity=capacity;
	this->operationalCost=operationalCost;
}

/**
 * @brief Displays the information about the sewage utility.
 * 
 * This method prints the name, capacity, and operational cost of the sewage 
 * utility to the console.
 */
void Sewage::displayInfo() {
    cout << "Sewage Utility Name: " << name << endl;
    cout << "Capacity: " << capacity << " cubic meters" << endl;
    cout << "Operational Cost: $" << operationalCost << " per hour" << endl;
}

/**
 * @brief Processes sewage based on the utility's capacity.
 * 
 * This method simulates the generation of resources by printing a message 
 * that indicates the amount of sewage being processed.
 */
void Sewage::generateResources() {
    cout << "Processing " << capacity << " cubic meters of sewage." << endl;
}

/**
 * @brief Requests maintenance for the sewage utility.
 * 
 * This method simulates the process of requesting maintenance for the sewage 
 * utility, providing a maintenance ID.
 * 
 * @param Utilities_util The ID of the maintenance request.
 */
void Sewage::requestMaintenance(int Utilities_util) {
    cout << "Requesting maintenance for sewage utility. Maintenance ID: " << Utilities_util << endl;
}
