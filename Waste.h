#ifndef WASTE_H
#define WASTE_H

#include "Utilities.h"
#include <string>
using namespace std;

/**
 * @brief The Waste class represents a utility for managing waste.
 * 
 * This class inherits from the Utilities class and contains information 
 * about a specific type of waste, including its name, capacity, and 
 * operational cost. It provides methods to display information about 
 * the waste, generate resources from it, and request maintenance.
 */
class Waste : public Utilities {

private:
    string name;             ///< The name of the waste utility
    double capacity;         ///< The maximum capacity of the waste utility
    double operationalCost;  ///< The operational cost associated with the waste utility

public:
    /**
     * @brief Constructs a Waste object with specified attributes.
     * 
     * @param name The name of the waste utility.
     * @param capacity The maximum capacity of the waste utility.
     * @param operationalCost The operational cost of the waste utility.
     */
    Waste(string name, double capacity, double operationalCost);
		
    /**
     * @brief Displays information about the waste utility.
     * 
     * This method outputs the details of the waste utility, including 
     * its name, capacity, and operational cost.
     */
    void displayInfo();

    /**
     * @brief Generates resources from the waste utility.
     * 
     * This method implements the logic for resource generation from the 
     * waste managed by this utility.
     */
    void generateResources();

    /**
     * @brief Requests maintenance for the waste utility.
     * 
     * @param Utilities_util An integer identifier for the type of utility
     *                       requesting maintenance.
     */
    void requestMaintenance(int Utilities_util);
};

#endif
