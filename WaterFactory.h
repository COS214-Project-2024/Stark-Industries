#ifndef WATERFACTORY_H
#define WATERFACTORY_H

#include "UtilitiesFactory.h"
#include "Utilities.h"
#include <string>

using namespace std;

/**
 * @brief The WaterFactory class is responsible for creating water-related utility objects.
 *
 * This class inherits from `UtilitiesFactory` and implements the `createUtility` method
 * to produce instances of water utilities, such as water treatment plants, reservoirs, or 
 * other water-related infrastructure.
 */
class WaterFactory : public UtilitiesFactory {

public:
    /**
     * @brief Creates and returns a new water-related utility object.
     *
     * This method overrides the `createUtility` function in `UtilitiesFactory`. It is 
     * responsible for instantiating and returning a water-related utility object.
     *
     * @return A pointer to a new `Utilities` object representing a water utility.
     */
    Utilities* createUtility();
};

#endif
