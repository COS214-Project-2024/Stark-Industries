#include "SatisfactionChecker.h"

void SatisfactionChecker::buildingSatisfaction(Citizen* citizen) {
    // std::cout << citizen->getName() << "'s building satisfaction: " << citizen->buildingSatisfaction << std::endl;
}

void SatisfactionChecker::citySatisfaction(Citizen* citizen) {
    // std::cout << citizen->getName() << "'s city satisfaction: " << citizen->citySatisfaction << std::endl;
}

void SatisfactionChecker::citySatisfaction(Building* building) {
    // std::cout << building->getType() << "'s city satisfaction: " << building->citySatisfaction << std::endl;
}

void SatisfactionChecker::transportSatisfaction(Citizen* citizen) {
    std::cout << citizen->getName() << "'s transport satisfaction: " << citizen->getSatisfactionTransport() << std::endl;
}

void SatisfactionChecker::visit(Citizen * citizen){
    //nothing...
}

void SatisfactionChecker::visit(Building * building){
    //nothing...
}