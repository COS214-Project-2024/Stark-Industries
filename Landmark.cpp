/**
 * @file Landmark.cpp
 * @brief Implements the Landmark class, representing a landmark building that influences satisfaction, economic impact, and resource consumption in a city.
 */

#include "Landmark.h"
#include <iostream>

int Landmark::numBuildings = 0;

/**
 * @brief Constructs a Landmark building with the given attributes.
 * 
 * @param name Name of the landmark.
 * @param satisfaction Initial satisfaction score of the landmark.
 * @param economicImpact Initial economic impact contributed by the landmark.
 * @param resourceConsumption Initial resource consumption of the landmark.
 * @param constructionStatus Boolean indicating if the landmark construction is complete.
 * @param improvementLevel Initial improvement level of the landmark.
 * @param resourcesAvailable Boolean indicating if resources are available for improvements.
 * @param capacity Maximum capacity of the landmark.
 * @param area Geographic area or location of the landmark.
 */
Landmark::Landmark(std::string name, int satisfaction, double economicImpact, 
                   double resourceConsumption, bool constructionStatus, 
                   int improvementLevel, bool resourcesAvailable, int capacity, std::string area)
    : Building(name, satisfaction, economicImpact, resourceConsumption, 
               constructionStatus, improvementLevel, resourcesAvailable, capacity, area), 
      name(name), satisfaction(satisfaction), economicImpact(economicImpact),
      resourceConsumption(resourceConsumption), constructionStatus(constructionStatus),
      improvementLevel(improvementLevel), resourcesAvailable(resourcesAvailable),
      capacity(capacity), area(area) {
    numBuildings++;
}

/**
 * @brief Default constructor for the Landmark class.
 */
Landmark::Landmark() {}

/**
 * @brief Returns the type of the building as its name.
 * 
 * @return A string representing the name/type of the landmark.
 */
std::string Landmark::getType() {
    return name;
}

/**
 * @brief Calculates the satisfaction level for the landmark.
 * 
 * @return An integer representing the satisfaction score.
 */
int Landmark::calculateSatisfaction() {
    return satisfaction;
}

/**
 * @brief Calculates the economic impact of the landmark.
 * 
 * @return A double representing the economic impact value.
 */
double Landmark::calculateEconomicImpact() {
    return economicImpact;
}

/**
 * @brief Calculates the resource consumption of the landmark.
 * 
 * @return A double representing the amount of resources consumed.
 */
double Landmark::calculateResourceConsumption() {
    return resourceConsumption;
}

/**
 * @brief Checks if the construction of the landmark is complete.
 * 
 * @return True if construction is complete, false otherwise.
 */
bool Landmark::constructionComplete() {
    return constructionStatus;
}

/**
 * @brief Performs improvements on the landmark.
 * 
 * If resources are available, increases improvement level and satisfaction, and 
 * significantly boosts economic impact. Citizens are notified of improvements.
 */
void Landmark::doImprovements() {
    if (checkResourceAvailability()) {
        improvementLevel++;
        satisfaction += 10;
        economicImpact *= 1.2;

        std::cout << "Landmark improved!\nNew Improvement Level: " << improvementLevel << "\n";

        notifyCitizens();
    } else {
        std::cout << "Resources unavailable for improvements.\n";
    }
}

/**
 * @brief Checks if resources are available for improvements.
 * 
 * @return True if resources are available, false otherwise.
 */
bool Landmark::checkResourceAvailability() {
    if (!resourcesAvailable) {
        citySatisfaction -= 10;
        for (auto& observer : observerList) {
            observer->buildingSatisfaction -= 10;
            observer->citySatisfaction -= 8;
        }
    } else {
        citySatisfaction += 10;
        for (auto& observer : observerList) {
            observer->buildingSatisfaction += 10;
            observer->citySatisfaction += 8;
        }
    }
    return resourcesAvailable;
}

/**
 * @brief Notifies all attached citizens about changes to the landmark.
 * 
 * Uses the base class implementation to notify all observers (citizens) about changes.
 */
void Landmark::notifyCitizens() {
    std::cout << "NOTIFICATION: New changes to " << name << "\n";
    Building::notifyCitizens();
}

/**
 * @brief Clones the landmark instance.
 * 
 * @return A pointer to the newly created copy of the Landmark object.
 */
Building* Landmark::clone() const {
    return new Landmark(*this);
}

/**
 * @brief Performs a specific action for the landmark.
 * 
 * Currently, this function collects property tax from the landmark.
 * 
 * @param type Action type (used for different actions; 0 collects tax in this case).
 */
void Landmark::performAction(int type) {
    payTax(0);
}

/**
 * @brief Collects property tax from the landmark.
 * 
 * @param taxRate The rate at which property tax is collected.
 */
void Landmark::payTax(float taxRate) {
    taxPaid += propertyTaxRate * buildingValue;
}

/**
 * @brief Accepts a tax collector visitor.
 * 
 * @param taxCollector Pointer to the Visitor object responsible for tax collection.
 */
void Landmark::acceptTaxCollector(Visitor* taxCollector) {
    taxCollector->visit(this);
}

/**
 * @brief Accepts a city satisfaction checker visitor.
 * 
 * @param satisfactionChecker Pointer to the Visitor object for checking city satisfaction.
 */
void Landmark::acceptCitySatisfactionChecker(Visitor* satisfactionChecker) {
    satisfactionChecker->citySatisfaction(this);
}

/**
 * @brief Returns the total number of landmark buildings created.
 * 
 * @return Total count of Landmark buildings.
 */
int Landmark::getNumBuildings() {
    return numBuildings;
}

/**
 * @brief Adds a citizen to the building if capacity is available.
 * 
 * @return True if the citizen is added, false if the building is at full capacity.
 */
bool Landmark::populateBuilding() {
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
 * @brief Adds a utility to the landmark.
 * 
 * @param utility Pointer to the Utilities object to add.
 */
void Landmark::addUtility(Utilities* utility) {
    utilities.push_back(utility);
}

/**
 * @brief Gets the type of the building as "Landmark".
 * 
 * @return A string representing the building type.
 */
std::string Landmark::getBuildingType() {
    return "Landmark";
}

/**
 * @brief Sets the value of the landmark building.
 * 
 * @param value The new value of the landmark.
 */
void Landmark::setBuildingValue(double value) {
    buildingValue = value;
}

/**
 * @brief Sets the total number of landmark buildings.
 * 
 * @param count The new total count of Landmark buildings.
 */
void Landmark::setNumBuildings(int count) { 
    numBuildings = count; 
}
