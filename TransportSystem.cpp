#include "TransportSystem.h"
#include <iostream>

TransportSystem::TransportSystem() : transportStrategy(NULL) {}


void TransportSystem::setTransportStrategy(Transport* strategy) {
    if (transportStrategy) {
        delete transportStrategy;
    }
    transportStrategy = strategy;
}

void TransportSystem::performMaintenance() {
    if (transportStrategy) {
        transportStrategy->doMaintenance();
    }
}

bool TransportSystem::isTransportAvailable() const {
    return transportStrategy ? transportStrategy->isAvailable() : false;
}

double TransportSystem::getTransportFee() const {
    return transportStrategy ? transportStrategy->getFee() : 0.0;
}

double TransportSystem::getCommuteTime() const {
    return transportStrategy ? transportStrategy->commuteTime() : 0.0;
}

int TransportSystem::calculateSatisfaction() const {
    return transportStrategy ? transportStrategy->calculateSatisfaction() : 0;
}

std::string TransportSystem::getTransportType() const {
    return transportStrategy ? transportStrategy->getType() : "None";
}

bool TransportSystem::checkSeatAvailability() const {
    return transportStrategy && transportStrategy->getAvailableSeats() > 0;
}

bool TransportSystem::checkCargoAvailability(int cargo) const {
    return transportStrategy && transportStrategy->hasCargoCapacity() &&
           transportStrategy->getAvailableCargoSpace() >= cargo;
}

bool TransportSystem::loadCargo(int cargo) {
    return transportStrategy ? transportStrategy->loadCargo(cargo) : false;
}

void TransportSystem::unloadCargo(int cargo) {
    if (transportStrategy) {
        transportStrategy->unloadCargo(cargo);
    }
}

TransportSystem::~TransportSystem() {
    delete transportStrategy;
}

bool TransportSystem::reserveSeat() {
    return transportStrategy ? transportStrategy->reserveSeat() : false;
}

void TransportSystem::releaseSeat() {
    if (transportStrategy) {
        transportStrategy->releaseSeat();
    }
}


void TransportSystem::checkAvailability(int TransportInfastructure_transInfas) {
	// TODO - implement TransportSystem::checkAvailability
	throw "Not yet implemented";
}
