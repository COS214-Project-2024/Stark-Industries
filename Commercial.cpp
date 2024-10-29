#include "Commercial.h"
#include <iostream>

string Commercial::getType() {
	// TODO - implement Commercial::getType
	throw "Not yet implemented";
}

int Commercial::calculateSatisfaction() {
	// TODO - implement Commercial::calculateSatisfaction
	throw "Not yet implemented";
}

double Commercial::calculateEconomicImpact() {
	// TODO - implement Commercial::calculateEconomicImpact
	throw "Not yet implemented";
}

double Commercial::calculateResourceConsumption() {
	// TODO - implement Commercial::calculateResourceConsumption
	throw "Not yet implemented";
}

bool Commercial::constructionComplete() {
	// TODO - implement Commercial::constructionComplete
	throw "Not yet implemented";
}

void Commercial::doImprovments() {
	// TODO - implement Commercial::doImprovments
	throw "Not yet implemented";
}

void Commercial::checkReasourceAvailability() {
	// TODO - implement Commercial::checkReasourceAvailability
	throw "Not yet implemented";
}

void Commercial::notifyCitizens() {
	// TODO - implement Commercial::notifyCitizens
	throw "Not yet implemented";
}

//command functions
void Commercial::performAction(int type) {
	if(type == 0) {
		//collect tax
		//std::cout<<"Have to collect Property T"<<std::endl;
		std::cout<<"Property and Sales Tax collected"<<std::endl;
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
void Commercial::payTax(float taxRate) {
	std::cout<<"Property and Sales Tax collected"<<std::endl;
}
