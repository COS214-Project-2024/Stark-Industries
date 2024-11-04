/**
 * @file ResourceManagement.cpp
 * @brief Implementation of the ResourceManagement class, managing energy, water, and budget resources.
 */
#include "ResourceManagerment.h"
#include <iostream>

/**
 * @brief Updates the energy resources by a specified change amount.
 * 
 * @param energyChange The amount to change the energy resources by (can be negative).
 */
void ResourceManagement::updateEnergy(int energyChange) {
    energy += energyChange;
}

/**
 * @brief Updates the water resources by a specified change amount.
 * 
 * @param waterChange The amount to change the water resources by (can be negative).
 */
void ResourceManagement::updateWater(int waterChange) {
    water += waterChange;
}

/**
 * @brief Updates the budget by a specified change amount.
 * 
 * @param budgetChange The amount to change the budget by (can be negative).
 */
void ResourceManagement::updateBudget(double budgetChange) {
    budget += budgetChange;
}

/**
 * @brief Initializes resources with base values.
 * 
 * Sets initial values for energy, water, and budget, and displays the resource status.
 */
// Initializes resources with base values
void ResourceManagement::createResources() {
    energy = 2000;    // Energy base value
    water = 1500;     // Water base value
    budget = 10000.0; // Budget base value

    std::cout << "Resources created with initial values." << std::endl;
    displayResourceStatus();
}

/**
 * @brief Allocates resources to a specified utility if sufficient resources are available.
 * 
 * @param utilityType The type of utility to allocate resources to.
 * @param energyRequired The amount of energy required by the utility.
 * @param waterRequired The amount of water required by the utility.
 * @param budgetRequired The amount of budget required by the utility.
 * @return true if resources were successfully allocated; otherwise, false.
 */
// Allocate resources to a specific utility
bool ResourceManagement::allocateResourcesToUtility(const std::string& utilityType, int energyRequired, int waterRequired, double budgetRequired) {
    if (energy >= energyRequired && water >= waterRequired && budget >= budgetRequired) {
        energy -= energyRequired;
        water -= waterRequired;
        budget -= budgetRequired;
        std::cout << "Allocated resources to " << utilityType << "." << std::endl;
        return true;
    } else {
        std::cout << "Insufficient resources to allocate to " << utilityType << "." << std::endl;
        return false;
    }
}

/**
 * @brief Displays the current status of resources.
 * 
 * Outputs the current values of energy, water, and budget to the console.
 */
void ResourceManagement::displayResourceStatus() const {
    std::cout << "Current Resource Status:" << std::endl;
    std::cout << "Energy: " << energy << std::endl;
    std::cout << "Water: " << water << std::endl;
    std::cout << "Budget: $" << budget << std::endl;
}

/**
 * @brief Resets all resources to zero.
 * 
 * Sets energy, water, and budget to their minimum values.
 */
void ResourceManagement::resetResources() {
    energy = 0;
    water = 0;
    budget = 0.0;
}
