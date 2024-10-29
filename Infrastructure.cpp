// Infrastructure.cpp
#include "Infrastructure.h"
#include <iostream>

Infrastructure::Infrastructure(double growthRate) : growthRate(growthRate) {}

void Infrastructure::handleRequest(int growthFactor) {
    if (growthFactor < 100 && growthFactor > 20) {
        cout << "Handling Infratructure Growth: The infrastructure is growing at a rate of " << growthRate << "%.\n";
        GrowthHandler::handleRequest(growthFactor);
    } else if (nextHandler) {
        // std::cout << "Infrastructure handler passes growth factor.\n";
        GrowthHandler::handleRequest(growthFactor);
    }
    // else {
    //     std::cout << "No handler available to process the request.\n";
    // }
}
