#ifndef LANDMARK_H
#define LANDMARK_H

#include "Building.h"
#include <string>
using namespace std;

class Landmark : public Building {

private:
    string name;
    int satisfaction;
    double economicImpact;
    double resourceConsumption;
    bool constructionStatus;
    int improvementLevel;
    bool resourcesAvailable;
    int citizenNotificationRadius;

public:

	Landmark(string name, int satisfaction, double economicImpact, double resourceConsumption, bool constructionStatus, int improvementLevel, bool resourcesAvailable, int notificationRadius);

	string getType();

	int calculateSatisfaction();

	double calculateEconomicImpact();

	double calculateResourceConsumption();

	bool constructionComplete();

	void doImprovments();

	void checkReasourceAvailability();

	void notifyCitizens();
};

#endif
