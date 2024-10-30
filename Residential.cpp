#include "Residential.h"
#include <iostream>

string Residential::getType() {
	// TODO - implement Residential::getType
	// "Not yet implemented";
}

int Residential::calculateSatisfaction() {
	// TODO - implement Residential::calculateSatisfaction
	// "Not yet implemented";
}

double Residential::calculateEconomicImpact() {
	// TODO - implement Residential::calculateEconomicImpact
	// "Not yet implemented";
}

double Residential::calculateResourceConsumption() {
	// TODO - implement Residential::calculateResourceConsumption
	// "Not yet implemented";
}

bool Residential::constructionComplete() {
	// TODO - implement Residential::constructionComplete
	// "Not yet implemented";
}

void Residential::doImprovements() {
	// TODO - implement Residential::doImprovments
	// "Not yet implemented";
}

void Residential::checkReasourceAvailability() {
	// TODO - implement Residential::checkReasourceAvailability
	// "Not yet implemented";
}

void Residential::notifyCitizens() {
	// TODO - implement Residential::notifyCitizens
	// "Not yet implemented";
}

//command functions
void Residential::performAction(int type) {
	if(type == 0) {
		//collect tax
		std::cout<<"Property Tax and Rental Income Tax collected from Residential Building"<<std::endl;
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
	//property and rental income tax
	double pTax = buildingValue * propertyTaxRate;
	double rTax = buildingRevenue * rentalTaxRate;	
	std::cout<<"Property Tax: "<<pTax<<std::endl;
	std::cout<<"Rental Tax: "<<rTax<<std::endl;
	buildingRevenue -= pTax;
	buildingRevenue -= rTax;
	taxPaid += pTax;
	taxPaid += rTax;
}

void Residential::acceptTaxCollector(Visitor * taxCollector) {
	taxCollector->visit(this);
}
