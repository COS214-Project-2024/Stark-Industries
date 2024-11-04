/**
 * @file Population.cpp
 * @brief Implements the Population class, responsible for managing population growth and adding new citizens to a city based on a growth factor.
 */

#include "Population.h"
#include "Citizen.h"
#include "Building.h"
#include "Residential.h"
#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>

/**
 * @brief Constructs a Population object with a specified growth rate.
 * 
 * Initializes the population growth rate and seeds the random number generator.
 * 
 * @param rate The population growth rate.
 */
Population::Population(double rate) : populationGrowthRate(rate) {
    std::srand(std::time(nullptr));  // Seed for random number generation
}

/**
 * @brief Handles the population growth request based on the growth factor.
 * 
 * Calculates the number of new citizens to add based on the current population size, 
 * growth rate, and growth factor. Adds citizens to the city's residential buildings
 * if space is available and attaches them to the city's observer list.
 * 
 * @param growthFactor Growth factor affecting the rate of population increase.
 * @param city Pointer to the City object where new citizens will be added.
 */
void Population::handleRequest(int growthFactor, City* city) {
    Citizen c;
    Residential* residentialBuilding = nullptr;
    for (Building* building : city->listBuildings()) {
        residentialBuilding = dynamic_cast<Residential*>(building);
        if (residentialBuilding) {
            break;  // Found a residential building
        }
    }
    
    if (growthFactor < 101 && growthFactor > 0) {
        int currentPopulation = c.getNumCitizens();
        double increase = currentPopulation * (populationGrowthRate / 100.0);

        int newCitizens = static_cast<int>(std::ceil(increase));
        std::cout << "POPULATION GROWS:\n";
        std::cout << "Population size has increased by " << populationGrowthRate
                  << "%, adding " << newCitizens << " citizens.\n\n";
        
        for (int i = 0; i < newCitizens; ++i) {
            std::string name = c.citizenNames[std::rand() % 200];
            int income = 30000 + std::rand() % 70000;
            double propertyValue = 50000 + std::rand() % 950000;
            std::string job = c.jobTitles[std::rand() % 200];
            Citizen* newCitizen = new Citizen(name, income, propertyValue, job);
            
            if (residentialBuilding->populateBuilding()) {
                city->attach(newCitizen);
            } else {
                std::cout << "No more space in the residential building for " << name << ".\n";
                delete newCitizen;
            }
        }

        std::cout << std::endl;
        c.setNumCitizens(currentPopulation + newCitizens);

        GrowthHandler::handleRequest(growthFactor, city);
    }
}

/**
 * @brief Retrieves the population growth rate.
 * 
 * @return The population growth rate as a double.
 */
double Population::getGrowthFactor() {
    return populationGrowthRate;
}
