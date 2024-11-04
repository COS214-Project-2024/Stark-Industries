#ifndef RUNWAYFACTORY_H
#define RUNWAYFACTORY_H

#include "TransportInfrastructureFactory.h"
#include "Runway.h"

class RunwayFactory : public TransportInfrastructureFactory {
public:
    TransportInfrastructure* createInfrastructure(double runwayLength, double runwayWidth) override;
    TransportInfrastructure* createInfrastructure(int, bool);
    TransportInfrastructure* createInfrastructure(int, double);
};

#endif
