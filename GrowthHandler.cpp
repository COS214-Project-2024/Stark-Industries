/**
 * @file GrowthHandler.cpp
 * @brief Implements the GrowthHandler class, which serves as an abstract handler in a chain of responsibility for managing growth-related requests.
 */

#include "GrowthHandler.h"
#include <iostream>
using namespace std;

/**
 * @brief Constructs a GrowthHandler with no next handler in the chain.
 */
GrowthHandler::GrowthHandler() : nextHandler(nullptr) {}

/**
 * @brief Sets the next handler in the chain of responsibility.
 * 
 * This allows chaining of multiple handlers for processing growth-related requests.
 * 
 * @param handler Pointer to the next GrowthHandler in the chain.
 */
void GrowthHandler::setNextHandler(GrowthHandler* handler) {
    nextHandler = handler;
}

/**
 * @brief Handles a growth-related request based on the growth factor and city.
 * 
 * If the growth factor is within the valid range (1 to 100), the request is passed 
 * to the next handler in the chain. Otherwise, an informational message is displayed.
 * 
 * @param growthFactor An integer representing the intensity of growth.
 * @param city Pointer to the City object related to the growth request.
 */
void GrowthHandler::handleRequest(int growthFactor, City* city) {
    if (nextHandler && growthFactor < 101 && growthFactor > 0) {
        nextHandler->handleRequest(growthFactor, city);
    } else if (nextHandler) {
        cout << "No handler available to process the request." << endl;
    }
}
