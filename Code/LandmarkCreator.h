#ifndef LANDMARKCREATOR_H
#define LANDMARKCREATOR_H

#include "BuildingCreator.h"
#include <string>
using namespace std;

/**
 * @brief The LandmarkCreator class is responsible for creating Landmark building objects.
 *
 * This class provides a factory method to create instances of the Landmark class, initializing
 * each landmark with specified attributes such as satisfaction level, economic impact, and more.
 */
class LandmarkCreator : public BuildingCreator {

public:
    /**
     * @brief Default constructor for the LandmarkCreator class.
     *
     * Initializes a LandmarkCreator instance. Primarily used to create Landmark buildings.
     */
    LandmarkCreator();

public: // Should be protected
    /**
     * @brief Creates a Landmark building with specified attributes.
     *
     * This method dynamically creates a new Landmark building using the provided parameters.
     *
     * @param name The name of the landmark.
     * @param satisfaction Initial satisfaction level associated with the landmark.
     * @param economicImpact Initial economic impact the landmark provides.
     * @param resourceConsumption The resource consumption level of the landmark.
     * @param constructionStatus Indicates whether the landmark construction is complete.
     * @param improvementLevel The initial improvement level of the landmark.
     * @param resourcesAvailable Boolean indicating resource availability for the landmark.
     * @param notificationRadius Radius within which citizens are notified about the landmark.
     * @return A pointer to the newly created Landmark building.
     */
    Building* createBuilding(string name, int satisfaction, double economicImpact, 
                             double resourceConsumption, bool constructionStatus, 
                             int improvementLevel, bool resourcesAvailable, 
                             int capacity, string area);
};

#endif // LANDMARKCREATOR_H
