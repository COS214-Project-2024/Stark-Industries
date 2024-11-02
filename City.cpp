#include "City.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

City::City(const std::string& cityName) : name(cityName) {
}

string City::getName() {
	return name;
}

void City::setGovernment(Government* government) {
	this->government = government;
	
}

void City::attach(Citizen* observer) {
    observerList.push_back(observer);
	citizens.push_back(observer);
}

void City::detach(Citizen* observer) {
    observerList.erase(std::remove(observerList.begin(), observerList.end(), observer), observerList.end());
	citizens.erase(std::remove(citizens.begin(), citizens.end(), observer), citizens.end());
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


void City::addBuilding(Building* building) {
    buildings.push_back(building);
    std::cout << "Building added to the city: " << building->getType() << "\n";
}

const std::vector<Building*>& City::listBuildings() const {
        return buildings;
    }

void City::addUtility(Utilities* utility) {
    utilities.push_back(utility);

}

void City::addInfrastructure(TransportInfrastructure* infrastructure) {
    roads.push_back(infrastructure);
    std::cout << "Infrastructure added to the city.\n";
}

const std::vector<TransportInfrastructure*>& City::listInfrastructures() const {
    return roads;
}

Government* City::getGovernment() {
    return government;
}
