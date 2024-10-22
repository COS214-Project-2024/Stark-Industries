#ifndef POWERPLANTFACTORY_H
#define POWERPLANTFACTORY_H

#include "UtilitiesFactory.h"
#include "Utilities.h"
#include <string>
using namespace std;

class PowerPlantFactory : public UtilitiesFactory {


protected:
	Utilities* createUtility();
};

#endif
