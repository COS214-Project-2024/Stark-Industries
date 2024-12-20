/**
 * @file Services.cpp
 * @brief Implementation of the Services class, representing a services department.
 */
#include "Services.h"
#include <iostream>

/**
 * @brief Constructs a Services department with the given attributes.
 * 
 * @param name Name of the services department.
 * @param healthcare Number of healthcare facilities managed by the department.
 * @param education Number of educational institutions managed by the department.
 * @param emergencyUnits Number of emergency response units available.
 */
Services::Services(const std::string& name, int healthcare, int education, int emergencyUnits)
    : Department(name), healthcareFacilities(healthcare), 
      educationalInstitutions(education), emergencyResponseUnits(emergencyUnits) {}

/**
 * @brief Operates the services department by displaying details of facilities and programs.
 * 
 * This method prints the number of healthcare facilities, educational institutions, 
 * and emergency response units managed by the department. It also lists all service programs 
 * offered by the department.
 */
void Services::operate() {
    std::cout << "Operating Services Department:\n"
              << "- Healthcare Facilities: " << healthcareFacilities << "\n"
              << "- Educational Institutions: " << educationalInstitutions << "\n"
              << "- Emergency Response Units: " << emergencyResponseUnits << "\n";
    cout << "Service Programs:\n";
    if (servicePrograms.empty()) {
        cout << "No available service programs.\n";
    }
    else {
        for (const auto& program : servicePrograms) {
        std::cout << "  - " << program << "\n";
    }
    }
}

/**
 * @brief Adds a new service program to the department's list of programs.
 * 
 * @param program The name of the service program to be added.
 */
void Services::addServiceProgram(const std::string& program) {
    servicePrograms.push_back(program);
    std::cout << "Added service program: " << program << "\n";
}

/**
 * @brief Gets the number of healthcare facilities managed by the department.
 * 
 * @return The number of healthcare facilities.
 */
int Services::getHealthcareFacilities(){
    return healthcareFacilities;
}

/**
 * @brief Gets the number of educational institutions managed by the department.
 * 
 * @return The number of educational institutions.
 */
int Services::getEducationalInstitutions(){
    return educationalInstitutions;
}

/**
 * @brief Executes commands related to the services department.
 * 
 * This method can be implemented to execute a list of commands associated with 
 * the services department.
 */
void Services::execute() {
//do nothing
}

/**
 * @brief Adds a command to the services department.
 * 
 * @param command A pointer to the Command object to be added.
 */
void Services::addCommand(Command* command) {
//do nothing
}

/**
 * @brief Removes a command from the services department by index.
 * 
 * @param i The index of the command to be removed.
 */
void Services::removeCommand(int i) {
  //do nothing  
}
