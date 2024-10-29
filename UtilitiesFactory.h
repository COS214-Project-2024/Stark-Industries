#ifndef UTILITIESFACTORY_H
#define UTILITIESFACTORY_H

#include "Utilities.h"

/**
 * @brief Abstract base class for creating utility objects.
 * 
 * The UtilitiesFactory class defines an interface for creating utility 
 * objects. Concrete factories will implement the `createUtility` method 
 * to instantiate specific types of utilities.
 */
class UtilitiesFactory {

private:
    Utilities* utilities; ///< Pointer to a Utilities object for internal use by derived classes.

protected:
    /**
     * @brief Creates a utility object.
     * 
     * This is a pure virtual function that must be overridden in derived 
     * classes to provide specific functionality for creating instances 
     * of Utilities.
     * 
     * @return A pointer to the newly created Utilities object.
     */
    virtual Utilities* createUtility() = 0; // Pure virtual function
};

#endif
