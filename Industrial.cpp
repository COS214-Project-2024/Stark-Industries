#include "Industrial.h"

Industrial::Industrial(string name, int satisfaction, double economicImpact, double resourceConsumption, bool constructionStatus, int improvementLevel, bool resourcesAvailable, int notificationRadius)
        : name(name), satisfaction(satisfaction), economicImpact(economicImpact),
      resourceConsumption(resourceConsumption), constructionStatus(constructionStatus),
      improvementLevel(improvementLevel), resourcesAvailable(resourcesAvailable),
      citizenNotificationRadius(notificationRadius), Building(name, satisfaction, economicImpact, resourceConsumption, constructionStatus, improvementLevel, resourcesAvailable, notificationRadius) {}
		
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

void Industrial::doImprovements() {
	//What do I do here?
	if (checkReasourceAvailability()) {
		improvementLevel++;
		satisfaction += 5; //Adjust
		economicImpact *= 1.1; //Adjust
	}
}

bool Industrial::checkReasourceAvailability() {
	return resourcesAvailable;
}

void Industrial::notifyCitizens() {
	//What do I do here? //Part of observer
}

  Building* Industrial::clone() const {
    return new Industrial(*this); // Create a new Commercial object using the copy constructor
}