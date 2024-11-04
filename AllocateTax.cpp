/**
 * @file AllocateTax.cpp
 * @brief Implements the AllocateTax class, which defines a command for allocating tax funds to a government entity.
 */

#include "AllocateTax.h"

/**
 * @brief Constructor to initialize the AllocateTax command with a government receiver.
 * @param govtReceiver A pointer to the Government object that will receive allocated tax funds.
 */
AllocateTax::AllocateTax(Government* govtReceiver) {
    this->govtReceiver = govtReceiver;	
    this->name = "Allocate";
}

/**
 * @brief Executes the tax allocation command by invoking the allocateTax function on the government receiver.
 */
void AllocateTax::execute() {
    govtReceiver->allocateTax();
}
