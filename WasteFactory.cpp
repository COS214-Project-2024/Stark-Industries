#include "WasteFactory.h"
#include "Waste.h"

/**
 * @brief Creates a new Waste object.
 * 
 * This method implements the createUtility function defined in the 
 * WasteFactory class, creating a Waste object configured with specific
 * parameters for waste management.
 * 
 * @return A pointer to a newly created Waste object initialized with
 *         the name "City Waste Management", a volume of 500.0, and a
 *         weight of 300.0.
 */
Utilities* WasteFactory::createUtility() {
    // Create and return a new Waste object
    return new Waste("City Waste Management", 500.0, 300.0);
}
