#include "Train.h"
#include <iostream>


Train::Train(string name,double travelTime, double fee, int seatingCap, int cargoCap) 
    : name(name),isUnderMaintenance(false), travelTime(travelTime), fee(fee) ,seatingCapacity(seatingCap),
      availableSeats(seatingCap), cargoCapacity(cargoCap), availableCargoSpace(cargoCap){}

void Train::doMaintenance() {
    isUnderMaintenance = false;
    cout << "Air transport maintenance completed.\n";
}

double Train::commuteTime() {
    return travelTime;
}

int Train::calculateSatisfaction() {
    return travelTime < 45 ? 95 : 80;
}

bool Train::isAvailable() const {
    return !isUnderMaintenance;
}

double Train::getFee() const {
    return fee;
}

std::string Train::getType() const {
    return "Train Transport";
}

// Seating capacity methods
int Train::getSeatingCapacity() const {
    return seatingCapacity;
}

int Train::getAvailableSeats() const {
    return availableSeats;
}

bool Train::reserveSeat() {
    if (availableSeats > 0) {
        --availableSeats;
        return true;
    }
    return false;
}

void Train::releaseSeat() {
    if (availableSeats < seatingCapacity) {
        ++availableSeats;
    }
}

// Cargo handling methods
bool Train::hasCargoCapacity() const {
    return true;
}

int Train::getCargoCapacity() const {
    return cargoCapacity;
}

int Train::getAvailableCargoSpace() const {
    return availableCargoSpace;
}

bool Train::loadCargo(int cargo) {
    if (availableCargoSpace >= cargo) {
        availableCargoSpace -= cargo;
        return true;
    }
    return false;
}

void Train::unloadCargo(int cargo) {
    if (availableCargoSpace + cargo <= cargoCapacity) {
        availableCargoSpace += cargo;
    }
}
