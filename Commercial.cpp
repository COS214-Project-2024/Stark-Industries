#include "Commercial.h"
#include <iostream>

/**
 * @brief Constructs a Commercial building with the given attributes.
 * 
 * @param name Name of the commercial building.
 * @param satisfaction Initial satisfaction score of the building.
 * @param economicImpact Initial economic impact contributed by the building.
 * @param resourceConsumption Initial resource consumption of the building.
 * @param constructionStatus Boolean indicating if the building construction is complete.
 * @param improvementLevel Initial improvement level of the building.
 * @param resourcesAvailable Boolean indicating if resources are available for improvements.
 * @param notificationRadius Radius within which citizens are notified of changes to the building.
 */
Commercial::Commercial(std::string name, int satisfaction, double economicImpact, 
                       double resourceConsumption, bool constructionStatus, 
                       int improvementLevel, bool resourcesAvailable, int notificationRadius)
    : Building(name, satisfaction, economicImpact, resourceConsumption, 
               constructionStatus, improvementLevel, resourcesAvailable, notificationRadius), name(name), satisfaction(satisfaction), economicImpact(economicImpact),
      resourceConsumption(resourceConsumption), constructionStatus(constructionStatus),
      improvementLevel(improvementLevel), resourcesAvailable(resourcesAvailable),
      citizenNotificationRadius(notificationRadius) {}

/**
 * @brief Returns the type of the building as its name.
 * 
 * @return A string representing the name/type of the commercial building.
 */
std::string Commercial::getType() {
    return name;
}

/**
 * @brief Calculates the satisfaction level for the commercial building.
 * 
 * @return An integer representing the satisfaction score.
 */
int Commercial::calculateSatisfaction() {
    return satisfaction;
}

/**
 * @brief Calculates the economic impact of the commercial building.
 * 
 * @return A double representing the economic impact value.
 */
double Commercial::calculateEconomicImpact() {
    return economicImpact;
}

/**
 * @brief Calculates the resource consumption of the commercial building.
 * 
 * @return A double representing the amount of resources consumed.
 */
double Commercial::calculateResourceConsumption() {
    return resourceConsumption;
}

/**
 * @brief Checks if the construction of the commercial building is complete.
 * 
 * @return True if construction is complete, false otherwise.
 */
bool Commercial::constructionComplete() {
    return constructionStatus;
}

/**
 * @brief Performs improvements on the commercial building.
 * 
 * If resources are available, the improvement level and satisfaction are increased, 
 * and the economic impact is boosted. Citizens are notified of the improvements.
 */
void Commercial::doImprovements() {
    if (checkResourceAvailability()) {
        improvementLevel++;
        satisfaction += 5;  // Increase satisfaction
        economicImpact *= 1.1;  // Boost economic impact slightly

        std::cout << "Commercial building improved! New Improvement Level: " 
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
bool Commercial::checkResourceAvailability() {
    return resourcesAvailable;
}

/**
 * @brief Notifies all attached citizens about changes to the commercial building.
 * 
 * Uses the base class implementation to notify all observers (citizens) about changes.
 */
void Commercial::notifyCitizens() {
    std::cout << "Notifying citizens about changes in the commercial building: " << name << "\n";
    Building::notifyCitizens();  // Call the base class notify method
}
