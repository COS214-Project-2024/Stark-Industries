// Housing.cpp
#include "Housing.h"
#include "CollectTax.h"
#include <iostream>
#include <cmath>

Housing::Housing(double growthRate, Residential* prototypeBuilding) 
    : rate(growthRate), prototype(prototypeBuilding) {}

void Housing::handleRequest(int growthFactor, City* city) {
    if (growthFactor > 10) {
        // Calculate the number of new buildings to create
        int currentBuildings = prototype->getNumBuildings();
        double increase = currentBuildings * (rate / 100.0) * growthFactor;
        int newBuildings = static_cast<int>(std::ceil(increase));

        std::cout << "Handling Housing Growth: The housing is growing at a rate of " << rate 
                  << "%, adding " << newBuildings << " new residential buildings.\n";

        // Create new Residential buildings by cloning
        for (int i = 0; i < newBuildings; i++) {
            Residential* newBuilding = dynamic_cast<Residential*>(prototype->clone());
            city->addBuilding(newBuilding);
            // if (newBuilding) {
            //     addBuilding(newBuilding); // Add the clone to the buildings collection
            // }
        }

        // Pass the request to the next handler in the chain
        GrowthHandler::handleRequest(growthFactor, city);
    }
    // } else if (nextHandler) {
    //     // Pass the growth factor to the next handler if there is one
    //     GrowthHandler::handleRequest(growthFactor);
    // } else {
    //     std::cout << "Housing handler passes growth factor.\n";
    // }
}
