// Infrastructure.cpp
#include "Infrastructure.h"
#include <iostream>

Infrastructure::Infrastructure(int roadsBuilt, int utilityCapacity)
    : roads(roadsBuilt), capacity(utilityCapacity) {}

void Infrastructure::handleRequest() {
    if (roads > 0 || capacity > 0) {
        std::cout << "Handling Infrastructure Growth: There are " 
                  << roads << " new roads built and a utility capacity of "
                  << capacity << ".\n";
    } else if (nextHandler) {
        nextHandler->handleRequest();
    } else {
        std::cout << "No handler available for this request.\n";
    }
}
