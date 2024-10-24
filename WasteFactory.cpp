#include "WasteFactory.h"
#include "Waste.h"

Utilities* WasteFactory::createUtility() {
    // Create and return a new Waste object
    return new Waste("City Waste Management", 500.0, 300.0);
}
