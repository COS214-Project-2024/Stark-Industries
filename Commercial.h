#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include "Building.h"
#include <string>
using namespace std;

/**
 * @class Commercial
 * @brief Represents a commercial building in the city simulation.
 *
 * This class derives from the Building class and implements the necessary methods
 * to manage the characteristics and behaviors of a commercial building, such as
 * satisfaction, economic impact, resource consumption, and citizen notifications.
 */
class Commercial : public Building {

private:
    string name;                     ///< Name of the commercial building.
    int satisfaction;                ///< Satisfaction rating of the building.
    double economicImpact;           ///< Economic impact of the building.
    double resourceConsumption;      ///< Resource consumption by the building.
    bool constructionStatus;         ///< Status of the construction (completed or not).
    int improvementLevel;            ///< Level of improvements made to the building.
    bool resourcesAvailable;          ///< Availability of resources for the building.
    int citizenNotificationRadius;   ///< Notification radius for citizen alerts.
    int numBuildings;    
    string area;

public:
    /**
     * @brief Constructor for the Commercial class.
     *
     * Initializes a Commercial building with the specified parameters.
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
    Commercial(string name, int satisfaction, double economicImpact, 
               double resourceConsumption, bool constructionStatus, 
               int improvementLevel, bool resourcesAvailable, 
               int notificationRadius, string area);

    Commercial();

    /**
     * @brief Gets the type of building.
     *
     * @return A string representing the type of building.
     */
    string getType();

    /**
     * @brief Calculates the satisfaction rating of the building.
     *
     * @return The satisfaction rating.
     */
    int calculateSatisfaction();

    /**
     * @brief Calculates the economic impact of the building.
     *
     * @return The economic impact value.
     */
    double calculateEconomicImpact();

    /**
     * @brief Calculates the resource consumption of the building.
     *
     * @return The resource consumption value.
     */
    double calculateResourceConsumption();

    /**
     * @brief Checks if the construction of the building is complete.
     *
     * @return True if construction is complete, false otherwise.
     */
    bool constructionComplete();

    /**
     * @brief Performs improvements to the building.
     *
     * If resources are available, increases the improvement level, 
     * adjusts satisfaction, and modifies economic impact.
     */
    void doImprovements();

    /**
     * @brief Checks the availability of resources for the building.
     *
     * @return True if resources are available, false otherwise.
     */
    bool checkResourceAvailability();

    /**
     * @brief Notifies citizens about updates regarding the building.
     *
     * This method should implement the observer pattern logic to notify 
     * citizens observing the building of any changes or updates.
     */
    void notifyCitizens();

    Building* clone() const override; // Override the clone function

	void checkReasourceAvailability();

	//command functions
	void performAction(int type);
	//visitor functions
	void payTax(float taxRate);
	void acceptTaxCollector(Visitor * taxCollector);
	void acceptCitySatisfactionChecker(Visitor* satisfactionChecker);

    int getNumBuildings();
private:
	float propertyTaxRate = 0.015;
	float salesTaxRate = 0.15;
};

#endif
