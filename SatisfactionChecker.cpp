#include "SatisfactionChecker.h"

void SatisfactionChecker::buildingSatisfaction(Citizen* citizen) {
    std::cout << citizen->getName() << "'s building satisfaction: " << citizen->buildingSatisfaction << std::endl;
    buildingSatisfactionTotal += citizen->buildingSatisfaction;
}

void SatisfactionChecker::citySatisfaction(Citizen* citizen) {
    std::cout << citizen->getName() << "'s city satisfaction: " << citizen->citySatisfaction << std::endl;
    citySatisfactionTotal += citizen->citySatisfaction;
}

void SatisfactionChecker::citySatisfaction(Building* building) {
    std::cout << building->getType() << "'s city satisfaction: " << building->citySatisfaction << std::endl;
    citySatisfactionTotal += building->citySatisfaction;
}

void SatisfactionChecker::transportSatisfaction(Citizen* citizen) {
    std::cout << citizen->getName() << "'s transport satisfaction: " << citizen->getSatisfactionTransport() << std::endl;
    transportSatisfactionTotal += citizen->getSatisfactionTransport();
}

void SatisfactionChecker::visit(Citizen * citizen){
    //nothing...
}

void SatisfactionChecker::visit(Building * building){
    //nothing...
}