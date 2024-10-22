#ifndef RAILWAYFACTORY_H
#define RAILWAYFACTORY_H

#include "TransportInfrastructureFactory.h"
#include "TransportInfrastructure.h"
#include <string>
using namespace std;

class RailwayFactory : TransportInfrastructureFactory {

public:
	string railwayType;

	RailwayFactory();

protected:
	TransportInfrastructure* createInfrastructure();
};

#endif
