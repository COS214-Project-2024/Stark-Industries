#ifndef RUNWAYFACTORY_H
#define RUNWAYFACTORY_H

#include "TransportInfrastructureFactory.h"
#include "TransportInfrastructure.h"
#include <string>
using namespace std;

class RunwayFactory : public TransportInfrastructureFactory {

public:
	string runwayType;

	RunwayFactory();

protected:
	TransportInfrastructure* createInfrastructure();
};

#endif
