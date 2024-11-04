/**
 * @file SatisfactionChecker.cpp
 * @brief Implementation of the SatisfactionChecker class, responsible for evaluating satisfaction levels of citizens and buildings.
 */
#include "SatisfactionChecker.h"


/**
 * @brief Updates the total building satisfaction based on a citizen's satisfaction level.
 * 
 * This method adds the building satisfaction of the provided citizen to the 
 * total building satisfaction tracked by the SatisfactionChecker.
 * 
 * @param citizen Pointer to the Citizen whose building satisfaction is being evaluated.
 */
void SatisfactionChecker::buildingSatisfaction(Citizen* citizen) {
    //std::cout << citizen->getName() << "'s building satisfaction: " << citizen->buildingSatisfaction << std::endl;
    buildingSatisfactionTotal += citizen->buildingSatisfaction;
}

/**
 * @brief Updates the total city satisfaction based on a citizen's satisfaction level.
 * 
 * This method adds the city satisfaction of the provided citizen to the 
 * total city satisfaction tracked by the SatisfactionChecker.
 * 
 * @param citizen Pointer to the Citizen whose city satisfaction is being evaluated.
 */
void SatisfactionChecker::citySatisfaction(Citizen* citizen) {
    //std::cout << citizen->getName() << "'s city satisfaction: " << citizen->citySatisfaction << std::endl;
    citySatisfactionTotal += citizen->citySatisfaction;
}

/**
 * @brief Updates the total city satisfaction based on a building's satisfaction level.
 * 
 * This method adds the city satisfaction of the provided building to the 
 * total city satisfaction tracked by the SatisfactionChecker.
 * 
 * @param building Pointer to the Building whose city satisfaction is being evaluated.
 */
void SatisfactionChecker::citySatisfaction(Building* building) {
    //std::cout << building->getType() << "'s city satisfaction: " << building->citySatisfaction << std::endl;
    citySatisfactionTotal += building->citySatisfaction;
}

/**
 * @brief Updates the total transport satisfaction based on a citizen's transport satisfaction level.
 * 
 * This method adds the transport satisfaction of the provided citizen to the 
 * total transport satisfaction tracked by the SatisfactionChecker.
 * 
 * @param citizen Pointer to the Citizen whose transport satisfaction is being evaluated.
 */
void SatisfactionChecker::transportSatisfaction(Citizen* citizen) {
    //std::cout << citizen->getName() << "'s transport satisfaction: " << citizen->getSatisfactionTransport() << std::endl;
    transportSatisfactionTotal += citizen->getSatisfactionTransport();
}

/**
 * @brief Visitor method for handling Citizen objects.
 * 
 * This method is a placeholder for future implementation of handling Citizen 
 * objects within the satisfaction checking mechanism.
 * 
 * @param citizen Pointer to the Citizen being visited.
 */
void SatisfactionChecker::visit(Citizen * citizen){
    //nothing...
}

/**
 * @brief Visitor method for handling Building objects.
 * 
 * This method is a placeholder for future implementation of handling Building 
 * objects within the satisfaction checking mechanism.
 * 
 * @param building Pointer to the Building being visited.
 */
void SatisfactionChecker::visit(Building * building){
    //nothing...
}