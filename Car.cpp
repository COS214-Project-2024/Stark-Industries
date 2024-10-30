#include "Car.h"
#include <iostream>

Car::Car(string name,double travelTime, int seatingCapacity) 
    :name(name) ,isUnderMaintenance(false), travelTime(travelTime), fee(0),seatingCapacity(seatingCapacity),availableSeats(seatingCapacity) {}

void Car::doMaintenance() {
    isUnderMaintenance = false;
    std::cout << "Car transport maintenance completed.\n";
}

double Car::commuteTime() {
    return travelTime;
}

int Car::calculateSatisfaction() {
    return travelTime < 30 ? 85 : 70;
}

bool Car::isAvailable() const {
    return !isUnderMaintenance;
}

double Car::getFee() const {
    return fee;
}

std::string Car::getType() const {
    return "Car Transport";
}




// Seating capacity methods
int Car::getSeatingCapacity() const {
    return seatingCapacity;
}

int Car::getAvailableSeats() const {
    return availableSeats;
}

bool Car::reserveSeat() {
    if (availableSeats > 0) {
        --availableSeats;
        return true;
    }
    return false;
}

void Car::releaseSeat() {
    if (availableSeats < seatingCapacity) {
        ++availableSeats;
    }
}

// Cargo handling methods
bool Car::hasCargoCapacity() const {
    return false;
}

int Car::getCargoCapacity() const {
   std::cout<< "Car doesnt support cargo";
    return 0;
}

int  Car::getAvailableCargoSpace() const {
 std::cout<<"Car doesnt support cargo";
    return 0;
}

bool  Car::loadCargo(int cargo) {
   std::cout<< "Car doesnt support cargo";
    return false;
}

void  Car::unloadCargo(int cargo) {
   std::cout<<  "Car doesnt support cargo";
    
}
