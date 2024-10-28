#include "Building.h"

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
