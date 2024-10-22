#ifndef LANDMARK_H
#define LANDMARK_H

#include <string>
using namespace std;

class Landmark {


public:
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
