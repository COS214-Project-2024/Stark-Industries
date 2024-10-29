#include "Landmark.h"

Landmark::Landmark(string name, int satisfaction, double economicImpact, double resourceConsumption, bool constructionStatus, int improvementLevel, bool resourcesAvailable, int notificationRadius)
        : name(name), satisfaction(satisfaction), economicImpact(economicImpact),
      resourceConsumption(resourceConsumption), constructionStatus(constructionStatus),
      improvementLevel(improvementLevel), resourcesAvailable(resourcesAvailable),
      citizenNotificationRadius(notificationRadius), Building(name, satisfaction, economicImpact, resourceConsumption, constructionStatus, improvementLevel, resourcesAvailable, notificationRadius) {}

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
	if (checkReasourceAvailability()) {
		improvementLevel++;
		satisfaction += 5; //Adjust
		economicImpact *= 1.1; //Adjust
	}
}

bool Landmark::checkReasourceAvailability() {
	return resourcesAvailable;
}

void Landmark::notifyCitizens() {
	//What do I do here? //Part of observer
}

Building* Landmark::clone() const {
    return new Landmark(*this); // Create a new Commercial object using the copy constructor
}