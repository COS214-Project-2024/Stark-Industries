/**
 * @file TaxCollector.cpp
 * @brief Implementation of the TaxCollector class, responsible for collecting taxes from various entities.
 */
#include "TaxCollector.h"

/**
 * @brief Collects tax from a Citizen object.
 *
 * This method adds the tax amount paid by the citizen to the total `taxCollected` by the `TaxCollector`.
 * 
 * @param citizen Pointer to the Citizen object from which tax is to be collected.
 */
void TaxCollector::visit(Citizen* citizen) {
    this->taxCollected += citizen->taxPaid;
    //std::cout << "Tax collected from " << citizen->getName() << " of " << citizen->taxPaid << std::endl;
}

/**
 * @brief Collects tax from a Building object.
 *
 * This method adds the tax amount paid by the building to the total `taxCollected` by the `TaxCollector`.
 * 
 * @param building Pointer to the Building object from which tax is to be collected.
 */
void TaxCollector::visit(Building* building) {
    this->taxCollected += building->taxPaid;
    //std::cout << "Tax collected from " << building->getType() << " of " << building->taxPaid << std::endl;
}