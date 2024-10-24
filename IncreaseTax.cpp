#include "IncreaseTax.h"

IncreaseTax::IncreaseTax(Department * receiver, int increase, string type) {
	this->receiver = receiver;
	this->increase = increase;
	this->taxType = type;
}

void IncreaseTax::execute() {
	receiver->performAction();
}
