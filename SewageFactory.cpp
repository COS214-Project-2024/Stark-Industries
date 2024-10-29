#include "SewageFactory.h"
#include "Sewage.h"

/**
 * @brief Creates a sewage utility object.
 * 
 * This method creates and returns a new instance of the Sewage 
 * utility. It initializes the sewage utility with a predefined 
 * name, capacity, and operational cost.
 * 
 * @return A pointer to the newly created Sewage object, which 
 *         is a derived class of Utilities.
 */
Utilities* SewageFactory::createUtility() {
    // Create and return a new Sewage object
    return new Sewage("City Sewage System", 600.0, 350.0);
}
