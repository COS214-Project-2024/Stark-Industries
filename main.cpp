#include <iostream>
#include <vector>
#include "ResidentialCreator.h"
#include "LandmarkCreator.h"
#include "CommercialCreator.h"
#include "IndustrialCreator.h"
#include "Building.h"

#include "WaterFactory.h"
#include "WasteFactory.h"
#include "SewageFactory.h"
#include "PowerPlantFactory.h"
#include "Utilities.h"
#include "Water.h"
#include "Waste.h"
#include "Sewage.h"

#include "Tax.h"
#include "Budget.h"
#include "Policies.h"
#include "Services.h"
#include "Government.h"

using namespace std;

void testFactoryUtilities() {
    // Water Factory
    WaterFactory waterFactory;
    Utilities* waterUtility = waterFactory.createUtility();
    cout << "Testing Water Utility:\n";
    waterUtility->displayInfo();
    waterUtility->generateResources();
    waterUtility->requestMaintenance(101);
    cout << endl;

    // Waste Factory
    WasteFactory wasteFactory;
    Utilities* wasteUtility = wasteFactory.createUtility();
    cout << "Testing Waste Utility:\n";
    wasteUtility->displayInfo();
    wasteUtility->generateResources();
    wasteUtility->requestMaintenance(102);
    cout << endl;

    // Sewage Factory
    SewageFactory sewageFactory;
    Utilities* sewageUtility = sewageFactory.createUtility();
    cout << "Testing Sewage Utility:\n";
    sewageUtility->displayInfo();
    sewageUtility->generateResources();
    sewageUtility->requestMaintenance(103);
    cout << endl;

    // PowerPlant Factory
    PowerPlantFactory powerPlantFactory;
    Utilities* powerPlantUtility = powerPlantFactory.createUtility();
    cout << "Testing Power Plant Utility:\n";
    powerPlantUtility->displayInfo();
    powerPlantUtility->generateResources();
    powerPlantUtility->requestMaintenance(104);
    cout << endl;

    // Clean up
    delete waterUtility;
    delete wasteUtility;
    delete sewageUtility;
    delete powerPlantUtility;
}

void testComposite(){
     std::cout << "City Simulation using Composite Pattern\n";

    // Create a Government (composite)
    Government* cityGovernment = new Government(0.15, 0.05);

    // Create individual departments (leaves)
    Department* taxDept = new Tax("Tax Department", 15.0f);
    Department* budgetDept = new Budget("Budget Department", 10000.0);
    Department* policiesDept = new Policies("Policies Department");
    Department* servicesDept = new Services("Public Services", 5, 10, 3);

    // Add policies to the Policies Department
    dynamic_cast<Policies*>(policiesDept)->addPolicy("Environmental Protection");
    dynamic_cast<Policies*>(policiesDept)->addPolicy("Healthcare Reform");

    // Add service programs to the Services Department
    dynamic_cast<Services*>(servicesDept)->addServiceProgram("Free Education Initiative");
    dynamic_cast<Services*>(servicesDept)->addServiceProgram("Healthcare for All");

    // Add departments to the Government composite
    cityGovernment->add(taxDept);
    cityGovernment->add(budgetDept);
    cityGovernment->add(policiesDept);
    cityGovernment->add(servicesDept);

    std::cout << "\nGovernment operates all departments:\n";
    cityGovernment->operate();  // Government will operate all added departments

    // Remove the Tax department and re-operate
    std::cout << "\nRemoving Tax Department...\n";
    cityGovernment->remove(taxDept);
    cityGovernment->operate();

    std::cout << "Simulation ended.\n";

    // Clean up dynamically allocated memory
    delete taxDept;
    delete budgetDept;
    delete policiesDept;
    delete servicesDept;
    delete cityGovernment;

    
}
  
void factoryBuildings() {
    // Initialize creators for each building type
    ResidentialCreator residentialCreator;
    LandmarkCreator landmarkCreator;
    CommercialCreator commercialCreator;
    IndustrialCreator industrialCreator;

    // Create Residential Building
    Building* residentialBuilding = residentialCreator.createBuilding("Residential Block", 30, 5000, 300, true, 1, true, 200);
    cout << "Residential Building Created:" << endl;
    cout << "Type: " << residentialBuilding->getType() << endl;
    cout << "Satisfaction: " << residentialBuilding->calculateSatisfaction() << endl;
    cout << "Economic Impact: " << residentialBuilding->calculateEconomicImpact() << endl;
    cout << "Resource Consumption: " << residentialBuilding->calculateResourceConsumption() << endl;
    residentialBuilding->doImprovements();
    cout << "Satisfaction after improvement: " << residentialBuilding->calculateSatisfaction() << endl;

    // Create Landmark Building
    Building* landmarkBuilding = landmarkCreator.createBuilding("Statue of Liberty", 50, 100000, 500, true, 1, true, 500);
    cout << "\nLandmark Building Created:" << endl;
    cout << "Type: " << landmarkBuilding->getType() << endl;
    cout << "Satisfaction: " << landmarkBuilding->calculateSatisfaction() << endl;
    cout << "Economic Impact: " << landmarkBuilding->calculateEconomicImpact() << endl;
    cout << "Resource Consumption: " << landmarkBuilding->calculateResourceConsumption() << endl;
    landmarkBuilding->doImprovements();
    cout << "Satisfaction after improvement: " << landmarkBuilding->calculateSatisfaction() << endl;

    // Create Commercial Building
    Building* commercialBuilding = commercialCreator.createBuilding("Mall", 20, 30000, 1000, true, 1, true, 300);
    cout << "\nCommercial Building Created:" << endl;
    cout << "Type: " << commercialBuilding->getType() << endl;
    cout << "Satisfaction: " << commercialBuilding->calculateSatisfaction() << endl;
    cout << "Economic Impact: " << commercialBuilding->calculateEconomicImpact() << endl;
    cout << "Resource Consumption: " << commercialBuilding->calculateResourceConsumption() << endl;
    commercialBuilding->doImprovements();
    cout << "Satisfaction after improvement: " << commercialBuilding->calculateSatisfaction() << endl;

    // Create Industrial Building
    Building* industrialBuilding = industrialCreator.createBuilding("Factory", 10, 20000, 2000, true, 1, true, 400);
    cout << "\nIndustrial Building Created:" << endl;
    cout << "Type: " << industrialBuilding->getType() << endl;
    cout << "Satisfaction: " << industrialBuilding->calculateSatisfaction() << endl;
    cout << "Economic Impact: " << industrialBuilding->calculateEconomicImpact() << endl;
    cout << "Resource Consumption: " << industrialBuilding->calculateResourceConsumption() << endl;
    industrialBuilding->doImprovements();
    cout << "Satisfaction after improvement: " << industrialBuilding->calculateSatisfaction() << endl;

    // Clean up
    delete residentialBuilding;
    delete landmarkBuilding;
    delete commercialBuilding;
    delete industrialBuilding;
}

int main() {
    
    testFactoryUtilities();
    testComposite
    factoryBuildings();
  
    return 0;
}