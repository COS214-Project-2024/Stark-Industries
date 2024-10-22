#ifndef RUNWAY_H
#define RUNWAY_H

#include "TransportInfrastructure.h"
#include <string>
using namespace std;

class Runway : public TransportInfrastructure {

private:
	string runwayType;
	int capacity;

public:
	Runway();

	void build();

	void updateCapacity();
};

#endif
