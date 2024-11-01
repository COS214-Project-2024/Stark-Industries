#ifndef INDUSTRIALCREATOR_H
#define INDUSTRIALCREATOR_H

#include "BuildingCreator.h"
#include <string>
using namespace std;

/**
 * @class IndustrialCreator
 * @brief A concrete creator class responsible for creating Industrial building instances.
 *
 * IndustrialCreator implements the Factory Method pattern, specifically for creating instances
 * of Industrial buildings with specified characteristics.
 */
class IndustrialCreator : public BuildingCreator {

public:
    /**
     * @brief Constructs an IndustrialCreator object.
     *
     * Initializes the IndustrialCreator, which will be used to create Industrial building instances.
     */
    IndustrialCreator();

// protected:
    /**
     * @brief Creates a new Industrial building with specified attributes.
     *
     * This function is part of the Factory Method pattern, responsible for creating
     * and initializing a new Industrial building based on provided parameters.
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
    Building* createBuilding(string name, int satisfaction, double economicImpact, 
                             double resourceConsumption, bool constructionStatus, 
                             int improvementLevel, bool resourcesAvailable, 
                             int notificationRadius, string area);
};

#endif
