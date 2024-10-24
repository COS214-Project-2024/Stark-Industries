// Economic.cpp
#include "Economic.h"
#include <iostream>

Economic::Economic(int jobs, double growthRate) : jobCreationRate(jobs), economicGrowthRate(growthRate) {}

void Economic::handleRequest() {
    if (jobCreationRate > 0) {
        std::cout << "Handling Economic Growth: There are " 
                  << jobCreationRate << " new job opportunities.\n";
    } else if (nextHandler) {
        nextHandler->handleRequest();
    } else {
        std::cout << "No handler available for this request.\n";
    }
}
