#include "Budget.h"
#include <iostream>

Budget::Budget(const std::string& name, double initialBudget)
    : Department(name), totalBudget(initialBudget), allocatedBudget(0.0) {}

void Budget::allocateFunds(double amount) {
    if (amount <= (totalBudget - allocatedBudget)) {
        allocatedBudget += amount;
        std::cout << "Allocated " << amount << " units from the budget.\n";
    } else {
        std::cout << "Insufficient budget to allocate " << amount << " units.\n";
    }
}

void Budget::operate() {
    std::cout << "Operating Budget Department: Total Budget = " << totalBudget
              << ", Allocated Budget = " << allocatedBudget
              << ", Available Budget = " << getAvailableBudget() << "\n";
}

double Budget::getAvailableBudget() const {
    return totalBudget - allocatedBudget;
}