#include "Industrial.h"

/**
 * @brief Constructs an Industrial building with the specified attributes.
 *
 * Initializes an Industrial building object with properties like name, satisfaction,
 * economic impact, resource consumption, construction status, improvement level,
 * resource availability, and citizen notification radius.
 *
 * @param name Name of the industrial building.
 * @param satisfaction Initial satisfaction rating.
 * @param economicImpact Initial economic impact.
 * @param resourceConsumption Initial resource consumption.
 * @param constructionStatus Initial construction status.
 * @param improvementLevel Initial improvement level.
 * @param resourcesAvailable Availability of resources.
 * @param notificationRadius Radius for citizen notifications.
 */
Industrial::Industrial(string name, int satisfaction, double economicImpact, 
                       double resourceConsumption, bool constructionStatus, 
                       int improvementLevel, bool resourcesAvailable, 
                       int notificationRadius)
    : name(name), satisfaction(satisfaction), economicImpact(economicImpact),
      resourceConsumption(resourceConsumption), constructionStatus(constructionStatus),
      improvementLevel(improvementLevel), resourcesAvailable(resourcesAvailable),
      citizenNotificationRadius(notificationRadius), 
      Building(name, satisfaction, economicImpact, resourceConsumption, 
               constructionStatus, improvementLevel, resourcesAvailable, notificationRadius) {}

/**
 * @brief Retrieves the type of the building.
 * @return The name of the building.
 */
string Industrial::getType() {
    return name;
}

/**
 * @brief Calculates and returns the current satisfaction level.
 * @return The satisfaction level of the building.
 */
int Industrial::calculateSatisfaction() {
    return satisfaction;
}

/**
 * @brief Calculates and returns the economic impact of the building.
 * @return The economic impact of the building.
 */
double Industrial::calculateEconomicImpact() {
    return economicImpact;
}

/**
 * @brief Calculates and returns the resource consumption of the building.
 * @return The resource consumption of the building.
 */
double Industrial::calculateResourceConsumption() {
    return resourceConsumption;
}

/**
 * @brief Checks if the construction of the building is complete.
 * @return True if construction is complete, otherwise false.
 */
bool Industrial::constructionComplete() {
    return constructionStatus;
}

/**
 * @brief Improves the building's level, satisfaction, and economic impact if resources are available.
 *
 * Increases the improvement level and adjusts satisfaction and economic impact
 * if resources are available for upgrades.
 */
void Industrial::doImprovements() {
    if (checkResourceAvailability()) {
        improvementLevel++;
        satisfaction += 5; // Adjust as needed
        economicImpact *= 1.1; // Adjust as needed
    }
}

/**
 * @brief Checks the availability of resources for the building.
 * @return True if resources are available, otherwise false.
 */
bool Industrial::checkResourceAvailability() {
    return resourcesAvailable;
}

/**
 * @brief Notifies citizens within a certain radius of the building.
 *
 * Implementation for notifying citizens, typically used as part of an observer
 * pattern. This functionality should be defined further to specify how
 * notifications are sent to nearby citizens.
 */
void Industrial::notifyCitizens() {
    // Implementation needed for notifying citizens
}
