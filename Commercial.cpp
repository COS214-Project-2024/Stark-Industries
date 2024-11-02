#include "Commercial.h"
#include <iostream>

/**
 * @brief Constructs a Commercial building with the given attributes.
 * 
 * @param name Name of the commercial building.
 * @param satisfaction Initial satisfaction score of the building.
 * @param economicImpact Initial economic impact contributed by the building.
 * @param resourceConsumption Initial resource consumption of the building.
 * @param constructionStatus Boolean indicating if the building construction is complete.
 * @param improvementLevel Initial improvement level of the building.
 * @param resourcesAvailable Boolean indicating if resources are available for improvements.
 * @param notificationRadius Radius within which citizens are notified of changes to the building.
 */

int Commercial::numBuildings = 0;

Commercial::Commercial(std::string name, int satisfaction, double economicImpact, 
                       double resourceConsumption, bool constructionStatus, 
                       int improvementLevel, bool resourcesAvailable, int capacity, string area)
    : Building(name, satisfaction, economicImpact, resourceConsumption, 
               constructionStatus, improvementLevel, resourcesAvailable, capacity, area), name(name), satisfaction(satisfaction), economicImpact(economicImpact),
      resourceConsumption(resourceConsumption), constructionStatus(constructionStatus),
      improvementLevel(improvementLevel), resourcesAvailable(resourcesAvailable),
      capacity(capacity), area(area) {
        numBuildings++;
      }

Commercial::Commercial() {

}

/**
 * @brief Returns the type of the building as its name.
 * 
 * @return A string representing the name/type of the commercial building.
 */
std::string Commercial::getType() {
    return name;
}

/**
 * @brief Calculates the satisfaction level for the commercial building.
 * 
 * @return An integer representing the satisfaction score.
 */
int Commercial::calculateSatisfaction() {
    return satisfaction;
}

/**
 * @brief Calculates the economic impact of the commercial building.
 * 
 * @return A double representing the economic impact value.
 */
double Commercial::calculateEconomicImpact() {
    return economicImpact;
}

/**
 * @brief Calculates the resource consumption of the commercial building.
 * 
 * @return A double representing the amount of resources consumed.
 */
double Commercial::calculateResourceConsumption() {
    return resourceConsumption;
}

/**
 * @brief Checks if the construction of the commercial building is complete.
 * 
 * @return True if construction is complete, false otherwise.
 */
bool Commercial::constructionComplete() {
    return constructionStatus;
}

/**
 * @brief Performs improvements on the commercial building.
 * 
 * If resources are available, the improvement level and satisfaction are increased, 
 * and the economic impact is boosted. Citizens are notified of the improvements.
 */
void Commercial::doImprovements() {
    if (checkResourceAvailability()) {
        improvementLevel++;
        satisfaction += 5;  // Increase satisfaction
        economicImpact *= 1.1;  // Boost economic impact slightly

        std::cout << "Commercial building improved!\nNew Improvement Level: " 
                  << improvementLevel << "\n";

        // Notify citizens about the improvement
        notifyCitizens();

		for (int i = 0 ; i < observerList.size(); i++) {
			//observerList[i]->buildingSatisfaction += 5; //Fix this
		}
    } else {
        std::cout << "Resources unavailable for improvements.\n";
    }
}

/**
 * @brief Checks if resources are available for improvements.
 * 
 * @return True if resources are available, false otherwise.
 */
bool Commercial::checkResourceAvailability() {
	if (resourcesAvailable) {
		citySatisfaction += 10;
	}
	else {
		citySatisfaction -= 10;
	}
    return resourcesAvailable;
}

/**
 * @brief Notifies all attached citizens about changes to the commercial building.
 * 
 * Uses the base class implementation to notify all observers (citizens) about changes.
 */
void Commercial::notifyCitizens() {
    std::cout << "NOTIFICATION: New changes to " << name << "\n";
    Building::notifyCitizens();  // Call the base class notify method
}

Building* Commercial::clone() const {
    return new Commercial(*this); // Create a new Commercial object using the copy constructor
}

//command functions
void Commercial::performAction(int type) {
	if(type == 0) {
		//collect tax
		//std::cout<<"Have to collect Property T"<<std::endl;
		std::cout<<"Property and Sales Tax collected"<<std::endl;
		payTax(0);
	}
	else if(type == 1) {
		//allocate tax
		std::cout<<"Tax allocated"<<std::endl;
	}
	else if(type == 2) {
		//increase tax
		std::cout<<"Tax increased"<<std::endl;
	}
	else {
		std::cout<<"Invalid command"<<std::endl;
	}
}

//visitor functions
void Commercial::payTax(float taxRate) {
	double propertyTax = buildingValue * propertyTaxRate;
	double salesTax = buildingRevenue * salesTaxRate;
	buildingRevenue -= propertyTax + salesTax;
	taxPaid += propertyTax + salesTax;
	std::cout<<"Property Tax of: " << propertyTax << " and Sales Tax of: " << salesTax << " collected"<<std::endl;												
}

void Commercial::acceptTaxCollector(Visitor * taxCollector) {
	taxCollector->visit(this);
}

void Commercial::acceptCitySatisfactionChecker(Visitor* satisfactionChecker){
	satisfactionChecker->visit(this);
}

int Commercial::getNumBuildings() {
    return numBuildings;
}

bool Commercial::populateBuilding() {
    if (capacity > 0) {
        capacity--;  // Decrease capacity by one
        std::cout << "Citizen added to the building. Remaining capacity: " << capacity << std::endl;
        return true;
    } else {
        std::cout << "Building is at full capacity. Cannot add more citizens." << std::endl;
        return false;
    }
}

void Commercial::addUtility(Utilities* utility) {
    utilities.push_back(utility);
}