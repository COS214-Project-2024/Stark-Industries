#ifndef COMMAND_H
#define COMMAND_H

//#include "Department.h"
#include "Citizen.h"
#include "Building.h"

class Command {

public:
	Citizen * citizenReceiver; 
	Building * buildingReceiver;
	virtual void execute() = 0;
	std::string name;
};

#endif

/*
Command Command Pattern:
	Invoker: Department/Tax
	Command: Command
	ConcreteCommand: Allocatetax, CollectTax, IncreaseTax
	Receiver: citizen and buildings
*/
