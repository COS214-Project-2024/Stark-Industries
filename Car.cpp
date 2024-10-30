#include "Car.h"
#include <iostream>

/**
 * @brief Constructor to initialize Car transport properties.
 * @param name The name of the car transport.
 * @param travelTime Travel time for the car transport.
 * @param seatingCapacity Total seating capacity of the car transport.
 */
Car::Car(string name, double travelTime, int seatingCapacity) 
    : name(name), isUnderMaintenance(false), travelTime(travelTime), fee(0), 
      seatingCapacity(seatingCapacity), availableSeats(seatingCapacity) {}

/**
 * @brief Perform maintenance on the car transport and mark it as available after completion.
 */
void Car::doMaintenance() {
    isUnderMaintenance = false;
    std::cout << "Car transport maintenance completed.\n";
}

/**
 * @brief Get the commute time for the car transport.
 * @return Travel time as a double.
 */
double Car::commuteTime() {
    return travelTime;
}

/**
 * @brief Calculate satisfaction based on travel time.
 * @return Satisfaction level as an integer (85 if travel time is less than 30, otherwise 70).
 */
int Car::calculateSatisfaction() {
    return travelTime < 30 ? 85 : 70;
}

/**
 * @brief Check if the car transport is available.
 * @return True if not under maintenance, otherwise false.
 */
bool Car::isAvailable() const {
    return !isUnderMaintenance;
}

/**
 * @brief Get the fee for the car transport.
 * @return Fee as a double, which is 0 in this case.
 */
double Car::getFee() const {
    return fee;
}

/**
 * @brief Get the type of the transport.
 * @return String representing the type of transport ("Car Transport").
 */
std::string Car::getType() const {
    return "Car Transport";
}

// Seating capacity methods

/**
 * @brief Get the seating capacity of the car transport.
 * @return Total seating capacity as an integer.
 */
int Car::getSeatingCapacity() const {
    return seatingCapacity;
}

/**
 * @brief Get the number of available seats.
 * @return Available seats as an integer.
 */
int Car::getAvailableSeats() const {
    return availableSeats;
}

/**
 * @brief Reserve a seat in the car transport.
 * @return True if a seat is successfully reserved, otherwise false.
 */
bool Car::reserveSeat() {
    if (availableSeats > 0) {
        --availableSeats;
        return true;
    }
    return false;
}

/**
 * @brief Release a reserved seat in the car transport.
 */
void Car::releaseSeat() {
    if (availableSeats < seatingCapacity) {
        ++availableSeats;
    }
}

// Cargo handling methods

/**
 * @brief Check if the car transport supports cargo.
 * @return False as cars do not support cargo in this implementation.
 */
bool Car::hasCargoCapacity() const {
    return false;
}

/**
 * @brief Get the cargo capacity of the car transport.
 * @return 0 as cars do not support cargo; displays a message.
 */
int Car::getCargoCapacity() const {
    std::cout << "Car doesn't support cargo\n";
    return 0;
}

/**
 * @brief Get the available cargo space.
 * @return 0 as cars do not support cargo; displays a message.
 */
int Car::getAvailableCargoSpace() const {
    std::cout << "Car doesn't support cargo\n";
    return 0;
}

/**
 * @brief Attempt to load cargo onto the car transport.
 * @param cargo The amount of cargo to load.
 * @return False as cars do not support cargo; displays a message.
 */
bool Car::loadCargo(int cargo) {
    std::cout << "Car doesn't support cargo\n";
    return false;
}

/**
 * @brief Attempt to unload cargo from the car transport.
 * @param cargo The amount of cargo to unload; displays a message.
 */
void Car::unloadCargo(int cargo) {
    std::cout << "Car doesn't support cargo\n";
}
