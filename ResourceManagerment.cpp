#include "ResourceManagerment.h"
#include <iostream>

void ResourceManagement::updateMaterials(int woodChange, int steelChange, int concreteChange) {
    wood += woodChange;
    steel += steelChange;
    concrete += concreteChange;
}

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
    wood = 1000;       // Example base values; adjust as needed
    steel = 500;
    concrete = 300;
    energy = 2000;     // Energy base value
    water = 1500;      // Water base value
    budget = 10000.0;  // Budget base value

    std::cout << "Resources created with initial values." << std::endl;
    displayResourceStatus();
}

// Supplies resources to utilities (example values for supply)
void ResourceManagement::supplyResources() {
    // Deduct a portion of resources as a simulation of supplying utilities
    int woodSupply = 100;
    int steelSupply = 50;
    int concreteSupply = 30;
    int energySupply = 200;
    int waterSupply = 150;
    double budgetSupply = 500.0;

    // Check and deduct if there are enough resources for supply
    if (wood >= woodSupply && steel >= steelSupply && concrete >= concreteSupply &&
        energy >= energySupply && water >= waterSupply && budget >= budgetSupply) {
        
        wood -= woodSupply;
        steel -= steelSupply;
        concrete -= concreteSupply;
        energy -= energySupply;
        water -= waterSupply;
        budget -= budgetSupply;

        std::cout << "Resources supplied to utilities." << std::endl;
    } else {
        std::cout << "Insufficient resources to supply utilities." << std::endl;
    }

    displayResourceStatus();
}

void ResourceManagement::displayResourceStatus() const {
    std::cout << "Current Resource Status:" << std::endl;
    std::cout << "Wood: " << wood << std::endl;
    std::cout << "Steel: " << steel << std::endl;
    std::cout << "Concrete: " << concrete << std::endl;
    std::cout << "Energy: " << energy << std::endl;
    std::cout << "Water: " << water << std::endl;
    std::cout << "Budget: " << budget << std::endl;
}

bool ResourceManagement::allocateBudget(double amount) {
    if (budget >= amount) {
        budget -= amount;
        return true;
    } else {
        return false;
    }
}
