#include "PowerPlantFactory.h"
#include "PowerPlant.h"

/**
 * @brief Creates and returns a new PowerPlant object.
 *
 * This method implements the `createUtility` function from the `UtilitiesFactory`
 * base class. It creates a specific instance of a `PowerPlant` with predefined
 * attributes such as name, production capacity, and operational cost.
 *
 * @return Utilities* Pointer to a newly created PowerPlant object.
 *
 * Example:
 * @code
 * PowerPlantFactory factory;
 * Utilities* plant = factory.createUtility();
 * @endcode
 */
Utilities* PowerPlantFactory::createUtility() {
    // Create and return a new PowerPlant object with specific parameters
    return new PowerPlant("Nuclear Power Plant", 5000.0, 2000.0);
}
