#include "WaterFactory.h"
#include "Water.h"

/**
 * @brief Creates and returns a new water-related utility object.
 *
 * This method instantiates a `Water` object with specific parameters for the
 * name, capacity, and operational cost, representing a water utility.
 *
 * @return A pointer to a new `Water` object representing the city water supply.
 */
Utilities* WaterFactory::createUtility() {
    // Create and return a new Water object
    return new Water("City Water Supply", 1000.0, 500.0);
}
