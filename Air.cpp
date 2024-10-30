#include "Air.h"
#include <iostream>

/**
 * @brief Constructor to initialize Air transport properties.
 * @param name The name of the air transport.
 * @param travelTime Travel time for the air transport.
 * @param fee The fee for the air transport.
 * @param seatingCap Total seating capacity of the air transport.
 * @param cargoCap Total cargo capacity of the air transport.
 */
Air::Air(string name, double travelTime, double fee, int seatingCap, int cargoCap) 
    : name(name), isUnderMaintenance(false), travelTime(travelTime), fee(fee), 
      seatingCapacity(seatingCap), availableSeats(seatingCap), 
      cargoCapacity(cargoCap), availableCargoSpace(cargoCap) {}

/**
 * @brief Perform maintenance on the air transport and mark it as available after completion.
 */
void Air::doMaintenance() {
    isUnderMaintenance = true;
    std::cout << "Air transport maintenance completed.\n";
    isUnderMaintenance = false;
}

/**
 * @brief Get the commute time for the air transport.
 * @return Travel time as a double.
 */
double Air::commuteTime() {
    return travelTime;
}

/**
 * @brief Calculate satisfaction based on travel time.
 * @return Satisfaction level as an integer (95 if travel time is less than 45, otherwise 80).
 */
int Air::calculateSatisfaction() {
    return travelTime < 45 ? 95 : 80;
}

/**
 * @brief Check if the air transport is available.
 * @return True if not under maintenance, otherwise false.
 */
bool Air::isAvailable() const {
    return !isUnderMaintenance;
}

/**
 * @brief Get the fee for the air transport.
 * @return Fee as a double.
 */
double Air::getFee() const {
    return fee;
}

/**
 * @brief Get the type of the transport.
 * @return String representing the type of transport ("Air Transport").
 */
std::string Air::getType() const {
    return "Air Transport";
}

/**
 * @brief Get the seating capacity of the air transport.
 * @return Total seating capacity as an integer.
 */
int Air::getSeatingCapacity() const {
    return seatingCapacity;
}

/**
 * @brief Get the number of available seats.
 * @return Available seats as an integer.
 */
int Air::getAvailableSeats() const {
    return availableSeats;
}

/**
 * @brief Reserve a seat on the air transport.
 * @return True if a seat is successfully reserved, otherwise false.
 */
bool Air::reserveSeat() {
    if (availableSeats > 0) {
        --availableSeats;
        return true;
    }
    return false;
}

/**
 * @brief Release a reserved seat on the air transport.
 */
void Air::releaseSeat() {
    if (availableSeats < seatingCapacity) {
        ++availableSeats;
    }
}

/**
 * @brief Check if the air transport supports cargo.
 * @return True as air transport supports cargo.
 */
bool Air::hasCargoCapacity() const {
    return true;
}

/**
 * @brief Get the cargo capacity of the air transport.
 * @return Cargo capacity as an integer.
 */
int Air::getCargoCapacity() const {
    return cargoCapacity;
}

/**
 * @brief Get the available cargo space.
 * @return Available cargo space as an integer.
 */
int Air::getAvailableCargoSpace() const {
    return availableCargoSpace;
}

/**
 * @brief Load cargo onto the air transport.
 * @param cargo The amount of cargo to load.
 * @return True if cargo is successfully loaded, otherwise false.
 */
bool Air::loadCargo(int cargo) {
    if (availableCargoSpace >= cargo) {
        availableCargoSpace -= cargo;
        return true;
    }
    return false;
}

/**
 * @brief Unload cargo from the air transport.
 * @param cargo The amount of cargo to unload.
 */
void Air::unloadCargo(int cargo) {
    if (availableCargoSpace + cargo <= cargoCapacity) {
        availableCargoSpace += cargo;
    }
}
