#include "Citizen.h"
#include <iostream>

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

void Citizen::observerUpdate() {
    std::cout << "Citizen " << name << " has been notified of a building change.\n";
    satisfaction++; 
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
