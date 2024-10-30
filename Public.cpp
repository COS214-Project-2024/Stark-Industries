#include "Public.h"

#include <iostream>

Public::Public(string name,double travelTime, double fee,int seatingCapacity) 
    :name(name) ,isUnderMaintenance(false), travelTime(travelTime), fee(fee),seatingCapacity(seatingCapacity),availableSeats(seatingCapacity) {}

void Public::doMaintenance() {
    isUnderMaintenance = false;
    std::cout << "Car transport maintenance completed.\n";
}

double Public::commuteTime() {
    return travelTime;
}

int Public::calculateSatisfaction() {
    return travelTime < 30 ? 85 : 70;
}

bool Public::isAvailable() const {
    return !isUnderMaintenance;
}

double Public::getFee() const {
    return fee;
}

std::string Public::getType() const {
    return "Public Transport";
}




// Seating capacity methods
int Public::getSeatingCapacity() const {
    return seatingCapacity;
}

int Public::getAvailableSeats() const {
    return availableSeats;
}

bool Public::reserveSeat() {
    if (availableSeats > 0) {
        --availableSeats;
        return true;
    }
    return false;
}

void Public::releaseSeat() {
    if (availableSeats < seatingCapacity) {
        ++availableSeats;
    }
}

// Cargo handling methods
bool Public::hasCargoCapacity() const {
    return false;
}

int Public::getCargoCapacity() const {
  std::cout<<  " Public doesnt support cargo";
    return 0;
}

int  Public::getAvailableCargoSpace() const {
std::cout<< " Public doesnt support cargo";
    return 0;
}

bool   Public::loadCargo(int cargo) {
   std::cout<< " Public doesnt support cargo";
    return false;
}

void   Public::unloadCargo(int cargo) {
  std::cout<<   " Public doesnt support cargo";
    
}
