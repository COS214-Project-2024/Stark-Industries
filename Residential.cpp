#include "Residential.h"
#include <iostream>

/**
 * @brief Constructs a Residential building with the given attributes.
 * 
 * @param name Name of the residential building.
 * @param satisfaction Initial satisfaction score of the building.
 * @param economicImpact Initial economic impact contributed by the building.
 * @param resourceConsumption Initial resource consumption of the building.
 * @param constructionStatus Boolean indicating if the building is complete.
 * @param improvementLevel Initial improvement level of the building.
 * @param resourcesAvailable Boolean indicating if resources are available for improvements.
 * @param notificationRadius Radius within which citizens are notified about changes.
 */
Residential::Residential(std::string name, int satisfaction, double economicImpact, 
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
 * @return A string representing the name/type of the residential building.
 */
std::string Residential::getType() {
    return name;
}

/**
 * @brief Calculates the satisfaction level for the residential building.
 * 
 * @return An integer representing the satisfaction score.
 */
int Residential::calculateSatisfaction() {
    return satisfaction;
}

/**
 * @brief Calculates the economic impact of the residential building.
 * 
 * @return A double representing the economic impact value.
 */
double Residential::calculateEconomicImpact() {
    return economicImpact;
}

/**
 * @brief Calculates the resource consumption of the residential building.
 * 
 * @return A double representing the amount of resources consumed.
 */
double Residential::calculateResourceConsumption() {
    return resourceConsumption;
}

/**
 * @brief Checks if the construction of the residential building is complete.
 * 
 * @return True if construction is complete, false otherwise.
 */
bool Residential::constructionComplete() {
    return constructionStatus;
}

/**
 * @brief Performs improvements on the residential building.
 * 
 * If resources are available, the improvement level and satisfaction are increased, 
 * and the economic impact is boosted. Citizens are notified of improvements.
 */
void Residential::doImprovements() {
    if (checkResourceAvailability()) {
        improvementLevel++;
        satisfaction += 5;  // Increase satisfaction
        economicImpact *= 1.1;  // Boost economic impact

        std::cout << "Residential building improved! New Improvement Level: " 
                  << improvementLevel << "\n";

        // Notify citizens about the improvements (Observer pattern)
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
bool Residential::checkResourceAvailability() {
    return resourcesAvailable;
}

/**
 * @brief Notifies all attached citizens about changes in the residential building.
 * 
 * Uses the base class implementation to notify all observers (citizens) about changes.
 */
void Residential::notifyCitizens() {
    std::cout << "Notifying citizens about changes in " << name << "...\n";
    Building::notifyCitizens();  // Call the base class notify method
}
