#include "IndustrialCreator.h"
#include "Industrial.h"

/**
 * @brief Constructs an IndustrialCreator object.
 *
 * The IndustrialCreator is responsible for creating Industrial building instances
 * using the Factory Method pattern.
 */
IndustrialCreator::IndustrialCreator() {
}

/**
 * @brief Creates a new Industrial building with specified parameters.
 *
 * This function uses the Factory Method pattern to create a new Industrial building
 * with the given attributes and returns a pointer to it.
 *
 * @param name Name of the industrial building.
 * @param satisfaction Initial satisfaction rating.
 * @param economicImpact Initial economic impact.
 * @param resourceConsumption Initial resource consumption.
 * @param constructionStatus Initial construction status.
 * @param improvementLevel Initial improvement level.
 * @param resourcesAvailable Availability of resources.
 * @param notificationRadius Radius for citizen notifications.
 * @return A pointer to the newly created Industrial building.
 */
Building* IndustrialCreator::createBuilding(string name, int satisfaction, double economicImpact, 
                                            double resourceConsumption, bool constructionStatus, 
                                            int improvementLevel, bool resourcesAvailable, 
                                            int notificationRadius) {
    buildings = new Industrial(name, satisfaction, economicImpact, resourceConsumption, 
                               constructionStatus, improvementLevel, resourcesAvailable, 
                               notificationRadius);
    return buildings;
}
