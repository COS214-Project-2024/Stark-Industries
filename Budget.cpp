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

void Budget::receiveTax(double tax) {
	totalBudget += tax;
	std::cout << "Budget received: " << tax << std::endl;
	allocateFunds(totalBudget);
}

double Budget::getAvailableBudget() const {
    return totalBudget - allocatedBudget;
}

void Budget::execute() {
    //Do nothing
}

void Budget::addCommand(Command* command) {
    //Do nothing
}

void Budget::removeCommand(int i) {
    //Do nothing
}