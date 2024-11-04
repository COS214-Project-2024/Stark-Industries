/**
 * @file LandmarkCreator.cpp
 * @brief Implements the LandmarkCreator class, which is responsible for creating instances of Landmark buildings using the Factory Method pattern.
 */

#include "LandmarkCreator.h"
#include "Landmark.h"

/**
 * @brief Default constructor for the LandmarkCreator class.
 *
 * Initializes a LandmarkCreator, responsible for creating Landmark buildings.
 */
LandmarkCreator::LandmarkCreator() {
    // No specific initialization needed
}

/**
 * @brief Creates a new Landmark building with the specified attributes.
 *
 * This method dynamically allocates a new Landmark object with the provided
 * parameters and returns a pointer to the created building.
 *
 * @param name The name of the landmark.
 * @param satisfaction Initial satisfaction level associated with the landmark.
 * @param economicImpact Initial economic impact of the landmark.
 * @param resourceConsumption Initial resource consumption level.
 * @param constructionStatus Indicates if the landmark's construction is complete.
 * @param improvementLevel Initial improvement level of the landmark.
 * @param resourcesAvailable Whether resources are available for the landmark.
 * @param capacity Maximum capacity of the landmark.
 * @param area Geographic area or zone where the landmark is located.
 * @return A pointer to the newly created Landmark building.
 */
Building* LandmarkCreator::createBuilding(std::string name, int satisfaction, double economicImpact, 
                                          double resourceConsumption, bool constructionStatus, 
                                          int improvementLevel, bool resourcesAvailable, 
                                          int capacity, std::string area) {
    buildings = new Landmark(name, satisfaction, economicImpact, resourceConsumption, 
                             constructionStatus, improvementLevel, resourcesAvailable, 
                             capacity, area);
    return buildings;
}
