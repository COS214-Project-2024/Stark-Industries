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

Tax::Tax(double totalRevenue, float initialTaxRate, string taxType) {
	this->taxType = taxType;
	this->taxRate = initialTaxRate;
	this->totalRevenue = 0;
}

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

string Tax::getTaxType() {
	string r = this->taxType;
	return r;
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
void Tax::collectTaxes(double revenue) {
	this->totalRevenue += revenue * this->taxRate;
    std::cout << "Collected taxes: " << revenue * this->taxRate << std::endl;
}

void Tax::operate() {
    std::cout << "Operating Tax Department:\nCurrent Tax Rate = " << taxRate 
              << "\nTotal Revenue = " << totalRevenue << "\n";
}

//command functions
void Tax::execute() {
	for (int i = 0; i < commands.size(); i++) {
        commands[i]->execute();
    }
	//commands[0]->execute();
}

void Tax::addCommand(Command* command) {
	commands.push_back(command);
}

void Tax::removeCommand(int i) {
	commands.erase(commands.begin() + i);
}