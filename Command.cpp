#include "Command.h"

void Command::addBuildingVector(vector<Building*> buildingList) {
    this->buildingList = buildingList;
}

void Command::addCitizenVector(vector<Citizen*> citizenList) {
    this->citizenList = citizenList;
}