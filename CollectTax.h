#ifndef COLLECTTAX_H
#define COLLECTTAX_H

#include "Command.h"
#include "Government.h"
#include <string>
using namespace std;

class CollectTax : public Command {

public:
	Department * receiver;
	CollectTax(Department * receiver);
	void execute();
};

#endif
