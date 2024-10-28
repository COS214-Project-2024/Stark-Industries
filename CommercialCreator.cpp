#include "CommercialCreator.h"
#include "Commercial.h"

CommercialCreator::CommercialCreator() {

}

Building* CommercialCreator::createBuilding(string name, int satisfaction, double economicImpact, double resourceConsumption, bool constructionStatus, int improvementLevel, bool resourcesAvailable, int notificationRadius) {
	buildings = new Commercial(name, satisfaction, economicImpact, resourceConsumption, constructionStatus, improvementLevel, resourcesAvailable, notificationRadius);
	return buildings;
}
