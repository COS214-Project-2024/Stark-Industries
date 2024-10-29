#ifndef POWERPLANT_H
#define POWERPLANT_H

#include "Utilities.h"
#include <string>

using namespace std;

/**
 * @class PowerPlant
 * @brief Represents a specific type of utility that generates energy resources.
 *
 * The `PowerPlant` class inherits from the `Utilities` base class and provides
 * specific functionality related to power generation. It includes attributes 
 * such as the power plant's name, capacity, and operational cost, and methods 
 * to display information, generate resources, and request maintenance.
 */
class PowerPlant : public Utilities {
private:
    string name;              /**< Name of the power plant */
    double capacity;          /**< Energy production capacity of the power plant in MW */
    double operationalCost;   /**< Operational cost of the power plant per unit time */

public:
    /**
     * @brief Constructs a new PowerPlant object with specified attributes.
     *
     * Initializes the power plant with a name, production capacity, and 
     * operational cost.
     *
     * @param name The name of the power plant.
     * @param capacity The production capacity of the power plant in MW.
     * @param operationalCost The operational cost of the power plant.
     */
    PowerPlant(string name, double capacity, double operationalCost);

    /**
     * @brief Displays the information of the power plant.
     *
     * Outputs the details of the power plant, including its name, capacity,
     * and operational cost. Useful for quick overviews or debugging.
     */
    void displayInfo();

    /**
     * @brief Generates resources based on the power plant's capacity.
     *
     * Simulates the generation of energy resources. The amount generated
     * is influenced by the plant's capacity. This method would typically
     * be used in a simulation of energy production.
     */
    void generateResources();

    /**
     * @brief Requests maintenance for the power plant.
     *
     * This method allows for the scheduling of maintenance activities.
     * Maintenance needs can be indicated by the `Utilities_util` parameter.
     *
     * @param Utilities_util Integer value representing the level or type
     * of maintenance required for the power plant.
     */
    void requestMaintenance(int Utilities_util);
};

#endif // POWERPLANT_H
