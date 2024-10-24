#include "CollectTax.h"

CollectTax::CollectTax(Citizen* citizenReceiver, Building* buildingReceiver) {
	this->citizenReceiver = citizenReceiver;
	this->buildingReceiver = buildingReceiver;
}

void CollectTax::execute() {
	citizenReceiver->performAction(0);
	buildingReceiver->performAction(0);
}
