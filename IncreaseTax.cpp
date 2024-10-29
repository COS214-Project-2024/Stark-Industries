#include "IncreaseTax.h"

IncreaseTax::IncreaseTax(Citizen * citizenReceiver, Building * buildingReceiver, int increase, string type) {
	this->citizenReceiver = citizenReceiver;
	this->buildingReceiver = buildingReceiver;
	this->increase = increase;
	this->taxType = type;
	this->name = "Increase";
}

void IncreaseTax::execute() {
	citizenReceiver->performAction(1);
	//buildingReceiver->performAction(1);
}
