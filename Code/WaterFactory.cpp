#include "WaterFactory.h"
#include "Water.h"

Utilities* WaterFactory::createUtility() {
    // Create and return a new Water object
    return new Water("City Water Supply", 1000.0, 500.0);
}
