/**
 * @file Runway.cpp
 * @brief Implementation of the Runway class, representing runway infrastructure.
 */
#include "Runway.h"
#include <iostream>

/**
 * @brief Static variable to keep track of the number of runway instances.
 */
int Runway::runwayCount = 0;

/**
 * @brief Constructs a Runway object with specified dimensions.
 * 
 * Initializes the runway with a given length and width, and marks it as under construction.
 * Increments the static runway count.
 * 
 * @param runwayLength Length of the runway.
 * @param runwayWidth Width of the runway.
 */
Runway::Runway(double runwayLength, double runwayWidth) 
    : length(runwayLength), width(runwayWidth), isUnderConstruction(true) {
        ++runwayCount;
    }

/**
 * @brief Builds the runway.
 * 
 * Outputs the construction details and sets the runway's construction status to complete.
 */
void Runway::build() {
    std::cout << "Building a runway with length " << length 
              << "km and width " << width << "km" << std::endl;
    isUnderConstruction = false;
}

/**
 * @brief Calculates the cost of the runway construction.
 * 
 * The cost is calculated based on the runway's dimensions, assuming a fixed cost per square kilometer.
 * 
 * @return The total cost of constructing the runway.
 */
double Runway::getCost() {
    return length * width * 5000;
}

/**
 * @brief Gets the construction status of the runway.
 * 
 * @return True if the runway is under construction, false otherwise.
 */
bool Runway::getConstructionStatus() {
    return isUnderConstruction;
}

/**
 * @brief Updates the runway's capacity by changing its dimensions.
 * 
 * Outputs the updated dimensions of the runway.
 * 
 * @param newLength New length of the runway.
 * @param newWidth New width of the runway.
 */
void Runway::updateCapacity(double newLength, double newWidth) {
    length = newLength;
    width = newWidth;

    std::cout << "Updated runway capacity: Length = " << length 
              << " km, Width = " << width << " km" << std::endl;
}

/**
 * @brief Gets the current count of runway instances.
 * 
 * @return The number of Runway objects created.
 */
int Runway::getRunwayCount() {
    return runwayCount;
}


/**
 * @brief Destructor for the Runway class.
 * 
 * Decrements the runway count when a Runway object is destroyed.
 */
Runway::~Runway() {
    runwayCount--;
}