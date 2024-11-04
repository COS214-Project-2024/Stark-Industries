#ifndef RESOURCEMANAGERMENT_H
#define RESOURCEMANAGERMENT_H

#include <string>
#include <iostream>

class ResourceManagement {
private:
    int energy;   // Energy for power plants
    int water;    // Water for water utilities
    double budget; // Financial resources for utilities

    // Private constructor for Singleton pattern
    ResourceManagement() : energy(2000), water(1500), budget(10000.0) {}

    // Delete copy constructor and assignment operator
    ResourceManagement(const ResourceManagement&) = delete;
    ResourceManagement& operator=(const ResourceManagement&) = delete;

public:
    // Meyers Singleton
    static ResourceManagement& getInstance() {
        static ResourceManagement onlyInstance;
        return onlyInstance;
    }

    // Methods to manage resources
    void updateEnergy(int energyChange);
    void updateWater(int waterChange);
    void updateBudget(double budgetChange);

    // Initializes the resources for the first time
    void createResources();

    // Method to allocate resources to a specific utility
    bool allocateResourcesToUtility(const std::string& utilityType, int energyRequired, int waterRequired, double budgetRequired);

    // Display current resource status
    void displayResourceStatus() const;

    // Reset all resources to zero
    void resetResources();
};

#endif // RESOURCEMANAGEMENT_H
