/**
 * @file Railway.cpp
 * @brief Implementation of the Railway class.
 * 
 * This file contains the implementation of the Railway class, which models 
 * a railway infrastructure with attributes such as length and electrification 
 * status. It includes methods to build the railway, calculate construction 
 * costs, and manage the railway's construction status.
 */
#include "Railway.h"
#include <iostream>


/**
 * @class Railway
 * @brief Represents a railway infrastructure.
 * 
 * The Railway class encapsulates the properties and behaviors of a railway, 
 * including its length, electrification status, and construction state. 
 * It provides methods to build the railway, calculate costs, and manage 
 * its construction status. The class also tracks the total number of 
 * railway instances created.
 */
int Railway::railwayCount = 0;

/**
 * @brief Constructs a Railway object with specified length and electrification status.
 * 
 * @param railLength The length of the railway in kilometers.
 * @param electrified A boolean indicating if the railway is electrified.
 */
Railway::Railway(double railLength, bool electrified) 
    : length(railLength), isElectrified(electrified), isUnderConstruction(true) {
        ++railwayCount;
    }

/**
 * @brief Builds the railway infrastructure.
 * 
 * This function simulates the construction of the railway, outputting 
 * the details about the railway being built, including its length and 
 * electrification status. It updates the construction status to complete.
 */
void Railway::build() {
    std::cout << "Building a " << (isElectrified ? "electrified" : "non-electrified") 
              << " railway with length " << length << "km" << std::endl;
    isUnderConstruction = false;
}


/**
 * @brief Calculates the construction cost of the railway.
 * 
 * @return The cost of constructing the railway based on its length and 
 *         whether it is electrified.
 */
double Railway::getCost() {
    return length * (isElectrified ? 2000 : 1500);
}

/**
 * @brief Gets the current construction status of the railway.
 * 
 * @return True if the railway is under construction; false otherwise.
 */
bool Railway::getConstructionStatus() {
    return isUnderConstruction;
}

/**
 * @brief Updates the capacity of the railway.
 * 
 * This function updates the railway's length and electrification status, 
 * outputting the new details of the railway.
 * 
 * @param newLength The new length of the railway in kilometers.
 * @param electrified A boolean indicating if the railway is electrified.
 */
void Railway::updateCapacity(double newLength, bool electrified) {
    length = newLength;
    isElectrified = electrified;

    std::cout << "Updated railway capacity: Length = " << length 
              << " km, Electrified = " << (isElectrified ? "Yes" : "No") << std::endl;
}


/**
 * @brief Gets the total count of Railway instances created.
 * 
 * @return The number of Railway objects currently in existence.
 */
int Railway::getRailwayCount() {
    return railwayCount;
}


/**
 * @brief Destructor for the Railway class.
 * 
 * This destructor decrements the railway count when a Railway object 
 * is destroyed.
 */
Railway::~Railway() {
    railwayCount--;
}