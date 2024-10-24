#include "Industrial.h"
#include <iostream>

string Industrial::getType() {
	// TODO - implement Industrial::getType
	throw "Not yet implemented";
}

int Industrial::calculateSatisfaction() {
	// TODO - implement Industrial::calculateSatisfaction
	throw "Not yet implemented";
}

double Industrial::calculateEconomicImpact() {
	// TODO - implement Industrial::calculateEconomicImpact
	throw "Not yet implemented";
}

double Industrial::calculateResourceConsumption() {
	// TODO - implement Industrial::calculateResourceConsumption
	throw "Not yet implemented";
}

bool Industrial::constructionComplete() {
	// TODO - implement Industrial::constructionComplete
	throw "Not yet implemented";
}

void Industrial::doImprovments() {
	// TODO - implement Industrial::doImprovments
	throw "Not yet implemented";
}

void Industrial::checkReasourceAvailability() {
	// TODO - implement Industrial::checkReasourceAvailability
	throw "Not yet implemented";
}

void Industrial::notifyCitizens() {
	// TODO - implement Industrial::notifyCitizens
	throw "Not yet implemented";
}

//command functions
void Industrial::performAction(int type) {
	if(type == 0) {
		//collect tax
		std::cout<<"Property Tax collected"<<std::endl;
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
