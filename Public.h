#ifndef PUBLIC_H
#define PUBLIC_H

#include "Transport.h"
#include <string>
using namespace std;

class Public : public Transport {

private:
	string publicName;
	int seatingcapacity;
	int curPassengers;
	double travelTime;
	bool isOpen;
	double price;

public:
	Public(string nameP, int Totalcapacity, int curCapacity, double price, double time, bool opne);

	void transport();

	void doMaintenance_();

	double commuteTime();

	int citizenSatisfaction();

	void updateTraffic();

	void updateCapacity();
};

#endif
