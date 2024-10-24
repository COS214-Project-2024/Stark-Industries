// Housing.cpp
#include "Housing.h"
#include <iostream>

Housing::Housing(int capacity, int demand) : housingDemand(demand) , housingCapacity(capacity)
{}

void Housing::handleRequest() {
    if (housingDemand > 0) {
        std::cout << "Handling Housing Growth: The housing demand is " 
                  << housingDemand << " new units.\n";
    } else if (nextHandler) {
        nextHandler->handleRequest();
    } else {
        std::cout << "No handler available for this request.\n";
    }
}
