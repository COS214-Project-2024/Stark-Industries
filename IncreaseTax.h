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
	Citizen * citizenReceiver; 
	Building * buildingReceiver;
	IncreaseTax(Citizen* citizenReceiver, Building * buildingReceiver, int increase, string type);
	void execute();
};

#endif
