#ifndef BUILDING_H
#define BUILDING_H

#include "Element.h"
#include "Utilities.h"
#include "Citizen.h"
#include <string>
#include <vector>
using namespace std;

class Building : public Element {

private:
	vector<Utilities*> utilities;
	std::vector<Citizen*> observerList; // vector so that multiple citizens can be attached

    string name;
    int satisfaction;
    double economicImpact;
    double resourceConsumption;
    bool constructionStatus;
    int improvementLevel;
    bool resourcesAvailable;
    int citizenNotificationRadius;

public:
	Building(string name, int satisfaction, double economicImpact, double resourceConsumption, bool constructionStatus, int improvementLevel, bool resourcesAvailable, int notificationRadius);
	virtual ~Building() = default;
	void get();
	void set();
	virtual string getType() = 0;
	virtual int calculateSatisfaction() = 0;
	virtual double calculateEconomicImpact() = 0;
	virtual double calculateResourceConsumption() = 0;
	virtual bool constructionComplete() = 0;
	virtual void doImprovements() = 0;
	virtual bool checkResourceAvailability() = 0;

	//Observer functions
	void attach(Citizen* observer);
	void detach(Citizen* observer);
	virtual void notifyCitizens() = 0;
};

#endif
