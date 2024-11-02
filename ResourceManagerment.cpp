#include "ResourceManagerment.h"

// Method to update materials
void ResourceManagement::updateMaterials(int woodChange, int steelChange, int concreteChange) {
    wood += woodChange;
    steel += steelChange;
    concrete += concreteChange;
    std::cout << "Materials updated. Wood: " << wood << ", Steel: " << steel << ", Concrete: " << concrete << std::endl;
}

// Method to update energy
void ResourceManagement::updateEnergy(int energyChange) {
    energy += energyChange;
    std::cout << "Energy updated. Current energy level: " << energy << std::endl;
}

// Method to update water
void ResourceManagement::updateWater(int waterChange) {
    water += waterChange;
    std::cout << "Water updated. Current water level: " << water << std::endl;
}

// Method to update budget
void ResourceManagement::updateBudget(double budgetChange) {
    budget += budgetChange;
    std::cout << "Budget updated. Current budget: " << budget << std::endl;
}

// Display current status of resources
void ResourceManagement::displayResourceStatus() const {
    std::cout << "Resource Status:" << std::endl;
    std::cout << "Wood: " << wood << std::endl;
    std::cout << "Steel: " << steel << std::endl;
    std::cout << "Concrete: " << concrete << std::endl;
    std::cout << "Energy: " << energy << std::endl;
    std::cout << "Water: " << water << std::endl;
    std::cout << "Budget: " << budget << std::endl;
}

// Example method for creating resources (placeholder)
void ResourceManagement::createResources() {
    std::cout << "Creating resources..." << std::endl;
}

// Example method for supplying resources (placeholder)
void ResourceManagement::supplyResources() {
    std::cout << "Supplying resources..." << std::endl;
}

// Method to allocate budget, returns true if allocation is successful
bool ResourceManagement::allocateBudget(double amount) {
    if (budget >= amount) {
        budget -= amount;
        std::cout << "Budget allocated: " << amount << ". Remaining budget: " << budget << std::endl;
        return true;
    } else {
        std::cout << "Insufficient budget for allocation of: " << amount << std::endl;
        return false;
    }
}
