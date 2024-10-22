#ifndef TRAIN_H
#define TRAIN_H

#include "Transport.h"
#include <string>
using namespace std;

class Train : public Transport {

private:
	string trainName;
	int seatingLoad;
	int curPassengers;
	double price;
	double travelTime;
	bool isOpen;
	int curGoods;

public:
	Train(string nameT, int Totalcapacity, int curcapacity, int curG, double price, double time, bool opne);

	void transport();

	void doMaintenance_();

	double commuteTime();

	int citizenSatisfaction();

	void updateCapacity();
};

#endif
