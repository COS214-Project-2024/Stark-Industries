#include "Industrial.h"
#include <iostream>

string Industrial::getType() {
    return "Industrial";
}

int Industrial::calculateSatisfaction() {
    // Implement the logic to calculate satisfaction
    return 75; // Example value
}

double Industrial::calculateEconomicImpact() {
    // Implement the logic to calculate economic impact
    return 100000.0; // Example value
}

double Industrial::calculateResourceConsumption() {
    // Implement the logic to calculate resource consumption
    return 5000.0; // Example value
}

bool Industrial::constructionComplete() {
    // Implement the logic to check if construction is complete
    return true; // Example value
}

void Industrial::doImprovements() {
    // Implement the logic to do improvements
    cout << "Improvements done" << endl;
}

void Industrial::checkReasourceAvailability() {
    // Implement the logic to check resource availability
    cout << "Resources available" << endl;
}

void Industrial::notifyCitizens() {
    // Implement the logic to notify citizens
    cout << "Citizens notified" << endl;
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
	std::cout<<"Property Tax of: " << tax << " collected"<<std::endl;

}
