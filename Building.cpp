#include "Building.h"

/**
 * @brief Constructs a Building object with the specified parameters.
 * 
 * @param name The name of the building.
 * @param satisfaction The satisfaction level that the building provides to citizens.
 * @param economicImpact The economic impact of the building on the city's economy.
 * @param resourceConsumption The amount of resources consumed by the building.
 * @param constructionStatus Indicates whether the building is currently constructed (true) or not (false).
 * @param improvementLevel The level of improvement or upgrade of the building.
 * @param resourcesAvailable Indicates whether resources are available for the building to function.
 * @param notificationRadius The radius within which citizens are notified about this building.
 */

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
