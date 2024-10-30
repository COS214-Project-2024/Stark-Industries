#ifndef INDUSTRIAL_H
#define INDUSTRIAL_H

#include "Building.h"
#include <string>
using namespace std;

/**
 * @class Industrial
 * @brief Represents an industrial building within the city simulation.
 *
 * The Industrial class inherits from Building and includes additional attributes
 * specific to industrial buildings, such as economic impact and resource consumption.
 * It provides methods to calculate building attributes, perform improvements, and
 * notify citizens within a certain radius.
 */
class Industrial : public Building {

private:
    string name;                  /**< Name of the industrial building. */
    int satisfaction;             /**< Satisfaction level for the industrial building. */
    double economicImpact;        /**< Economic impact factor of the building. */
    double resourceConsumption;   /**< Resource consumption level of the building. */
    bool constructionStatus;      /**< Indicates whether construction is complete. */
    int improvementLevel;         /**< Current improvement level of the building. */
    bool resourcesAvailable;      /**< Flag to indicate if resources are available for improvements. */
    int citizenNotificationRadius;/**< Radius for notifying citizens around the building. */

public:
    /**
     * @brief Constructs an Industrial building with specified attributes.
     *
     * @param name Name of the industrial building.
     * @param satisfaction Initial satisfaction rating.
     * @param economicImpact Initial economic impact.
     * @param resourceConsumption Initial resource consumption.
     * @param constructionStatus Initial construction status.
     * @param improvementLevel Initial improvement level.
     * @param resourcesAvailable Availability of resources.
     * @param notificationRadius Radius for citizen notifications.
     */
    Industrial(string name, int satisfaction, double economicImpact, double resourceConsumption, 
               bool constructionStatus, int improvementLevel, bool resourcesAvailable, int notificationRadius);

    Industrial();
    
    /**
     * @brief Retrieves the type or name of the industrial building.
     * @return The name of the industrial building.
     */
    string getType();

    /**
     * @brief Calculates and returns the satisfaction level of the building.
     * @return The current satisfaction level.
     */
    int calculateSatisfaction();

    /**
     * @brief Calculates and returns the economic impact of the building.
     * @return The current economic impact.
     */
    double calculateEconomicImpact();

    /**
     * @brief Calculates and returns the resource consumption of the building.
     * @return The current resource consumption.
     */
    double calculateResourceConsumption();

    /**
     * @brief Checks if the building construction is complete.
     * @return True if construction is complete, otherwise false.
     */
    bool constructionComplete();

    /**
     * @brief Performs improvements on the building, adjusting satisfaction and economic impact.
     *
     * Increases the improvement level if resources are available and enhances satisfaction and
     * economic impact accordingly.
     */
    void doImprovements();

    /**
     * @brief Checks the availability of resources required for building improvements.
     * @return True if resources are available, otherwise false.
     */
    bool checkResourceAvailability();

    /**
     * @brief Notifies citizens within a defined radius of the building.
     *
     * This function should be implemented to notify citizens in the area, potentially
     * as part of an observer pattern.
     */
	void notifyCitizens();

	Building* clone() const override; // Override the clone function


	//command functions
	void performAction(int type);
	//visitor functions
	void payTax(float taxRate);

	void acceptTaxCollector(Visitor * taxCollector);
	void acceptCitySatisfactionChecker(Visitor* satisfactionChecker);


private: 
	float propertyTaxRate = 0.015;
};

#endif
