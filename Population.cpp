// Population.cpp
#include "Population.h"
#include <iostream>

Population::Population(int rate) : populationGrowthRate(rate) {}

void Population::handleRequest() {
    if (populationGrowthRate > 0) {
        std::cout << "Handling Population Growth: The population is growing at a rate of " 
                  << populationGrowthRate << "%.\n";
    } else if (nextHandler) {
        nextHandler->handleRequest();
    } else {
        std::cout << "No handler available for this request.\n";
    }
}
