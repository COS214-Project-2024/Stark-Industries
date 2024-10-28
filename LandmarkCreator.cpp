#include "LandmarkCreator.h"
#include "Landmark.h"

LandmarkCreator::LandmarkCreator() {

}

Building* LandmarkCreator::createBuilding(string name, int satisfaction, double economicImpact, double resourceConsumption, bool constructionStatus, int improvementLevel, bool resourcesAvailable, int notificationRadius) {
	buildings = new Landmark(name, satisfaction, economicImpact, resourceConsumption, constructionStatus, improvementLevel, resourcesAvailable, notificationRadius);
	return buildings;
}
