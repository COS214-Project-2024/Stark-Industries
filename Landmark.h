#ifndef LANDMARK_H
#define LANDMARK_H

#include "Building.h"
#include <string>
using namespace std;

/**
 * @brief Represents a Landmark building in the city simulation.
 *
 * The Landmark class is derived from the Building base class and contains
 * attributes specific to landmarks, such as satisfaction level, economic impact,
 * resource consumption, construction status, and improvement level.
 */
class Landmark : public Building {

private:
    string name;                    /**< Name of the landmark */
    int satisfaction;               /**< Satisfaction level of the landmark */
    double economicImpact;          /**< Economic impact of the landmark */
    double resourceConsumption;     /**< Resource consumption level */
    bool constructionStatus;        /**< Construction completion status */
    int improvementLevel;           /**< Improvement level of the landmark */
    bool resourcesAvailable;        /**< Resource availability status */
    int citizenNotificationRadius;  /**< Radius for notifying citizens */

public:

    /**
     * @brief Constructs a Landmark with the specified attributes.
     *
     * @param name Name of the landmark.
     * @param satisfaction Initial satisfaction level.
     * @param economicImpact Initial economic impact.
     * @param resourceConsumption Initial resource consumption.
     * @param constructionStatus Whether construction is complete.
     * @param improvementLevel Initial improvement level.
     * @param resourcesAvailable Availability of resources.
     * @param notificationRadius Radius for notifying citizens.
     */
    Landmark(string name, int satisfaction, double economicImpact, double resourceConsumption, 
             bool constructionStatus, int improvementLevel, bool resourcesAvailable, 
             int notificationRadius);

    /**
     * @brief Retrieves the type or name of the landmark.
     * @return The name of the landmark.
     */
    string getType();

    /**
     * @brief Calculates and returns the satisfaction level of the landmark.
     * @return The current satisfaction level.
     */
    int calculateSatisfaction();

    /**
     * @brief Calculates and returns the economic impact of the landmark.
     * @return The current economic impact.
     */
    double calculateEconomicImpact();

    /**
     * @brief Calculates and returns the resource consumption of the landmark.
     * @return The current resource consumption level.
     */
    double calculateResourceConsumption();

    /**
     * @brief Checks if the landmark's construction is complete.
     * @return True if construction is complete, otherwise false.
     */
    bool constructionComplete();

    /**
     * @brief Improves the landmark by increasing satisfaction and economic impact.
     *
     * Checks if resources are available and, if so, increments the improvement level,
     * increases satisfaction, and adjusts economic impact accordingly.
     */
    void doImprovements();

    /**
     * @brief Checks if resources are available for improvements.
     * @return True if resources are available, otherwise false.
     */
    bool checkResourceAvailability();

    /**
     * @brief Notifies citizens within a certain radius about the landmark.
     *
     * This method will notify citizens as part of the observer pattern,
     * informing them of updates related to the landmark.
     */
    void notifyCitizens();
	void notifyCitizens();

	Building* clone() const override; // Override the clone function

};

#endif
