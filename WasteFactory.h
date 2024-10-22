#ifndef WASTEFACTORY_H
#define WASTEFACTORY_H

#include "UtilitiesFactory.h"
#include "Utilities.h"
#include <string>
using namespace std;

class WasteFactory : public UtilitiesFactory {


protected:
	Utilities* createUtility();
};

#endif
