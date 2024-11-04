/**
 * @file Public.cpp
 * @brief Implements the Public class, representing a public transport system with properties such as seating capacity, maintenance status, and travel time.
 */

#include "Public.h"
#include <iostream>

/**
 * @brief Constructor to initialize Public transport properties.
 * 
 * @param name The name of the public transport.
 * @param travelTime Travel time for the public transport.
 * @param fee The fee for using this transport.
 * @param seatingCapacity Total seating capacity of the public transport.
 */
Public::Public(std::string name, double travelTime, double fee, int seatingCapacity) 
    : name(name), isUnderMaintenance(false), travelTime(travelTime), fee(fee), 
      seatingCapacity(seatingCapacity), availableSeats(seatingCapacity) {}

/**
 * @brief Perform maintenance on the public transport and mark it as available after completion.
 */
void Public::doMaintenance() {
    isUnderMaintenance = false;
    std::cout << "Public transport maintenance completed.\n";
}

/**
 * @brief Get the commute time for the public transport.
 * @return Travel time as a double.
 */
double Public::commuteTime() {
    return travelTime;
}

/**
 * @brief Calculate passenger satisfaction based on travel time.
 * 
 * @return Satisfaction level as an integer (85 if travel time is less than 30, otherwise 70).
 */
int Public::calculateSatisfaction() {
    return travelTime < 30 ? 85 : 70;
}

/**
 * @brief Check if the public transport is available.
 * @return True if not under maintenance, otherwise false.
 */
bool Public::isAvailable() const {
    return !isUnderMaintenance;
}

/**
 * @brief Get the fee for the public transport.
 * @return Fee as a double.
 */
double Public::getFee() const {
    return fee;
}

/**
 * @brief Get the type of the transport.
 * @return String representing the type of transport ("Public Transport").
 */
std::string Public::getType() const {
    return "Public Transport";
}

// Seating capacity methods

/**
 * @brief Get the seating capacity of the public transport.
 * @return Total seating capacity as an integer.
 */
int Public::getSeatingCapacity() const {
    return seatingCapacity;
}

/**
 * @brief Get the number of available seats.
 * @return Available seats as an integer.
 */
int Public::getAvailableSeats() const {
    return availableSeats;
}

/**
 * @brief Reserve a seat in the public transport.
 * @return True if a seat is successfully reserved, otherwise false.
 */
bool Public::reserveSeat() {
    if (availableSeats > 0) {
        --availableSeats;
        return true;
    }
    return false;
}

/**
 * @brief Release a reserved seat in the public transport.
 */
void Public::releaseSeat() {
    if (availableSeats < seatingCapacity) {
        ++availableSeats;
    }
}

// Cargo handling methods

/**
 * @brief Check if the public transport supports cargo.
 * @return False as public transport does not support cargo in this implementation.
 */
bool Public::hasCargoCapacity() const {
    return false;
}

/**
 * @brief Get the cargo capacity of the public transport.
 * @return 0 as public transport does not support cargo; displays a message.
 */
int Public::getCargoCapacity() const {
    std::cout << "Public transport doesn't support cargo\n";
    return 0;
}

/**
 * @brief Get the available cargo space.
 * @return 0 as public transport does not support cargo; displays a message.
 */
int Public::getAvailableCargoSpace() const {
    std::cout << "Public transport doesn't support cargo\n";
    return 0;
}

/**
 * @brief Attempt to load cargo onto the public transport.
 * 
 * @param cargo The amount of cargo to load.
 * @return False as public transport does not support cargo; displays a message.
 */
bool Public::loadCargo(int cargo) {
    std::cout << "Public transport doesn't support cargo\n";
    return false;
}

/**
 * @brief Attempt to unload cargo from the public transport.
 * 
 * @param cargo The amount of cargo to unload; displays a message.
 */
void Public::unloadCargo(int cargo) {
    std::cout << "Public transport doesn't support cargo\n";
}
