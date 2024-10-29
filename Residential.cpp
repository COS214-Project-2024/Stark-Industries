#include "Residential.h"
#include <iostream>

string Residential::getType() {
	// TODO - implement Residential::getType
	throw "Not yet implemented";
}

int Residential::calculateSatisfaction() {
	// TODO - implement Residential::calculateSatisfaction
	throw "Not yet implemented";
}

double Residential::calculateEconomicImpact() {
	// TODO - implement Residential::calculateEconomicImpact
	throw "Not yet implemented";
}

double Residential::calculateResourceConsumption() {
	// TODO - implement Residential::calculateResourceConsumption
	throw "Not yet implemented";
}

bool Residential::constructionComplete() {
	// TODO - implement Residential::constructionComplete
	throw "Not yet implemented";
}

void Residential::doImprovments() {
	// TODO - implement Residential::doImprovments
	throw "Not yet implemented";
}

void Residential::checkReasourceAvailability() {
	// TODO - implement Residential::checkReasourceAvailability
	throw "Not yet implemented";
}

void Residential::notifyCitizens() {
	// TODO - implement Residential::notifyCitizens
	throw "Not yet implemented";
}

//command functions
void Residential::performAction(int type) {
	if(type == 0) {
		//collect tax
		std::cout<<"Property Tax collected"<<std::endl;
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
	std::cout<<"Property Tax collected"<<std::endl;
}
