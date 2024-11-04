/**
 * @file Housing.cpp
 * @brief Implements the Housing class, responsible for managing housing growth by adding new residential buildings in response to growth factors.
 */

#include "Housing.h"
#include "CollectTax.h"
#include <iostream>
#include <cmath>

/**
 * @brief Constructs a Housing object with a specified growth rate and a prototype building.
 * 
 * @param growthRate Rate of housing growth.
 * @param prototypeBuilding Pointer to a Residential building used as a prototype for cloning new buildings.
 */
Housing::Housing(double growthRate, Residential* prototypeBuilding) 
    : rate(growthRate), prototype(prototypeBuilding) {}

/**
 * @brief Handles housing growth requests based on the growth factor.
 * 
 * This function calculates the number of new residential buildings to add to the city based on the
 * growth factor and housing growth rate. New buildings are created by cloning the prototype building 
 * and added to the city's list of buildings. The request is then passed to the next handler in the chain.
 * 
 * @param growthFactor Integer representing the growth intensity.
 * @param city Pointer to the City object where new buildings are added.
 */
void Housing::handleRequest(int growthFactor, City* city) {
    if (growthFactor > 10) {
        // Calculate the number of new buildings to create
        int currentBuildings = prototype->getNumBuildings();
        double increase = currentBuildings * (rate / 100.0);
        int newBuildings = static_cast<int>(std::ceil(increase));

        std::cout << "HOUSING GROWS:\n";
        std::cout << "The housing is growing at a rate of " << rate 
                  << "%, adding " << newBuildings << " new residential buildings.\n\n";

        // Create new Residential buildings by cloning
        for (int i = 0; i < newBuildings; i++) {
            Residential* newBuilding = dynamic_cast<Residential*>(prototype->clone());
            city->addBuilding(newBuilding);
        }

        // Pass the request to the next handler in the chain
        GrowthHandler::handleRequest(growthFactor, city);
    }
}

/**
 * @brief Gets the housing growth factor rate.
 * 
 * @return The housing growth rate as a double.
 */
double Housing::getGrowthFactor() {
    return rate;
}
