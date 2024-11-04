/**
 * @file IncreaseTax.cpp
 * @brief Implements the IncreaseTax command, which increases tax rates for citizens.
 */

#include "IncreaseTax.h"

/**
 * @brief Constructs an IncreaseTax command object.
 * 
 * This command will be responsible for instructing citizens to increase their taxes.
 */
IncreaseTax::IncreaseTax() {}

/**
 * @brief Executes the increase tax command on all citizens in the list.
 * 
 * Iterates through the `citizenList` and invokes the `performAction` method 
 * with action type `1` to increase tax rates for each citizen.
 */
void IncreaseTax::execute() {
    for (int i = 0; i < citizenList.size(); i++) {
        citizenList[i]->performAction(1);
    }
    // Uncomment to apply tax increase to a specific building, if applicable.
    // buildingReceiver->performAction(1);
}
