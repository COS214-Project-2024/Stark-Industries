/**
 * @file Command.cpp
 * @brief Implements the Command class methods for managing lists of buildings and citizens.
 */

#include "Command.h"

/**
 * @brief Sets the list of buildings associated with the command.
 * 
 * Replaces the existing building list with the provided list of buildings.
 * 
 * @param buildingList A vector of pointers to Building objects to be associated with the command.
 */
void Command::addBuildingVector(std::vector<Building*> buildingList) {
    this->buildingList = buildingList;
}

/**
 * @brief Sets the list of citizens associated with the command.
 * 
 * Replaces the existing citizen list with the provided list of citizens.
 * 
 * @param citizenList A vector of pointers to Citizen objects to be associated with the command.
 */
void Command::addCitizenVector(std::vector<Citizen*> citizenList) {
    this->citizenList = citizenList;
}
