/**
 * @file CollectTax.cpp
 * @brief Implements the CollectTax class, which defines a command for collecting taxes from citizens and buildings.
 */

#include "CollectTax.h"

/**
 * @brief Constructs a CollectTax command with initial citizen and building receivers.
 * 
 * @param citizenReceiver Pointer to the Citizen object from which to collect tax.
 * @param buildingReceiver Pointer to the Building object from which to collect tax.
 */
CollectTax::CollectTax(Citizen* citizenReceiver, Building* buildingReceiver) {
    this->buildingList.push_back(buildingReceiver);
    this->citizenList.push_back(citizenReceiver);
    this->name = "Collect";
}

/**
 * @brief Executes the tax collection command for all added citizens and buildings.
 * 
 * Calls the `performAction` method with action type `0` on each building and citizen, indicating tax collection.
 */
void CollectTax::execute() {
    for (int i = 0; i < this->buildingList.size(); i++) {
        if (this->buildingList[i] != nullptr)
            this->buildingList[i]->performAction(0);
    }
    for (int i = 0; i < this->citizenList.size(); i++) {
        if (this->citizenList[i] != nullptr)
            this->citizenList[i]->performAction(0);
    }
}

/**
 * @brief Adds a building to the list of buildings to collect tax from.
 * 
 * @param buildingReceiver Pointer to the Building object to add.
 */
void CollectTax::addBuilding(Building* buildingReceiver) {
    this->buildingList.push_back(buildingReceiver);
}

/**
 * @brief Adds a citizen to the list of citizens to collect tax from.
 * 
 * @param citizenReceiver Pointer to the Citizen object to add.
 */
void CollectTax::addCitizen(Citizen* citizenReceiver) {
    this->citizenList.push_back(citizenReceiver);
}
