#ifndef INCREASETAX_H
#define INCREASETAX_H

#include "Command.h"
#include "Government.h"
#include <string>
using namespace std;

class IncreaseTax : public Command {

private:
	Government gov;
	double increase;
	string taxType;

public:
	IncreaseTax(Government gov, int increase, string type);

	void execute();
};

#endif
