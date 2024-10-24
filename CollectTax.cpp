#include "CollectTax.h"

CollectTax::CollectTax(Department * receiver) {
	this->receiver = receiver;
}

void CollectTax::execute() {
	receiver->performAction();
}
