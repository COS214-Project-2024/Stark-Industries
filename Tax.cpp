#include "Tax.h"

Tax::Tax(std:: string name, float initialTaxRate) {
	// TODO - implement Tax::Tax
	throw "Not yet implemented";
}

void Tax::setTaxRate(float rate) {
	this->taxRate = rate;
}

float Tax::getTaxRate() {
	return this->taxRate;
}

void Tax::collectTaxes(double revenue) {
	// TODO - implement Tax::collectTaxes
	throw "Not yet implemented";
}

void Tax::operate() {
	// TODO - implement Tax::operate
	throw "Not yet implemented";
}

//command functions
void Department::execute() {
	for (int i = 0; i < commands.size(); i++) {
        commands[i]->execute();
    }
}

void Department::addCommand(Command* command) {
	commands.push_back(command);
}

void Department::removeCommand(int i) {
	commands.erase(commands.begin() + i);
}
