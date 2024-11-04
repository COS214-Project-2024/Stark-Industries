/**
 * @file SewageFactory.cpp
 * @brief Implementation of the SewageFactory class responsible for creating 
 * Sewage utilities.
 */
#include "SewageFactory.h"
#include "Sewage.h"

/**
 * @brief Creates a new Sewage utility.
 * 
 * This method instantiates a new Sewage object with predefined attributes such as 
 * name, capacity, and operational cost, and returns it as a pointer to the base 
 * Utilities class.
 * 
 * @return A pointer to a newly created Sewage utility.
 */
Utilities* SewageFactory::createUtility() {
    // Create and return a new Sewage object
    return new Sewage("City Sewage System", 600.0, 350.0);
}
