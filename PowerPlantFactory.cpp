/**
 * @file PowerPlantFactory.cpp
 * @brief Implements the PowerPlantFactory class, responsible for creating instances of PowerPlant utilities using the Factory Method pattern.
 */

#include "PowerPlantFactory.h"
#include "PowerPlant.h"

/**
 * @brief Creates a new PowerPlant utility.
 * 
 * This method instantiates a new PowerPlant object with predefined attributes and 
 * returns it as a pointer to a Utilities object.
 * 
 * @return A pointer to the newly created PowerPlant object.
 */
Utilities* PowerPlantFactory::createUtility() {
    // Create and return a new PowerPlant object
    return new PowerPlant("Nuclear Power Plant", 5000.0, 2000.0);
}
