#ifndef SEWAGEFACTORY_H
#define SEWAGEFACTORY_H

#include "UtilitiesFactory.h"
#include "Utilities.h"
#include <string>
using namespace std;

class SewageFactory : public UtilitiesFactory {


protected:
	Utilities* createUtility();
};

#endif
