/**
 * @file CommercialCreator.cpp
 * @brief Implements the CommercialCreator class, responsible for creating instances of Commercial buildings.
 */

#include "CommercialCreator.h"
#include "Commercial.h"

/**
 * @brief Constructor for the CommercialCreator class.
 *
 * Initializes a CommercialCreator object, which is responsible for creating 
 * instances of Commercial buildings.
 */
CommercialCreator::CommercialCreator() {}

/**
 * @brief Creates a new Commercial building.
 *
 * This function creates a new Commercial building using the specified parameters
 * and returns a pointer to the Building base class.
 *
 * @param name Name of the commercial building.
 * @param satisfaction Initial satisfaction rating.
 * @param economicImpact Initial economic impact.
 * @param resourceConsumption Initial resource consumption.
 * @param constructionStatus Initial construction status.
 * @param improvementLevel Initial improvement level.
 * @param resourcesAvailable Availability of resources.
 * @param capacity Maximum capacity of the building.
 * @param area Geographic area or location of the building.
 * 
 * @return A pointer to the created Building object.
 */
Building* CommercialCreator::createBuilding(std::string name, int satisfaction, 
                                            double economicImpact, 
                                            double resourceConsumption, 
                                            bool constructionStatus, 
                                            int improvementLevel, 
                                            bool resourcesAvailable, 
                                            int capacity, std::string area) {
    buildings = new Commercial(name, satisfaction, economicImpact, 
                               resourceConsumption, constructionStatus, 
                               improvementLevel, resourcesAvailable, 
                               capacity, area);
    return buildings;
}
