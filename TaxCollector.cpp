#include "TaxCollector.h"

void TaxCollector::visit(Citizen* citizen) {
    this->taxCollected += citizen->taxPaid;
    std::cout << "Tax collected from " << citizen->getName() << std::endl;
}

void TaxCollector::visit(Building* building) {
    this->taxCollected += building->taxPaid;
}