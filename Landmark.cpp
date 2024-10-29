#include "Landmark.h"
#include <iostream>

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
    if (checkResourceAvailability()) {
        improvementLevel++;
        satisfaction += 10; // Adjust
        economicImpact *= 1.2; // Adjust

        std::cout << "Landmark improved! New Improvement Level: " 
                  << improvementLevel << "\n";

        // Notify citizens about the improvement
        notifyCitizens();
    } else {
        std::cout << "Resources unavailable for improvements.\n";
    }
}

bool Landmark::checkResourceAvailability() {
	return resourcesAvailable;
}

void Landmark::notifyCitizens() {
	std::cout << "Notifying citizens about changes to the landmark: " << name << "\n";
    Building::notifyCitizens();
}
