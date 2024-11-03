#include "IncreaseTax.h"

IncreaseTax::IncreaseTax() {
}

void IncreaseTax::execute() {
	for (int i = 0 ; i < citizenReceivers.size() ; i++){
		citizenReceivers[i]->performAction(1);
	}
	//buildingReceiver->performAction(1);
}

