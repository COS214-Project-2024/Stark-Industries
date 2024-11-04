/**
 * @file RunwayFactory.cpp
 * @brief Implementation of the RunwayFactory class, responsible for creating runway infrastructure.
 */
#include "RunwayFactory.h"

/**
 * @brief Creates a Runway infrastructure with specified dimensions.
 * 
 * This method constructs a Runway object with the provided length and width,
 * and returns a pointer to the created TransportInfrastructure.
 * 
 * @param runwayLength Length of the runway.
 * @param runwayWidth Width of the runway.
 * @return A pointer to the newly created Runway object.
 */
TransportInfrastructure* RunwayFactory::createInfrastructure(double runwayLength, double runwayWidth) {
    product = new Runway(runwayLength, runwayWidth);
    return product;
}

/**
 * @brief Creates a TransportInfrastructure object (no operation).
 * 
 * This overloaded method is provided for compatibility but does not perform any action.
 * 
 * @param param1 Unused integer parameter.
 * @param param2 Unused boolean parameter.
 * @return A nullptr, indicating no operation performed.
 */
TransportInfrastructure* RunwayFactory::createInfrastructure(int, bool) {
    //Do nothing
}

/**
 * @brief Creates a TransportInfrastructure object (no operation).
 * 
 * This overloaded method is provided for compatibility but does not perform any action.
 * 
 * @param param1 Unused integer parameter.
 * @param param2 Unused double parameter.
 * @return A nullptr, indicating no operation performed.
 */
TransportInfrastructure* RunwayFactory::createInfrastructure(int, double) {
    //Do nothing
}