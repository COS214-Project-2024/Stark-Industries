#include "Water.h"
#include <iostream>

/**
 * @brief Constructs a Water utility object with specified details.
 *
 * Initializes the name, capacity, and operational cost of the water utility.
 *
 * @param name The name of the water utility.
 * @param capacity The capacity of the water utility in liters.
 * @param operationalCost The operational cost of the water utility in currency per hour.
 */
Water::Water(string name, double capacity, double operationalCost) : Utilities(name, capacity, operationalCost) 
{
    this->name = name;
    this->capacity = capacity;
    this->operationalCost = operationalCost;
}

/**
 * @brief Displays information about the water utility.
 *
 * Outputs the water utility's name, capacity (in liters), and operational cost (per hour).
 */
void Water::displayInfo() {
    cout << "Water Utility Name: " << name << endl;
    cout << "Capacity: " << capacity << " liters" << endl;
    cout << "Operational Cost: $" << operationalCost << " per hour" << endl;
}

/**
 * @brief Simulates the supply of water resources.
 *
 * Outputs a message indicating the amount of water being supplied.
 */
void Water::generateResources() {
    cout << "Supplying " << capacity << " liters of water." << endl;
}

/**
 * @brief Requests maintenance for the water utility.
 *
 * Outputs a maintenance request message with a provided maintenance ID for tracking.
 *
 * @param Utilities_util The maintenance ID for the maintenance request.
 */
void Water::requestMaintenance(int Utilities_util) {
    cout << "Requesting maintenance for water utility. Maintenance ID: " << Utilities_util << endl;
}
