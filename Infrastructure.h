#ifndef INFRASTRUCTURE_H
#define INFRASTRUCTURE_H

#include "GrowthHandler.h"
#include <string>
using namespace std;

class Infrastructure : public GrowthHandler {

private:
	int roadsBuilt;
	int utilityCapacity;

public:
	Infrastructure(int roads, int capacity);

	void handleRequest();
};

#endif
