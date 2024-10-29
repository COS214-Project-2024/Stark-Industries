// Population.cpp
#include "Population.h"
#include <iostream>

Population::Population(double rate) : populationGrowthRate(rate) {}

void Population::handleRequest(int growthFactor) {
    if (growthFactor < 100 && growthFactor > 0) {
        cout << "Handling Population Growth: The population is growing at a rate of " << populationGrowthRate << "%.\n";
        GrowthHandler::handleRequest(growthFactor);
    } else if (nextHandler) {
        GrowthHandler::handleRequest(growthFactor);
    }
    else {
        cout << "Population handler passes growth factor.\n";
    }
}
