#ifndef RAILWAYFACTORY_H
#define RAILWAYFACTORY_H

#include "TransportInfrastructureFactory.h"
#include "Railway.h"

class RailwayFactory : public TransportInfrastructureFactory {
public:
    TransportInfrastructure* createInfrastructure(int lanes, bool electrified) override;
    TransportInfrastructure* createInfrastructure(int, double);
    TransportInfrastructure* createInfrastructure(double, double);
};

#endif // RAILWAYFACTORY_H
