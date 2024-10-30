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
#include <iostream>

Citizen::Citizen(std::string name, double baseIncome) {
	this->name = name;
	this->income = baseIncome;
}

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

//command functions
void Citizen::performAction(int type) {
	if(type == 0) {
		//collect tax
		std::cout<<"Income Tax collected from citizens"<<std::endl;
		payTax();
	}
	else if(type == 1) {
		//increase tax
		std::cout<<"Tax increased by 2%"<<std::endl;
		setTaxRate();
		// affect satisfaction??
	}
	else if(type == 2) {
		//allocate tax
		std::cout<<"Tax allocated"<<std::endl;
		//probably deleting this
	}
	else {
		std::cout<<"Invalid command"<<std::endl;
	}
}

void Citizen::payTax() {
	std::cout<<"Time to collect Income Tax from citizens"<<std::endl;
	// citizens pay 15% of their income
	double tax = this->income * taxRate;
	income -= tax;
	taxPaid += tax;
	std::cout<<"Tax paid: "<<tax<<std::endl;
	//will have to send to government
}

void Citizen::getPaid(double income) {
	this->income += income;
}

void Citizen::setTaxRate() {
	taxRate *= 1.02;
}

void Citizen::acceptTaxCollector(Visitor * taxCollector) {
	taxCollector->visit(this);
}

string Citizen::getName(){
	return name;
}