#include "IncreaseTax.h"

IncreaseTax::IncreaseTax() {
}

void IncreaseTax::execute() {
	for (int i = 0 ; i < citizenList.size() ; i++){
		citizenList[i]->performAction(1);
	}
	//buildingReceiver->performAction(1);
}

