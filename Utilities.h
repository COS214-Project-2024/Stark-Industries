#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
using namespace std;

/**
 * @brief Abstract base class for utilities.
 * 
 * The Utilities class provides a common interface for all utility 
 * types, including methods for generating resources, displaying 
 * information, and requesting maintenance. It is intended to be 
 * subclassed by specific utility implementations.
 */
class Utilities {

private:
    string name;             ///< The name of the utility.
    double capacity;         ///< The maximum capacity of the utility.
    double operationalCost;  ///< The operational cost associated with the utility.

public:
    /**
     * @brief Constructs a Utilities object with specified details.
     * 
     * This constructor initializes a Utilities object with the given 
     * name, capacity, and operational cost.
     * 
     * @param name The name of the utility.
     * @param capacity The maximum capacity of the utility.
     * @param operationalCost The operational cost of the utility.
     */
    Utilities(string name, double capacity, double operationalCost)
        : name(name), capacity(capacity), operationalCost(operationalCost) {}

    /**
     * @brief Generates resources from the utility.
     * 
     * This is a pure virtual function that must be overridden by 
     * derived classes to implement specific resource generation logic.
     */
    virtual void generateResources() = 0;

    /**
     * @brief Displays information about the utility.
     * 
     * This is a pure virtual function that must be implemented by 
     * derived classes to output details about the utility.
     */
    virtual void displayInfo() = 0;

    /**
     * @brief Requests maintenance for the utility.
     * 
     * This is a pure virtual function that must be implemented by 
     * derived classes to handle maintenance requests.
     * 
     * @param Utilities_util An integer identifier for the type of utility 
     *                       requesting maintenance.
     */
    virtual void requestMaintenance(int Utilities_util) = 0;

    /**
     * @brief Virtual destructor for the Utilities class.
     * 
     * This ensures that derived class destructors are called correctly 
     * when an object is deleted through a pointer to the base class.
     */
    virtual ~Utilities() = default;  // Virtual destructor for cleanup
};

#endif
