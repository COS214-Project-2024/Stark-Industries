#include "Commercial.h"
#include <iostream>

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
    if (checkResourceAvailability()) {
        improvementLevel++;
        satisfaction += 5;  // Adjust
        economicImpact *= 1.1;  // Adjust

        std::cout << "Commercial building improved! New Improvement Level: " 
                  << improvementLevel << "\n";

        // Notify citizens about the improvement
        notifyCitizens();
    } else {
        std::cout << "Resources unavailable for improvements.\n";
    }
}

bool Commercial::checkResourceAvailability() {
	return resourcesAvailable;
}

void Commercial::notifyCitizens() {
    std::cout << "Notifying citizens about changes in the commercial building: " << name << "\n";
    Building::notifyCitizens();
}
