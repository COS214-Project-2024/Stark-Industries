#include "IndustrialCreator.h"
#include "Industrial.h"

IndustrialCreator::IndustrialCreator() {

}

Building* IndustrialCreator::createBuilding(string name, int satisfaction, double economicImpact, double resourceConsumption, bool constructionStatus, int improvementLevel, bool resourcesAvailable, int notificationRadius) {
	buildings = new Industrial(name, satisfaction, economicImpact, resourceConsumption, constructionStatus, improvementLevel, resourcesAvailable, notificationRadius);
	return buildings;
}
