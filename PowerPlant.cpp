#include "PowerPlant.h"
#include <iostream>

using namespace std;

/**
 * @brief Constructs a PowerPlant object with specified name, capacity, and operational cost.
 *
 * Initializes the `PowerPlant` with given parameters, assigning values to the 
 * `name`, `capacity`, and `operationalCost` attributes. Inherits from the `Utilities` class.
 *
 * @param name The name of the power plant.
 * @param capacity The energy production capacity in MW.
 * @param operationalCost The cost of operation per hour.
 */
PowerPlant::PowerPlant(string name, double capacity, double operationalCost) : Utilities(name, capacity, operationalCost) 
{
    this->name = name;
    this->capacity = capacity;
    this->operationalCost = operationalCost;
}

/**
 * @brief Displays detailed information about the power plant.
 *
 * Outputs the power plant's name, capacity, and operational cost to the console.
 * Useful for monitoring and debugging purposes.
 */
void PowerPlant::displayInfo() {
    cout << "Power Plant Name: " << name << endl;
    cout << "Capacity: " << capacity << " MW" << endl;
    cout << "Operational Cost: $" << operationalCost << " per hour" << endl;
}

/**
 * @brief Simulates resource generation based on the plant's capacity.
 *
 * Prints a message to indicate the amount of power (in MW) currently being generated.
 * This simulates the power plant's functionality in a real environment.
 */
void PowerPlant::generateResources() {
    cout << "Generating " << capacity << " MW of power." << endl;
}

/**
 * @brief Requests maintenance for the power plant with a specific maintenance ID.
 *
 * Displays a message indicating a maintenance request for the power plant. 
 * The `Utilities_util` parameter provides the unique ID for the maintenance request.
 *
 * @param Utilities_util The maintenance request ID.
 */
void PowerPlant::requestMaintenance(int Utilities_util) {
    cout << "Requesting maintenance for power plant. Maintenance ID: " << Utilities_util << endl;
}
