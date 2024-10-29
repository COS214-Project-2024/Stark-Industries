#ifndef SEWAGE_H
#define SEWAGE_H

#include "Utilities.h"
#include <string>
using namespace std;

/**
 * @brief Class representing a sewage utility.
 * 
 * The Sewage class inherits from the Utilities class and represents 
 * a specific type of utility related to sewage management. It provides 
 * methods for displaying information, generating resources, and 
 * requesting maintenance.
 */
class Sewage : public Utilities {

private:
    string name;             ///< The name of the sewage utility.
    double capacity;         ///< The maximum capacity of the sewage utility.
    double operationalCost;  ///< The operational cost associated with the sewage utility.

public:
    /**
     * @brief Constructs a Sewage object with specified details.
     * 
     * This constructor initializes a Sewage object with the given 
     * name, capacity, and operational cost.
     * 
     * @param name The name of the sewage utility.
     * @param capacity The maximum capacity of the sewage utility.
     * @param operationalCost The operational cost of the sewage utility.
     */
    Sewage(string name, double capacity, double operationalCost);

    /**
     * @brief Displays information about the sewage utility.
     * 
     * This method outputs the details of the sewage utility, including 
     * its name, capacity, and operational cost.
     */
    void displayInfo();

    /**
     * @brief Generates resources from the sewage utility.
     * 
     * This method implements the logic for processing resources 
     * from the sewage utility.
     */
    void generateResources();

    /**
     * @brief Requests maintenance for the sewage utility.
     * 
     * This method handles maintenance requests for the sewage utility.
     * 
     * @param Utilities_util An integer identifier for the type of utility 
     *                       requesting maintenance.
     */
    void requestMaintenance(int Utilities_util);
};

#endif
