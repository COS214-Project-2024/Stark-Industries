#include "Air.h"
#include <iostream>

Air::Air(string name,double travelTime, double fee, int seatingCap, int cargoCap) 
    : name(name),isUnderMaintenance(false), travelTime(travelTime), fee(fee) ,seatingCapacity(seatingCap),
      availableSeats(seatingCap), cargoCapacity(cargoCap), availableCargoSpace(cargoCap){}

void Air::doMaintenance() {
    isUnderMaintenance = true;
    std::cout << "Air transport maintenance completed.\n";
      isUnderMaintenance = false;
}

double Air::commuteTime() {
    return travelTime;
}

int Air::calculateSatisfaction() {
    return travelTime < 45 ? 95 : 80;
}

bool Air::isAvailable() const {
    return !isUnderMaintenance;
}

double Air::getFee() const {
    return fee;
}

std::string Air::getType() const {
    return "Air Transport";
}

// Seating capacity methods
int Air::getSeatingCapacity() const {
    return seatingCapacity;
}

int Air::getAvailableSeats() const {
    return availableSeats;
}

bool Air::reserveSeat() {
    if (availableSeats > 0) {
        --availableSeats;
        return true;
    }
    return false;
}

void Air::releaseSeat() {
    if (availableSeats < seatingCapacity) {
        ++availableSeats;
    }
}

// Cargo handling methods
bool Air::hasCargoCapacity() const {
    return true;
}

int Air::getCargoCapacity() const {
    return cargoCapacity;
}

int Air::getAvailableCargoSpace() const {
    return availableCargoSpace;
}

bool Air::loadCargo(int cargo) {
    if (availableCargoSpace >= cargo) {
        availableCargoSpace -= cargo;
        return true;
    }
    return false;
}

void Air::unloadCargo(int cargo) {
    if (availableCargoSpace + cargo <= cargoCapacity) {
        availableCargoSpace += cargo;
    }
}
