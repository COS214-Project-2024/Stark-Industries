#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

#include "Building.h"
#include "Citizen.h"
#include <string>
#include <vector>
using namespace std;

/**
 * @class Residential
 * @brief Represents a residential building with various attributes and functionalities.
 *
 * The Residential class inherits from the Building class and encapsulates attributes
 * such as satisfaction levels, economic impact, resource consumption, and improvement
 * levels. It also provides methods to calculate these attributes and manage building
 * improvements and notifications to citizens.
 */
class Residential : public Building {

private:
    string name; ///< The name of the residential building.
    int satisfaction; ///< Current satisfaction level of the residents.
    double economicImpact; ///< Economic impact of the residential building.
    double resourceConsumption; ///< Resource consumption by the residential building.
    bool constructionStatus; ///< Indicates if the building is under construction.
    int improvementLevel; ///< Current level of improvements made to the building.
    bool resourcesAvailable; ///< Indicates if resources are available for improvements.
    int capacity; ///< Radius for notifying citizens about the building.
    string area;
    static int numBuildings;
    std::vector<Citizen*> occupants; 

public:

    /**
     * @brief Constructs a Residential building with specified attributes.
     *
     * @param name The name of the residential building.
     * @param satisfaction Initial satisfaction level of the residents.
     * @param economicImpact Initial economic impact of the residential building.
     * @param resourceConsumption The amount of resources consumed by the building.
     * @param constructionStatus Indicates if the building is under construction.
     * @param improvementLevel The current level of improvements made to the building.
     * @param resourcesAvailable Indicates whether resources are available for improvements.
     * @param notificationRadius The radius within which citizens are notified about the building.
     */
    Residential(string name, int satisfaction, double economicImpact, double resourceConsumption, 
                bool constructionStatus, int improvementLevel, bool resourcesAvailable, 
                int capacity, string area);

    Residential();
    
    /**
     * @brief Retrieves the type of the residential building.
     *
     * @return The name of the residential building.
     */
    string getType();

    /**
     * @brief Calculates the current satisfaction level of the residents.
     *
     * @return The current satisfaction level.
     */
    int calculateSatisfaction();

    /**
     * @brief Calculates the economic impact of the residential building.
     *
     * @return The economic impact value.
     */
    double calculateEconomicImpact();

    /**
     * @brief Calculates the resource consumption of the residential building.
     *
     * @return The resource consumption value.
     */
    double calculateResourceConsumption();

    /**
     * @brief Checks if the construction of the residential building is complete.
     *
     * @return True if the construction is complete, false otherwise.
     */
    bool constructionComplete();

    /**
     * @brief Performs improvements on the residential building.
     *
     * Increases the improvement level and adjusts satisfaction and economic impact
     * if resources are available.
     */
    void doImprovements();

    /**
     * @brief Checks the availability of resources for improvements.
     *
     * @return True if resources are available, false otherwise.
     */
    bool checkResourceAvailability();

    /**
     * @brief Notifies citizens about changes related to the residential building.
     *
     * This function should implement the observer pattern to inform citizens.
     */
	void notifyCitizens();

    Building* clone() const override; // Override the clone function


	//command functions
	void performAction(int type);
	//visitor functions
	void payTax(float taxRate);

	void acceptTaxCollector(Visitor * taxCollector);
	void acceptCitySatisfactionChecker(Visitor* satisfactionChecker);
	void collectRent();

    int getNumBuildings();

    bool populateBuilding();

    void addUtility(Utilities* utility);

    int getAvailableCapacity() const;

    int getOccupantCount() const;

private:
	float propertyTaxRate = 0.01;
	float rentalTaxRate = 0.20;
};

#endif
