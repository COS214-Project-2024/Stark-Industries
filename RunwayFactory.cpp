#include "RunwayFactory.h"

TransportInfrastructure* RunwayFactory::createInfrastructure(double runwayLength, double runwayWidth) {
    product = new Runway(runwayLength, runwayWidth);
    return product;
}

TransportInfrastructure* RunwayFactory::createInfrastructure(int, bool) {
    //Do nothing
}

TransportInfrastructure* RunwayFactory::createInfrastructure(int, double) {
    //Do nothing
}