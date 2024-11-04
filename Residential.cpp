#include "Residential.h" ///< Header for the Residential class representing residential buildings.
#include "SatisfactionChecker.h" ///< Header for the SatisfactionChecker class used to assess citizen satisfaction.
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

/**
 * @brief Default constructor for Residential class.
 *
 * This constructor initializes a Residential object with default values.
 */
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
 * @brief Notifies all attached citizens about changes in the residential building.
 * 
 * Uses the base class implementation to notify all observers (citizens) about changes.
 */
void Residential::notifyCitizens() {
    std::cout << "NOTIFICATION: New changes to " << name << "\n";
    Building::notifyCitizens();  // Call the base class notify method
}

/**
 * @brief Clones the current Residential object.
 * 
 * This method creates a new Residential object that is a copy of the current instance.
 * 
 * @return A pointer to the newly created Residential object.
 */
Building* Residential::clone() const {
    return new Residential(*this); // Create a new Commercial object using the copy constructor
}

/**
 * @brief Performs a specified action related to taxation.
 * 
 * This function performs actions based on the given command type, which could be 
 * collecting taxes, allocating taxes, or increasing taxes.
 * 
 * @param type An integer representing the type of action to perform.
 */
//command functions
void Residential::performAction(int type) {
	if(type == 0) {
		//collect tax
		//std::cout<<"Property Tax and Rental Income Tax collected from Residential Building"<<std::endl;
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

/**
 * @brief Pays tax for the residential building.
 * 
 * This function calculates and deducts property and rental income tax from the building's revenue.
 * 
 * @param taxRate The tax rate applied to the building's value and revenue.
 */
//visitor functions
void Residential::payTax(float taxRate) {
	//property and rental income tax
	double pTax = buildingValue * propertyTaxRate;
	double rTax = buildingRevenue * rentalTaxRate;	
	std::cout<<"Property Tax of: "<< pTax << " and Income Tax of: " << rTax << " collected from " << this->name << std::endl;
	buildingRevenue -= pTax;
	buildingRevenue -= rTax;
	taxPaid += pTax;
	taxPaid += rTax;
}

/**
 * @brief Accepts a tax collector visitor to perform tax-related operations.
 * 
 * @param taxCollector Pointer to a Visitor object that performs tax collection.
 */
void Residential::acceptTaxCollector(Visitor * taxCollector) {
	taxCollector->visit(this);
}

/**
 * @brief Returns the total number of Residential buildings created.
 * 
 * @return An integer representing the total number of Residential buildings.
 */
int Residential::getNumBuildings() {
    return numBuildings;
}

/**
 * @brief Accepts a city satisfaction checker visitor to evaluate city satisfaction.
 * 
 * @param satisfactionChecker Pointer to a Visitor object that checks city satisfaction.
 */
void Residential::acceptCitySatisfactionChecker(Visitor* satisfactionChecker){
	satisfactionChecker->citySatisfaction(this);
}

/**
 * @brief Collects rent from citizens living in the residential building.
 * 
 * This function iterates through the list of observers (citizens) and collects rent.
 */
void Residential::collectRent(){
	for (int i = 0 ; i < observerList.size(); i++) {
		observerList[i]->payRent(rent);
		buildingRevenue += rent;
		std::cout << "Collected rent from " << observerList[i]->getName() << "of: "<< rent<< std::endl;
	}
}

/**
 * @brief Populates the building by adding a citizen.
 * 
 * This function decreases the building's capacity and returns true if a citizen is added successfully.
 * 
 * @return True if a citizen is added, false if the building is at full capacity.
 */
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

/**
 * @brief Displays the satisfaction levels of citizens in the residential building.
 * 
 * This function uses the SatisfactionChecker to assess and print the satisfaction levels.
 */
void Residential::getCitizenSatisfactionForBuilding(){
	std::cout << "--Satisfaction of the citizens in the '" << this->name << "' building-- \n";
	SatisfactionChecker satisfactionChecker;
	for (int i = 0; i < observerList.size(); i++) {
		observerList[i]->acceptBuildingSatisfactionChecker(&satisfactionChecker);
	}
}

/**
 * @brief Adds a utility to the residential building.
 * 
 * @param utility Pointer to a Utilities object representing a utility to be added.
 */
void Residential::addUtility(Utilities* utility) {
    utilities.push_back(utility);
}

/**
 * @brief Returns the available capacity of the residential building.
 * 
 * This function returns the number of additional occupants that can be accommodated 
 * in the building.
 * 
 * @return An integer representing the available capacity of the building.
 */
int Residential::getAvailableCapacity() const {
    return capacity;
}

/**
 * @brief Returns the current count of occupants in the residential building.
 * 
 * This function counts and returns the number of citizens currently residing 
 * in the residential building.
 * 
 * @return An integer representing the number of occupants in the building.
 */
int Residential::getOccupantCount() const{
	return occupants.size();
}

/**
 * @brief Returns the type of the building.
 * 
 * This function returns a string that identifies the building type as "Residential".
 * 
 * @return A string representing the building type.
 */
std::string Residential::getBuildingType(){
	return "Residential";
}

/**
 * @brief Sets the rental rate for the residential building.
 * 
 * This function updates the rental rate and decreases the satisfaction of all 
 * observers (citizens) by 10 as a consequence of the rent adjustment.
 * 
 * @param newRent The new rental rate to be set for the building.
 */
void Residential::setRentalRate(double newRent){
	rent = newRent;
	for (int i = 0 ; i < observerList.size(); i++){
		observerList[i]->buildingSatisfaction -= 10;
	}
}

/**
 * @brief Returns the current rental rate of the residential building.
 * 
 * This function retrieves and returns the current rental rate set for the building.
 * 
 * @return A double representing the current rental rate of the building.
 */
double Residential::getRent(){
	return rent;
}
