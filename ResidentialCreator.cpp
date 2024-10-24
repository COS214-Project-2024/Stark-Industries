#include "ResidentialCreator.h"
#include "Residential.h"

ResidentialCreator::ResidentialCreator() {

}

Building* ResidentialCreator::createBuilding(string name, int satisfaction, double economicImpact, double resourceConsumption, bool constructionStatus, int improvementLevel, bool resourcesAvailable, int notificationRadius) {
	buildings = new Residential(name, satisfaction, economicImpact, resourceConsumption, constructionStatus, improvementLevel, resourcesAvailable, notificationRadius);
	return buildings;
}
