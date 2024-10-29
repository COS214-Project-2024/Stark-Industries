#include "Citizen.h"
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

void Citizen::observerUpdate() {
	// TODO - implement Citizen::observerUpdate
	throw "Not yet implemented";
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

void Citizen::requestUtilitieService() {
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
		std::cout<<"Tax increased"<<std::endl;
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
	double tax = this->income * 0.15;
	income -= tax;
	std::cout<<"Tax paid: "<<tax<<std::endl;
	//will have to send to government
}

void Citizen::getPaid(double income) {
	this->income += income;
}
