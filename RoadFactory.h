#ifndef ROADFACTORY_H
#define ROADFACTORY_H

#include "TransportInfrastructureFactory.h"
#include "Road.h"

class RoadFactory : public TransportInfrastructureFactory {

 TransportInfrastructure* createInfrastructure() override;
};

#endif
