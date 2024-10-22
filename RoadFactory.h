#ifndef ROADFACTORY_H
#define ROADFACTORY_H

#include "TransportInfrastructureFactory.h"
#include "TransportInfrastructure.h"
#include <string>
using namespace std;

class RoadFactory : public TransportInfrastructureFactory {

public:
	string roadType;

	RoadFactory();

protected:
	TransportInfrastructure* createInfrastructure();
};

#endif
