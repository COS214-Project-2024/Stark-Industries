#ifndef ROAD_H
#define ROAD_H

#include "TransportInfrastructure.h"
#include <string>
using namespace std;

class Road : public TransportInfrastructure {

private:
	string roadType;
	int capacity;

public:
	Road();

	void build();

	void updateCapacity();
};

#endif
