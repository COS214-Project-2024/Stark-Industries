#include "Landmark.h"

/**
 * @brief Constructs a Landmark building with specified attributes.
 *
 * Initializes a Landmark with given parameters such as name, satisfaction rating,
 * economic impact, resource consumption, construction status, improvement level,
 * resource availability, and citizen notification radius.
 *
 * @param name Name of the landmark.
 * @param satisfaction Initial satisfaction rating.
 * @param economicImpact Initial economic impact.
 * @param resourceConsumption Initial resource consumption.
 * @param constructionStatus Initial construction status.
 * @param improvementLevel Initial improvement level.
 * @param resourcesAvailable Availability of resources.
 * @param notificationRadius Radius for citizen notifications.
 */
Landmark::Landmark(string name, int satisfaction, double economicImpact, double resourceConsumption, 
                   bool constructionStatus, int improvementLevel, bool resourcesAvailable, 
                   int notificationRadius)
    : name(name), satisfaction(satisfaction), economicImpact(economicImpact),
      resourceConsumption(resourceConsumption), constructionStatus(constructionStatus),
      improvementLevel(improvementLevel), resourcesAvailable(resourcesAvailable),
      citizenNotificationRadius(notificationRadius),
      Building(name, satisfaction, economicImpact, resourceConsumption, constructionStatus, 
               improvementLevel, resourcesAvailable, notificationRadius) {}

/**
 * @brief Retrieves the type of the landmark as a string.
 *
 * @return The name of the landmark, representing its type.
 */
string Landmark::getType() {
    return name;
}

/**
 * @brief Calculates and returns the satisfaction level for the landmark.
 *
 * @return The current satisfaction level.
 */
int Landmark::calculateSatisfaction() {
    return satisfaction;
}

/**
 * @brief Calculates and returns the economic impact of the landmark.
 *
 * @return The current economic impact.
 */
double Landmark::calculateEconomicImpact() {
    return economicImpact;
}

/**
 * @brief Calculates and returns the resource consumption of the landmark.
 *
 * @return The current resource consumption.
 */
double Landmark::calculateResourceConsumption() {
    return resourceConsumption;
}

/**
 * @brief Checks if the landmark's construction is complete.
 *
 * @return True if the construction is complete, false otherwise.
 */
bool Landmark::constructionComplete() {
    return constructionStatus;
}

/**
 * @brief Improves the landmark by increasing satisfaction and economic impact.
 *
 * If resources are available, the improvement level is increased, satisfaction
 * is boosted, and economic impact is adjusted.
 */
void Landmark::doImprovements() {
    if (checkResourceAvailability()) {
        improvementLevel++;
        satisfaction += 5; // Adjust as necessary
        economicImpact *= 1.1; // Adjust as necessary
    }
}

/**
 * @brief Checks if sufficient resources are available for improvements.
 *
 * @return True if resources are available, false otherwise.
 */
bool Landmark::checkResourceAvailability() {
    return resourcesAvailable;
}

/**
 * @brief Notifies citizens within a certain radius about the landmark.
 *
 * This method will be part of the observer pattern implementation to update citizens
 * affected by the landmark's presence or changes.
 */
void Landmark::notifyCitizens() {
    // Implementation required for notifying citizens.
}
