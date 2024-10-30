#ifndef RUNWAYFACTORY_H
#define RUNWAYFACTORY_H

#include "TransportInfrastructureFactory.h"
#include "Runway.h"

class RunwayFactory : public TransportInfrastructureFactory {
public:
    TransportInfrastructure* createInfrastructure() override;
};

#endif
