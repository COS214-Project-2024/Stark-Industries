#include "Residential.h"

Residential::Residential(string name, int satisfaction, double economicImpact, double resourceConsumption, bool constructionStatus, int improvementLevel, bool resourcesAvailable, int notificationRadius)
        : Building(name, satisfaction, economicImpact, resourceConsumption, constructionStatus, improvementLevel, resourcesAvailable, notificationRadius) {}

string Residential::getType() {
	return name;
}

int Residential::calculateSatisfaction() {
	return satisfaction;
}

double Residential::calculateEconomicImpact() {
	return economicImpact;
}

double Residential::calculateResourceConsumption() {
	return resourceConsumption;
}

bool Residential::constructionComplete() {
	return constructionStatus;
}

void Residential::doImprovements() {
	//What do I do here?
	if (checkReasourceAvailability()) {
		improvementLevel++;
		satisfaction += 5; //Adjust
		economicImpact *= 1.1; //Adjust
	}
}

bool Residential::checkReasourceAvailability() {
	return resourcesAvailable;
}

void Residential::notifyCitizens() {
	//What do I do here? //Part of observer
}
