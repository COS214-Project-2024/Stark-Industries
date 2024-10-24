#ifndef INCREASETAX_H
#define INCREASETAX_H

#include "Command.h"
#include "Government.h"
#include <string>
using namespace std;

class IncreaseTax : public Command {

private:
	double increase;
	string taxType;

public:
	Department * receiver;
	IncreaseTax(Department * receiver, int increase, string type);
	void execute();
};

#endif
