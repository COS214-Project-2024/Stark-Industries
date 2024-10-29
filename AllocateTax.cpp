#include "AllocateTax.h"

AllocateTax::AllocateTax(Government* govtReceiver) {
	this->govtReceiver = govtReceiver;	
	this->name = "Allocate";
}

void AllocateTax::execute() {
	govtReceiver->allocateTax();
}
