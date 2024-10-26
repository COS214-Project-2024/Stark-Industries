#include "Services.h"
#include <iostream>

Services::Services(const std::string& name, int healthcare, int education, int emergencyUnits)
    : Department(name), healthcareFacilities(healthcare), 
      educationalInstitutions(education), emergencyResponseUnits(emergencyUnits) {}

void Services::operate() {
    std::cout << "Operating Services Department:\n"
              << "- Healthcare Facilities: " << healthcareFacilities << "\n"
              << "- Educational Institutions: " << educationalInstitutions << "\n"
              << "- Emergency Response Units: " << emergencyResponseUnits << "\n"
              << "Service Programs:\n";
    for (const auto& program : servicePrograms) {
        std::cout << "  - " << program << "\n";
    }
}

void Services::addServiceProgram(const std::string& program) {
    servicePrograms.push_back(program);
    std::cout << "Added service program: " << program << "\n";
}
