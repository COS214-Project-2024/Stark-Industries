/**
 * @file Building.cpp
 * @brief Implements the Building class, which represents a structure with economic, social, and resource-related attributes.
 */

#include "Building.h"
#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @brief Constructs a Building with the given attributes.
 * 
 * @param name Name of the building.
 * @param satisfaction Initial satisfaction score of the building.
 * @param economicImpact Initial economic impact of the building.
 * @param resourceConsumption Initial resource consumption of the building.
 * @param constructionStatus Status indicating if the building is completed.
 * @param improvementLevel Initial improvement level of the building.
 * @param resourcesAvailable Availability of resources for improvements.
 * @param capacity Maximum occupancy of the building.
 * @param area Location area or designation of the building.
 */
Building::Building(std::string name, int satisfaction, double economicImpact, 
                   double resourceConsumption, bool constructionStatus, 
                   int improvementLevel, bool resourcesAvailable, int capacity, std::string area) 
    : name(name), satisfaction(satisfaction), economicImpact(economicImpact),
      resourceConsumption(resourceConsumption), constructionStatus(constructionStatus),
      improvementLevel(improvementLevel), resourcesAvailable(resourcesAvailable),
      capacity(capacity), area(area) {}

/**
 * @brief Default constructor for the Building class.
 */
Building::Building() {}

/**
 * @brief Displays the details of the building.
 * 
 * This method outputs the building's name, satisfaction score, economic impact,
 * capacity, and area to the console.
 */
void Building::get() {
    std::cout << "Building Details:\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Satisfaction: " << satisfaction << "\n";
    std::cout << "Economic Impact: " << economicImpact << "\n";
    std::cout << "Capacity: " << capacity << "\n";
    std::cout << "Area: " << area << "\n";
}

/**
 * @brief Attaches a citizen observer to the building.
 * 
 * @param observer Pointer to the Citizen object to be added as an observer.
 */
void Building::attach(Citizen* observer) {
    observerList.push_back(observer);
}

/**
 * @brief Detaches a citizen observer from the building.
 * 
 * @param observer Pointer to the Citizen object to be removed from the observer list.
 */
void Building::detach(Citizen* observer) {
    observerList.erase(std::remove(observerList.begin(), observerList.end(), observer), observerList.end());
}

/**
 * @brief Notifies all attached citizen observers about changes in the building.
 * 
 * Calls the update method on each observer to inform them of changes in the building's state.
 */
void Building::notifyCitizens() {
    for (Citizen* citizen : observerList) {
        citizen->observerUpdate("Building");
    }
}

/**
 * @brief Sets the rental rate for the building.
 * 
 * Adjusts the rental rate and decreases each citizen observer's satisfaction by 10 points.
 * 
 * @param newRentalRate The new rental rate to be set for the building.
 */
void Building::setRentalRate(double newRentalRate) {
    rent = newRentalRate;
    for (int i = 0; i < observerList.size(); i++) {
        observerList[i]->buildingSatisfaction -= 10;
    }
}

/**
 * @brief Adds a utility to the building.
 * 
 * This method is intended to be overridden in derived classes for specific utility handling.
 * 
 * @param utility Pointer to the Utilities object to be added to the building.
 */
void Building::addUtility(Utilities* utility) {
    // Virtual function, intended for override
}

/**
 * @brief Sets the building's market value.
 * 
 * @param value The new market value for the building.
 */
void Building::setBuildingValue(double value) {
    buildingValue = value;
}

/**
 * @brief Retrieves the current rental rate of the building.
 * 
 * @return The rental rate as a double.
 */
double Building::getRent() {
    return rent;
}
