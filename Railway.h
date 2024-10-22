#ifndef RAILWAY_H
#define RAILWAY_H

#include "TransportInfrastructure.h"
#include <string>
using namespace std;

class Railway : public TransportInfrastructure {

private:
	string railwayType;
	int capacity;

public:
	Railway();

	void build();

	void updateCapacity();
};

#endif
