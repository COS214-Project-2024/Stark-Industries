#ifndef ALLOCATETAX_H
#define ALLOCATETAX_H

#include "Command.h"
#include "Government.h"
#include <string>
using namespace std;

class AllocateTax : public Command {

private:
	Government gov;
	string department;
	double amount;

public:
	AllocateTax(Government gov, string dep, double amount);

	void execute();
};

#endif
