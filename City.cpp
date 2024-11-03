#include "City.h"
#include "Residential.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

City::City(const std::string& cityName) : name(cityName) {
}


BuildingCreator* City::getBuildingCreator(const std::string& buildingType) {
    if (buildingType == "Residential") {
        return &residentialCreator;
    } else if (buildingType == "Commercial") {
        return &commercialCreator;
    } else if (buildingType == "Industrial") {
        return &industrialCreator;
    } else if (buildingType == "Landmark") {
        return &landmarkCreator;
    } else {
        std::cout << "Invalid building type: " << buildingType << "\n";
        return nullptr;
    }
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

const std::vector<Utilities*>& City::listUtilities() const {
    return utilities;
}

Government* City::getGovernment() {
    return government;
}

std::vector<Building*>& City::listBuildings() {
    return buildings;
}

int City::getTotalPopulation() const {
    return citizens.size();
}

int City::getAvailableHousingCapacity() const {
    int totalCapacity = 0;
    for (const auto& building : buildings) {
        Residential* residentialBuilding = dynamic_cast<Residential*>(building);
        if (residentialBuilding) {
            totalCapacity += residentialBuilding->getAvailableCapacity();
        }
    }
    return totalCapacity;
}

vector<Citizen*>& City::getCitizens() {
        return observerList;
    }

void City::attach(Building* building) {
	buildings.push_back(building);
}

void City::detach(Building* building) {
	buildings.erase(std::remove(buildings.begin(), buildings.end(), building), buildings.end());
}
