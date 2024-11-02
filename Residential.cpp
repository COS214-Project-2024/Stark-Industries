#include "Residential.h"
#include "SatisfactionChecker.h"
#include <iostream>

int Residential::numBuildings = 0;

/**
 * @brief Constructs a Residential building with the given attributes.
 * 
 * @param name Name of the residential building.
 * @param satisfaction Initial satisfaction score of the building.
 * @param economicImpact Initial economic impact contributed by the building.
 * @param resourceConsumption Initial resource consumption of the building.
 * @param constructionStatus Boolean indicating if the building is complete.
 * @param improvementLevel Initial improvement level of the building.
 * @param resourcesAvailable Boolean indicating if resources are available for improvements.
 * @param notificationRadius Radius within which citizens are notified about changes.
 */
Residential::Residential(std::string name, int satisfaction, double economicImpact, 
                         double resourceConsumption, bool constructionStatus, 
                         int improvementLevel, bool resourcesAvailable, int capacity, string area)
    : Building(name, satisfaction, economicImpact, resourceConsumption, 
               constructionStatus, improvementLevel, resourcesAvailable, capacity, area), name(name), satisfaction(satisfaction), economicImpact(economicImpact),
      resourceConsumption(resourceConsumption), constructionStatus(constructionStatus),
      improvementLevel(improvementLevel), resourcesAvailable(resourcesAvailable),
      capacity(capacity), area(area) 
    {
        numBuildings++;
    }

Residential::Residential() {

}

/**
 * @brief Returns the type of the building as its name.
 * 
 * @return A string representing the name/type of the residential building.
 */
std::string Residential::getType() {
    return name;
}

/**
 * @brief Calculates the satisfaction level for the residential building.
 * 
 * @return An integer representing the satisfaction score.
 */
int Residential::calculateSatisfaction() {
    return satisfaction;
}

/**
 * @brief Calculates the economic impact of the residential building.
 * 
 * @return A double representing the economic impact value.
 */
double Residential::calculateEconomicImpact() {
    return economicImpact;
}

/**
 * @brief Calculates the resource consumption of the residential building.
 * 
 * @return A double representing the amount of resources consumed.
 */
double Residential::calculateResourceConsumption() {
    return resourceConsumption;
}

/**
 * @brief Checks if the construction of the residential building is complete.
 * 
 * @return True if construction is complete, false otherwise.
 */
bool Residential::constructionComplete() {
    return constructionStatus;
}

/**
 * @brief Performs improvements on the residential building.
 * 
 * If resources are available, the improvement level and satisfaction are increased, 
 * and the economic impact is boosted. Citizens are notified of improvements.
 */
void Residential::doImprovements() {
    if (checkResourceAvailability()) {
        improvementLevel++;
        satisfaction += 5;  // Increase satisfaction
        economicImpact *= 1.1;  // Boost economic impact

        std::cout << "Residential building improved!\nNew Improvement Level: " 
                  << improvementLevel << "\n";

        // Notify citizens about the improvements (Observer pattern)
        notifyCitizens();

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
bool Residential::checkResourceAvailability() {
	if (resourcesAvailable) {
		citySatisfaction += 10;
	}
	else {
		citySatisfaction -= 10;
	}
    return resourcesAvailable;
}

/**
 * @brief Notifies all attached citizens about changes in the residential building.
 * 
 * Uses the base class implementation to notify all observers (citizens) about changes.
 */
void Residential::notifyCitizens() {
    std::cout << "NOTIFICATION: New changes to " << name << "\n";
    Building::notifyCitizens();  // Call the base class notify method
}

Building* Residential::clone() const {
    return new Residential(*this); // Create a new Commercial object using the copy constructor
}

//command functions
void Residential::performAction(int type) {
	if(type == 0) {
		//collect tax
		std::cout<<"Property Tax and Rental Income Tax collected from Residential Building"<<std::endl;
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
void Residential::payTax(float taxRate) {
	//property and rental income tax
	double pTax = buildingValue * propertyTaxRate;
	double rTax = buildingRevenue * rentalTaxRate;	
	std::cout<<"Property Tax: "<<pTax<<std::endl;
	std::cout<<"Rental Tax: "<<rTax<<std::endl;
	buildingRevenue -= pTax;
	buildingRevenue -= rTax;
	taxPaid += pTax;
	taxPaid += rTax;
}

void Residential::acceptTaxCollector(Visitor * taxCollector) {
	taxCollector->visit(this);
}

int Residential::getNumBuildings() {
    return numBuildings;
}

void Residential::acceptCitySatisfactionChecker(Visitor* satisfactionChecker){
	satisfactionChecker->visit(this);
}

void Residential::collectRent(){
	for (int i = 0 ; i < observerList.size(); i++) {
		observerList[i]->payRent(rent);
		buildingRevenue += rent;
		std::cout << "Collected rent from " << observerList[i]->getName() << std::endl;
	}
}

bool Residential::populateBuilding() {
    if (capacity > 0) {
        capacity--;  // Decrease capacity by one
        std::cout << "Citizen added to the building. Remaining capacity: " << capacity << std::endl;
        return true;
    } else {
        std::cout << "Building is at full capacity. Cannot add more citizens." << std::endl;
        return false;
    }
}

void Residential::getCitizenSatisfactionForBuilding(){
	std::cout << "--Satisfaction of the citizens in the '" << this->name << "' building-- \n";
	SatisfactionChecker satisfactionChecker;
	for (int i = 0; i < observerList.size(); i++) {
		observerList[i]->acceptBuildingSatisfactionChecker(&satisfactionChecker);
	}
}