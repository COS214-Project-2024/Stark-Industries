#include "City.h"
#include <iostream>
#include <vector>
#include <algorithm>

void City::attach(Citizen* observer) {
    observerList.push_back(observer);
}

void City::detach(Citizen* observer) {
    observerList.erase(std::remove(observerList.begin(), observerList.end(), observer), observerList.end());
}

void City::notify() {
    std::cout << "Notifying citizens about changes in city.\n";
    for (Citizen* citizen : observerList) {
        citizen->observerUpdate("City");  // Call the observer's update method
    }
}

void City::requestBuilding(int Citizen_cit, int String_buildtype) {
	// TODO - implement City::requestBuilding
	throw "Not yet implemented";
}

void City::buildingComplete(int String_buildtype, int Citizen_citizen) {
	// TODO - implement City::buildingComplete
	throw "Not yet implemented";
}

bool City::inspectBuilding() {
	// TODO - implement City::inspectBuilding
	throw "Not yet implemented";
}
