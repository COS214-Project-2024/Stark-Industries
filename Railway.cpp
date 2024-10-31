#include "Railway.h"
#include <iostream>



int Railway::railwayCount = 0;

Railway::Railway(double railLength, bool electrified) 
    : length(railLength), isElectrified(electrified), isUnderConstruction(true) {
        ++railwayCount;
    }

void Railway::build() {
    std::cout << "Building a " << (isElectrified ? "electrified" : "non-electrified") 
              << " railway with length " << length << "km" << std::endl;
    isUnderConstruction = false;
}


double Railway::getCost() {
    return length * (isElectrified ? 2000 : 1500);
}

bool Railway::getConstructionStatus() {
    return isUnderConstruction;
}

void Railway::updateCapacity(double newLength, bool electrified) {
    length = newLength;
    isElectrified = electrified;

    std::cout << "Updated railway capacity: Length = " << length 
              << " km, Electrified = " << (isElectrified ? "Yes" : "No") << std::endl;
}

int Railway::getRailwayCount() {
    return railwayCount;
}


Railway::~Railway() {
    railwayCount--;
}