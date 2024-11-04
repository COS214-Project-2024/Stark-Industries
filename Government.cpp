/**
 * @file Government.cpp
 * @brief Implements the Government class, which manages various departments and handles tax-related operations.
 */

#include "Government.h"
#include "Department.h"
#include <iostream>
#include <algorithm>
#include <vector>

/**
 * @brief Constructs a Government with specified tax rates.
 * 
 * @param incomeTaxRate Initial income tax rate.
 * @param propertyTaxRate Initial property tax rate.
 */
Government::Government(double incomeTaxRate, double propertyTaxRate)
    : Department("Government"), incomeTaxRate(incomeTaxRate), propertyTaxRate(propertyTaxRate) {}

/**
 * @brief Default constructor for the Government class.
 */
Government::Government() : Department() {}

/**
 * @brief Increases tax rates by a specified amount.
 * 
 * This function is intended to adjust tax rates upward by the given amount.
 * 
 * @param amount Amount to increase the tax rates by.
 * @throws std::runtime_error Always throws "Not yet implemented" as a placeholder.
 */
void Government::increaseTax(int amount) {
    // TODO - implement Government::increaseTax
    throw "Not yet implemented";
}

/**
 * @brief Allocates collected tax to the Budget department.
 * 
 * Transfers the collected tax to the department named "Budget," if found.
 */
void Government::allocateTax() {
    for (int i = 0; i < departments.size(); i++) {
        if (departments[i]->name == "Budget") {
            departments[i]->receiveTax(taxCollected);
            break;
        }
    }
}

/**
 * @brief Collects tax using the assigned visitor.
 * 
 * Updates the `taxCollected` amount based on the visitor's collected tax.
 */
void Government::collectTax() {
    if (visitor != nullptr) {
        taxCollected = visitor->taxCollected;
    }
}

/**
 * @brief Gets data related to the government operations.
 * 
 * This method is intended to retrieve government-related data.
 * 
 * @throws std::runtime_error Always throws "Not yet implemented" as a placeholder.
 */
void Government::get() {
    // TODO - implement Government::get
    throw "Not yet implemented";
}

/**
 * @brief Sets data related to the government operations.
 * 
 * This method is intended to set government-related data.
 * 
 * @throws std::runtime_error Always throws "Not yet implemented" as a placeholder.
 */
void Government::set() {
    // TODO - implement Government::set
    throw "Not yet implemented";
}

/**
 * @brief Retrieves the current government state.
 * 
 * Intended to get the state of the Government object.
 * 
 * @return A pointer to the current Government state.
 * @throws std::runtime_error Always throws "Not yet implemented" as a placeholder.
 */
Government* Government::getState() {
    // TODO - implement Government::getState
    throw "Not yet implemented";
}

/**
 * @brief Sets the state of the government.
 * 
 * Intended to set the Government object's state.
 * 
 * @throws std::runtime_error Always throws "Not yet implemented" as a placeholder.
 */
void Government::setState() {
    // TODO - implement Government::setState
    throw "Not yet implemented";
}

/**
 * @brief Adds a department to the government's list of departments.
 * 
 * Also assigns specific department pointers based on the department type.
 * 
 * @param department Pointer to the Department object to add.
 */
void Government::add(Department* department) {
    departments.push_back(department);

    if (Tax* tax = dynamic_cast<Tax*>(department)) {
        taxDepartment = tax;
    } else if (Budget* budget = dynamic_cast<Budget*>(department)) {
        budgetDepartment = budget;
    } else if (Policies* policies = dynamic_cast<Policies*>(department)) {
        policiesDepartment = policies;
    } else if (Services* services = dynamic_cast<Services*>(department)) {
        servicesDepartment = services;
    }
}

/**
 * @brief Removes a department from the government's list of departments.
 * 
 * @param department Pointer to the Department object to remove.
 */
void Government::remove(Department* department) {
    auto it = std::remove(departments.begin(), departments.end(), department);
    if (it != departments.end()) {
        departments.erase(it, departments.end()); 
    }
}

/**
 * @brief Retrieves a child department at a specified index.
 * 
 * @param index Index of the department in the list.
 * @return Pointer to the Department at the specified index, or nullptr if index is invalid.
 */
Department* Government::getChild(int index) {
    if (index >= 0 && index < departments.size()) {
        return departments[index];
    }
    return nullptr;
}

/**
 * @brief Operates the government, managing all departments.
 * 
 * Calls the `operate` method on each department within the government.
 */
void Government::operate() {
    std::cout << "Government is operating and managing departments.\n";
    for (Department* dep : departments) {
        dep->operate(); 
    }
}

/**
 * @brief Notifies citizens that taxes have been increased.
 * 
 * Displays a message to indicate that a notification has been sent.
 */
void Government::notifyCitizensTaxIncreased() {
    std::cout << "Notifying citizens: Taxes have been increased.\n";
}

/**
 * @brief Executes a government operation.
 * 
 * Currently, this function does nothing and serves as a placeholder.
 */
void Government::execute() {
    // Do nothing
}

/**
 * @brief Adds a command to the government.
 * 
 * Currently, this function does nothing and serves as a placeholder.
 * 
 * @param command Pointer to the Command object to add.
 */
void Government::addCommand(Command* command) {
    // Do nothing
}

/**
 * @brief Removes a command from the government by index.
 * 
 * Currently, this function does nothing and serves as a placeholder.
 * 
 * @param i Index of the command to remove.
 */
void Government::removeCommand(int i) {
    // Do nothing
}
