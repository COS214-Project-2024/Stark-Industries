#include "Citizen.h"
#include <iostream>


/**
 * @brief Constructs a Citizen with the given attributes.
 * 
 * @param name Name of the citizen.
 * @param income Income of the citizen.
 * @param propertyValue Value of the citizen's property.
 */
Citizen::Citizen(const std::string& name, int income, double propertyValue)
    : name(name), income(income), propertyValue(propertyValue), commuteTime(0),
      isSatisfiedTrans(0), hasPaid(false) {}

void Citizen::get() {
	// TODO - implement Citizen::get
	throw "Not yet implemented";
}

void Citizen::set() {
	// TODO - implement Citizen::set
	throw "Not yet implemented";
}

CitizenPrototype* Citizen::clone() {
	// TODO - implement Citizen::clone
	throw "Not yet implemented";
}


/**
 * @brief Updates the citizen when a building notifies them of a change (Observer pattern).
 * 
 * This method is called by the building when there are changes, increasing the satisfaction level of the citizen.
 */
void Citizen::observerUpdate(string type) {
	if (type == "City") {
		std::cout << "Citizen " << name << " has been notified of a city change.\n";
	}
	else if (type == "Building") {
		std::cout << "Citizen " << name << " has been notified of a building change.\n";
	}
    satisfaction++; 
	wasNotified = true;
}

bool Citizen::isNotified() const {
	return wasNotified; 
}
void Citizen::resetNotification() {
	wasNotified = false;
} 

int Citizen::calculateSatisfaction() {
	// TODO - implement Citizen::calculateSatisfaction
	throw "Not yet implemented";
}

void Citizen::taxPaid() {
	// TODO - implement Citizen::taxPaid
	throw "Not yet implemented";
}

void Citizen::requestBuilding(int City_city, int String_buildtype) {
	// TODO - implement Citizen::requestBuilding
	throw "Not yet implemented";
}

void Citizen::recieveMoveinDate() {
	// TODO - implement Citizen::recieveMoveinDate
	throw "Not yet implemented";
}

void Citizen::choseTransport(int Transport_trans) {
	// TODO - implement Citizen::choseTransport
	throw "Not yet implemented";
}

void Citizen::requestUtilitiesService() {
	// TODO - implement Citizen::requestUtilitieService
	throw "Not yet implemented";
}
