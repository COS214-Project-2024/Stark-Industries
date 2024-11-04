/**
 * @file Road.cpp
 * @brief Implementation of the Road class, representing a road infrastructure.
 */
#include "Road.h"
#include <cmath>
#include <iostream>
#include <algorithm>

int Road::roadCount = 0;

/**
 * @brief Constructs a Road object with the specified number of lanes and length.
 * 
 * Initializes the road and increments the road count.
 * 
 * @param numLanes Number of lanes in the road.
 * @param roadLength Length of the road in kilometers.
 */
Road::Road(int numLanes, double roadLength) 
    : lanes(numLanes), length(roadLength), isUnderConstruction(true) {
       ++roadCount;} 

/**
 * @brief Builds the road and marks it as no longer under construction.
 * 
 * Outputs the details of the road being built.
 */
void Road::build() {


    std::cout << "Building a road with " << lanes << " lanes and length " 
              << length << "km" << std::endl;
    isUnderConstruction = false;
}



/**
 * @brief Updates the traffic conditions based on the time of day.
 * 
 * Calculates current traffic load and updates traffic statistics, 
 * including vehicle count, average speed, and congestion level.
 * 
 * @param time The current time in hours (24-hour format).
 */
void Road::updateTraffic(int time) {
    double baseTraffic = capacity * 0.4;
    double rushHourFactor = 1.0;
    
    if(time >= 7 && time <= 9) {
        rushHourFactor = 2.5;
    }
    else if(time >= 16 && time <= 18) {
        rushHourFactor = 2.3;
    }
    else if(time >= 23 || time <= 5) {
        rushHourFactor = 0.3;
    }
    
    currentLoad = static_cast<int>(baseTraffic * rushHourFactor);
    hourlyTrafficVolume[time] = currentLoad;
    
    trafficStats.vehicleCount = currentLoad;
    trafficStats.averageSpeed = speedLimit * (1 - (static_cast<double>(currentLoad) / capacity) * (static_cast<double>(currentLoad) / capacity));
    trafficStats.congestionLevel = static_cast<int>((static_cast<double>(currentLoad) / capacity) * 100);
    
    double deteriorationFactor = (static_cast<double>(currentLoad) / capacity) * 0.01;
    deteriorate(deteriorationFactor);
}



/**
 * @brief Calculates the construction cost of the road.
 * 
 * @return The estimated cost of constructing the road.
 */
double Road::getCost() {
    return length * lanes * 1000; // Cost per km per lane

}

/**
 * @brief Checks if the road is currently under construction.
 * 
 * @return True if the road is under construction; otherwise, false.
 */
bool Road::getConstructionStatus() {
    return isUnderConstruction;
}


/**
 * @brief Deteriorates the road condition based on traffic load.
 * 
 * @param deteriorationFactor Factor affecting the rate of deterioration.
 */
void Road::deteriorate(double deteriorationFactor) {
    condition -= (deteriorationFactor * 100.0);

    if (condition < 0.0) {
        condition = 0.0;
    }

    if (condition < 30.0) {
        needsRepaving = true;
    }
}


/**
 * @brief Updates the road's capacity and type based on new specifications.
 * 
 * @param newLanes The new number of lanes for the road.
 * @param newType The new type of the road.
 */
void Road::updateCapacity(int newLanes, RoadType newType) {
    lanes = newLanes;
    type = newType;

    switch(type) {
        case RoadType::LOCAL:
            capacity = 500 * lanes;
            speedLimit = 30;
            constructionCost = length * lanes * 800000;
            break;
        case RoadType::COLLECTOR:
            capacity = 1000 * lanes;
            speedLimit = 40;
            constructionCost = length * lanes * 1200000;
            break;
        case RoadType::ARTERIAL:
            capacity = 2000 * lanes;
            speedLimit = 60;
            constructionCost = length * lanes * 1500000;
            break;
        case RoadType::HIGHWAY:
            capacity = 3000 * lanes;
            speedLimit = 120;
            constructionCost = length * lanes * 2000000;
            break;
    }

    maintenanceCostPerYear = constructionCost * 0.05;
}


/**
 * @brief Adds a traffic light at a specified position on the road.
 * 
 * @param position The position of the traffic light along the road length.
 */
void Road::addTrafficLight(double position) {
    if (position >= 0 && position <= length &&
        std::find(trafficLights.begin(), trafficLights.end(), position) == trafficLights.end()) {
        trafficLights.push_back(position);
    }
}

/**
 * @brief Removes a traffic light from a specified position on the road.
 * 
 * @param position The position of the traffic light to be removed.
 */
void Road::removeTrafficLight(double position) {
    auto it = std::find(trafficLights.begin(), trafficLights.end(), position);
    if (it != trafficLights.end()) {
        trafficLights.erase(it); // Remove the traffic light if it exists
    }
}

/**
 * @brief Retrieves a list of traffic light positions on the road.
 * 
 * @return A vector containing the positions of traffic lights.
 */
std::vector<double> Road::getTrafficLights() {
    return trafficLights;
}

/**
 * @brief Retrieves the total count of Road objects created.
 * 
 * @return The current count of road instances.
 */
// Getter for road count
int Road::getRoadCount() {
    return roadCount;
}

/**
 * @brief Destructor for the Road class.
 * 
 * Decreases the road count when a Road object is destroyed.
 */
Road::~Road() {
    roadCount--;
}