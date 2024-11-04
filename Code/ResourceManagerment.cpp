#include "ResourceManagerment.h"
#include <iostream>

void ResourceManagement::updateEnergy(int energyChange) {
    energy += energyChange;
}

void ResourceManagement::updateWater(int waterChange) {
    water += waterChange;
}

void ResourceManagement::updateBudget(double budgetChange) {
    budget += budgetChange;
}

// Initializes resources with base values
void ResourceManagement::createResources() {
    energy = 2000;    // Energy base value
    water = 1500;     // Water base value
    budget = 10000.0; // Budget base value

    std::cout << "Resources created with initial values." << std::endl;
    displayResourceStatus();
}

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

void ResourceManagement::displayResourceStatus() const {
    std::cout << "Current Resource Status:" << std::endl;
    std::cout << "Energy: " << energy << std::endl;
    std::cout << "Water: " << water << std::endl;
    std::cout << "Budget: $" << budget << std::endl;
}

void ResourceManagement::resetResources() {
    energy = 0;
    water = 0;
    budget = 0.0;
}
