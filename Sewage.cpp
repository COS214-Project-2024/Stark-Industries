#include "Sewage.h"
#include <iostream>

/**
 * @brief Constructs a Sewage object with specified details.
 * 
 * This constructor initializes a Sewage object with the given 
 * name, capacity, and operational cost by invoking the base 
 * class constructor and setting the member variables.
 * 
 * @param name The name of the sewage utility.
 * @param capacity The maximum capacity of the sewage utility.
 * @param operationalCost The operational cost of the sewage utility.
 */
Sewage::Sewage(string name, double capacity, double operationalCost)
        : Utilities(name, capacity, operationalCost) 
{
    this->name = name;
    this->capacity = capacity;
    this->operationalCost = operationalCost;
}

/**
 * @brief Displays information about the sewage utility.
 * 
 * This method outputs the details of the sewage utility, including 
 * its name, capacity, and operational cost, to the console.
 */
void Sewage::displayInfo() {
    cout << "Sewage Utility Name: " << name << endl;
    cout << "Capacity: " << capacity << " cubic meters" << endl;
    cout << "Operational Cost: $" << operationalCost << " per hour" << endl;
}

/**
 * @brief Generates resources from the sewage utility.
 * 
 * This method simulates processing the specified capacity of sewage, 
 * outputting the process to the console.
 */
void Sewage::generateResources() {
    cout << "Processing " << capacity << " cubic meters of sewage." << endl;
}

/**
 * @brief Requests maintenance for the sewage utility.
 * 
 * This method handles maintenance requests for the sewage utility 
 * by outputting a maintenance request message to the console, 
 * including the provided maintenance ID.
 * 
 * @param Utilities_util An integer identifier for the type of utility 
 *                       requesting maintenance.
 */
void Sewage::requestMaintenance(int Utilities_util) {
    cout << "Requesting maintenance for sewage utility. Maintenance ID: " << Utilities_util << endl;
}
