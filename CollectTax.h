#ifndef COLLECTTAX_H
#define COLLECTTAX_H

#include "Command.h"
//#include "Government.h"
#include "Citizen.h"
#include "Building.h"
#include <string>
#include <vector>
using namespace std;

class CollectTax : public Command {

public:
	CollectTax(Citizen * citizenReceiver, Building * buildingReceiver);
	CollectTax(){};
	void addBuilding(Building * buildingReceiver);
	void addCitizen(Citizen * citizenReceiver);
	void execute();
};

#endif
