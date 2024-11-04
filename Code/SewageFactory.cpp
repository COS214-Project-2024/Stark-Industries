#include "SewageFactory.h"
#include "Sewage.h"

Utilities* SewageFactory::createUtility() {
    // Create and return a new Sewage object
    return new Sewage("City Sewage System", 600.0, 350.0);
}
