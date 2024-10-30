#include "RunwayFactory.h"

TransportInfrastructure* RunwayFactory::createInfrastructure() {
    return new Runway();
}