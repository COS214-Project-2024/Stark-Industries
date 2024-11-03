#include "Infrastructure.h"
#include "Commercial.h"
#include "Industrial.h"
#include "Landmark.h"
#include "Road.h"
#include <iostream>
#include <cmath>

Infrastructure::Infrastructure(double growthRate, Commercial* prototypeC, Industrial* prototypeI, Landmark* prototypeL) 
: growthRate(growthRate), prototypeC(prototypeC), prototypeI(prototypeI), prototypeL(prototypeL) {}

void Infrastructure::handleRequest(int growthFactor, City* city) {
    if (growthFactor < 100 && growthFactor > 20) {
        std::cout << "INFRASTRUCTURE GROWS:\n";
        std::cout << "The infrastructure is growing at a rate of " 
                  << growthRate << "%.\n\n";

        // Example of how you might calculate the number of roads to build based on the growth factor
        int numNewRoads = (growthFactor / 10); // Arbitrary example; adjust as needed
        for (int i = 0; i < numNewRoads; ++i) {
            increaseRoads(2, 1.0, city); // Example: 2 lanes, 1 km long roads
        }

        // Increase commercial, industrial, and landmark areas
        increaseCommercial(growthFactor, prototypeC, city);
        increaseIndustrial(growthFactor, prototypeI, city);
        increaseLandmark(growthFactor, prototypeL, city);

        GrowthHandler::handleRequest(growthFactor, city);
    }
    // } else if (nextHandler) {
    //     GrowthHandler::handleRequest(growthFactor);
    // } else {
    //     std::cout << "No handler available to process the request.\n";
    // }
}

void Infrastructure::increaseRoads(int numLanes, double roadLength, City* city) {
    Road* newRoad = new Road(numLanes, roadLength); // Create a new Road object
    newRoad->build(); // Build the road
    city->addInfrastructure(newRoad);
    // roads.push_back(newRoad); // Store the new road
    std::cout << "New road added: " << numLanes << " lanes, " << roadLength << " km long.\n";
}

void Infrastructure::increaseCommercial(int growthFactor, Commercial* prototypeC, City* city) {
        // Calculate the number of new buildings to create
        int currentBuildings = prototypeC->getNumBuildings(); // Assuming prototypeCommercial is defined
        double increase = currentBuildings * (growthRate / 100.0) * growthFactor;
        int newBuildings = static_cast<int>(std::ceil(increase));

        std::cout << "Handling Commercial Growth: Adding " << newBuildings << " new commercial buildings.\n";

        // Create new Commercial buildings by cloning
        for (int i = 0; i < newBuildings; i++) {
            Commercial* newBuilding = dynamic_cast<Commercial*>(prototypeC->clone()); // Clone commercial building
            city->addBuilding(newBuilding);
            // Add the new building to a collection
            // commercialBuildings.push_back(std::unique_ptr<Residential>(newBuilding));
        }
        prototypeC->setNumBuildings(currentBuildings + newBuildings);
}

void Infrastructure::increaseIndustrial(int growthFactor, Industrial* prototypeI, City* city) {
        // Calculate the number of new buildings to create
        int currentBuildings = prototypeI->getNumBuildings(); // Assuming prototypeIndustrial is defined
        double increase = currentBuildings * (growthRate / 100.0) * growthFactor;
        int newBuildings = static_cast<int>(std::ceil(increase));

        std::cout << "Adding " << newBuildings << " new industrial buildings.\n";

        // Create new Industrial buildings by cloning
        for (int i = 0; i < newBuildings; i++) {
            Industrial* newBuilding = dynamic_cast<Industrial*>(prototypeI->clone()); // Clone industrial building
            city->addBuilding(newBuilding);
            // Add the new building to a collection
            // commercialBuildings.push_back(std::unique_ptr<Residential>(newBuilding));
        }
        prototypeI->setNumBuildings(currentBuildings + newBuildings);
}

void Infrastructure::increaseLandmark(int growthFactor, Landmark* prototypeL, City* city) {
        // Calculate the number of new buildings to create
        int currentBuildings = prototypeL->getNumBuildings(); // Assuming prototypeLandmark is defined
        double increase = currentBuildings * (growthRate / 100.0) * growthFactor;
        int newBuildings = static_cast<int>(std::ceil(increase));

        std::cout << "Adding " << newBuildings << " new landmarks.\n";

        // Create new Landmark buildings by cloning
        for (int i = 0; i < newBuildings; i++) {
            Landmark* newBuilding = dynamic_cast<Landmark*>(prototypeL->clone()); // Clone landmark building
            city->addBuilding(newBuilding);
            // Add the new building to a collection
            // landmarkBuildings.push_back(std::unique_ptr<Residential>(newBuilding));
        }
        prototypeL->setNumBuildings(currentBuildings + newBuildings);
}
