#include "Commercial.h"

/**
 * @brief Constructor for the Commercial class.
 *
 * Initializes a Commercial building with the specified parameters.
 *
 * @param name Name of the building.
 * @param satisfaction Initial satisfaction rating.
 * @param economicImpact Initial economic impact.
 * @param resourceConsumption Initial resource consumption.
 * @param constructionStatus Initial construction status.
 * @param improvementLevel Initial improvement level.
 * @param resourcesAvailable Availability of resources.
 * @param notificationRadius Radius for citizen notifications.
 */
Commercial::Commercial(string name, int satisfaction, double economicImpact, 
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
 * @brief Gets the type of building.
 *
 * @return A string representing the type of building.
 */
string Commercial::getType() {
    return name;
}

/**
 * @brief Calculates the satisfaction rating of the building.
 *
 * @return The satisfaction rating.
 */
int Commercial::calculateSatisfaction() {
    return satisfaction;
}

/**
 * @brief Calculates the economic impact of the building.
 *
 * @return The economic impact value.
 */
double Commercial::calculateEconomicImpact() {
    return economicImpact;
}

/**
 * @brief Calculates the resource consumption of the building.
 *
 * @return The resource consumption value.
 */
double Commercial::calculateResourceConsumption() {
    return resourceConsumption;
}

/**
 * @brief Checks if the construction of the building is complete.
 *
 * @return True if construction is complete, false otherwise.
 */
bool Commercial::constructionComplete() {
    return constructionStatus;
}

/**
 * @brief Performs improvements to the building.
 *
 * If resources are available, increases the improvement level, 
 * adjusts satisfaction, and modifies economic impact.
 */
void Commercial::doImprovements() {
    if (checkResourceAvailability()) {
        improvementLevel++;
        satisfaction += 5; // Adjust satisfaction
        economicImpact *= 1.1; // Adjust economic impact
    }
}

/**
 * @brief Checks the availability of resources for the building.
 *
 * @return True if resources are available, false otherwise.
 */
bool Commercial::checkResourceAvailability() {
    return resourcesAvailable;
}

/**
 * @brief Notifies citizens about updates regarding the building.
 *
 * This method should implement the observer pattern logic to notify 
 * citizens observing the building of any changes or updates.
 */
void Commercial::notifyCitizens() {
    // Implement the notification logic for citizens observing this building.
}
