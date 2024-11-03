#include "Industrial.h"
#include "SatisfactionChecker.h"
#include <iostream>

int Industrial::numBuildings = 0;

/**
 * @brief Constructs an Industrial building with the given attributes.
 * 
 * @param name Name of the industrial building.
 * @param satisfaction Initial satisfaction score associated with the building.
 * @param economicImpact Initial economic impact generated by the building.
 * @param resourceConsumption Initial resource consumption of the building.
 * @param constructionStatus Boolean indicating whether construction is complete.
 * @param improvementLevel Initial improvement level of the building.
 * @param resourcesAvailable Boolean indicating if resources are available for improvements.
 * @param notificationRadius Radius within which citizens are notified of changes to the building.
 */

Industrial::Industrial(std::string name, int satisfaction, double economicImpact, 
                       double resourceConsumption, bool constructionStatus, 
                       int improvementLevel, bool resourcesAvailable, int capacity, string area)
    : Building(name, satisfaction, economicImpact, resourceConsumption, 
               constructionStatus, improvementLevel, resourcesAvailable, capacity, area), name(name), satisfaction(satisfaction), economicImpact(economicImpact),
      resourceConsumption(resourceConsumption), constructionStatus(constructionStatus),
      improvementLevel(improvementLevel), resourcesAvailable(resourcesAvailable),
      capacity(capacity), area(area) 
    {
        numBuildings;
    }

Industrial::Industrial() {

}

/**
 * @brief Returns the type of the building as its name.
 * 
 * @return A string representing the name/type of the industrial building.
 */
std::string Industrial::getType() {
    return name;
}

/**
 * @brief Calculates the satisfaction level for the industrial building.
 * 
 * @return An integer representing the satisfaction score.
 */
int Industrial::calculateSatisfaction() {
    return satisfaction;
}

/**
 * @brief Calculates the economic impact of the industrial building.
 * 
 * @return A double representing the economic impact value.
 */
double Industrial::calculateEconomicImpact() {
    return economicImpact;
}

/**
 * @brief Calculates the resource consumption of the industrial building.
 * 
 * @return A double representing the amount of resources consumed.
 */
double Industrial::calculateResourceConsumption() {
    return resourceConsumption;
}

/**
 * @brief Checks if the construction of the industrial building is complete.
 * 
 * @return True if construction is complete, false otherwise.
 */
bool Industrial::constructionComplete() {
    return constructionStatus;
}

/**
 * @brief Performs improvements on the industrial building.
 * 
 * If resources are available, the improvement level and satisfaction are increased, 
 * and the economic impact is boosted. Citizens observing the building are notified 
 * of the improvements.
 */
void Industrial::doImprovements() {
    if (checkResourceAvailability()) {
        improvementLevel++;
        satisfaction += 5;  // Increase satisfaction
        economicImpact *= 1.1;  // Boost economic impact slightly

        std::cout << "Industrial building improved!\nNew Improvement Level: " 
                  << improvementLevel << "\n";

        // Notify citizens about the improvements
        notifyCitizens();

		//update the citizens' satisfaction level for buildings 
		for (int i = 0 ; i < observerList.size(); i++) {
			observerList[i]->buildingSatisfaction += 5;
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
bool Industrial::checkResourceAvailability() {
	if (!resourcesAvailable){
		citySatisfaction -= 10;
			for (int i = 0 ; i < observerList.size(); i++) {
			observerList[i]->buildingSatisfaction -= 10;
			observerList[i]->citySatisfaction -= 8;
		}
	}
	else {
		citySatisfaction += 10;
		for (int i = 0 ; i < observerList.size(); i++) {
			observerList[i]->buildingSatisfaction += 10;
			observerList[i]->citySatisfaction += 8;
		}
	}
    return resourcesAvailable;
}

/**
 * @brief Notifies all attached citizens about changes to the industrial building.
 * 
 * Uses the base class implementation to notify all observers (citizens) about changes.
 */
void Industrial::notifyCitizens() {
    std::cout << "NOTIFICATION: New changes to " << name << "\n";
    Building::notifyCitizens();  // Call the base class notify method
}

//command functions
void Industrial::performAction(int type) {
	if(type == 0) {
		//collect tax
		std::cout<<"Property Tax collected from Industrial Building"<<std::endl;
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
void Industrial::payTax(float taxRate) {
	double tax = this->propertyTaxRate * this->buildingValue;
	this->buildingRevenue -= tax;
	taxPaid += tax;
	std::cout<<"Property Tax of: " << tax << " collected from " << this->name <<std::endl;

}

void Industrial::acceptTaxCollector(Visitor * taxCollector) {
	taxCollector->visit(this);
}

Building* Industrial::clone() const {
    return new Industrial(*this); // Create a new Commercial object using the copy constructor
}

void Industrial::acceptCitySatisfactionChecker(Visitor* satisfactionChecker){
	satisfactionChecker->citySatisfaction(this);
}

int Industrial::getNumBuildings() {
    return numBuildings;
}

bool Industrial::populateBuilding() {
    if (capacity > 0) {
        capacity--;  // Decrease capacity by one
        std::cout << "Citizen added to the building. Remaining capacity: " << capacity << std::endl;
        return true;
    } else {
        std::cout << "Building is at full capacity. Cannot add more citizens." << std::endl;
        return false;
    }
}

void Industrial::getCitizenSatisfactionForBuilding(){
	std::cout << "--Satisfaction of the citizens in the '" << this->name << "' building-- \n";
	SatisfactionChecker satisfactionChecker;
	for (int i = 0; i < observerList.size(); i++) {
		observerList[i]->acceptBuildingSatisfactionChecker(&satisfactionChecker);
	}
}

void Industrial::addUtility(Utilities* utility) {
    utilities.push_back(utility);
}

std::string Industrial::getBuildingType() {
	return "Industrial";
}