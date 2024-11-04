#ifndef COMMERCIALCREATOR_H
#define COMMERCIALCREATOR_H

#include "BuildingCreator.h"
#include <string>
using namespace std;

/**
 * @class CommercialCreator
 * @brief A creator class for creating Commercial building objects.
 *
 * This class implements the factory method to create instances of Commercial buildings.
 * It inherits from BuildingCreator and overrides the createBuilding method.
 */
class CommercialCreator : public BuildingCreator {

public:
    /**
     * @brief Constructor for the CommercialCreator class.
     *
     * Initializes a CommercialCreator object, responsible for creating 
     * Commercial building instances.
     */
    CommercialCreator();

// protected:
    /**
     * @brief Creates a new Commercial building.
     *
     * This method constructs a new instance of a Commercial building with the given parameters.
     *
     * @param name Name of the commercial building.
     * @param satisfaction Initial satisfaction rating.
     * @param economicImpact Initial economic impact.
     * @param resourceConsumption Initial resource consumption.
     * @param constructionStatus Initial construction status.
     * @param improvementLevel Initial improvement level.
     * @param resourcesAvailable Availability of resources.
     * @param notificationRadius Radius for citizen notifications.
     * 
     * @return A pointer to the created Building object.
     */
    Building* createBuilding(string name, int satisfaction, double economicImpact, 
                             double resourceConsumption, bool constructionStatus, 
                             int improvementLevel, bool resourcesAvailable, 
                             int capacity, string area);
};

#endif
