/**
 * @file WasteFactory.h
 * @brief Implementation of the WasteFactory class for creating Waste utility objects.
 * 
 * The WasteFactory class is responsible for creating and returning instances 
 * of the Waste utility as part of a factory design pattern.
 */
#include "WasteFactory.h"
#include "Waste.h"

/**
 * @brief Creates a Waste utility object.
 * 
 * This function creates a new Waste object with a specified name, capacity, 
 * and operational cost, and returns it as a pointer to a Utilities base type.
 * 
 * @return A pointer to a new Waste object with a name "City Waste Management", 
 *         a capacity of 500.0 units, and an operational cost of 300.0 per hour.
 */
Utilities* WasteFactory::createUtility() {
    // Create and return a new Waste object
    return new Waste("City Waste Management", 500.0, 300.0);
}
