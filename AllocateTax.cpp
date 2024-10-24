#include "AllocateTax.h"

AllocateTax::AllocateTax(Citizen * citizenReceiver, Building * buildingReceiver, string dep, double amount) {
	this->citizenReceiver = citizenReceiver;
	this->buildingReceiver = buildingReceiver;
	this->department = dep;
	this->amount = amount;
}

void AllocateTax::execute() {
	citizenReceiver->performAction(2);
	buildingReceiver->performAction(2);
}
