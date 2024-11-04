/**
 * @file Commercial.cpp
 * @brief Implements the Commercial class, representing a commercial building that contributes to city satisfaction, economic impact, and resource management.
 */

#include "Commercial.h"
#include <iostream>
#include "SatisfactionChecker.h"

int Commercial::numBuildings = 0;

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
 * @param capacity Maximum capacity of the building.
 * @param area Geographic area where the building is located.
 */
Commercial::Commercial(std::string name, int satisfaction, double economicImpact, 
                       double resourceConsumption, bool constructionStatus, 
                       int improvementLevel, bool resourcesAvailable, int capacity, std::string area)
    : Building(name, satisfaction, economicImpact, resourceConsumption, 
               constructionStatus, improvementLevel, resourcesAvailable, capacity, area), 
      name(name), satisfaction(satisfaction), economicImpact(economicImpact),
      resourceConsumption(resourceConsumption), constructionStatus(constructionStatus),
      improvementLevel(improvementLevel), resourcesAvailable(resourcesAvailable),
      capacity(capacity), area(area) {
    numBuildings++;
    buildingRevenue = 100;
}

/**
 * @brief Default constructor for the Commercial class.
 */
Commercial::Commercial() {
    numBuildings++;
    buildingRevenue = 100;
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
 * and the economic impact is boosted. Citizens observing the building are notified 
 * of the improvements.
 */
void Commercial::doImprovements() {
    if (checkResourceAvailability()) {
        improvementLevel++;
        satisfaction += 5;
        economicImpact *= 1.1;

        std::cout << "Commercial building improved!\nNew Improvement Level: " 
                  << improvementLevel << "\n";
        notifyCitizens();

        for (auto& observer : observerList) {
            observer->buildingSatisfaction += 5;
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
        for (auto& observer : observerList) {
            observer->buildingSatisfaction += 10;
            observer->citySatisfaction += 8;
        }
    } else {
        citySatisfaction -= 10;
        for (auto& observer : observerList) {
            observer->buildingSatisfaction -= 10;
            observer->citySatisfaction -= 8;
        }
    }
    return resourcesAvailable;
}

/**
 * @brief Notifies all attached citizens about changes to the commercial building.
 */
void Commercial::notifyCitizens() {
    std::cout << "NOTIFICATION: New changes to " << name << "\n";
    Building::notifyCitizens();
}

/**
 * @brief Creates a clone of the commercial building.
 * 
 * @return A pointer to the newly created clone of the Commercial object.
 */
Building* Commercial::clone() const {
    return new Commercial(*this);
}

/**
 * @brief Performs an action on the building based on the specified type.
 * 
 * @param type Type of action to perform, such as collecting tax, allocating tax, or increasing tax.
 */
void Commercial::performAction(int type) {
    if (type == 0) {
        payTax(0);
    } else if (type == 1) {
        std::cout << "Tax allocated" << std::endl;
    } else if (type == 2) {
        std::cout << "Tax increased" << std::endl;
    } else {
        std::cout << "Invalid command" << std::endl;
    }
}

/**
 * @brief Collects property and sales tax from the commercial building.
 * 
 * @param taxRate The tax rate applied for calculation.
 */
void Commercial::payTax(float taxRate) {
    double propertyTax = buildingValue * propertyTaxRate;
    double salesTax = buildingRevenue * salesTaxRate;
    buildingRevenue -= propertyTax + salesTax;
    taxPaid += propertyTax + salesTax;
    std::cout << "Property Tax of: " << propertyTax << " and Sales Tax of: " 
              << salesTax << " collected from " << this->name << std::endl;
}

/**
 * @brief Accepts a tax collector visitor.
 * 
 * @param taxCollector Pointer to the Visitor object responsible for tax collection.
 */
void Commercial::acceptTaxCollector(Visitor* taxCollector) {
    taxCollector->visit(this);
}

/**
 * @brief Accepts a city satisfaction checker visitor.
 * 
 * @param satisfactionChecker Pointer to the Visitor object for checking city satisfaction.
 */
void Commercial::acceptCitySatisfactionChecker(Visitor* satisfactionChecker) {
    satisfactionChecker->citySatisfaction(this);
}

/**
 * @brief Returns the total number of commercial buildings.
 * 
 * @return Total count of Commercial buildings.
 */
int Commercial::getNumBuildings() {
    return numBuildings;
}

/**
 * @brief Adds a citizen to the building if capacity is available.
 * 
 * @return True if the citizen is added, false if the building is at full capacity.
 */
bool Commercial::populateBuilding() {
    if (capacity > 0) {
        capacity--;
        std::cout << "Citizen added to the building. Remaining capacity: " << capacity << std::endl;
        return true;
    } else {
        std::cout << "Building is at full capacity. Cannot add more citizens." << std::endl;
        return false;
    }
}

/**
 * @brief Displays satisfaction levels of citizens in the building.
 */
void Commercial::getCitizenSatisfactionForBuilding() {
    std::cout << "--Satisfaction of the citizens in the '" << this->name << "' building-- \n";
    SatisfactionChecker satisfactionChecker;
    for (auto& observer : observerList) {
        observer->acceptBuildingSatisfactionChecker(&satisfactionChecker);
    }
}

/**
 * @brief Generates revenue for the commercial building.
 */
void Commercial::generateRevenue() {
    buildingRevenue *= 35;
}

/**
 * @brief Adds a utility to the commercial building.
 * 
 * @param utility Pointer to the Utilities object to add.
 */
void Commercial::addUtility(Utilities* utility) {
    utilities.push_back(utility);
}

/**
 * @brief Gets the type of the building as "Commercial".
 * 
 * @return A string representing the building type.
 */
std::string Commercial::getBuildingType() {
    return "Commercial";
}

/**
 * @brief Sets the total number of commercial buildings.
 * 
 * @param count The new total count of Commercial buildings.
 */
void Commercial::setNumBuildings(int count) { 
    numBuildings = count; 
}
