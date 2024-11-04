#ifndef RESIDENTIALCREATOR_H
#define RESIDENTIALCREATOR_H

#include "BuildingCreator.h"
#include <string>
using namespace std;

/**
 * @class ResidentialCreator
 * @brief A factory class for creating Residential buildings.
 *
 * The ResidentialCreator class inherits from BuildingCreator and provides
 * an interface for creating Residential building instances with specified attributes.
 */
class ResidentialCreator : public BuildingCreator {

public:
    /**
     * @brief Constructs a ResidentialCreator instance.
     *
     * This constructor initializes the ResidentialCreator object.
     */
    ResidentialCreator();

// protected:
    /**
     * @brief Creates a Residential building instance.
     *
     * This method initializes a new Residential building with the specified attributes
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
    Building* createBuilding(string name, int satisfaction, double economicImpact, 
                             double resourceConsumption, bool constructionStatus, 
                             int improvementLevel, bool resourcesAvailable, 
                             int capacity, string area);
};

#endif
