// Economic.cpp
#include "Economic.h"
#include <iostream>

Economic::Economic(double growthRate) : economicGrowthRate(growthRate) {}

void Economic::handleRequest(int growthFactor) {
    if (growthFactor < 100 && growthFactor > 15) {
        cout << "Handling Economy Growth: The economy is growing at a rate of " << economicGrowthRate << "%.\n";
        GrowthHandler::handleRequest(growthFactor);
    } else if (nextHandler) {
        // cout << "Economy handler passes growth factor.\n";
        GrowthHandler::handleRequest(growthFactor);
    }
    else {
        cout << "Economy handler passes growth factor.\n";
    }
}
