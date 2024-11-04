/**
 * @file PowerPlant.cpp
 * @brief Implements the PowerPlant class, which represents a utility for generating power within a city infrastructure.
 */

#include "PowerPlant.h"
#include <iostream>

/**
 * @brief Constructs a PowerPlant object with the specified attributes.
 * 
 * @param name The name of the power plant.
 * @param capacity The power generation capacity of the plant in megawatts (MW).
 * @param operationalCost The operational cost per hour for the power plant.
 */
PowerPlant::PowerPlant(std::string name, double capacity, double operationalCost) 
    : Utilities(name, capacity, operationalCost) {
    this->name = name;
    this->capacity = capacity;
    this->operationalCost = operationalCost;
}

/**
 * @brief Displays information about the power plant.
 * 
 * Outputs the name, capacity, and operational cost of the power plant to the console.
 */
void PowerPlant::displayInfo() {
    std::cout << "Power Plant Name: " << name << std::endl;
    std::cout << "Capacity: " << capacity << " MW" << std::endl;
    std::cout << "Operational Cost: $" << operationalCost << " per hour" << std::endl;
}

/**
 * @brief Simulates power generation.
 * 
 * Outputs a message indicating that the power plant is generating power at its specified capacity.
 */
void PowerPlant::generateResources() {
    std::cout << "Generating " << capacity << " MW of power." << std::endl;
}

/**
 * @brief Requests maintenance for the power plant.
 * 
 * Outputs a message indicating a maintenance request with a specified maintenance ID.
 * 
 * @param Utilities_util The maintenance ID associated with this maintenance request.
 */
void PowerPlant::requestMaintenance(int Utilities_util) {
    std::cout << "Requesting maintenance for power plant. Maintenance ID: " << Utilities_util << std::endl;
}
