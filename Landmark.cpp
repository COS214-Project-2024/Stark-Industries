#include "Landmark.h"
#include <iostream>

int Landmark::numBuildings = 0;

/**
 * @brief Constructs a Landmark building with the given attributes.
 * 
 * @param name Name of the landmark.
 * @param satisfaction Initial satisfaction score of the landmark.
 * @param economicImpact Initial economic impact contributed by the landmark.
 * @param resourceConsumption Initial resource consumption of the landmark.
 * @param constructionStatus Boolean indicating if the landmark construction is complete.
 * @param improvementLevel Initial improvement level of the landmark.
 * @param resourcesAvailable Boolean indicating if resources are available for improvements.
 * @param notificationRadius Radius within which citizens are notified of changes to the landmark.
 */
Landmark::Landmark(std::string name, int satisfaction, double economicImpact, 
                   double resourceConsumption, bool constructionStatus, 
                   int improvementLevel, bool resourcesAvailable, int capacity, string area)
    : Building(name, satisfaction, economicImpact, resourceConsumption, 
               constructionStatus, improvementLevel, resourcesAvailable, capacity, area), name(name), satisfaction(satisfaction), economicImpact(economicImpact),
      resourceConsumption(resourceConsumption), constructionStatus(constructionStatus),
      improvementLevel(improvementLevel), resourcesAvailable(resourcesAvailable),
      capacity(capacity), area(area) 
    {
        numBuildings++;
    }

/**
 * @brief Returns the type of the building as its name.
 * 
 * @return A string representing the name/type of the landmark.
 */
std::string Landmark::getType() {
    return name;
}

/**
 * @brief Calculates the satisfaction level for the landmark.
 * 
 * @return An integer representing the satisfaction score.
 */
int Landmark::calculateSatisfaction() {
    return satisfaction;
}

/**
 * @brief Calculates the economic impact of the landmark.
 * 
 * @return A double representing the economic impact value.
 */
double Landmark::calculateEconomicImpact() {
    return economicImpact;
}

/**
 * @brief Calculates the resource consumption of the landmark.
 * 
 * @return A double representing the amount of resources consumed.
 */
double Landmark::calculateResourceConsumption() {
    return resourceConsumption;
}

/**
 * @brief Checks if the construction of the landmark is complete.
 * 
 * @return True if construction is complete, false otherwise.
 */
bool Landmark::constructionComplete() {
    return constructionStatus;
}

/**
 * @brief Performs improvements on the landmark.
 * 
 * If resources are available, the improvement level and satisfaction are increased, 
 * and the economic impact is boosted. Citizens are notified about the improvements.
 */
void Landmark::doImprovements() {
    if (checkResourceAvailability()) {
        improvementLevel++;
        satisfaction += 10;  // Increase satisfaction for landmarks
        economicImpact *= 1.2;  // Boost economic impact significantly

        std::cout << "Landmark improved!\nNew Improvement Level: " 
                  << improvementLevel << "\n";

        // Notify citizens about the improvement
        notifyCitizens();
    } else {
        std::cout << "Resources unavailable for improvements.\n";
    }
}

/**
 * @brief Checks if resources are available for improvements.
 * 
 * @return True if resources are available, false otherwise.
 */
bool Landmark::checkResourceAvailability() {
	if (!resourcesAvailable){
		citySatisfaction -= 10;
			for (int i = 0 ; i < observerList.size(); i++) {
			observerList[i]->buildingSatisfaction -= 10;
			observerList[i]->citySatisfaction -= 8;
		}
	}
	else {
		citySatisfaction += 10;
		for (int i = 0 ; i < observerList.size(); i++) {
			observerList[i]->buildingSatisfaction += 10;
			observerList[i]->citySatisfaction += 8;
		}
	}
    return resourcesAvailable;
}

/**
 * @brief Notifies all attached citizens about changes to the landmark.
 * 
 * Uses the base class implementation to notify all observers (citizens) about changes.
 */
void Landmark::notifyCitizens() {
    std::cout << "NOTIFICATION: New changes to " << name << "\n";
    Building::notifyCitizens();  // Call the base class notify method
}

Building* Landmark::clone() const {
    return new Landmark(*this); // Create a new Commercial object using the copy constructor
}

void Landmark::performAction(int type) {
    //Do nothing
}

void Landmark::payTax(float taxRate) {
    //Do nothing
}

void Landmark::acceptTaxCollector(Visitor * taxCollector) {
    //Do nothing
}

int Landmark::getNumBuildings() {
    return numBuildings;
}

Landmark::Landmark() {
    
}

bool Landmark::populateBuilding() {
    if (capacity > 0) {
        capacity--;  // Decrease capacity by one
        std::cout << "Citizen added to the building. Remaining capacity: " << capacity << std::endl;
        return true;
    } else {
        std::cout << "Building is at full capacity. Cannot add more citizens." << std::endl;
        return false;
    }
}

void Landmark::addUtility(Utilities* utility) {
    utilities.push_back(utility);
}