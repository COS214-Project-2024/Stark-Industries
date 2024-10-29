#ifndef WATER_H
#define WATER_H

#include "Utilities.h"
#include <string>

using namespace std;

/**
 * @brief The Water class represents a water utility.
 *
 * This class inherits from `Utilities` and provides specific implementations for
 * water-related utility functions, including displaying information, generating resources,
 * and requesting maintenance.
 */
class Water : public Utilities {

private:
    string name;           ///< The name of the water utility.
    double capacity;       ///< The capacity of the water utility (in gallons or another unit).
    double operationalCost; ///< The operational cost of the water utility (in currency per hour).

public:
    /**
     * @brief Constructs a Water utility with specified details.
     *
     * @param name The name of the water utility.
     * @param capacity The capacity of the water utility.
     * @param operationalCost The operational cost of the water utility.
     */
    Water(string name, double capacity, double operationalCost);

    /**
     * @brief Displays information about the water utility.
     *
     * Prints the utility's name, capacity, and operational cost.
     */
    void displayInfo();

    /**
     * @brief Simulates the generation of water resources.
     *
     * Outputs a message indicating the amount of water being generated.
     */
    void generateResources();

    /**
     * @brief Requests maintenance for the water utility.
     *
     * Outputs a maintenance request message with a provided maintenance ID.
     *
     * @param Utilities_util The maintenance ID for tracking purposes.
     */
    void requestMaintenance(int Utilities_util);
};

#endif
