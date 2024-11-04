#ifndef ROADFACTORY_H
#define ROADFACTORY_H

#include "TransportInfrastructureFactory.h"
#include "Road.h"

class RoadFactory : public TransportInfrastructureFactory {
public:
    TransportInfrastructure* createInfrastructure(int lanes, double length) override;
    TransportInfrastructure* createInfrastructure(int, bool);
    TransportInfrastructure* createInfrastructure(double, double);
};

#endif
