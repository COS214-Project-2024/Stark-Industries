#include "ResidentialCreator.h" ///< Header for ResidentialCreator class.
#include "Residential.h" ///< Header for Residential class, representing residential buildings.


/**
 * @class ResidentialCreator
 * @brief A factory class for creating Residential building instances.
 *
 * The ResidentialCreator class inherits from BuildingCreator and provides
 * functionality to create Residential buildings with specified attributes.
 */
ResidentialCreator::ResidentialCreator() {
    // Constructor implementation (if needed)
}

/**
 * @brief Creates a Residential building instance.
 *
 * This function initializes a new Residential building with the specified attributes
 * and returns a pointer to the created Building object.
 *
 * @param name The name of the residential building.
 * @param satisfaction Initial satisfaction level of the residents.
 * @param economicImpact Initial economic impact of the residential building.
 * @param resourceConsumption The amount of resources consumed by the building.
 * @param constructionStatus Indicates if the building is under construction.
 * @param improvementLevel The current level of improvements made to the building.
 * @param resourcesAvailable Indicates whether resources are available for improvements.
 * @param notificationRadius The radius within which citizens are notified about the building.
 * @return A pointer to the newly created Residential building.
 */
Building* ResidentialCreator::createBuilding(string name, int satisfaction, double economicImpact, 
                                             double resourceConsumption, bool constructionStatus, 
                                             int improvementLevel, bool resourcesAvailable, 
                                             int capacity, string area) {
    buildings = new Residential(name, satisfaction, economicImpact, resourceConsumption, 
                                constructionStatus, improvementLevel, resourcesAvailable, 
                                capacity, area);
    return buildings;
}
