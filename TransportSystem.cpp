#include "TransportSystem.h"
#include <iostream>


/**
 * @brief Default constructor that initializes the transport strategy to NULL.
 */
TransportSystem::TransportSystem() : transportStrategy(NULL) {}

/**
 * @brief Sets a new transport strategy, replacing any previous one.
 * Deletes the previous strategy to avoid memory leaks.
 * @param strategy A pointer to the new Transport strategy to be used.
 */
void TransportSystem::setTransportStrategy(Transport* strategy) {
    if (transportStrategy) {
        delete transportStrategy;
    }
    transportStrategy = strategy;
}

/**
 * @brief Performs maintenance on the current transport strategy if available.
 */
void TransportSystem::performMaintenance() {
    if (transportStrategy) {
        transportStrategy->doMaintenance();
    }
}

/**
 * @brief Checks if the current transport strategy is available.
 * @return True if available, false otherwise.
 */
bool TransportSystem::isTransportAvailable() const {
    return transportStrategy ? transportStrategy->isAvailable() : false;
}

/**
 * @brief Gets the fee for the current transport strategy.
 * @return The transport fee, or 0.0 if no strategy is set.
 */
double TransportSystem::getTransportFee() const {
    return transportStrategy ? transportStrategy->getFee() : 0.0;
}

/**
 * @brief Gets the commute time of the current transport strategy.
 * @return Commute time in minutes, or 0.0 if no strategy is set.
 */
double TransportSystem::getCommuteTime() const {
    return transportStrategy ? transportStrategy->commuteTime() : 0.0;
}

/**
 * @brief Calculates the satisfaction level for the current transport strategy.
 * @return Satisfaction level, or 0 if no strategy is set.
 */
int TransportSystem::calculateSatisfaction() const {
    return transportStrategy ? transportStrategy->calculateSatisfaction() : 0;
}

/**
 * @brief Gets the type of transport being used in the current strategy.
 * @return A string representing the transport type, or "None" if no strategy is set.
 */
std::string TransportSystem::getTransportType() const {
    return transportStrategy ? transportStrategy->getType() : "None";
}

/**
 * @brief Checks if seats are available on the current transport.
 * @return True if seats are available, false otherwise.
 */
bool TransportSystem::checkSeatAvailability() const {
    return transportStrategy && transportStrategy->getAvailableSeats() > 0;
}

/**
 * @brief Checks if cargo space is available on the current transport for a specified amount.
 * @param cargo The amount of cargo space needed.
 * @return True if enough cargo space is available, false otherwise.
 */
bool TransportSystem::checkCargoAvailability(int cargo) const {
    return transportStrategy && transportStrategy->hasCargoCapacity() &&
           transportStrategy->getAvailableCargoSpace() >= cargo;
}

/**
 * @brief Loads the specified amount of cargo onto the current transport if possible.
 * @param cargo The amount of cargo to load.
 * @return True if cargo was successfully loaded, false otherwise.
 */
bool TransportSystem::loadCargo(int cargo) {
    return transportStrategy ? transportStrategy->loadCargo(cargo) : false;
}

/**
 * @brief Unloads the specified amount of cargo from the current transport.
 * @param cargo The amount of cargo to unload.
 */
void TransportSystem::unloadCargo(int cargo) {
    if (transportStrategy) {
        transportStrategy->unloadCargo(cargo);
    }
}

/**
 * @brief Destructor for TransportSystem. Ensures the transport strategy is deleted to free memory.
 */
TransportSystem::~TransportSystem() {
    delete transportStrategy;
}

/**
 * @brief Reserves a seat on the current transport if available.
 * @return True if the seat was successfully reserved, false otherwise.
 */
bool TransportSystem::reserveSeat() {
    return transportStrategy ? transportStrategy->reserveSeat() : false;
}

/**
 * @brief Releases a reserved seat on the current transport.
 */
void TransportSystem::releaseSeat() {
    if (transportStrategy) {
        transportStrategy->releaseSeat();
    }
}

/**
 * @brief Placeholder for checking the availability of transport infrastructure.
 * Not yet implemented.
 * @param TransportInfastructure_transInfas Reference or ID of the transport infrastructure to check.
 */
void TransportSystem::checkAvailability(int TransportInfastructure_transInfas) {
    // TODO - implement TransportSystem::checkAvailability
    throw "Not yet implemented";
}
