#ifndef COLLECTTAX_H
#define COLLECTTAX_H

#include "Command.h"
//#include "Government.h"
#include "Citizen.h"
#include "Building.h"
#include <string>
using namespace std;

class CollectTax : public Command {

public:
	Citizen * citizenReceiver; 
	Building * buildingReceiver;
	CollectTax(Citizen * citizenReceiver, Building * buildingReceiver);
	void execute();
};

#endif
