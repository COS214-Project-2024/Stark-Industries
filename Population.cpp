// Population.cpp
#include "Population.h"
#include "Citizen.h"
#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>


Population::Population(double rate) : populationGrowthRate(rate) {
    std::srand(std::time(nullptr)); // Seed for random number generation
}

void Population::handleRequest(int growthFactor) {
    Citizen c;
    if (growthFactor < 100 && growthFactor > 0) {
        int currentPopulation = c.getNumCitizens();
        double increase = currentPopulation * (populationGrowthRate / 100.0) * growthFactor;

        // Round up to the nearest integer
        int newCitizens = static_cast<int>(std::ceil(increase));

        // Add new citizens
        for (int i = 0; i < newCitizens; ++i) {
            std::string name = c.citizenNames[std::rand() % 200];
            int income = 30000 + std::rand() % 70000;  // Income range from 30,000 to 100,000
            double propertyValue = 50000 + std::rand() % 950000;  // Property value from 50,000 to 1,000,000
            std::string job = c.jobTitles[std::rand() % 200];
            Citizen* newCitizen = new Citizen(name, income, propertyValue, job);
            // citizens.push_back(newCitizen); // Assuming citizens is a collection of pointers to Citizen
        }

        c.setNumCitizens(currentPopulation + newCitizens);

        std::cout << "Population size has increased by " << populationGrowthRate
                  << "%, adding " << newCitizens << " citizens.\n";

        // Proceed to the next handler if applicable
        GrowthHandler::handleRequest(growthFactor);
    }
}