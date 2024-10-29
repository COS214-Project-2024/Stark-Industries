// Housing.cpp
#include "Housing.h"
#include <iostream>

Housing::Housing(double growthRate) : rate(growthRate)
{}

void Housing::handleRequest(int growthFactor) {
    if (growthFactor < 100 && growthFactor > 10) {
        cout << "Handling Housing Growth: The housing is growing at a rate of " << rate << "%.\n";
        GrowthHandler::handleRequest(growthFactor);
    } else if (nextHandler) {
        // cout << "Housing handler passes growth factor.\n";
        GrowthHandler::handleRequest(growthFactor);
    }
    else {
        cout << "Housing handler passes growth factor.\n";
    }
}
