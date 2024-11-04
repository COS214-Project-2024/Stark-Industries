/**
 * @file WaterFactory.h
 * @brief Implementation of the WaterFactory class.
 * 
 * The WaterFactory class is responsible for creating Water objects, 
 * which are derived from the Utilities base class. 
 */
#include "WaterFactory.h"
#include "Water.h"

/**
 * @brief Creates and returns a new Water utility object.
 * 
 * This method overrides the createUtility method in the UtilitiesFactory 
 * base class, instantiating a Water object configured with a name, 
 * capacity, and initial usage. The created Water object represents 
 * the city's water supply with default parameters.
 * 
 * @return Utilities* A pointer to the created Water object.
 */
Utilities* WaterFactory::createUtility() {
    // Create and return a new Water object
    return new Water("City Water Supply", 1000.0, 500.0);
}
