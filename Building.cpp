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
 * @param notificationRadius Radius within which citizens are notified of changes.
 */
Building::Building(string name, int satisfaction, double economicImpact, 
                   double resourceConsumption, bool constructionStatus, 
                   int improvementLevel, bool resourcesAvailable, int capacity, string area) 
    : name(name), satisfaction(satisfaction), economicImpact(economicImpact),
      resourceConsumption(resourceConsumption), constructionStatus(constructionStatus),
      improvementLevel(improvementLevel), resourcesAvailable(resourcesAvailable),
      capacity(capacity), area(area) {}

/**
 * @brief Placeholder method for getting building details (to be implemented).
 */

void Building::get() {
    std::cout << "Building Details:\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Satisfaction: " << satisfaction << "\n";
    std::cout << "Economic Impact: " << economicImpact << "\n";
    std::cout << "Capacity: " << capacity << "\n";
    std::cout << "Area: " << area << "\n";
}


Building::Building() {

}

/**
 * @brief Placeholder method for setting building details (to be implemented).
 */
void Building::set() {
	// TODO - implement Building::set
	
    throw "Not yet implemented";
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
 */
void Building::notifyCitizens() {
    // std::cout << "Notifying citizens about changes in " << name << "...\n";
    for (Citizen* citizen : observerList) {
        citizen->observerUpdate("Building");  // Call the observer's update method
    }
}

void Building::setRentalRate(double newRentalRate) {
	rent = newRentalRate;
}

void Building::addUtility(Utilities* utility) {
    //virtual
}

void Building::setBuildingValue(double value) {
	buildingValue = value;
}

double Building::getRent(){
    return rent;
}