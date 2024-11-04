#include "RailwayFactory.h"

TransportInfrastructure* RailwayFactory::createInfrastructure(int lanes, bool electrified) {
    product = new Railway(lanes, electrified);
    return product;
}

TransportInfrastructure* RailwayFactory::createInfrastructure(int, double) {
    //Do nothing
}

TransportInfrastructure* RailwayFactory::createInfrastructure(double, double) {
    //Do nothing
}

