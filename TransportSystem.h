#ifndef TRANSPORTSYSTEM_H
#define TRANSPORTSYSTEM_H

#include "Transport.h"
#include <string>
using namespace std;

class TransportSystem {

private:
	Transport* transType;

	double totalCommuteTime;

public:
	void setTrans(Transport* newTrans);

	void doMantenance();

	double CalcTotalCommuteTime();

	void updateCitizens();

	void checkAvailability(int TransportInfastructure_transInfas);
};

#endif
