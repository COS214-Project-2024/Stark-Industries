#ifndef COMMAND_H
#define COMMAND_H

#include "Department.h"

class Command {

public:
	Department * receiver; 
	virtual void execute() = 0;
};

#endif

/*
Command Command Pattern:
	Invoker: Department
	ConcreteCommand: Allocatetax, CollectTax, IncreaseTax
	Receiver: Department, then there is tax-child of departemnnt
*/
