#include "Budget.h"
#include <iostream>

/**
 * @brief Constructs a Budget department with the given name and initial budget.
 * 
 * @param name Name of the budget department.
 * @param initialBudget Initial total budget allocated to the department.
 */
Budget::Budget(const std::string& name, double initialBudget)
    : Department(name), totalBudget(initialBudget), allocatedBudget(0.0) {}

/**
 * @brief Allocates a specified amount of funds from the budget.
 * 
 * If the requested amount is available within the remaining budget, 
 * it is added to the allocated budget. Otherwise, an error message is displayed.
 * 
 * @param amount The amount of funds to allocate from the budget.
 */
void Budget::allocateFunds(double amount) {
    if (amount <= (totalBudget - allocatedBudget)) {
        allocatedBudget += amount;
        std::cout << "Allocated " << amount << " units from the budget.\n";
    } else {
        std::cout << "Insufficient budget to allocate " << amount << " units.\n";
    }
}

/**
 * @brief Operates the budget department, displaying budget details.
 * 
 * This method prints out the total budget, allocated budget, and 
 * available budget to the console.
 */
void Budget::operate() {
    std::cout << "Operating Budget Department: Total Budget = " << totalBudget
              << ", Allocated Budget = " << allocatedBudget
              << ", Available Budget = " << getAvailableBudget() << "\n";
}

/**
 * @brief Gets the available budget.
 * 
 * @return A double representing the unallocated budget amount.
 */
double Budget::getAvailableBudget() const {
    return totalBudget - allocatedBudget;
}
