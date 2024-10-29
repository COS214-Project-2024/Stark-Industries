#include "Building.h"
#include <iostream>
#include <vector>
#include <algorithm>


Building::Building(string name, int satisfaction, double economicImpact, double resourceConsumption, bool constructionStatus, int improvementLevel, bool resourcesAvailable, int notificationRadius) : name(name),
      satisfaction(satisfaction),
      economicImpact(economicImpact),
      resourceConsumption(resourceConsumption),
      constructionStatus(constructionStatus),
      improvementLevel(improvementLevel),
      resourcesAvailable(resourcesAvailable),
      citizenNotificationRadius(notificationRadius) {}

void Building::get() {
	// TODO - implement Building::get
	throw "Not yet implemented";
}

void Building::set() {
	// TODO - implement Building::set
	throw "Not yet implemented";
}

// Attach a citizen to the observer list
void Building::attach(Citizen* observer) {
    observerList.push_back(observer);
}

// Detach a citizen from the observer list
void Building::detach(Citizen* observer) {
    observerList.erase(std::remove(observerList.begin(), observerList.end(), observer), observerList.end());
}

// Notify all observers (citizens) about changes
void Building::notifyCitizens() {
    std::cout << "Notifying citizens about changes in " << name << "...\n";
    for (Citizen* citizen : observerList) {
        citizen->observerUpdate();  // Call the observer's update method
    }
}
