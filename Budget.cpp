#include "Budget.h"

void Budget::operate() {
	// TODO - implement Budget::operate
	//throw "Not yet implemented";
}

void Budget::allocateFunds() {
	// TODO - implement Budget::allocateFunds
	//throw "Not yet implemented";
	//do budget things
}

void Budget::receiveTax(double tax) {
	totalBudget += tax;
	std::cout << "Budget received: " << tax << std::endl;
	allocateFunds();
}
