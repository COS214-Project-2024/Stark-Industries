
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

#include "RunwayFactory.h"
#include "RoadFactory.h"
#include "RailwayFactory.h"
#include "Citizen.h"
#include "Transport.h"
#include "Public.h"
#include "Train.h"
#include "Air.h"

#include "CollectTax.h"
#include "IncreaseTax.h"
#include "SatisfactionChecker.h"

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
  
// void factoryBuildings() {
//     // Initialize creators for each building type
//     ResidentialCreator residentialCreator;
//     LandmarkCreator landmarkCreator;
//     CommercialCreator commercialCreator;
//     IndustrialCreator industrialCreator;

//     // Create Residential Building
//     Building* residentialBuilding = residentialCreator.createBuilding("Residential Block", 30, 5000, 300, true, 1, true, 200);
//     cout << "Residential Building Created:" << endl;
//     cout << "Type: " << residentialBuilding->getType() << endl;
//     cout << "Satisfaction: " << residentialBuilding->calculateSatisfaction() << endl;
//     cout << "Economic Impact: " << residentialBuilding->calculateEconomicImpact() << endl;
//     cout << "Resource Consumption: " << residentialBuilding->calculateResourceConsumption() << endl;
//     residentialBuilding->doImprovements();
//     cout << "Satisfaction after improvement: " << residentialBuilding->calculateSatisfaction() << endl;

//     // Create Landmark Building
//     Building* landmarkBuilding = landmarkCreator.createBuilding("Statue of Liberty", 50, 100000, 500, true, 1, true, 500);
//     cout << "\nLandmark Building Created:" << endl;
//     cout << "Type: " << landmarkBuilding->getType() << endl;
//     cout << "Satisfaction: " << landmarkBuilding->calculateSatisfaction() << endl;
//     cout << "Economic Impact: " << landmarkBuilding->calculateEconomicImpact() << endl;
//     cout << "Resource Consumption: " << landmarkBuilding->calculateResourceConsumption() << endl;
//     landmarkBuilding->doImprovements();
//     cout << "Satisfaction after improvement: " << landmarkBuilding->calculateSatisfaction() << endl;

//     // Create Commercial Building
//     Building* commercialBuilding = commercialCreator.createBuilding("Mall", 20, 30000, 1000, true, 1, true, 300);
//     cout << "\nCommercial Building Created:" << endl;
//     cout << "Type: " << commercialBuilding->getType() << endl;
//     cout << "Satisfaction: " << commercialBuilding->calculateSatisfaction() << endl;
//     cout << "Economic Impact: " << commercialBuilding->calculateEconomicImpact() << endl;
//     cout << "Resource Consumption: " << commercialBuilding->calculateResourceConsumption() << endl;
//     commercialBuilding->doImprovements();
//     cout << "Satisfaction after improvement: " << commercialBuilding->calculateSatisfaction() << endl;

//     // Create Industrial Building
//     Building* industrialBuilding = industrialCreator.createBuilding("Factory", 10, 20000, 2000, true, 1, true, 400);
//     cout << "\nIndustrial Building Created:" << endl;
//     cout << "Type: " << industrialBuilding->getType() << endl;
//     cout << "Satisfaction: " << industrialBuilding->calculateSatisfaction() << endl;
//     cout << "Economic Impact: " << industrialBuilding->calculateEconomicImpact() << endl;
//     cout << "Resource Consumption: " << industrialBuilding->calculateResourceConsumption() << endl;
//     industrialBuilding->doImprovements();
//     cout << "Satisfaction after improvement: " << industrialBuilding->calculateSatisfaction() << endl;

//     // Clean up
//     delete residentialBuilding;
//     delete landmarkBuilding;
//     delete commercialBuilding;
//     delete industrialBuilding;
// }

// void testCOR() {
//     // Create handlers with test values
//     Residential* apartment = new Residential("Sunset Apartments", 80, 5000, 200, true, 1, true, 5);
//     Commercial* mall = new Commercial("City Mall", 75, 10000, 500, true, 1, true, 10);
//     Industrial* factory = new Industrial("Steel Factory", 70, 15000, 1000, true, 1, true, 8);
//     Landmark* monument = new Landmark("Freedom Monument", 90, 8000, 500, true, 1, true, 10);
//     int growthFactor = 21;
//     Population populationHandler(growthFactor);
//     Housing housingHandler(growthFactor * 0.5, apartment);
//     Economic economicHandler(growthFactor * 0.2);
//     Infrastructure infrastructureHandler(growthFactor * 0.3, mall, factory, monument);

//     // Set up the chain of responsibility
//     populationHandler.setNextHandler(&housingHandler);
//     housingHandler.setNextHandler(&economicHandler);
//     economicHandler.setNextHandler(&infrastructureHandler);

//     // Test the chain with a growth factor
//     populationHandler.handleRequest(growthFactor);
// }

// void testBuildingObserver(){
//     // Create citizens
//     Citizen* alice = new Citizen("Alice", 50000, 250000);
//     Citizen* bob = new Citizen("Bob", 60000, 300000);
//     Citizen* charlie = new Citizen("Charlie", 70000, 350000);

//     // Create different types of buildings
//     Residential* apartment = new Residential("Sunset Apartments", 80, 5000, 200, true, 1, true, 5);
//     Commercial* mall = new Commercial("City Mall", 75, 10000, 500, true, 1, true, 10);
//     Industrial* factory = new Industrial("Steel Factory", 70, 15000, 1000, true, 1, true, 8);
//     Landmark* monument = new Landmark("Freedom Monument", 90, 8000, 500, true, 1, true, 10);

//     // Attach citizens to different buildings
//     std::cout << "\n=== Citizens Observing Different Buildings ===\n";
//     apartment->attach(alice);
//     mall->attach(alice);
//     factory->attach(bob);
//     monument->attach(charlie);

//     // Perform improvements to trigger notifications
//     std::cout << "\n=== Performing Improvements on Residential Building ===\n";
//     apartment->doImprovements();  // Alice should be notified

//     std::cout << "\n=== Performing Improvements on Commercial Building ===\n";
//     mall->doImprovements();  // Alice should be notified again

//     std::cout << "\n=== Performing Improvements on Industrial Building ===\n";
//     factory->doImprovements();  // Bob should be notified

//     std::cout << "\n=== Performing Improvements on Landmark ===\n";
//     monument->doImprovements();  // Charlie should be notified

//     // Detach a citizen from a building
//     std::cout << "\n=== Detaching Alice from the Commercial Building ===\n";
//     mall->detach(alice);

//     // Perform another improvement on the Commercial building
//     std::cout << "\n=== Performing Improvements on Commercial Building Again ===\n";
//     mall->doImprovements();  // Alice should not be notified this time

//     // Clean up
//     delete alice;
//     delete bob;
//     delete charlie;
//     delete apartment;
//     delete mall;
//     delete factory;
//     delete monument;
// }

// void testCityObserver(){
//     // Create citizens
//     Citizen* alice = new Citizen("Alice", 50000, 250000);
//     Citizen* bob = new Citizen("Bob", 60000, 300000);
//     Citizen* charlie = new Citizen("Charlie", 70000, 350000);

//     // Create city
//     City city;

//     // Attach observers
//     city.attach(alice);
//     city.attach(bob);
//     city.attach(charlie);

//     // Notify observers and check if they receive the update
//     city.notify();
    
//     // Validate notifications (this would be checked by output or in a real unit test framework)
//     if (alice->isNotified() && bob->isNotified() && charlie->isNotified()) {
//         std::cout << "All citizens received the notification.\n";
//     } else {
//         std::cout << "Test failed: Not all citizens received the notification.\n";
//     }

//     // Reset notification status
//     alice->resetNotification();
//     bob->resetNotification();
//     charlie->resetNotification();

//     // Detach an observer and test again
//     city.detach(bob);

//     city.notify();  // Should only notify Alice and Charlie

//     if (alice->isNotified() && !bob->isNotified() && charlie->isNotified()) {
//         std::cout << "Test passed for detaching citizens.\n";
//     } else {
//         std::cout << "Test failed for detaching citizens.\n";
//     }

//     // Clean up
//     delete alice;
//     delete bob;
//     delete charlie;
// }
#include "Citizen.h"
#include "CollectTax.h"
#include "Industrial.h"
#include "Residential.h"
#include "Commercial.h"
#include "IncreaseTax.h"
#include "TaxCollector.h"
#include "City.h"

// void testCollectTax(){
//     Citizen* citizen = new Citizen("Tony", 1000);
//     Building* industrial = new Industrial();
//     CollectTax* collectTax = new CollectTax(citizen, industrial);
//     //Building* residential = new Residential();
//     //collectTax->addBuilding(residential);
//     //Building* commercial = new Commercial();
//     //collectTax->addBuilding(commercial);
//     collectTax->execute();
// }

// void testIncreaseTax(){
//     Citizen* citizen = new Citizen("Tony", 10000);
//     Command * incTax = new IncreaseTax(citizen);
//     incTax->execute(); 
// }

// void testTaxCollector(){
//     TaxCollector* taxCollector = new TaxCollector();
//     Citizen* citizen = new Citizen("Tony", 1000);
//     Citizen* citizen2 = new Citizen("Sherlock", 1000);
//     City * city = new City();
//     CollectTax* collectTax = new CollectTax(citizen, nullptr);
//     collectTax->addCitizen(citizen2);
//     collectTax->execute();
//     city->attach(citizen);
//     city->attach(citizen2);
//     for (int i = 0 ; i < city->citizens.size() ; i++){
//         taxCollector->visit(city->citizens[i]);
//     }
// }

// void testSatisfactionChecker(){
//     SatisfactionChecker* satisfactionChecker = new SatisfactionChecker();
//     Citizen* citizen = new Citizen("Tony", 1000);
//     Industrial* industrial = new Industrial();
//     satisfactionChecker->transportSatisfaction(citizen);
//     satisfactionChecker->buildingSatisfaction(citizen);
//     satisfactionChecker->citySatisfaction(citizen);
//     satisfactionChecker->citySatisfaction(industrial);
// }

// void testRent(){
//     Citizen* citizen = new Citizen("Tony", 1000);
//     Citizen* citizen2 = new Citizen("Sherlock", 1000);
//     Building* residential = new Residential();
//     residential->attach(citizen);
//     residential->attach(citizen2);
//     residential->collectRent();
// }

// // Function to test transport selection based on seat availability and maintenance status
// void testTransportSelection(Citizen& citizen, Transport& transport) {
//     std::cout << "\n=== " << citizen.getName() << " tries to choose " << transport.getType() << " transport ===\n";
//     citizen.chooseTransport(&transport);
// }

// // Function to test if citizens can afford the transport fee
// void testTransportAffordability(Citizen& citizen, Transport& transport) {
//     std::cout << "\n=== Testing affordability for " << citizen.getName() << " with income " << citizen.getIncome() << " ===\n";
//     if (citizen.getIncome() < transport.getFee()) {
//         std::cout << citizen.getName() << " cannot afford " << transport.getType() << " transport.\n";
//     } else {
//         std::cout << citizen.getName() << " can afford " << transport.getType() << " transport.\n";
//         citizen.chooseTransport(&transport);
//     }
// }

// // Function to test seat availability for a given transport
// void testSeatAvailability(Citizen& citizen, Transport& transport) {
//     std::cout << "\n=== Testing seat availability for " << citizen.getName() << " on " << transport.getType() << " ===\n";
//     if (transport.getAvailableSeats()>=1) {
//         std::cout << "Seats are available on " << transport.getType() << ".\n";
//         citizen.chooseTransport(&transport);
//     } else {
//         std::cout << "No seats available on " << transport.getType() << ".\n";
//     }
// }

// // Function to test citizen feedback and satisfaction level
// void testCitizenSatisfaction(Citizen& citizen) {
//     std::cout << "\n=== Testing satisfaction level for " << citizen.getName() << " ===\n";
//     citizen.leaveFeedback();
//     if (citizen.getSatisfactionTransport()>60) {
//         std::cout << citizen.getName() << " is satisfied with the transportation.\n";
//     } else {
//         std::cout << citizen.getName() << " is unsatisfied with the transportation.\n";
//     }
// }

// // Function to simulate citizen disembarking from transport
// void testDisembark(Citizen& citizen) {
//     std::cout << "\n=== " << citizen.getName() << " disembarks from transport ===\n";
//     citizen.disembark();
// }


// void testRunway() {
//     RunwayFactory runwayFactory;
//     runwayFactory.buildInfrastructure();
//     TransportInfrastructure* runway = runwayFactory.createInfrastructure();

//     std::cout << "Runway construction status: " 
//               << (static_cast<Runway*>(runway)->getConstructionStatus() ? "Under construction" : "Completed") << std::endl;

//     runway->build();

//     std::cout << "Runway construction status after building: " 
//               << (static_cast<Runway*>(runway)->getConstructionStatus() ? "Under construction" : "Completed") << std::endl;

//     std::cout << "Runway cost: " << runway->getCost() << std::endl;

//     delete runway;
// }

// void testRoad() {
//     RoadFactory roadFactory;
//     roadFactory.buildInfrastructure();
//     TransportInfrastructure* road = roadFactory.createInfrastructure();

//     std::cout << "Road construction status: " 
//               << (static_cast<Road*>(road)->getConstructionStatus() ? "Under construction" : "Completed") << std::endl;

//     // Build the road
//     road->build();

//     std::cout << "Road construction status after building: " 
//               << (static_cast<Road*>(road)->getConstructionStatus() ? "Under construction" : "Completed") << std::endl;

//     std::cout << "Road cost: " << road->getCost() << std::endl;

//     delete road;
// }

// void testRailway() {
//     RailwayFactory railwayFactory;
//     railwayFactory.buildInfrastructure();
//     TransportInfrastructure* railway = railwayFactory.createInfrastructure();

//     std::cout << "Railway construction status: " 
//               << (static_cast<Railway*>(railway)->getConstructionStatus() ? "Under construction" : "Completed") << std::endl;

//     railway->build();

//     std::cout << "Railway construction status after building: " 
//               << (static_cast<Railway*>(railway)->getConstructionStatus() ? "Under construction" : "Completed") << std::endl;


//     std::cout << "Railway cost: " << railway->getCost() << std::endl;

//     delete railway;
// }

// void testCustomInfrastructures() {
//     Runway customRunway(3.0, 0.1);
//     std::cout << "Custom Runway cost: " << customRunway.getCost() << std::endl;

//     Road customRoad(4, 2.0);
//     std::cout << "Custom Road cost: " << customRoad.getCost() << std::endl;

//     Railway customRailway(2.0, false);
//     std::cout << "Custom non-electrified Railway cost: " << customRailway.getCost() << std::endl;
// }

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

// ANSI color codes for styling the output
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define MAGENTA "\033[35m"
#define BLUE "\033[34m"

void bigTestingMain() {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed for random names and jobs

    // Create city
    City* ourCity = new City();
    std::cout << BOLD << BLUE << "\n========== City Simulation Start ==========\n" << RESET;

    // Create buildings
    ResidentialCreator residentialCreator;
    LandmarkCreator landmarkCreator;
    CommercialCreator commercialCreator;
    IndustrialCreator industrialCreator;

    // Create Residential Building
    Building* residentialBuilding = residentialCreator.createBuilding(
        "Residential Block", 30, 5000, 300, true, 1, true, 200, "Suburb"
    );
    std::cout << CYAN << "\n--- Residential Building ---" << RESET << std::endl;
    std::cout << "Type: " << residentialBuilding->getType() << std::endl;
    std::cout << GREEN << "Satisfaction: " << residentialBuilding->calculateSatisfaction() << RESET << std::endl;
    std::cout << YELLOW << "Economic Impact: " << residentialBuilding->calculateEconomicImpact() << RESET << std::endl;
    std::cout << RED << "Resource Consumption: " << residentialBuilding->calculateResourceConsumption() << RESET << std::endl;
    residentialBuilding->doImprovements();
    std::cout << GREEN << "Satisfaction after improvement: " << residentialBuilding->calculateSatisfaction() << RESET << std::endl;

    Building* residentialBuilding2 = residentialCreator.createBuilding(
        "Apartments", 30, 5000, 300, true, 1, true, 100, "Suburb"
    );
    std::cout << CYAN << "\n--- Residential Building ---" << RESET << std::endl;
    std::cout << "Type: " << residentialBuilding2->getType() << std::endl;
    std::cout << GREEN << "Satisfaction: " << residentialBuilding2->calculateSatisfaction() << RESET << std::endl;
    std::cout << YELLOW << "Economic Impact: " << residentialBuilding2->calculateEconomicImpact() << RESET << std::endl;
    std::cout << RED << "Resource Consumption: " << residentialBuilding2->calculateResourceConsumption() << RESET << std::endl;
    residentialBuilding2->doImprovements();
    std::cout << GREEN << "Satisfaction after improvement: " << residentialBuilding2->calculateSatisfaction() << RESET << std::endl;

    // Create Landmark Building
    Building* landmarkBuilding = landmarkCreator.createBuilding(
        "Statue of Liberty", 50, 100000, 500, true, 1, true, 50, "Suburb"
    );
    std::cout << MAGENTA << "\n--- Landmark Building ---" << RESET << std::endl;
    std::cout << "Type: " << landmarkBuilding->getType() << std::endl;
    std::cout << GREEN << "Satisfaction: " << landmarkBuilding->calculateSatisfaction() << RESET << std::endl;
    std::cout << YELLOW << "Economic Impact: " << landmarkBuilding->calculateEconomicImpact() << RESET << std::endl;
    std::cout << RED << "Resource Consumption: " << landmarkBuilding->calculateResourceConsumption() << RESET << std::endl;
    landmarkBuilding->doImprovements();
    std::cout << GREEN << "Satisfaction after improvement: " << landmarkBuilding->calculateSatisfaction() << RESET << std::endl;

    Building* landmarkBuilding2 = landmarkCreator.createBuilding(
        "Museum", 50, 100000, 500, true, 1, true, 150, "Suburb"
    );
    std::cout << MAGENTA << "\n--- Landmark Building ---" << RESET << std::endl;
    std::cout << "Type: " << landmarkBuilding2->getType() << std::endl;
    std::cout << GREEN << "Satisfaction: " << landmarkBuilding2->calculateSatisfaction() << RESET << std::endl;
    std::cout << YELLOW << "Economic Impact: " << landmarkBuilding2->calculateEconomicImpact() << RESET << std::endl;
    std::cout << RED << "Resource Consumption: " << landmarkBuilding2->calculateResourceConsumption() << RESET << std::endl;
    landmarkBuilding2->doImprovements();
    std::cout << GREEN << "Satisfaction after improvement: " << landmarkBuilding2->calculateSatisfaction() << RESET << std::endl;

    // Create Commercial Building
    Building* commercialBuilding = commercialCreator.createBuilding(
        "Mall", 20, 30000, 1000, true, 1, true, 1000, "Suburb"
    );
    std::cout << YELLOW << "\n--- Commercial Building ---" << RESET << std::endl;
    std::cout << "Type: " << commercialBuilding->getType() << std::endl;
    std::cout << GREEN << "Satisfaction: " << commercialBuilding->calculateSatisfaction() << RESET << std::endl;
    std::cout << YELLOW << "Economic Impact: " << commercialBuilding->calculateEconomicImpact() << RESET << std::endl;
    std::cout << RED << "Resource Consumption: " << commercialBuilding->calculateResourceConsumption() << RESET << std::endl;
    commercialBuilding->doImprovements();
    std::cout << GREEN << "Satisfaction after improvement: " << commercialBuilding->calculateSatisfaction() << RESET << std::endl;

    Building* commercialBuilding2 = commercialCreator.createBuilding(
        "Hardware Store", 20, 30000, 1000, true, 1, true, 100, "Suburb"
    );
    std::cout << YELLOW << "\n--- Commercial Building ---" << RESET << std::endl;
    std::cout << "Type: " << commercialBuilding2->getType() << std::endl;
    std::cout << GREEN << "Satisfaction: " << commercialBuilding2->calculateSatisfaction() << RESET << std::endl;
    std::cout << YELLOW << "Economic Impact: " << commercialBuilding2->calculateEconomicImpact() << RESET << std::endl;
    std::cout << RED << "Resource Consumption: " << commercialBuilding2->calculateResourceConsumption() << RESET << std::endl;
    commercialBuilding2->doImprovements();
    std::cout << GREEN << "Satisfaction after improvement: " << commercialBuilding2->calculateSatisfaction() << RESET << std::endl;

    // Create Industrial Building
    Building* industrialBuilding = industrialCreator.createBuilding(
        "Hardware Factory", 10, 20000, 2000, true, 1, true, 400, "Industrial"
    );
    std::cout << RED << "\n--- Industrial Building ---" << RESET << std::endl;
    std::cout << "Type: " << industrialBuilding->getType() << std::endl;
    std::cout << GREEN << "Satisfaction: " << industrialBuilding->calculateSatisfaction() << RESET << std::endl;
    std::cout << YELLOW << "Economic Impact: " << industrialBuilding->calculateEconomicImpact() << RESET << std::endl;
    std::cout << RED << "Resource Consumption: " << industrialBuilding->calculateResourceConsumption() << RESET << std::endl;
    industrialBuilding->doImprovements();
    std::cout << GREEN << "Satisfaction after improvement: " << industrialBuilding->calculateSatisfaction() << RESET << std::endl;

    Building* industrialBuilding2 = industrialCreator.createBuilding(
        "Coca-Cola Factory", 10, 20000, 2000, true, 1, true, 400, "Industrial"
    );
    std::cout << RED << "\n--- Industrial Building ---" << RESET << std::endl;
    std::cout << "Type: " << industrialBuilding2->getType() << std::endl;
    std::cout << GREEN << "Satisfaction: " << industrialBuilding2->calculateSatisfaction() << RESET << std::endl;
    std::cout << YELLOW << "Economic Impact: " << industrialBuilding2->calculateEconomicImpact() << RESET << std::endl;
    std::cout << RED << "Resource Consumption: " << industrialBuilding2->calculateResourceConsumption() << RESET << std::endl;
    industrialBuilding2->doImprovements();
    std::cout << GREEN << "Satisfaction after improvement: " << industrialBuilding2->calculateSatisfaction() << RESET << std::endl;

    // Create utilities
    WaterFactory waterFactory;
    Utilities* waterUtility = waterFactory.createUtility();
    std::cout << CYAN << "\n--- Water System ---" << RESET << std::endl;
    waterUtility->displayInfo();
    waterUtility->generateResources();
    waterUtility->requestMaintenance(101);

    Utilities* waterUtility2 = waterFactory.createUtility();
    std::cout << CYAN << "\n--- Water System 2 ---" << RESET << std::endl;
    waterUtility2->displayInfo();
    waterUtility2->generateResources();
    waterUtility2->requestMaintenance(150);

    WasteFactory wasteFactory;
    Utilities* wasteUtility = wasteFactory.createUtility();
    std::cout << MAGENTA << "\n--- Waste System ---" << RESET << std::endl;
    wasteUtility->displayInfo();
    wasteUtility->generateResources();
    wasteUtility->requestMaintenance(102);

    Utilities* wasteUtility2 = wasteFactory.createUtility();
    std::cout << MAGENTA << "\n--- Waste System 2 ---" << RESET << std::endl;
    wasteUtility2->displayInfo();
    wasteUtility2->generateResources();
    wasteUtility2->requestMaintenance(151);

    SewageFactory sewageFactory;
    Utilities* sewageUtility = sewageFactory.createUtility();
    std::cout << YELLOW << "\n--- Sewage System ---" << RESET << std::endl;
    sewageUtility->displayInfo();
    sewageUtility->generateResources();
    sewageUtility->requestMaintenance(103);

    Utilities* sewageUtility2 = sewageFactory.createUtility();
    std::cout << YELLOW << "\n--- Sewage System 2 ---" << RESET << std::endl;
    sewageUtility2->displayInfo();
    sewageUtility2->generateResources();
    sewageUtility2->requestMaintenance(152);

    PowerPlantFactory powerPlantFactory;
    Utilities* powerPlantUtility = powerPlantFactory.createUtility();
    std::cout << GREEN << "\n--- Power Plant ---" << RESET << std::endl;
    powerPlantUtility->displayInfo();
    powerPlantUtility->generateResources();
    powerPlantUtility->requestMaintenance(104);

    Utilities* powerPlantUtility2 = powerPlantFactory.createUtility();
    std::cout << GREEN << "\n--- Power Plant 2 ---" << RESET << std::endl;
    powerPlantUtility2->displayInfo();
    powerPlantUtility2->generateResources();
    powerPlantUtility2->requestMaintenance(153);

    // Build transport infrastructure
    std::cout << BOLD << BLUE << "\n--- Creating Transport Infrastructure ---\n" << RESET;
    RoadFactory roadFactory;
    RailwayFactory railwayFactory;
    RunwayFactory runwayFactory;
    TransportInfrastructure* road = roadFactory.createInfrastructure(2, 10.0);
    road->build();
    TransportInfrastructure* railway = railwayFactory.createInfrastructure(20, true);
    railway->build();
    TransportInfrastructure* runway = runwayFactory.createInfrastructure(1.0, 0.5);
    runway->build();
    TransportInfrastructure* road2 = roadFactory.createInfrastructure(4, 100.0);
    road2->build();
    TransportInfrastructure* railway2 = railwayFactory.createInfrastructure(30, false);
    railway2->build();
    TransportInfrastructure* runway2 = runwayFactory.createInfrastructure(2.0, 1);
    runway2->build();
    TransportInfrastructure* road3 = roadFactory.createInfrastructure(1, 15.0);
    road3->build();
    TransportInfrastructure* railway3 = railwayFactory.createInfrastructure(45, true);
    railway3->build();
    TransportInfrastructure* runway3 = runwayFactory.createInfrastructure(1.0, 0.7);
    runway3->build();

    // Create citizens
    Citizen c;
    std::cout << BOLD << BLUE << "\n--- Creating Citizens ---\n" << RESET;
    for (int i = 0; i < 30; i++) {
        std::string name = c.citizenNames[std::rand() % 200];
        int income = 30000 + std::rand() % 70000; // Income range from 30,000 to 100,000
        double propertyValue = 50000 + std::rand() % 950000; // Property value from 50,000 to 1,000,000
        std::string job = c.jobTitles[std::rand() % 200];
        Citizen* newCitizen = new Citizen(name, income, propertyValue, job);
        std::cout << CYAN << "Citizen " << (i + 1) << ": " << RESET 
                  << name << " with job " << job << ", with income $" << income 
                  << " and property value $" << std::fixed << std::setprecision(2) << propertyValue << std::endl;
        residentialBuilding->populateBuilding();
    }

    // Create government
    Government government(0.15, 0.02); // 15% income tax, 2% property tax

    // Create departments and add them to the government
    Budget* budgetDept = new Budget("Budget Department", 10000.0);
    Policies* policiesDept = new Policies("Policies Department");
    Services* servicesDept = new Services("Services Department", 10, 5, 3);
    Tax* taxDept = new Tax("Tax Department", 0.15);

    std::cout << CYAN << "\n--- Budget Department Created ---" << RESET << std::endl;
    government.add(budgetDept);
    budgetDept->operate();
    std::cout << MAGENTA << "\n--- Policies Department Created ---" << RESET << std::endl;
    government.add(policiesDept);
    policiesDept->operate();
    std::cout << YELLOW << "\n--- Services Department Created ---" << RESET << std::endl;
    government.add(servicesDept);
    servicesDept->operate();
    std::cout << RED << "\n--- Tax Department Created ---" << RESET << std::endl;
    government.add(taxDept);
    taxDept->operate();

    // Add policies
    std::cout << CYAN << "\n--- Add Policies ---" << RESET << std::endl;
    policiesDept->addPolicy("Environmental Protection");
    policiesDept->addPolicy("Healthcare Reform");

    // Add service programs
    std::cout << CYAN << "\n--- Add Services ---" << RESET << std::endl;
    servicesDept->addServiceProgram("Emergency Health Services");
    servicesDept->addServiceProgram("Education Outreach");

    // Example of Government operating and managing departments
    std::cout << MAGENTA << "\n--- Government operates ---" << RESET << std::endl;
    government.operate();

    //Below can be used later on
    // // Simulate tax collection and allocation
    // taxDept->collectTaxes(20000.0);  // Collecting taxes based on revenue
    // government.collectTax();           // Government records collected taxes
    // government.allocateTax();          // Allocate tax revenue to budget

    // // Display the current status of each department
    // budgetDept->operate();
    // policiesDept->operate();
    // servicesDept->operate();
    // taxDept->operate();

    // // Notify citizens about tax changes
    // government.notifyCitizensTaxIncreased();

    // Clean up
    delete budgetDept;
    delete policiesDept;
    delete servicesDept;
    delete taxDept;
    delete waterUtility;
    delete wasteUtility;
    delete sewageUtility;
    delete powerPlantUtility;
    delete residentialBuilding;
    delete landmarkBuilding;
    delete commercialBuilding;
    delete industrialBuilding;

    std::cout << BOLD << BLUE << "\n========== City Simulation End ==========\n" << RESET;
}

int main() {
    bigTestingMain();
    //testFactoryUtilities();
    //testComposite();
    //factoryBuildings();
    // testCOR();
    //testBuildingObserver();
    //testCityObserver();
    //testRunway();
    //testRoad();
    //testRailway();
    //testCustomInfrastructures();
    //Public bus("Bus",30,5, 20); // Bus with 5 seats and a fee of 20
    //Train train("Train1",10,10, 15,3); // Train with 10 seats and a fee of 15
    //Air air("Plane1",20,2, 100,4); // Air transport with 2 seats and a fee of 100

    // Create citizens with different incomes
    //Citizen alice("Alice", 30,2);
    //Citizen bob("Bob", 10,0);
    //Citizen charlie("Charlie", 200,15);

    // Test various functionalities using individual functions

    // Test transport selection
    //testTransportSelection(alice, bus);
    //testTransportSelection(bob, bus); // Bob can't afford

    // Test transport affordability
    //testTransportAffordability(bob, train);
    //testTransportAffordability(charlie, air);

    // Test seat availability for bus and air transport
    //testSeatAvailability(alice, air); // Alice should be able to select the air transport
    //testSeatAvailability(charlie, air); // Seats might be full if Alice took the last seat

    // Test disembarking and choosing new transport
    //testDisembark(alice);
    //testTransportSelection(alice, air); // Alice tries air transport again after disembarking

    // Test citizen satisfaction feedback and satisfaction check
    //testCitizenSatisfaction(alice);
    //testCitizenSatisfaction(bob);
    //testCitizenSatisfaction(charlie);
    //testCollectTax();
    //testIncreaseTax();
    //testTaxCollector();
    //testSatisfactionChecker();
    // testRent();

    return 0;
}

