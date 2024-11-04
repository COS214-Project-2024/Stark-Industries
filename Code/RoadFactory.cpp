#include "RoadFactory.h"

TransportInfrastructure* RoadFactory::createInfrastructure(int lanes, double length) {
    product = new Road(lanes, length);
    return product;
}

TransportInfrastructure* RoadFactory::createInfrastructure(int, bool) {
    //Do nothing
}

TransportInfrastructure* RoadFactory::createInfrastructure(double, double) {
    //Do nothing
}

