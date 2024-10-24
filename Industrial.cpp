#include "Industrial.h"

Industrial::Industrial(string name, int satisfaction, double economicImpact, double resourceConsumption, bool constructionStatus, int improvementLevel, bool resourcesAvailable, int notificationRadius)
        : name(name), satisfaction(satisfaction), 
        economicImpact(economicImpact), resourceConsumption(resourceConsumption), 
        constructionStatus(constructionStatus), improvementLevel(improvementLevel), 
        resourcesAvailable(resourcesAvailable), citizenNotificationRadius(notificationRadius) {}
		
string Industrial::getType() {
	return name;
}

int Industrial::calculateSatisfaction() {
	return satisfaction;
}

double Industrial::calculateEconomicImpact() {
	return economicImpact;
}

double Industrial::calculateResourceConsumption() {
	return resourceConsumption;
}

bool Industrial::constructionComplete() {
	return constructionStatus;
}

void Industrial::doImprovments() {
	//What do I do here?
	if (resourcesAvailable) {
		improvementLevel++;
		satisfaction += 5; //Adjust
		economicImpact *= 1.1; //Adjust
	}
}

void Industrial::checkReasourceAvailability() {
	resourcesAvailable = true;
}

void Industrial::notifyCitizens() {
	//What do I do here?
}
