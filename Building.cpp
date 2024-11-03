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
                   int improvementLevel, bool resourcesAvailable, int notificationRadius, string area) 
    : name(name), satisfaction(satisfaction), economicImpact(economicImpact),
      resourceConsumption(resourceConsumption), constructionStatus(constructionStatus),
      improvementLevel(improvementLevel), resourcesAvailable(resourcesAvailable),
      capacity(capacity), area(area) {}

/**
 * @brief Placeholder method for getting building details (to be implemented).
 */
void Building::get() {
	// TODO - implement Building::get
	
    throw "Not yet implemented";
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
	for (int i = 0 ; i < observerList.size(); i++) {
		observerList[i]->buildingSatisfaction -= 10;
	}
}

void Building::setBuildingValue(double value){
	buildingValue = value;
}