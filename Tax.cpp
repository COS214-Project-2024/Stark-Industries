/**
 * @file Tax.cpp
 * @brief Implementation of the Tax class, which manages tax collection, revenue tracking, and executing commands for a tax department.
 */
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
 * @brief Constructs a Tax department with specific revenue, tax rate, and type.
 * 
 * @param totalRevenue Initial total revenue of the department.
 * @param initialTaxRate Initial tax rate for the department.
 * @param taxType Type of tax managed by the department.
 */
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

/**
 * @brief Gets the type of tax managed by the department.
 * 
 * @return A string representing the type of tax.
 */
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
double Tax::collectTaxes(double revenue) {
    totalRevenue += revenue;
    //std::cout << "Collected taxes: " << revenue << std::endl;
}

/**
 * @brief Displays the current status of the tax department.
 * 
 * This function outputs the current tax rate and total revenue to the console,
 * providing a summary of the department's operational status.
 */
void Tax::operate() {
    std::cout << "Operating Tax Department:\nCurrent Tax Rate = " << taxRate 
              << "\nTotal Revenue = " << totalRevenue << "\n";
}

/**
 * @brief Executes all stored commands in the department's command list.
 */
//command functions
void Tax::execute() {
	for (int i = 0; i < commands.size(); i++) {
        commands[i]->execute();
    }
	//commands[0]->execute();
}

/**
 * @brief Adds a command to the department's command list.
 * 
 * @param command Pointer to the Command to add.
 */
void Tax::addCommand(Command* command) {
	commands.push_back(command);
}

/**
 * @brief Removes a command from the department's command list by index.
 * 
 * @param i Index of the command to remove.
 */
void Tax::removeCommand(int i) {
	commands.erase(commands.begin() + i);
}

/**
 * @brief Gets the total revenue collected by the department.
 * 
 * @return The total revenue as a double.
 */
double Tax::getTotalRevenue() {
    return totalRevenue;
}

/**
 * @brief Increases the tax rate by executing the associated command.
 */
void Tax::increaseTax(){
    commands[1]->execute();
}

/**
 * @brief Executes the command to collect taxes.
 */
void Tax::collectTaxes() {
    commands[0]->execute();
}

/**
 * @brief Destructor for the Tax class, deletes all stored commands to prevent memory leaks.
 */
Tax::~Tax() {
    for (Command* command : commands) {
        delete command;
    }
}