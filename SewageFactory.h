#ifndef SEWAGEFACTORY_H
#define SEWAGEFACTORY_H

#include "UtilitiesFactory.h"
#include "Utilities.h"
#include <string>
using namespace std;

/**
 * @brief Concrete factory class for creating sewage utility objects.
 * 
 * The SewageFactory class is a concrete implementation of the 
 * UtilitiesFactory, providing functionality to create specific 
 * types of utilities related to sewage management.
 */
class SewageFactory : public UtilitiesFactory {

public:
    /**
     * @brief Creates a sewage utility object.
     * 
     * This method overrides the createUtility method in the 
     * UtilitiesFactory class and returns a pointer to a newly 
     * created Utilities object specific to sewage management.
     * 
     * @return A pointer to the newly created Utilities object.
     */
    Utilities* createUtility();
};

#endif
