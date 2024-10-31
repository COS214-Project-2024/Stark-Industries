#include "Runway.h"
#include <iostream>


int Runway::runwayCount = 0;
Runway::Runway(double runwayLength, double runwayWidth) 
    : length(runwayLength), width(runwayWidth), isUnderConstruction(true) {
        ++runwayCount;
    }

void Runway::build() {
    std::cout << "Building a runway with length " << length 
              << "km and width " << width << "km" << std::endl;
    isUnderConstruction = false;
}

double Runway::getCost() {
    return length * width * 5000;
}

bool Runway::getConstructionStatus() {
    return isUnderConstruction;
}

void Runway::updateCapacity(double newLength, double newWidth) {
    length = newLength;
    width = newWidth;

    std::cout << "Updated runway capacity: Length = " << length 
              << " km, Width = " << width << " km" << std::endl;
}

int Runway::getRunwayCount() {
    return runwayCount;
}


Runway::~Runway() {
    runwayCount--;
}