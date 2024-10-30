#ifndef INCREASETAX_H
#define INCREASETAX_H

#include "Command.h"
#include "Government.h"
#include <string>
#include <vector>
using namespace std;

class IncreaseTax : public Command {

private:
	double increase;
	string taxType;

public:
	vector<Citizen*> citizenReceivers;
	IncreaseTax(Citizen* citizenReceiver);
	void execute();
};

#endif
