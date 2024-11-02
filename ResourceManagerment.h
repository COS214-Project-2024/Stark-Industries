#ifndef RESOURCEMANAGEMENT_H
#define RESOURCEMANAGEMENT_H

#include <string>
#include <iostream>

class ResourceManagement {
private:
    // Resource quantities
    int wood;
    int steel;
    int concrete;
    int energy;
    int water;
    double budget;

    // Private constructor for Singleton pattern
    ResourceManagement()
        : wood(0), steel(0), concrete(0), energy(0), water(0), budget(0.0) {}

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
    void updateMaterials(int woodChange, int steelChange, int concreteChange);
    void updateEnergy(int energyChange);
    void updateWater(int waterChange);
    void updateBudget(double budgetChange);

    // New methods for creation and supply
    void createResources();       // Initializes the resources for the first time
    void supplyResources();       // Supplies resources to utilities

    // Display current resource status
    void displayResourceStatus() const;

    // Methods for resource operations
    bool allocateBudget(double amount);

    void resetResources();
};

#endif // RESOURCEMANAGEMENT_H
