#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include "Building.h"
#include <string>
using namespace std;

class Commercial : public Building {

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

	Commercial(string name, int satisfaction, double economicImpact, double resourceConsumption, bool constructionStatus, int improvementLevel, bool resourcesAvailable, int notificationRadius);

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
