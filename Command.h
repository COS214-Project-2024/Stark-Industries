#ifndef COMMAND_H
#define COMMAND_H

#include "Department.h"

class Command {

public:
	Department * receiver; 
	void execute();
};

#endif



/*
Command Command Pattern:
	Invoker: Department
	ConcreteCommand: Allocatetax, CollectTax, IncreaseTax
	Receiver: Department
*/
