#include "Landmark.h"

Landmark::Landmark(string name, int satisfaction, double economicImpact, double resourceConsumption, bool constructionStatus, int improvementLevel, bool resourcesAvailable, int notificationRadius)
        : name(name), satisfaction(satisfaction), 
        economicImpact(economicImpact), resourceConsumption(resourceConsumption), 
        constructionStatus(constructionStatus), improvementLevel(improvementLevel), 
        resourcesAvailable(resourcesAvailable), citizenNotificationRadius(notificationRadius) {}

string Landmark::getType() {
	return name;
}

int Landmark::calculateSatisfaction() {
	return satisfaction;
}

double Landmark::calculateEconomicImpact() {
	return economicImpact;
}

double Landmark::calculateResourceConsumption() {
	return resourceConsumption;
}

bool Landmark::constructionComplete() {
	return constructionStatus;
}

void Landmark::doImprovements() {
	//What do I do here?
	if (resourcesAvailable) {
		improvementLevel++;
		satisfaction += 5; //Adjust
		economicImpact *= 1.1; //Adjust
	}
}

void Landmark::checkReasourceAvailability() {
	resourcesAvailable = true;
}

void Landmark::notifyCitizens() {
	//What do I do here?
}
