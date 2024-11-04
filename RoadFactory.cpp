/**
 * @file RoadFactory.cpp
 * @brief Implementation of the RoadFactory class, responsible for creating Road infrastructure.
 */
#include "RoadFactory.h"

/**
 * @brief Creates a Road infrastructure with specified lanes and length.
 * 
 * This method initializes a new Road object with the given number of lanes and length.
 * 
 * @param lanes Number of lanes in the road.
 * @param length Length of the road.
 * @return A pointer to the newly created TransportInfrastructure (Road).
 */
TransportInfrastructure* RoadFactory::createInfrastructure(int lanes, double length) {
    product = new Road(lanes, length);
    return product;
}

/**
 * @brief A placeholder method for creating infrastructure using an integer and a boolean.
 * 
 * This method currently does nothing and is a placeholder for future implementation.
 * 
 * @param lanes Number of lanes (not used).
 * @param isPaved Indicates whether the road is paved (not used).
 * @return nullptr.
 */
TransportInfrastructure* RoadFactory::createInfrastructure(int, bool) {
    //Do nothing
}

/**
 * @brief A placeholder method for creating infrastructure using two doubles.
 * 
 * This method currently does nothing and is a placeholder for future implementation.
 * 
 * @param length Length of the road (not used).
 * @param width Width of the road (not used).
 * @return nullptr.
 */
TransportInfrastructure* RoadFactory::createInfrastructure(double, double) {
    //Do nothing
}

