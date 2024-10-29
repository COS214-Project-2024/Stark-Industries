#include "Residential.h"
#include <iostream>

Residential::Residential(string name, int satisfaction, double economicImpact, double resourceConsumption, bool constructionStatus, int improvementLevel, bool resourcesAvailable, int notificationRadius)
        : name(name), satisfaction(satisfaction), economicImpact(economicImpact),
      resourceConsumption(resourceConsumption), constructionStatus(constructionStatus),
      improvementLevel(improvementLevel), resourcesAvailable(resourcesAvailable),
      citizenNotificationRadius(notificationRadius), Building(name, satisfaction, economicImpact, resourceConsumption, constructionStatus, improvementLevel, resourcesAvailable, notificationRadius) {}

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
    if (checkResourceAvailability()) {
        improvementLevel++;
        satisfaction += 5; //Adjust
        economicImpact *= 1.1; //Adjust

        std::cout << "Residential building improved! New Improvement Level: " 
                  << improvementLevel << "\n";

        notifyCitizens(); //added this to Observer pattern, citizens are notified when improvements are done
    } else {
        std::cout << "Resources unavailable for improvements.\n";
    }
}

bool Residential::checkResourceAvailability() {
	return resourcesAvailable;
}

void Residential::notifyCitizens() {
	std::cout << "Notifying citizens about changes in " << name << "...\n";
    Building::notifyCitizens();
}
