#include "Residential.h"

/**
 * @brief Constructs a Residential building with specified attributes.
 *
 * @param name The name of the residential building.
 * @param satisfaction Initial satisfaction level of the residents.
 * @param economicImpact Initial economic impact of the residential building.
 * @param resourceConsumption The amount of resources consumed by the residential building.
 * @param constructionStatus Indicates if the residential building is under construction.
 * @param improvementLevel The current level of improvements made to the residential building.
 * @param resourcesAvailable Indicates whether resources are available for improvements.
 * @param notificationRadius The radius within which citizens are notified about the building.
 */
Residential::Residential(string name, int satisfaction, double economicImpact, 
                         double resourceConsumption, bool constructionStatus, 
                         int improvementLevel, bool resourcesAvailable, 
                         int notificationRadius)
        : name(name), satisfaction(satisfaction), economicImpact(economicImpact),
          resourceConsumption(resourceConsumption), constructionStatus(constructionStatus),
          improvementLevel(improvementLevel), resourcesAvailable(resourcesAvailable),
          citizenNotificationRadius(notificationRadius), 
          Building(name, satisfaction, economicImpact, resourceConsumption, 
                   constructionStatus, improvementLevel, resourcesAvailable, 
                   notificationRadius) {}

/**
 * @brief Retrieves the type of the residential building.
 *
 * @return The name of the residential building.
 */
string Residential::getType() {
    return name;
}

/**
 * @brief Calculates the current satisfaction level of the residents.
 *
 * @return The current satisfaction level.
 */
int Residential::calculateSatisfaction() {
    return satisfaction;
}

/**
 * @brief Calculates the economic impact of the residential building.
 *
 * @return The economic impact value.
 */
double Residential::calculateEconomicImpact() {
    return economicImpact;
}

/**
 * @brief Calculates the resource consumption of the residential building.
 *
 * @return The resource consumption value.
 */
double Residential::calculateResourceConsumption() {
    return resourceConsumption;
}

/**
 * @brief Checks if the construction of the residential building is complete.
 *
 * @return True if the construction is complete, false otherwise.
 */
bool Residential::constructionComplete() {
    return constructionStatus;
}

/**
 * @brief Performs improvements on the residential building.
 *
 * Increases the improvement level and adjusts satisfaction and economic impact
 * if resources are available.
 */
void Residential::doImprovements() {
    // Improvement logic
    if (checkResourceAvailability()) {
        improvementLevel++;
        satisfaction += 5; // Adjust
        economicImpact *= 1.1; // Adjust
    }
}

/**
 * @brief Checks the availability of resources for improvements.
 *
 * @return True if resources are available, false otherwise.
 */
bool Residential::checkResourceAvailability() {
    return resourcesAvailable;
}

/**
 * @brief Notifies citizens about changes related to the residential building.
 *
 * This function should implement the observer pattern to inform citizens.
 */
void Residential::notifyCitizens() {
    // Notification logic // Part of observer
}
