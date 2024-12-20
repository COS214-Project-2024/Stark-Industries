/**
 * @file Budget.cpp
 * @brief Implements the Budget class, which manages departmental budget allocation, tax reception, and other budgetary functions.
 */

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
              << "\nAllocated Budget = " << allocatedBudget
              << "\nAvailable Budget = " << getAvailableBudget() << "\n";
}

/**
 * @brief Receives tax funds and adds them to the total budget.
 * 
 * The received tax amount is added to the total budget, and an allocation 
 * attempt is made for the new total budget.
 * 
 * @param tax Amount of tax funds received.
 */
void Budget::receiveTax(double tax) {
    totalBudget += tax;
    std::cout << "Budget received: " << tax << std::endl;
    allocateFunds(totalBudget);
}

/**
 * @brief Gets the available budget by calculating the difference between the total and allocated budgets.
 * 
 * @return The available budget as a double.
 */
double Budget::getAvailableBudget() const {
    return totalBudget - allocatedBudget;
}

/**
 * @brief Retrieves the total budget.
 * 
 * @return The total budget as a double.
 */
double Budget::getTotalBudget() const {
    return totalBudget;
}

/**
 * @brief Executes the budget-related command.
 * 
 * Currently, this method does nothing and serves as a placeholder.
 */
void Budget::execute() {
    // Do nothing
}

/**
 * @brief Adds a command to the budget department.
 * 
 * Currently, this method does nothing and serves as a placeholder.
 * 
 * @param command Pointer to a Command object to be added.
 */
void Budget::addCommand(Command* command) {
    // Do nothing
}

/**
 * @brief Removes a command from the budget department by index.
 * 
 * Currently, this method does nothing and serves as a placeholder.
 * 
 * @param i Index of the command to remove.
 */
void Budget::removeCommand(int i) {
    // Do nothing
}

/**
 * @brief Default constructor for the Budget class.
 */
Budget::Budget() {
    // Default initialization
}

/**
 * @brief Adds collected taxes to the total budget.
 * 
 * The specified tax amount is added to the total budget, and a message 
 * displays the updated budget total.
 * 
 * @param amount Amount of taxes collected and added to the budget.
 */
void Budget::addCollectedTaxes(double amount) {
    totalBudget += amount;
    std::cout << "Budget updated with collected taxes. New total budget: " << totalBudget << "\n";
}
