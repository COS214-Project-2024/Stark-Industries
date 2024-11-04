/**
 * @class Train
 * @brief Represents a train transport system, providing functionality for managing seats, cargo space, and other transport-related operations.
 * 
 * This class provides a specific implementation for Train transport within the transport strategy pattern.
 */
#include "Train.h"
#include <iostream>

/**
 * @brief Constructor to initialize Train transport properties.
 * @param name The name of the train transport.
 * @param travelTime Travel time for the train transport.
 * @param fee The fee for the train transport.
 * @param seatingCap Total seating capacity of the train transport.
 * @param cargoCap Total cargo capacity of the train transport.
 */
Train::Train(string name, double travelTime, double fee, int seatingCap, int cargoCap) 
    : name(name), isUnderMaintenance(false), travelTime(travelTime), fee(fee),
      seatingCapacity(seatingCap), availableSeats(seatingCap), 
      cargoCapacity(cargoCap), availableCargoSpace(cargoCap) {}

/**
 * @brief Perform maintenance on the train transport and mark it as available after completion.
 */
void Train::doMaintenance() {
    isUnderMaintenance = false;
    std::cout << "Train transport maintenance completed.\n";
}

/**
 * @brief Get the commute time for the train transport.
 * @return Travel time as a double.
 */
double Train::commuteTime() {
    return travelTime;
}

/**
 * @brief Calculate satisfaction based on travel time.
 * @return Satisfaction level as an integer (95 if travel time is less than 45, otherwise 80).
 */
int Train::calculateSatisfaction() {
    return travelTime < 45 ? 95 : 80;
}

/**
 * @brief Check if the train transport is available.
 * @return True if not under maintenance, otherwise false.
 */
bool Train::isAvailable() const {
    return !isUnderMaintenance;
}

/**
 * @brief Get the fee for the train transport.
 * @return Fee as a double.
 */
double Train::getFee() const {
    return fee;
}

/**
 * @brief Get the type of the transport.
 * @return String representing the type of transport ("Train Transport").
 */
std::string Train::getType() const {
    return "Train Transport";
}

// Seating capacity methods

/**
 * @brief Get the seating capacity of the train transport.
 * @return Total seating capacity as an integer.
 */
int Train::getSeatingCapacity() const {
    return seatingCapacity;
}

/**
 * @brief Get the number of available seats.
 * @return Available seats as an integer.
 */
int Train::getAvailableSeats() const {
    return availableSeats;
}

/**
 * @brief Reserve a seat on the train transport.
 * @return True if a seat is successfully reserved, otherwise false.
 */
bool Train::reserveSeat() {
    if (availableSeats > 0) {
        --availableSeats;
        return true;
    }
    return false;
}

/**
 * @brief Release a reserved seat on the train transport.
 */
void Train::releaseSeat() {
    if (availableSeats < seatingCapacity) {
        ++availableSeats;
    }
}

// Cargo handling methods

/**
 * @brief Check if the train transport supports cargo.
 * @return True as train transport supports cargo.
 */
bool Train::hasCargoCapacity() const {
    return true;
}

/**
 * @brief Get the cargo capacity of the train transport.
 * @return Cargo capacity as an integer.
 */
int Train::getCargoCapacity() const {
    return cargoCapacity;
}

/**
 * @brief Get the available cargo space.
 * @return Available cargo space as an integer.
 */
int Train::getAvailableCargoSpace() const {
    return availableCargoSpace;
}

/**
 * @brief Load cargo onto the train transport.
 * @param cargo The amount of cargo to load.
 * @return True if cargo is successfully loaded, otherwise false.
 */
bool Train::loadCargo(int cargo) {
    if (availableCargoSpace >= cargo) {
        availableCargoSpace -= cargo;
        return true;
    }
    return false;
}

/**
 * @brief Unload cargo from the train transport.
 * @param cargo The amount of cargo to unload.
 */
void Train::unloadCargo(int cargo) {
    if (availableCargoSpace + cargo <= cargoCapacity) {
        availableCargoSpace += cargo;
    }
}
