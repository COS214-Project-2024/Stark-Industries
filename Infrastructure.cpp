/**
 * @file Infrastructure.cpp
 * @brief Implements the Infrastructure class, responsible for managing infrastructure growth by adding roads, commercial, industrial, and landmark buildings in response to growth factors.
 */

#include "Infrastructure.h"
#include "Commercial.h"
#include "Industrial.h"
#include "Landmark.h"
#include "Road.h"
#include <iostream>
#include <cmath>

/**
 * @brief Constructs an Infrastructure object with a specified growth rate and prototype buildings.
 * 
 * @param growthRate Rate at which infrastructure should grow.
 * @param prototypeC Prototype for Commercial buildings.
 * @param prototypeI Prototype for Industrial buildings.
 * @param prototypeL Prototype for Landmark buildings.
 */
Infrastructure::Infrastructure(double growthRate, Commercial* prototypeC, Industrial* prototypeI, Landmark* prototypeL) 
    : growthRate(growthRate), prototypeC(prototypeC), prototypeI(prototypeI), prototypeL(prototypeL) {}

/**
 * @brief Handles the growth request for infrastructure based on the growth factor.
 * 
 * This method increases the number of roads, commercial, industrial, and landmark buildings
 * based on the growth factor. The request is passed to the next handler in the chain.
 * 
 * @param growthFactor Growth factor influencing the scale of infrastructure expansion.
 * @param city Pointer to the City object where infrastructure will be added.
 */
void Infrastructure::handleRequest(int growthFactor, City* city) {
    if (growthFactor < 100 && growthFactor > 20) {
        std::cout << "INFRASTRUCTURE GROWS:\n";
        std::cout << "The infrastructure is growing at a rate of " << growthRate << "%.\n\n";

        int numNewRoads = (growthFactor / 10);
        for (int i = 0; i < numNewRoads; ++i) {
            increaseRoads(2, 1.0, city);  // Example: 2 lanes, 1 km long roads
        }

        increaseCommercial(growthFactor, prototypeC, city);
        increaseIndustrial(growthFactor, prototypeI, city);
        increaseLandmark(growthFactor, prototypeL, city);

        GrowthHandler::handleRequest(growthFactor, city);
    }
}

/**
 * @brief Adds a new road to the city's infrastructure.
 * 
 * @param numLanes Number of lanes for the road.
 * @param roadLength Length of the road in kilometers.
 * @param city Pointer to the City object where the road will be added.
 */
void Infrastructure::increaseRoads(int numLanes, double roadLength, City* city) {
    Road* newRoad = new Road(numLanes, roadLength);
    newRoad->build();
    city->addInfrastructure(newRoad);
    std::cout << "New road added: " << numLanes << " lanes, " << roadLength << " km long.\n";
}

/**
 * @brief Adds new commercial buildings to the city based on the growth factor.
 * 
 * This method clones the prototype commercial building to create the required number of new buildings.
 * 
 * @param growthFactor Factor influencing the number of new buildings.
 * @param prototypeC Pointer to the prototype Commercial building.
 * @param city Pointer to the City object where buildings will be added.
 */
void Infrastructure::increaseCommercial(int growthFactor, Commercial* prototypeC, City* city) {
    int currentBuildings = prototypeC->getNumBuildings();
    double increase = currentBuildings * (growthRate / 100.0);
    int newBuildings = static_cast<int>(std::ceil(increase));

    std::cout << "Adding " << newBuildings << " new commercial buildings.\n";

    for (int i = 0; i < newBuildings; i++) {
        Commercial* newBuilding = dynamic_cast<Commercial*>(prototypeC->clone());
        city->addBuilding(newBuilding);
    }
    prototypeC->setNumBuildings(currentBuildings + newBuildings);
}

/**
 * @brief Adds new industrial buildings to the city based on the growth factor.
 * 
 * This method clones the prototype industrial building to create the required number of new buildings.
 * 
 * @param growthFactor Factor influencing the number of new buildings.
 * @param prototypeI Pointer to the prototype Industrial building.
 * @param city Pointer to the City object where buildings will be added.
 */
void Infrastructure::increaseIndustrial(int growthFactor, Industrial* prototypeI, City* city) {
    int currentBuildings = prototypeI->getNumBuildings();
    double increase = currentBuildings * (growthRate / 100.0);
    int newBuildings = static_cast<int>(std::ceil(increase));

    std::cout << "Adding " << newBuildings << " new industrial buildings.\n";

    for (int i = 0; i < newBuildings; i++) {
        Industrial* newBuilding = dynamic_cast<Industrial*>(prototypeI->clone());
        city->addBuilding(newBuilding);
    }
    prototypeI->setNumBuildings(currentBuildings + newBuildings);
}

/**
 * @brief Adds new landmarks to the city based on the growth factor.
 * 
 * This method clones the prototype landmark building to create the required number of new landmarks.
 * 
 * @param growthFactor Factor influencing the number of new landmarks.
 * @param prototypeL Pointer to the prototype Landmark building.
 * @param city Pointer to the City object where landmarks will be added.
 */
void Infrastructure::increaseLandmark(int growthFactor, Landmark* prototypeL, City* city) {
    int currentBuildings = prototypeL->getNumBuildings();
    double increase = currentBuildings * (growthRate / 100.0);
    int newBuildings = static_cast<int>(std::ceil(increase));

    std::cout << "Adding " << newBuildings << " new landmarks.\n";

    for (int i = 0; i < newBuildings; i++) {
        Landmark* newBuilding = dynamic_cast<Landmark*>(prototypeL->clone());
        city->addBuilding(newBuilding);
    }
    prototypeL->setNumBuildings(currentBuildings + newBuildings);
}

/**
 * @brief Retrieves the growth factor for infrastructure.
 * 
 * @return The infrastructure growth rate as a double.
 */
double Infrastructure::getGrowthFactor() {
    return growthRate;
}
