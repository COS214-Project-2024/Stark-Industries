#include "PowerPlantFactory.h"
#include "PowerPlant.h"

Utilities* PowerPlantFactory::createUtility() {
 // Create and return a new PowerPlant object
    return new PowerPlant("Nuclear Power Plant", 5000.0, 2000.0);
}
