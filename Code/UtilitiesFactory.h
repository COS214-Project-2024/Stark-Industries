#ifndef UTILITIESFACTORY_H
#define UTILITIESFACTORY_H

#include "Utilities.h"

class UtilitiesFactory {

private:
	Utilities* utilities;

protected:
	virtual Utilities* createUtility() = 0;
};

#endif
