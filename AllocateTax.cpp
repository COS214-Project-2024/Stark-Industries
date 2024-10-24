#include "AllocateTax.h"

AllocateTax::AllocateTax(Department * receiver, string dep, double amount) {
	this->receiver = receiver;
	this->department = dep;
	this->amount = amount;
}

void AllocateTax::execute() {
	receiver->performAction();
}
