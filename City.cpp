/**
 * @file City.cpp
 * @brief Implements the City class, which manages citizens, buildings, infrastructure, and utilities in a city.
 */

#include "City.h"
#include "Residential.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

/**
 * @brief Constructs a City with the given name.
 * 
 * @param cityName The name of the city.
 */
City::City(const std::string& cityName) : name(cityName) {}

/**
 * @brief Gets the appropriate BuildingCreator based on the building type.
 * 
 * @param buildingType The type of building ("Residential", "Commercial", "Industrial", or "Landmark").
 * @return Pointer to the BuildingCreator for the specified type, or nullptr if type is invalid.
 */
BuildingCreator* City::getBuildingCreator(const std::string& buildingType) {
    if (buildingType == "Residential") {
        return &residentialCreator;
    } else if (buildingType == "Commercial") {
        return &commercialCreator;
    } else if (buildingType == "Industrial") {
        return &industrialCreator;
    } else if (buildingType == "Landmark") {
        return &landmarkCreator;
    } else {
        std::cout << "Invalid building type: " << buildingType << "\n";
        return nullptr;
    }
}

/**
 * @brief Retrieves the name of the city.
 * 
 * @return Name of the city as a string.
 */
std::string City::getName() {
    return name;
}

/**
 * @brief Sets the government entity associated with the city.
 * 
 * @param government Pointer to the Government object.
 */
void City::setGovernment(Government* government) {
    this->government = government;
}

/**
 * @brief Attaches a Citizen observer to the city for notifications.
 * 
 * @param observer Pointer to the Citizen to be added.
 */
void City::attach(Citizen* observer) {
    observerList.push_back(observer);
    citizens.push_back(observer);
}

/**
 * @brief Detaches a Citizen observer from the city.
 * 
 * @param observer Pointer to the Citizen to be removed.
 */
void City::detach(Citizen* observer) {
    observerList.erase(std::remove(observerList.begin(), observerList.end(), observer), observerList.end());
    citizens.erase(std::remove(citizens.begin(), citizens.end(), observer), citizens.end());
}

/**
 * @brief Notifies all attached citizen observers about changes in the city.
 */
void City::notify() {
    std::cout << "Notifying citizens about changes in city.\n";
    for (Citizen* citizen : observerList) {
        citizen->observerUpdate("City");
    }
}

/**
 * @brief Requests construction of a building.
 * 
 * @param Citizen_cit Identifier for the citizen requesting the building.
 * @param String_buildtype Identifier for the type of building requested.
 * @throws std::runtime_error Not yet implemented.
 */
void City::requestBuilding(int Citizen_cit, int String_buildtype) {
    throw "Not yet implemented";
}

/**
 * @brief Marks a building as complete once construction finishes.
 * 
 * @param String_buildtype Identifier for the type of building.
 * @param Citizen_citizen Identifier for the citizen associated with the building.
 * @throws std::runtime_error Not yet implemented.
 */
void City::buildingComplete(int String_buildtype, int Citizen_citizen) {
    throw "Not yet implemented";
}

/**
 * @brief Inspects a building in the city.
 * 
 * @return True if inspection is successful, false otherwise.
 * @throws std::runtime_error Not yet implemented.
 */
bool City::inspectBuilding() {
    throw "Not yet implemented";
}

/**
 * @brief Adds a building to the city's list of buildings.
 * 
 * @param building Pointer to the Building to add.
 */
void City::addBuilding(Building* building) {
    buildings.push_back(building);
}

/**
 * @brief Lists all buildings in the city.
 * 
 * @return Constant reference to a vector containing pointers to all buildings.
 */
const std::vector<Building*>& City::listBuildings() const {
    return buildings;
}

/**
 * @brief Adds a utility to the city's list of utilities.
 * 
 * @param utility Pointer to the Utility to add.
 */
void City::addUtility(Utilities* utility) {
    utilities.push_back(utility);
}

/**
 * @brief Adds infrastructure to the city's transport network.
 * 
 * @param infrastructure Pointer to the TransportInfrastructure to add.
 */
void City::addInfrastructure(TransportInfrastructure* infrastructure) {
    roads.push_back(infrastructure);
    std::cout << "Infrastructure added to the city.\n";
}

/**
 * @brief Lists all transport infrastructures in the city.
 * 
 * @return Constant reference to a vector of pointers to all infrastructures.
 */
const std::vector<TransportInfrastructure*>& City::listInfrastructures() const {
    return roads;
}

/**
 * @brief Lists all utilities in the city.
 * 
 * @return Constant reference to a vector of pointers to all utilities.
 */
const std::vector<Utilities*>& City::listUtilities() const {
    return utilities;
}

/**
 * @brief Retrieves the government entity associated with the city.
 * 
 * @return Pointer to the Government object.
 */
Government* City::getGovernment() {
    return government;
}

/**
 * @brief Lists all buildings in the city (non-const version).
 * 
 * @return Reference to a vector of pointers to all buildings.
 */
std::vector<Building*>& City::listBuildings() {
    return buildings;
}

/**
 * @brief Gets the total population of the city.
 * 
 * @return Total number of citizens in the city.
 */
int City::getTotalPopulation() const {
    return citizens.size();
}

/**
 * @brief Calculates the total available housing capacity in the city.
 * 
 * @return Available housing capacity as an integer.
 */
int City::getAvailableHousingCapacity() const {
    int totalCapacity = 0;
    for (const auto& building : buildings) {
        Residential* residentialBuilding = dynamic_cast<Residential*>(building);
        if (residentialBuilding) {
            totalCapacity += residentialBuilding->getAvailableCapacity();
        }
    }
    return totalCapacity;
}

/**
 * @brief Gets the list of all citizens in the city.
 * 
 * @return Reference to a vector of pointers to all Citizen objects.
 */
std::vector<Citizen*>& City::getCitizens() {
    return observerList;
}

/**
 * @brief Attaches a building to the city's list of buildings.
 * 
 * @param building Pointer to the Building to add.
 */
void City::attach(Building* building) {
    buildings.push_back(building);
}

/**
 * @brief Detaches a building from the city's list of buildings.
 * 
 * @param building Pointer to the Building to remove.
 */
void City::detach(Building* building) {
    buildings.erase(std::remove(buildings.begin(), buildings.end(), building), buildings.end());
}
