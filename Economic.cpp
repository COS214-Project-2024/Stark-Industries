#include "Economic.h"
#include "Budget.h"
#include <iostream>
#include <iomanip> // For std::setprecision

Economic::Economic(double growthRate)
    : economicGrowthRate(growthRate) // Set the initial growth rate
    {}

void Economic::handleRequest(int growthFactor, City* city) {
    Budget b;
    if (growthFactor < 100 && growthFactor > 15) {
        // Calculate the increase in budget based on the economic growth rate
        double currentBudget = b.getAvailableBudget(); // Get available budget
        cout << "CUURRRR " << currentBudget;
        double increase = currentBudget * (economicGrowthRate / 100.0); // Calculate increase
        cout << "INNNCCCCCC " << increase;
        std::cout << "ECONOMY GROWS:\n";
        std::cout << "The economy is growing at a rate of " 
                  << economicGrowthRate << "%, increasing budget by " 
                  << std::fixed << std::setprecision(2) << increase << " units.\n\n";
        // Increase budget using receiveTax
        b.allocateFunds(increase); // Allocate more budget based on growth
        std::cout << std::endl;

        GrowthHandler::handleRequest(growthFactor, city);
    }
    // } else if (nextHandler) {
    //     GrowthHandler::handleRequest(growthFactor);
    // } else {
    //     std::cout << "Economy handler passes growth factor.\n";
    // }
}
