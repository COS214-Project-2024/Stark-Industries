#include "Tax.h"
#include <iostream>

Tax::Tax(double totalRevenue, float initialTaxRate, string taxType) {
	this->taxType = taxType;
	this->taxRate = initialTaxRate;
	this->totalRevenue = 0;
}

void Tax::setTaxRate(float rate) {
	this->taxRate = rate;
}

float Tax::getTaxRate() {
	return this->taxRate;
}

string Tax::getTaxType() {
	string r = this->taxType;
	return r;
}

void Tax::collectTaxes(double revenue) {
	this->totalRevenue += revenue * this->taxRate;
    std::cout << "Collected taxes: " << revenue * this->taxRate << std::endl;
}

void Tax::operate() {
	// TODO - implement Tax::operate
	throw "Not yet implemented";
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
