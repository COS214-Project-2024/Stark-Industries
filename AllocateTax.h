#ifndef ALLOCATETAX_H
#define ALLOCATETAX_H

#include "Command.h"
#include "Government.h"
#include <string>
using namespace std;

class AllocateTax : public Command {

private:
	string department;
	double amount;

public:
	Department * receiver;
	AllocateTax(Department * receiver, string dep, double amount);

	void execute();
};

#endif
