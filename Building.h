#ifndef BUILDING_H
#define BUILDING_H

#include "Element.h"
#include "Utilities.h"
#include "Citizen.h"
#include <string>
#include <vector>
using namespace std;

/**
 * @class Building
 * @brief Abstract base class representing a building in the city simulation.
 *
 * This class provides a blueprint for different types of buildings, allowing for
 * the calculation of satisfaction, economic impact, resource consumption, and
 * handling of citizen notifications.
 */
class Building : public Element {
private:
    /// List of utilities associated with the building.
    vector<Utilities*> utilities;
    
    /// List of citizens observing this building.
    std::vector<Citizen*> observerList; // vector so that multiple citizens can be attached

    string name;                     ///< Name of the building.
    int satisfaction;                ///< Satisfaction rating of the building.
    double economicImpact;           ///< Economic impact of the building.
    double resourceConsumption;      ///< Resource consumption by the building.
    bool constructionStatus;         ///< Status of the construction (completed or not).
    int improvementLevel;            ///< Level of improvements made to the building.
    bool resourcesAvailable;          ///< Availability of resources for the building.
    int citizenNotificationRadius;   ///< Notification radius for citizen alerts.

public:
    /**
     * @brief Constructor for the Building class.
     * 
     * @param name Name of the building.
     * @param satisfaction Initial satisfaction rating.
     * @param economicImpact Initial economic impact.
     * @param resourceConsumption Initial resource consumption.
     * @param constructionStatus Initial construction status.
     * @param improvementLevel Initial improvement level.
     * @param resourcesAvailable Availability of resources.
     * @param notificationRadius Radius for citizen notifications.
     */
    Building(string name, int satisfaction, double economicImpact, double resourceConsumption, 
             bool constructionStatus, int improvementLevel, bool resourcesAvailable, 
             int notificationRadius);

    /// Default destructor.
    virtual ~Building() = default;

    /**
     * @brief Retrieves building information.
     */
    void get();

    /**
     * @brief Sets building parameters.
     */
    void set();

    /**
     * @brief Gets the type of the building.
     * 
     * @return A string representing the building type.
     */
    virtual string getType() = 0;

    /**
     * @brief Calculates the satisfaction rating of the building.
     * 
     * @return The calculated satisfaction rating.
     */
    virtual int calculateSatisfaction() = 0;

    /**
     * @brief Calculates the economic impact of the building.
     * 
     * @return The calculated economic impact.
     */
    virtual double calculateEconomicImpact() = 0;

    /**
     * @brief Calculates the resource consumption of the building.
     * 
     * @return The calculated resource consumption.
     */
    virtual double calculateResourceConsumption() = 0;

    /**
     * @brief Checks if the construction of the building is complete.
     * 
     * @return True if construction is complete, false otherwise.
     */
    virtual bool constructionComplete() = 0;

    /**
     * @brief Performs improvements to the building.
     */
    virtual void doImprovements() = 0;

	//Observer functions
	void attach(Citizen* observer);
	void detach(Citizen* observer);
	virtual void notifyCitizens() = 0;
};

#endif
