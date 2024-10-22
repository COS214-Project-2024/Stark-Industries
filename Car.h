#ifndef CAR_H
#define CAR_H

#include "Transport.h"
#include <string>
using namespace std;

class Car : public Transport {

private:
	string carName;
	int seatingCapacity;
	double travelTime;
	bool isOpen;

public:
	Car(string nameC, int capacity, bool open, double time);

	void transport();

	void doMaintenance_();

	double commuteTime();

	int citizenSatisfaction();

	void updateTraffic();

	void updateCapacity();
};

#endif
