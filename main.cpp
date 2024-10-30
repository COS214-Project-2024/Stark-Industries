#include <iostream>
#include <vector>

#include "Population.h"
#include "Housing.h"
#include "Economic.h"
#include "Infrastructure.h"
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

#include "Residential.h"
#include "Commercial.h"
#include "Industrial.h"
#include "Landmark.h"
#include "Citizen.h"

#include "City.h"

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

void testCOR() {
    // Create handlers with test values
    int growthFactor = 101;
    Population populationHandler(growthFactor);
    Housing housingHandler(growthFactor * 0.5);
    Economic economicHandler(growthFactor * 0.75);
    Infrastructure infrastructureHandler(growthFactor * 0.3);

    // Set up the chain of responsibility
    populationHandler.setNextHandler(&housingHandler);
    housingHandler.setNextHandler(&economicHandler);
    economicHandler.setNextHandler(&infrastructureHandler);

    // Test the chain with a growth factor
    populationHandler.handleRequest(growthFactor);
}

void testBuildingObserver(){
    // Create citizens
    Citizen* alice = new Citizen("Alice", 50000, 250000);
    Citizen* bob = new Citizen("Bob", 60000, 300000);
    Citizen* charlie = new Citizen("Charlie", 70000, 350000);

    // Create different types of buildings
    Residential* apartment = new Residential("Sunset Apartments", 80, 5000, 200, true, 1, true, 5);
    Commercial* mall = new Commercial("City Mall", 75, 10000, 500, true, 1, true, 10);
    Industrial* factory = new Industrial("Steel Factory", 70, 15000, 1000, true, 1, true, 8);
    Landmark* monument = new Landmark("Freedom Monument", 90, 8000, 500, true, 1, true, 10);

    // Attach citizens to different buildings
    std::cout << "\n=== Citizens Observing Different Buildings ===\n";
    apartment->attach(alice);
    mall->attach(alice);
    factory->attach(bob);
    monument->attach(charlie);

    // Perform improvements to trigger notifications
    std::cout << "\n=== Performing Improvements on Residential Building ===\n";
    apartment->doImprovements();  // Alice should be notified

    std::cout << "\n=== Performing Improvements on Commercial Building ===\n";
    mall->doImprovements();  // Alice should be notified again

    std::cout << "\n=== Performing Improvements on Industrial Building ===\n";
    factory->doImprovements();  // Bob should be notified

    std::cout << "\n=== Performing Improvements on Landmark ===\n";
    monument->doImprovements();  // Charlie should be notified

    // Detach a citizen from a building
    std::cout << "\n=== Detaching Alice from the Commercial Building ===\n";
    mall->detach(alice);

    // Perform another improvement on the Commercial building
    std::cout << "\n=== Performing Improvements on Commercial Building Again ===\n";
    mall->doImprovements();  // Alice should not be notified this time

    // Clean up
    delete alice;
    delete bob;
    delete charlie;
    delete apartment;
    delete mall;
    delete factory;
    delete monument;
}

void testCityObserver(){
    // Create citizens
    Citizen* alice = new Citizen("Alice", 50000, 250000);
    Citizen* bob = new Citizen("Bob", 60000, 300000);
    Citizen* charlie = new Citizen("Charlie", 70000, 350000);

    // Create city
    City city;

    // Attach observers
    city.attach(alice);
    city.attach(bob);
    city.attach(charlie);

    // Notify observers and check if they receive the update
    city.notify();
    
    // Validate notifications (this would be checked by output or in a real unit test framework)
    if (alice->isNotified() && bob->isNotified() && charlie->isNotified()) {
        std::cout << "All citizens received the notification.\n";
    } else {
        std::cout << "Test failed: Not all citizens received the notification.\n";
    }

    // Reset notification status
    alice->resetNotification();
    bob->resetNotification();
    charlie->resetNotification();

    // Detach an observer and test again
    city.detach(bob);

    city.notify();  // Should only notify Alice and Charlie

    if (alice->isNotified() && !bob->isNotified() && charlie->isNotified()) {
        std::cout << "Test passed for detaching citizens.\n";
    } else {
        std::cout << "Test failed for detaching citizens.\n";
    }

    // Clean up
    delete alice;
    delete bob;
    delete charlie;
}
#include "Citizen.h"
#include "CollectTax.h"
#include "Industrial.h"
#include "Residential.h"
#include "Commercial.h"
#include "IncreaseTax.h"
#include "TaxCollector.h"
#include "City.h"

void testCollectTax(){
    Citizen* citizen = new Citizen("Tony", 1000);
    Building* industrial = new Industrial();
    CollectTax* collectTax = new CollectTax(citizen, industrial);
    Building* residential = new Residential();
    collectTax->addBuilding(residential);
    Building* commercial = new Commercial();
    collectTax->addBuilding(commercial);
    collectTax->execute();
}

void testIncreaseTax(){
    Citizen* citizen = new Citizen("Tony", 10000);
    Command * incTax = new IncreaseTax(citizen);
    incTax->execute(); 
}

void testTaxCollector(){
    TaxCollector* taxCollector = new TaxCollector();
    Citizen* citizen = new Citizen("Tony", 1000);
    Citizen* citizen2 = new Citizen("Sherlock", 1000);
    City * city = new City();
    CollectTax* collectTax = new CollectTax(citizen, nullptr);
    collectTax->addCitizen(citizen2);
    collectTax->execute();
    city->attach(citizen);
    city->attach(citizen2);
    for (int i = 0 ; i < city->citizens.size() ; i++){
        taxCollector->visit(city->citizens[i]);
    }
}

int main() {
    
    testFactoryUtilities();
    testComposite();
    factoryBuildings();
    testCOR();
    testBuildingObserver();
    testCityObserver();
    testCollectTax();
    testIncreaseTax();
    testTaxCollector();

    return 0;
}

