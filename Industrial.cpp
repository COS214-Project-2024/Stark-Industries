#include "Industrial.h"
#include <iostream>

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
    if (checkResourceAvailability()) {
        improvementLevel++;
        satisfaction += 5;  // Adjust
        economicImpact *= 1.1;  // Adjust

        std::cout << "Industrial building improved! New Improvement Level: " 
                  << improvementLevel << "\n";

        // Notify citizens about the improvement
        notifyCitizens();
    } else {
        std::cout << "Resources unavailable for improvements.\n";
    }
}

bool Industrial::checkResourceAvailability() {
	return resourcesAvailable;
}

void Industrial::notifyCitizens() {
	std::cout << "Notifying citizens about changes in the industrial building: " << name << "\n";
    Building::notifyCitizens();
}
