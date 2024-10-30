#ifndef WATERFACTORY_H
#define WATERFACTORY_H

#include "UtilitiesFactory.h"
#include "Utilities.h"
#include <string>
using namespace std;

class WaterFactory : public UtilitiesFactory {


public:
	Utilities* createUtility();
};

#endif
