#ifndef BUILDINGCREATOR_H
#define BUILDINGCREATOR_H

#include "Building.h"
#include <string>
using namespace std;

/**
 * @class BuildingCreator
 * @brief Abstract base class for creating buildings.
 *
 * This class provides a blueprint for concrete building creators, defining the
 * necessary method for creating building instances. Derived classes must implement
 * the building creation logic.
 */
class BuildingCreator {

protected:
    Building* buildings;  ///< Pointer to the created building instance.

    /**
     * @brief Abstract method for creating a building.
     *
     * Derived classes must implement this method to create specific types of buildings.
     *
     * @param name Name of the building.
     * @param satisfaction Initial satisfaction rating.
     * @param economicImpact Initial economic impact.
     * @param resourceConsumption Initial resource consumption.
     * @param constructionStatus Initial construction status.
     * @param improvementLevel Initial improvement level.
     * @param resourcesAvailable Availability of resources.
     * @param notificationRadius Radius for citizen notifications.
     * @return A pointer to the created Building instance.
     */
    virtual Building* createBuilding(string name, int satisfaction, double economicImpact, 
                                      double resourceConsumption, bool constructionStatus, 
                                      int improvementLevel, bool resourcesAvailable, 
                                      int notificationRadius, string area) = 0;

public:
    /// Default destructor.
    virtual ~BuildingCreator() = default;
};

#endif
