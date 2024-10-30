#include "RailwayFactory.h"

TransportInfrastructure* RailwayFactory::createInfrastructure() {
    return new Railway();
}

