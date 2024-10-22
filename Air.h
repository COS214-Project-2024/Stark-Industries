#ifndef AIR_H
#define AIR_H

#include "Transport.h"
#include <string>
using namespace std;

class Air : public Transport {

private:
	string airportName;
	int flightCapacity;
	int curPassengers;
	double price;
	double travelTime;
	bool isOpen;
	int curCargo;

public:
	Air(string nameA, int Totalcapacity, int curcapacity, double price, double time, bool opne, int curCargo);

	void transport();

	void doMaintenance_();

	double commuteTime();

	int citizenSatisfaction();

	void updateCapacity();
};

#endif
