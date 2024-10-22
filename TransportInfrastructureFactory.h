#ifndef TRANSPORTINFRASTRUCTUREFACTORY_H
#define TRANSPORTINFRASTRUCTUREFACTORY_H

#include "TransportInfrastructure.h"

class TransportInfrastructureFactory {


protected:
	virtual TransportInfrastructure* createInfrastructure() = 0;
};

#endif
