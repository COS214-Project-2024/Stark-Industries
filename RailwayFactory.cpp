#include "RailwayFactory.h"

/**
 * @class RailwayFactory
 * @brief A factory class for creating Railway infrastructure instances.
 * 
 * The RailwayFactory class is responsible for creating instances of Railway 
 * infrastructure, providing methods to create different types of transport 
 * infrastructure based on specified parameters.
 *
 * This factory follows the Factory Method design pattern, allowing for 
 * flexibility in the creation of transport infrastructures without specifying 
 * the exact classes of objects that will be created.
 */
TransportInfrastructure* RailwayFactory::createInfrastructure(int lanes, bool electrified) {
    product = new Railway(lanes, electrified);
    return product;
}

/**
 * @brief Creates a TransportInfrastructure with specified attributes (overloaded).
 * 
 * This overloaded function is not implemented and does nothing. It is provided 
 * to fulfill the factory interface requirements. 
 * 
 * @param lanes The number of lanes (not used in this implementation).
 * @param speed The speed (not used in this implementation).
 * @return A pointer to TransportInfrastructure (currently returns nullptr).
 */
TransportInfrastructure* RailwayFactory::createInfrastructure(int, double) {
    //Do nothing
}

/**
 * @brief Creates a TransportInfrastructure with specified attributes (overloaded).
 * 
 * This overloaded function is not implemented and does nothing. It is provided 
 * to fulfill the factory interface requirements.
 * 
 * @param length The length of the infrastructure (not used in this implementation).
 * @param width The width of the infrastructure (not used in this implementation).
 * @return A pointer to TransportInfrastructure (currently returns nullptr).
 */
TransportInfrastructure* RailwayFactory::createInfrastructure(double, double) {
    //Do nothing
}

