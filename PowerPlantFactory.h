#ifndef POWERPLANTFACTORY_H
#define POWERPLANTFACTORY_H

#include "UtilitiesFactory.h"
#include "Utilities.h"
#include <string>

using namespace std;

/**
 * @class PowerPlantFactory
 * @brief A concrete factory class for creating Power Plant utility objects.
 *
 * This class is responsible for creating instances of `Utilities` that represent
 * a Power Plant. It inherits from the `UtilitiesFactory` abstract class and 
 * implements the `createUtility` method to provide a specific implementation for
 * Power Plants.
 */
class PowerPlantFactory : public UtilitiesFactory {
public:
    /**
     * @brief Creates a new instance of a Power Plant utility.
     *
     * This method overrides the `createUtility` method from the `UtilitiesFactory`
     * abstract base class. It creates and returns an instance of a `Utilities`
     * object that represents a Power Plant.
     *
     * @return Utilities* Pointer to a new Power Plant utility object.
     */
    Utilities* createUtility() override;
};

#endif // POWERPLANTFACTORY_H
