#include "Commercial.h"

Commercial::Commercial(string name, int satisfaction, double economicImpact, double resourceConsumption, bool constructionStatus, int improvementLevel, bool resourcesAvailable, int notificationRadius)
        : name(name), satisfaction(satisfaction), economicImpact(economicImpact),
      resourceConsumption(resourceConsumption), constructionStatus(constructionStatus),
      improvementLevel(improvementLevel), resourcesAvailable(resourcesAvailable),
      citizenNotificationRadius(notificationRadius), Building(name, satisfaction, economicImpact, resourceConsumption, constructionStatus, improvementLevel, resourcesAvailable, notificationRadius) {}

string Commercial::getType() {
	return name;
}

int Commercial::calculateSatisfaction() {
	return satisfaction;
}

double Commercial::calculateEconomicImpact() {
	return economicImpact;
}

double Commercial::calculateResourceConsumption() {
	return resourceConsumption;
}

bool Commercial::constructionComplete() {
	return constructionStatus;
}

void Commercial::doImprovements() {
	//What do I do here?
	if (checkReasourceAvailability()) {
		improvementLevel++;
		satisfaction += 5; //Adjust
		economicImpact *= 1.1; //Adjust
	}
}

bool Commercial::checkReasourceAvailability() {
	return resourcesAvailable;
}

void Commercial::notifyCitizens() {
	//What do I do here? //Part of observer
}

Building* Commercial::clone() const {
    return new Commercial(*this); // Create a new Commercial object using the copy constructor
}
