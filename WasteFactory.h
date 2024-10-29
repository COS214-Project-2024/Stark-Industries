#ifndef WASTEFACTORY_H
#define WASTEFACTORY_H

#include "UtilitiesFactory.h"
#include "Utilities.h"
#include <string>
using namespace std;

/**
 * @brief The WasteFactory class is a concrete factory that creates utility objects.
 * 
 * This class inherits from the UtilitiesFactory and implements the createUtility method
 * to produce instances of Utilities.
 */
class WasteFactory : public UtilitiesFactory {
public:
    /**
     * @brief Creates a utility object.
     * 
     * This method overrides the createUtility method in the UtilitiesFactory class.
     * 
     * @return A pointer to a newly created Utilities object.
     */
    Utilities* createUtility();
};

#endif
