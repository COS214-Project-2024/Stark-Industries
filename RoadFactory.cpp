#include "RoadFactory.h"

TransportInfrastructure* RoadFactory::createInfrastructure() {
    return new Road();
}


