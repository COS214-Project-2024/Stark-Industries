#include "Economic.h"
#include "Budget.h"
#include <iostream>
#include <iomanip> // For std::setprecision

Economic::Economic(double growthRate)
    : economicGrowthRate(growthRate) // Set the initial growth rate
    {}

void Economic::handleRequest(int growthFactor, City* city) {
    // Get the Budget instance from the city’s government
    Budget* budgetDept = dynamic_cast<Budget*>(city->getGovernment()->getBudgetDepartment());

    if (budgetDept && growthFactor < 100 && growthFactor > 15) {
        // Calculate the increase in budget based on the economic growth rate
        double currentBudget = budgetDept->getAvailableBudget(); // Get the current available budget
        double increase = currentBudget * (economicGrowthRate / 100.0); // Calculate the increase

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
        // Optional: Pass the request if not handled, or output a message
        std::cout << "Growth factor outside economic growth range or budget department not found.\n";
    }

    delete budgetDept;
}

double Economic::getGrowthFactor() {
    return economicGrowthRate;
}