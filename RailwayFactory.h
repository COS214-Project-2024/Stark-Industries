#ifndef RAILWAYFACTORY_H
#define RAILWAYFACTORY_H

#include "TransportInfrastructureFactory.h"
#include "Railway.h"

class RailwayFactory : public TransportInfrastructureFactory {
public:
    TransportInfrastructure* createInfrastructure() override;
};

#endif // RAILWAYFACTORY_H
