#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

#include "Building.h"
#include <string>
using namespace std;

class Residential : public Building {

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

	Residential(string name, int satisfaction, double economicImpact, double resourceConsumption, bool constructionStatus, int improvementLevel, bool resourcesAvailable, int notificationRadius);

	string getType();

	int calculateSatisfaction();

	double calculateEconomicImpact();

	double calculateResourceConsumption();

	bool constructionComplete();

	void doImprovements();

	bool checkReasourceAvailability();

	void notifyCitizens();
};

#endif
