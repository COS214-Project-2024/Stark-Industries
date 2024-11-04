// Population.cpp
#include "Population.h"
#include "Citizen.h"
#include "Building.h"
#include "Residential.h"
#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>


Population::Population(double rate) : populationGrowthRate(rate) {
    std::srand(std::time(nullptr)); // Seed for random number generation
}

void Population::handleRequest(int growthFactor, City* city) {
    Citizen c;
    Residential* residentialBuilding = nullptr;
    for (Building* building : city->listBuildings()) {
        residentialBuilding = dynamic_cast<Residential*>(building);
        if (residentialBuilding) {
            break;  // Found a residential building, so break out of the loop
        }
    }
    if (growthFactor < 100 && growthFactor > 0) {
        int currentPopulation = c.getNumCitizens();
        double increase = currentPopulation * (populationGrowthRate / 100.0) * growthFactor;

        // Round up to the nearest integer
        int newCitizens = static_cast<int>(std::ceil(increase));
    	std::cout << "POPULATION GROWS:\n";
        std::cout << "Population size has increased by " << populationGrowthRate
                << "%, adding " << newCitizens << " citizens.\n\n";
        // Add new citizens
        for (int i = 0; i < newCitizens; ++i) {
            std::string name = c.citizenNames[std::rand() % 200];
            int income = 30000 + std::rand() % 70000;  // Income range from 30,000 to 100,000
            double propertyValue = 50000 + std::rand() % 950000;  // Property value from 50,000 to 1,000,000
            std::string job = c.jobTitles[std::rand() % 200];
            Citizen* newCitizen = new Citizen(name, income, propertyValue, job);
            // citizens.push_back(newCitizen); // Assuming citizens is a collection of pointers to Citizen
            // Try to assign the citizen to the residential building
            if (residentialBuilding->populateBuilding()) {
                city->attach(newCitizen); // Add citizen to city’s observer list
            } else {
                std::cout << "No more space in the residential building for " << name << ".\n";
                delete newCitizen; // Delete citizen if not assigned
            }
        }
        std::cout << std::endl;

        c.setNumCitizens(currentPopulation + newCitizens);

        // Proceed to the next handler if applicable
        GrowthHandler::handleRequest(growthFactor, city);

        delete residentialBuilding;
    }
}

double Population::getGrowthFactor() {
    return populationGrowthRate;
}