#include "Tax.h"
#include <iostream>

/**
 * @brief Constructs a Tax department with the given name and initial tax rate.
 * 
 * @param name Name of the tax department.
 * @param initialTaxRate Initial tax rate set for the department.
 */
Tax::Tax(const std::string& name, float initialTaxRate)
    : Department(name), totalRevenue(0.0), taxRate(initialTaxRate) {}

/**
 * @brief Sets the tax rate for the department.
 * 
 * @param rate The new tax rate to be set.
 */
void Tax::setTaxRate(float rate) {
    taxRate = rate;
}

/**
 * @brief Gets the current tax rate of the department.
 * 
 * @return A float representing the current tax rate.
 */
float Tax::getTaxRate() const {
    return taxRate;
}

/**
 * @brief Tracks revenue collected by the department.
 * 
 * This method adds the given revenue amount to the total revenue 
 * and prints the updated total to the console.
 * 
 * @param revenue The amount of revenue collected.
 */
void Tax::trackRevenue(double revenue) {
    totalRevenue += revenue;
    std::cout << "Tracked revenue: " << revenue << ". Total revenue: " 
              << totalRevenue << "\n";
}

/**
 * @brief Operates the tax department by displaying its current status.
 * 
 * This method prints the current tax rate and total revenue to the console.
 */
void Tax::operate() {
    std::cout << "Operating Tax Department: Current Tax Rate = " << taxRate 
              << ", Total Revenue = " << totalRevenue << "\n";
}
