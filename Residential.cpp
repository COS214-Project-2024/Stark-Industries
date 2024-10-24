#include "Residential.h"

Residential::Residential(string name, int satisfaction, double economicImpact, double resourceConsumption, bool constructionStatus, int improvementLevel, bool resourcesAvailable, int notificationRadius)
        : name(name), satisfaction(satisfaction), 
        economicImpact(economicImpact), resourceConsumption(resourceConsumption), 
        constructionStatus(constructionStatus), improvementLevel(improvementLevel), 
        resourcesAvailable(resourcesAvailable), citizenNotificationRadius(notificationRadius) {}

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

void Residential::doImprovments() {
	//What do I do here?
	if (resourcesAvailable) {
		improvementLevel++;
		satisfaction += 5; //Adjust
		economicImpact *= 1.1; //Adjust
	}
}

void Residential::checkReasourceAvailability() {
	resourcesAvailable = true;
}

void Residential::notifyCitizens() {
	//What do I do here?
}
