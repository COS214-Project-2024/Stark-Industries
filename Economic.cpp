/**
 * @file Economic.cpp
 * @brief Implements the Economic class, which handles economic growth rate adjustments and budget allocations within a city.
 */

#include "Economic.h"
#include "Budget.h"
#include <iostream>
#include <iomanip> // For std::setprecision

/**
 * @brief Constructs an Economic object with the specified growth rate.
 * 
 * @param growthRate Initial economic growth rate.
 */
Economic::Economic(double growthRate)
    : economicGrowthRate(growthRate) {}

/**
 * @brief Handles the economic growth process, adjusting the city’s budget based on growth rate.
 * 
 * This method calculates an increase in the budget based on the economic growth rate and 
 * allocates the increase to the city's budget. If the growth factor falls within the 
 * acceptable range (15 to 100), the method handles the budget increase and then 
 * passes the request to the next handler in the chain.
 * 
 * @param growthFactor Factor representing the growth intensity.
 * @param city Pointer to the City object representing the city affected by economic growth.
 */
void Economic::handleRequest(int growthFactor, City* city) {
    // Get the Budget instance from the city’s government
    Budget* budgetDept = dynamic_cast<Budget*>(city->getGovernment()->getBudgetDepartment());

    if (budgetDept && growthFactor < 100 && growthFactor > 15) {
        // Calculate the increase in budget based on the economic growth rate
        double currentBudget = budgetDept->getAvailableBudget();
        double increase = currentBudget * (economicGrowthRate / 100.0);

        std::cout << "ECONOMY GROWS:\n";
        std::cout << "The economy is growing at a rate of " 
                  << economicGrowthRate << "%, increasing budget by " 
                  << std::fixed << std::setprecision(2) << increase << " units.\n\n";
        
        // Allocate the calculated increase to the budget
        budgetDept->allocateFunds(increase);
        std::cout << "New Available Budget: " << budgetDept->getAvailableBudget() << std::endl;

        // Pass the growth factor to the next handler in the chain
        GrowthHandler::handleRequest(growthFactor, city);
    } else {
        std::cout << "Growth factor outside economic growth range or budget department not found.\n";
    }

    delete budgetDept;
}

/**
 * @brief Gets the current economic growth rate.
 * 
 * @return The economic growth rate as a double.
 */
double Economic::getGrowthFactor() {
    return economicGrowthRate;
}
