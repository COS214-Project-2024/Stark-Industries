#include "Road.h"
#include <cmath>
#include <iostream>
#include <algorithm>

int Road::roadCount = 0;
Road::Road(int numLanes, double roadLength) 
    : lanes(numLanes), length(roadLength), isUnderConstruction(true) {
        ++roadCount;
    }
void Road::build() {


    std::cout << "Building a road with " << lanes << " lanes and length " 
              << length << "km" << std::endl;
    isUnderConstruction = false;
}



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



double Road::getCost() {
    return length * lanes * 1000; // Cost per km per lane

}

bool Road::getConstructionStatus() {
    return isUnderConstruction;
}


void Road::deteriorate(double deteriorationFactor) {
    condition -= (deteriorationFactor * 100.0);

    if (condition < 0.0) {
        condition = 0.0;
    }

    if (condition < 30.0) {
        needsRepaving = true;
    }
}


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


void Road::addTrafficLight(double position) {
    if (position >= 0 && position <= length &&
        std::find(trafficLights.begin(), trafficLights.end(), position) == trafficLights.end()) {
        trafficLights.push_back(position);
    }
}

void Road::removeTrafficLight(double position) {
    auto it = std::find(trafficLights.begin(), trafficLights.end(), position);
    if (it != trafficLights.end()) {
        trafficLights.erase(it); // Remove the traffic light if it exists
    }
}

// Getter for road count
int Road::getRoadCount() {
    return roadCount;
}

Road::~Road() {
    roadCount--;
}