#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <ctime>
#include <algorithm>

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

#include "Citizen.h"
#include "CollectTax.h"
#include "Industrial.h"
#include "Residential.h"
#include "Commercial.h"
#include "IncreaseTax.h"
#include "TaxCollector.h"
#include "City.h"
#include "ResourceManagerment.h"

using namespace std;

void testSingleton() {
    // Get the singleton instance
    ResourceManagement& resourceManager = ResourceManagement::getInstance();

    // Step 1: Create initial resources
    resourceManager.createResources();

    // Step 2: Update materials, energy, water, and budget
    resourceManager.updateMaterials(200, 100, 50);   // Adding resources
    resourceManager.updateEnergy(300);               // Increase energy
    resourceManager.updateWater(200);                // Increase water
    resourceManager.updateBudget(1500.0);            // Increase budget

    // Step 3: Display resource status after updates
    std::cout << "\nAfter updates:" << std::endl;
    resourceManager.displayResourceStatus();

    // Step 4: Supply resources to utilities
    resourceManager.supplyResources();

    // Step 5: Attempt to allocate some budget
    double allocationAmount = 800.0;
    if (resourceManager.allocateBudget(allocationAmount)) {
        std::cout << "\nBudget allocated successfully: " << allocationAmount << std::endl;
    } else {
        std::cout << "\nFailed to allocate budget: " << allocationAmount << std::endl;
    }

    // Step 6: Final display of resource status
    std::cout << "\nFinal Resource Status:" << std::endl;
    resourceManager.displayResourceStatus();
}

// ANSI color codes for styling the output
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define MAGENTA "\033[35m"
#define BLUE "\033[34m"


//**********INITIAL SETUP**********/
void pauseForUser() {
    std::cout << BOLD << BLUE << "\nPress enter to continue..." << RESET;
    std::cin.get();
}

void createInitialBuildings(City* city) {
    std::cout << CYAN << "\nThe wizard raises their hands to the sky, channeling the powers of creation...\n" << RESET;
    
    // Create Residential Building
    Residential* residentialBuilding = new Residential(
        "Wizard’s Haven", 30, 5000, 300, true, 1, true, 100, "Residential District"
    );
    city->addBuilding(residentialBuilding);
    std::cout << GREEN << "A Residential Building rises: " << residentialBuilding->getType() << "\n"
              << "Located in: Residential District\n" << RESET;
    

    // Create Commercial Building
    Commercial* commercialBuilding = new Commercial(
        "Potion Emporium", 20, 30000, 1000, true, 1, true, 5, "Market Square"
    );
    city->addBuilding(commercialBuilding);
    std::cout << YELLOW << "A Commercial Building appears: " << commercialBuilding->getType() << "\n"
              << "Located in: Market Square\n" << RESET;
   

    // Create Industrial Building
    Industrial* industrialBuilding = new Industrial(
        "Alchemy Workshop", 10, 20000, 2000, true, 1, true, 3, "Industrial Zone"
    );
    city->addBuilding(industrialBuilding);
    std::cout << RED << "An Industrial Building is forged: " << industrialBuilding->getType() << "\n"
              << "Located in: Industrial Zone\n" << RESET;

    // Create Landmark Building
    Landmark* landmarkBuilding = new Landmark(
        "Mystic Fountain", 50, 100000, 500, true, 1, true, 100, "Central Plaza"
    );
    city->addBuilding(landmarkBuilding);
    std::cout << MAGENTA << "A Landmark springs forth: " << landmarkBuilding->getType() << "\n"
              << "Located in: Central Plaza\n" << RESET;
    pauseForUser();
}

void createAndAssignUtilities(City* city) {
    std::cout << CYAN << "\nWith a wave of the wizard's hand, the city's essential utilities begin to materialize...\n" << RESET;

    // Create Water Utility
    WaterFactory waterFactory;
    Utilities* waterUtility = waterFactory.createUtility();
    city->addUtility(waterUtility);
    std::cout << GREEN << "\nWater Utility Created:\n" << RESET;
    waterUtility->displayInfo();
    

    // Create Waste Management Utility
    WasteFactory wasteFactory;
    Utilities* wasteUtility = wasteFactory.createUtility();
    city->addUtility(wasteUtility);
    std::cout << MAGENTA << "\nWaste Management Utility Created:\n" << RESET;
    wasteUtility->displayInfo();
    

    // Create Sewage Utility
    SewageFactory sewageFactory;
    Utilities* sewageUtility = sewageFactory.createUtility();
    city->addUtility(sewageUtility);
    std::cout << YELLOW << "\nSewage Utility Created:\n" << RESET;
    sewageUtility->displayInfo();
    

    // Create Power Plant Utility
    PowerPlantFactory powerPlantFactory;
    Utilities* powerPlantUtility = powerPlantFactory.createUtility();
    city->addUtility(powerPlantUtility);
    std::cout << BLUE << "\nPower Plant Utility Created:\n" << RESET;
    powerPlantUtility->displayInfo();
    pauseForUser();

    // Assign utilities to buildings
    std::cout << CYAN << "\nThe wizard channels the utilities to serve each building in the city...\n" << RESET;
    for (Building* building : city->listBuildings()) {
        building->addUtility(waterUtility);
        building->addUtility(wasteUtility);
        building->addUtility(sewageUtility);
        building->addUtility(powerPlantUtility);

        std::cout << GREEN << "Utilities have been assigned to " << building->getType() << "\n" << RESET;
        
    }
    pauseForUser();
}

void createAndAssignTransport(City* city) {
    std::cout << CYAN << BOLD << "\nThe wizard conjures essential transport infrastructure for the city...\n" << RESET;

    RoadFactory roadFactory;
    RailwayFactory railwayFactory;
    RunwayFactory runwayFactory;

    // Create a road
    TransportInfrastructure* road = roadFactory.createInfrastructure(4, 20.0);
    road->build();
    city->addInfrastructure(road);
    std::cout << GREEN << "Road created with 4 lanes and length 20km.\n" << RESET;
    

    // Create a railway
    TransportInfrastructure* railway = railwayFactory.createInfrastructure(15, true);
    railway->build();
    city->addInfrastructure(railway);
    std::cout << YELLOW << "Electrified railway created with length 15km.\n" << RESET;
    

    // Create a runway
    TransportInfrastructure* runway = runwayFactory.createInfrastructure(3.0, 0.75);
    runway->build();
    city->addInfrastructure(runway);
    std::cout << BLUE << "Runway created with length 3.0km and width 0.75km.\n" << RESET;
    pauseForUser();
}

void setupGovernment(City* city) {
    std::cout << MAGENTA << BOLD << "\nThe wizard forms a government to lead the city...\n" << RESET;

    Government* government = new Government(0.15, 0.02);  // 15% income tax, 2% property tax

    // Create departments
    Budget* budgetDept = new Budget("Budget Department", 10000.0);
    Policies* policiesDept = new Policies("Policies Department");
    Services* servicesDept = new Services("Services Department", 10, 5, 3);
    Tax* taxDept = new Tax("Tax Department", 0.15);

    // Add departments to government
    government->add(budgetDept);
    std::cout << GREEN << "Budget Department created and added to the government.\n" << RESET;
    

    government->add(policiesDept);
    std::cout << YELLOW << "Policies Department created and added to the government.\n" << RESET;
    

    government->add(servicesDept);
    std::cout << CYAN << "Services Department created and added to the government.\n" << RESET;
   

    government->add(taxDept);
    std::cout << RED << "Tax Department created and added to the government.\n" << RESET;
    

    // Assign the government to the city
    city->setGovernment(government);
    std::cout << MAGENTA << BOLD << "\nGovernment and departments successfully established for the city.\n" << RESET;
    pauseForUser();
}

void createAndAssignCitizens(City* city) {
    std::cout << CYAN << "\nThe wizard decides to populate the city with its first citizens...\n" << RESET;

    // Look for an existing residential building in the city
    Residential* residentialBuilding = nullptr;
    for (Building* building : city->listBuildings()) {
        residentialBuilding = dynamic_cast<Residential*>(building);
        if (residentialBuilding) {
            break;  // Found a residential building, so break out of the loop
        }
    }

    if (!residentialBuilding) {
        std::cout << RED << "No residential building found. Citizens cannot be assigned.\n" << RESET;
        return;
    }

    Citizen prototypeCitizen; // To use predefined names and job titles
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed for randomness

    // Create and assign 3 citizens to the residential building
    for (int i = 0; i < 3; ++i) {
        std::string name = prototypeCitizen.citizenNames[std::rand() % prototypeCitizen.citizenNames.size()];
        int income = 30000 + std::rand() % 70000; // Random income between 30,000 and 100,000
        double propertyValue = 50000 + std::rand() % 950000; // Property value between 50,000 and 1,000,000
        std::string job = prototypeCitizen.jobTitles[std::rand() % prototypeCitizen.jobTitles.size()];

        Citizen* newCitizen = new Citizen(name, income, propertyValue, job);

        std::cout << GREEN << "Citizen created: " << RESET << name 
                  << ", Job: " << job << ", Income: $" << income 
                  << ", Property Value: $" << std::fixed << std::setprecision(2) << propertyValue << "\n";

        // Try to assign the citizen to the residential building
        if (residentialBuilding->populateBuilding()) {
            city->attach(newCitizen); // Add citizen to city’s observer list
            std::cout << BLUE << name << " has moved into " << residentialBuilding->getType() << "\n" << RESET;
        } else {
            std::cout << RED << "No more space in the residential building for " << name << ".\n" << RESET;
            delete newCitizen; // Delete citizen if not assigned
        }

         // Pause for user to proceed to next citizen
    }
    pauseForUser();
}
//**********INITIAL SETUP**********/


//**********MAIN MENU**********/
void showMainMenu() {
    std::cout << BOLD << BLUE << "\n========== Main Menu ==========\n" << RESET;
    std::cout << GREEN << "1. Manage Government\n";
    std::cout << "2. Build and Manage Buildings\n";
    std::cout << "3. Manage Citizens\n";
    std::cout << "4. Provide Utilities\n";
    std::cout << "5. Manage Transport\n";
    std::cout << "6. Show City Status\n";
    std::cout << "7. Change city population\n";
    std::cout << "8. Exit Simulation\n" << RESET;
    std::cout << "Please select an option: ";
}
//**********MAIN MENU**********/



//**********1. MANAGE GOVERNMENT OPTION**********/
void manageTaxDepartment(Tax* taxDept, Budget* budgetDept) { // Pass Budget pointer as parameter
    bool managingTax = true;
    while (managingTax) {
        std::cout << "\n" << CYAN << "Manage Tax Department\n" << RESET;
        std::cout << "1. Set Tax Rate\n";
        std::cout << "2. Collect Taxes\n";
        std::cout << "3. View Total Revenue\n";
        std::cout << "4. Back to Government Menu\n";
        std::cout << "Select an option: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear input buffer

        switch (choice) {
            case 1: {
                float newRate;
                std::cout << "Enter new tax rate (as a decimal, e.g., 0.15 for 15%): ";
                std::cin >> newRate;
                taxDept->setTaxRate(newRate);
                std::cout << GREEN << "Tax rate set to " << newRate << "\n" << RESET;
                break;
            }
            case 2: {
                double revenue;
                std::cout << "Enter total revenue to calculate taxes: ";
                std::cin >> revenue;
                double collectedTaxes = taxDept->collectTaxes(revenue); // Collect taxes
                budgetDept->addCollectedTaxes(collectedTaxes); // Add collected taxes to budget
                break;
            }
            case 3:
                std::cout << "Total Revenue: " << taxDept->getTotalRevenue() << "\n";
                break;
            case 4:
                managingTax = false;
                break;
            default:
                std::cout << RED << "Invalid option.\n" << RESET;
        }
    }
}


void manageBudgetDepartment(Budget* budgetDept) {
    bool managingBudget = true;
    while (managingBudget) {
        std::cout << "\n" << CYAN << "Manage Budget Department\n" << RESET;
        std::cout << "1. Allocate Funds\n";
        std::cout << "2. View Budget Details\n";
        std::cout << "3. Back to Government Menu\n";
        std::cout << "Select an option: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear input buffer

        switch (choice) {
            case 1: {
                double amount;
                std::cout << "Enter amount to allocate: ";
                std::cin >> amount;
                budgetDept->allocateFunds(amount);
                break;
            }
            case 2:
                budgetDept->operate();  // Displays budget details
                break;
            case 3:
                managingBudget = false;
                break;
            default:
                std::cout << RED << "Invalid option.\n" << RESET;
        }
    }
}


void managePoliciesDepartment(Policies* policiesDept) {
    bool managingPolicies = true;
    while (managingPolicies) {
        std::cout << "\n" << CYAN << "Manage Policies Department\n" << RESET;
        std::cout << "1. Add Policy\n";
        std::cout << "2. Remove Policy\n";
        std::cout << "3. View Active Policies\n";
        std::cout << "4. Back to Government Menu\n";
        std::cout << "Select an option: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear input buffer

        switch (choice) {
            case 1: {
                std::string policy;
                std::cout << "Enter policy to add: ";
                std::getline(std::cin, policy);
                policiesDept->addPolicy(policy);
                break;
            }
            case 2: {
                std::string policy;
                std::cout << "Enter policy to remove: ";
                std::getline(std::cin, policy);
                policiesDept->removePolicy(policy);
                break;
            }
            case 3:
                policiesDept->operate();  // Displays active policies
                break;
            case 4:
                managingPolicies = false;
                break;
            default:
                std::cout << RED << "Invalid option.\n" << RESET;
        }
    }
}


void manageServicesDepartment(Services* servicesDept) {
    bool managingServices = true;
    while (managingServices) {
        std::cout << "\n" << CYAN << "Manage Services Department\n" << RESET;
        std::cout << "1. Add Service Program\n";
        std::cout << "2. View Services\n";
        std::cout << "3. Back to Government Menu\n";
        std::cout << "Select an option: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear input buffer

        switch (choice) {
            case 1: {
                std::string program;
                std::cout << "Enter service program to add: ";
                std::getline(std::cin, program);
                servicesDept->addServiceProgram(program);
                break;
            }
            case 2:
                servicesDept->operate();  // Displays service details
                break;
            case 3:
                managingServices = false;
                break;
            default:
                std::cout << RED << "Invalid option.\n" << RESET;
        }
    }
}

// Function to handle the government management menu
void manageGovernment(City* city) {
    bool managingGovernment = true;
    while (managingGovernment) {
        std::cout << "\n" << CYAN << "Manage Government\n" << RESET;
        std::cout << "1. Tax Department\n";
        std::cout << "2. Budget Department\n";
        std::cout << "3. Policies Department\n";
        std::cout << "4. Services Department\n";
        std::cout << "5. Return to Main Menu\n";
        std::cout << "Select an option: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear input buffer

        switch (choice) {
            case 1: {
                Tax* taxDept = city->getGovernment()->getTaxDepartment();
                Budget* budgetDept = city->getGovernment()->getBudgetDepartment();
                if (taxDept && budgetDept) {
                    manageTaxDepartment(taxDept, budgetDept);
                } else {
                    std::cout << "Failed to access Tax or Budget Department.\n";
                }
                break;
            }
            case 2: {
                Budget* budgetDept = city->getGovernment()->getBudgetDepartment();
                if (budgetDept) {
                    manageBudgetDepartment(budgetDept);
                } else {
                    std::cout << "Failed to access Budget Department.\n";
                }
                break;
            }
            // ... other cases remain the same
            case 5:
                managingGovernment = false;
                break;
            default:
                std::cout << RED << "Invalid option. Please select again.\n" << RESET;
        }
    }
}

//**********1. MANAGE GOVERNMENT OPTION**********/


//**********2. MANAGE BUILDINGS OPTION**********/
void buildNewBuilding(City* city) {
    int buildingType;
    std::string buildingName;
    double buildingCost = 0;  // Track the cost of the building

    std::cout << "Select the type of building to construct:\n";
    std::cout << "1. Residential\n";
    std::cout << "2. Commercial\n";
    std::cout << "3. Industrial\n";
    std::cout << "4. Landmark\n";
    std::cout << "Select an option: ";
    std::cin >> buildingType;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear input buffer

    // Prompt for the building name
    std::cout << "Enter the name of the new building: ";
    std::getline(std::cin, buildingName);

    Building* newBuilding = nullptr;

    // Use the appropriate creator based on the building type selected
    switch (buildingType) {
        case 1: {
            ResidentialCreator residentialCreator;
            buildingCost = 50;  // Example cost for a residential building
            newBuilding = residentialCreator.createBuilding(buildingName, 50, 10000, 500, true, 1, true, 10, "Residential District");
            break;
        }
        case 2: {
            CommercialCreator commercialCreator;
            buildingCost = 100;  // Example cost for a commercial building
            newBuilding = commercialCreator.createBuilding(buildingName, 40, 30000, 1000, true, 1, true, 15, "Commercial District");
            break;
        }
        case 3: {
            IndustrialCreator industrialCreator;
            buildingCost = 150;  // Example cost for an industrial building
            newBuilding = industrialCreator.createBuilding(buildingName, 30, 20000, 2000, true, 1, true, 20, "Industrial Zone");
            break;
        }
        case 4: {
            LandmarkCreator landmarkCreator;
            buildingCost = 200;  // Example cost for a landmark building
            newBuilding = landmarkCreator.createBuilding(buildingName, 80, 50000, 100, true, 1, true, 0, "City Center");
            break;
        }
        default:
            std::cout << "Invalid option. Returning to main menu.\n";
            return;
    }

    // Check if budget can cover the cost
    Budget* budgetDept = dynamic_cast<Budget*>(city->getGovernment()->getBudgetDepartment());
    if (budgetDept && budgetDept->getAvailableBudget() >= buildingCost) {
        budgetDept->allocateFunds(buildingCost);  // Deduct cost from the budget

        if (newBuilding) {
            city->addBuilding(newBuilding);
            std::cout << "Building added to the city: " << buildingName << "\n";
            std::cout << "Building constructed: " << newBuilding->getType() << "\n";
        }
    } else {
        std::cout << "Insufficient budget to construct this building.\n";
        delete newBuilding;  // Clean up the allocated memory
    }
}



void inspectBuilding(City* city) {
    int buildingIndex;
    const auto& buildings = city->listBuildings();

    if (buildings.empty()) {
        std::cout << RED << "No buildings in the city.\n" << RESET;
        return;
    }

    std::cout << "Select a building to inspect:\n";
    for (size_t i = 0; i < buildings.size(); ++i) {
        std::cout << i + 1 << ". " << buildings[i]->getType() << "\n";
    }
    std::cin >> buildingIndex;

    if (buildingIndex < 1 || buildingIndex > buildings.size()) {
        std::cout << RED << "Invalid selection.\n" << RESET;
        return;
    }

    buildings[buildingIndex - 1]->get();  // Display details of selected building
}


void improveBuilding(City* city) {
    int buildingIndex;
    const auto& buildings = city->listBuildings();

    if (buildings.empty()) {
        std::cout << RED << "No buildings in the city.\n" << RESET;
        return;
    }

    std::cout << "Select a building to improve:\n";
    for (size_t i = 0; i < buildings.size(); ++i) {
        std::cout << i + 1 << ". " << buildings[i]->getType() << "\n";
    }
    std::cin >> buildingIndex;

    if (buildingIndex < 1 || buildingIndex > buildings.size()) {
        std::cout << RED << "Invalid selection.\n" << RESET;
        return;
    }

    buildings[buildingIndex - 1]->doImprovements();
}


void removeBuilding(City* city) {
    int buildingIndex;
    auto& buildings = city->listBuildings();  // Non-const to allow modifications

    if (buildings.empty()) {
        std::cout << RED << "No buildings to remove.\n" << RESET;
        return;
    }

    std::cout << "Select a building to remove:\n";
    for (size_t i = 0; i < buildings.size(); ++i) {
        std::cout << i + 1 << ". " << buildings[i]->getType() << "\n";
    }
    std::cin >> buildingIndex;

    if (buildingIndex < 1 || buildingIndex > buildings.size()) {
        std::cout << RED << "Invalid selection.\n" << RESET;
        return;
    }

    Building* building = buildings[buildingIndex - 1];

    // Check if the building is residential and occupied
    Residential* residentialBuilding = dynamic_cast<Residential*>(building);
    if (residentialBuilding && residentialBuilding->getOccupantCount() > 0) {
        std::cout << RED << "Cannot remove " << building->getType() 
                  << " because it has residents. Please relocate them first.\n" << RESET;
        return;
    }

    // Proceed with deletion if no residents
    delete building;  // Free memory
    buildings.erase(buildings.begin() + buildingIndex - 1);
    std::cout << GREEN << "Building removed from the city.\n" << RESET;
}



void viewAllBuildings(City* city) {
    const auto& buildings = city->listBuildings();

    if (buildings.empty()) {
        std::cout << RED << "No buildings in the city.\n" << RESET;
        return;
    }

    std::cout << CYAN << "\n=== All Buildings in the City ===\n" << RESET;
    for (const auto& building : buildings) {
        std::cout << "Building: " << building->getType()
                  << ", Satisfaction: " << building->calculateSatisfaction()
                  << ", Economic Impact: " << building->calculateEconomicImpact() << "\n";
    }
    std::cout << MAGENTA << "=============================\n" << RESET;
}



void manageBuildings(City* city) {
    bool buildingManagement = true;
    while (buildingManagement) {
        std::cout << "\n" << CYAN << "Manage Buildings\n" << RESET;
        std::cout << "1. Build New Building\n";
        std::cout << "2. Inspect Building\n";
        std::cout << "3. Improve Building\n";
        std::cout << "4. Remove Building\n";
        std::cout << "5. View All Buildings\n";
        std::cout << "6. Back to Main Menu\n";
        std::cout << "Select an option: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear input buffer

        switch (choice) {
            case 1:
                buildNewBuilding(city);
                break;
            case 2:
                inspectBuilding(city);
                break;
            case 3:
                improveBuilding(city);
                break;
            case 4:
                removeBuilding(city);
                break;
            case 5:
                viewAllBuildings(city);
                break;
            case 6:
                buildingManagement = false;
                break;
            default:
                std::cout << RED << "Invalid option. Please select again.\n" << RESET;
        }
    }
}
//**********2. MANAGE BUILDINGS OPTION**********/



//**********3. MANAGE CITIZENS OPTION**********/
void addCustomCitizen(City* city) {
    if (city->getTotalPopulation() >= 200) {
        std::cout << RED << "Maximum population reached. Cannot add more citizens.\n" << RESET;
        return;
    }

    std::string name, job;
    int income;
    double propertyValue;

    std::cout << "Enter the name of the new citizen: ";
    std::getline(std::cin, name);

    std::cout << "Enter the job of the new citizen: ";
    std::getline(std::cin, job);

    std::cout << "Enter the income of the new citizen: ";
    std::cin >> income;

    std::cout << "Enter the property value owned by the new citizen: ";
    std::cin >> propertyValue;

    Citizen* newCitizen = new Citizen(name, income, propertyValue, job);

    // Check if there's space in a residential building
    Residential* residentialBuilding = nullptr;
    for (Building* building : city->listBuildings()) {
        residentialBuilding = dynamic_cast<Residential*>(building);
        if (residentialBuilding && residentialBuilding->populateBuilding()) {
            city->attach(newCitizen);
            std::cout << GREEN << "Citizen " << name << " has moved into " 
                      << residentialBuilding->getType() << "\n" << RESET;
            return;
        }
    }

    std::cout << RED << "No residential building with available capacity. Consider building more housing.\n" << RESET;
    delete newCitizen; // Delete citizen if not assigned
}


void addMultipleCitizens(City* city) {
    int numberOfCitizens;
    std::cout << "Enter the number of citizens to add (1 to 10): ";
    std::cin >> numberOfCitizens;

    if (numberOfCitizens < 1 || numberOfCitizens > 10) {
        std::cout << RED << "Invalid number. Please enter a value between 1 and 10.\n" << RESET;
        return;
    }

    int currentPopulation = city->getTotalPopulation();
    if (currentPopulation + numberOfCitizens > 200) {
        std::cout << RED << "Adding " << numberOfCitizens << " citizens would exceed the maximum population limit of 200.\n" << RESET;
        return;
    }

    // Check available capacity across residential buildings
    int availableCapacity = city->getAvailableHousingCapacity();
    if (numberOfCitizens > availableCapacity) {
        std::cout << RED << "Not enough housing capacity for " << numberOfCitizens 
                  << " citizens. Consider building more buildings before creating more citizens.\n" << RESET;
        return;
    }

    Citizen prototypeCitizen; // To use predefined names and job titles
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed for randomness

    for (int i = 0; i < numberOfCitizens; ++i) {
        std::string name = prototypeCitizen.citizenNames[std::rand() % prototypeCitizen.citizenNames.size()];
        int income = 30000 + std::rand() % 70000; // Random income between 30,000 and 100,000
        double propertyValue = 50000 + std::rand() % 950000; // Property value between 50,000 and 1,000,000
        std::string job = prototypeCitizen.jobTitles[std::rand() % prototypeCitizen.jobTitles.size()];

        Citizen* newCitizen = new Citizen(name, income, propertyValue, job);

        // Try to assign the citizen to a residential building
        bool assigned = false;
        for (Building* building : city->listBuildings()) {
            Residential* residentialBuilding = dynamic_cast<Residential*>(building);
            if (residentialBuilding && residentialBuilding->populateBuilding()) {
                city->attach(newCitizen); // Add citizen to city’s observer list
                std::cout << BLUE << name << " has moved into " << residentialBuilding->getType() << "\n" << RESET;
                assigned = true;
                break;
            }
        }

        if (!assigned) {
            std::cout << RED << "No more space in available residential buildings for " << name << ".\n" << RESET;
            delete newCitizen; // Delete citizen if not assigned
        }
    }
}

void viewCitizenInformation(City* city) {
    const auto& citizens = city->getCitizens();

    if (citizens.empty()) {
        std::cout << RED << "No citizens available.\n" << RESET;
        return;
    }

    std::cout << "Select a citizen to view details:\n";
    for (size_t i = 0; i < citizens.size(); ++i) {
        std::cout << i + 1 << ". " << citizens[i]->getName() << "\n";
    }
    int citizenIndex;
    std::cin >> citizenIndex;

    if (citizenIndex < 1 || citizenIndex > citizens.size()) {
        std::cout << RED << "Invalid selection.\n" << RESET;
        return;
    }

    Citizen* citizen = citizens[citizenIndex - 1];
    
    // Use getter methods if `job` and `propertyValue` are private
    std::cout << "Name: " << citizen->getName() << "\n";
    std::cout << "Income: " << citizen->getIncome() << "\n";
    std::cout << "Job: " << citizen->job << "\n"; // Assuming a getJob() method
    std::cout << "Property Value: " << citizen->propertyValue << "\n"; // Assuming a getPropertyValue() method
    std::cout << "Satisfaction: " << citizen->calculateSatisfaction() << "\n";
}


void viewAllCitizens(City* city) {
    const auto& citizens = city->getCitizens();

    if (citizens.empty()) {
        std::cout << RED << "No citizens available.\n" << RESET;
        return;
    }

    std::cout << CYAN << "\n=== All Citizens ===\n" << RESET;
    for (const auto& citizen : citizens) {
        std::cout << "Name: " << citizen->getName()
                  << ", Income: " << citizen->getIncome()
                  << ", Job: " << citizen->job << "\n";
    }
    std::cout << MAGENTA << "=====================\n" << RESET;
}

void removeCitizen(City* city) {
    auto& citizens = city->getCitizens();  // Non-const to allow modifications

    if (citizens.empty()) {
        std::cout << RED << "No citizens available.\n" << RESET;
        return;
    }

    std::cout << "Select a citizen to remove:\n";
    for (size_t i = 0; i < citizens.size(); ++i) {
        std::cout << i + 1 << ". " << citizens[i]->getName() << "\n";
    }
    int citizenIndex;
    std::cin >> citizenIndex;

    if (citizenIndex < 1 || citizenIndex > citizens.size()) {
        std::cout << RED << "Invalid selection.\n" << RESET;
        return;
    }

    delete citizens[citizenIndex - 1];  // Free memory
    citizens.erase(citizens.begin() + citizenIndex - 1);  // Remove from vector
    std::cout << GREEN << "Citizen removed from the city.\n" << RESET;
}


// void manageTransportForCitizen(City* city) {                 //Please fix
//      const auto& citizens = city->getCitizens();

//     if (citizens.empty()) {
//         std::cout << RED << "No citizens available.\n" << RESET;
//         return;
//     }

//     std::cout << "Select a citizen to manage transport:\n";
//     for (size_t i = 0; i < citizens.size(); ++i) {
//         std::cout << i + 1 << ". " << citizens[i]->getName() << "\n";
//     }
//     int citizenIndex;
//     std::cin >> citizenIndex;

//     if (citizenIndex < 1 || citizenIndex > citizens.size()) {
//         std::cout << RED << "Invalid citizen selection.\n" << RESET;
//         return;
//     }

//     Citizen* citizen = citizens[citizenIndex - 1];

//     // Present transport options to the user
//     std::cout << "Select a transport type:\n";
//     std::cout << "1. Road\n";
//     std::cout << "2. Railway\n";
//     std::cout << "3. Air\n";
//     int transportType;
//     std::cin >> transportType;

//     // Create or retrieve the selected transport type
//     Transport* chosenTransport = nullptr;
//     switch (transportType) {
//         case 1:
//             chosenTransport = new Road();  // Assuming Road is derived from Transport
//             break;
//         case 2:
//             chosenTransport = new Railway();  // Assuming Railway is derived from Transport
//             break;
//         case 3:
//             chosenTransport = new Air();  // Assuming Air is derived from Transport
//             break;
//         default:
//             std::cout << RED << "Invalid transport selection.\n" << RESET;
//             return;
//     }

//     // Assign the chosen transport to the citizen
//     citizen->chooseTransport(chosenTransport);
// }



void manageCitizens(City* city) {
    bool managingCitizens = true;
    while (managingCitizens) {
        std::cout << "\n" << CYAN << "Manage Citizens\n" << RESET;
        std::cout << "1. Add Custom Citizen\n";
        std::cout << "2. Add Multiple Citizens\n";
        std::cout << "3. View Citizen Information\n";
        std::cout << "4. View All Citizens\n";
        std::cout << "5. Remove Citizen\n";
        // std::cout << "6. Manage Transport for Citizen\n"; Uncomment when done with function
        std::cout << "7. Back to Main Menu\n";
        std::cout << "Select an option: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear input buffer

        switch (choice) {
            case 1:
                addCustomCitizen(city);
                break;
            case 2:
                addMultipleCitizens(city);
                break;
            case 3:
                viewCitizenInformation(city);
                break;
            case 4:
                viewAllCitizens(city);
                break;
            case 5:
                removeCitizen(city);
                break;
            // case 6:
            //     manageTransportForCitizen(city);  Uncomment when done with function
            //     break;
            case 7:
                managingCitizens = false;
                break;      
            default:
                std::cout << RED << "Invalid option. Please select again.\n" << RESET;
        }
    }
}


//**********3. MANAGE CITIZENS OPTION**********/




//**********4. MANAGE UTILITIES OPTION**********/
void manageUtilities(City* city) {
    std::cout << "TODO: Implement utility management functions here.\n";
    // Here, you would add options to manage utilities for the citizens.
}
//**********4. MANAGE UTILITIES OPTION**********/




//**********5. MANAGE TRANSPORT OPTION**********/
void manageTransport(City* city) {
    
}
//**********5. MANAGE TRANSPORT OPTION**********/





//**********6. SHOW STATS OPTION**********/
void displayCityStats(City* city) {
    std::cout << CYAN << "\n=== City Statistics ===\n" << RESET;

    // Population and Citizen Stats
    std::cout << "Population: " << city->citizens.size() << " citizens\n";

    // int totalSatisfaction = 0;
    // for (Citizen* citizen : city->citizens) {
    //     totalSatisfaction += citizen->getOverallSatisfaction();  // Add in once implemented
    // }
    // int averageSatisfaction = city->citizens.size() > 0 ? totalSatisfaction / city->citizens.size() : 0;
    // std::cout << "Average Citizen Satisfaction: " << averageSatisfaction << "%\n";

    // Building Stats
    std::cout << "Number of Buildings: " << city->listBuildings().size() << "\n";
    int residentialCount = 0, commercialCount = 0, industrialCount = 0, landmarkCount = 0;
    for (Building* building : city->listBuildings()) {
        if (dynamic_cast<Residential*>(building)) ++residentialCount;
        else if (dynamic_cast<Commercial*>(building)) ++commercialCount;
        else if (dynamic_cast<Industrial*>(building)) ++industrialCount;
        else if (dynamic_cast<Landmark*>(building)) ++landmarkCount;
    }
    std::cout << " - Residential Buildings: " << residentialCount << "\n";
    std::cout << " - Commercial Buildings: " << commercialCount << "\n";
    std::cout << " - Industrial Buildings: " << industrialCount << "\n";
    std::cout << " - Landmarks: " << landmarkCount << "\n";

    // Utility Stats
    std::cout << "Utility Capacity and Usage:\n";
    for (Utilities* utility : city->listUtilities()) {
        utility->displayInfo();  // Assuming displayInfo shows capacity and usage
    }

    // Transport Infrastructure
    std::cout << "Transport Infrastructure:\n";
    int roadCount = 0, railwayCount = 0, runwayCount = 0;
    for (TransportInfrastructure* infrastructure : city->listInfrastructures()) {
        if (dynamic_cast<Road*>(infrastructure)) ++roadCount;
        else if (dynamic_cast<Railway*>(infrastructure)) ++railwayCount;
        else if (dynamic_cast<Runway*>(infrastructure)) ++runwayCount;
    }
    std::cout << " - Roads: " << roadCount << "\n";
    std::cout << " - Railways: " << railwayCount << "\n";
    std::cout << " - Runways: " << runwayCount << "\n";

    // Economic and Financial Stats
    Government* government = city->getGovernment();
    if (government) {
        Tax* taxDept = government->getTaxDepartment();
        Budget* budgetDept = government->getBudgetDepartment();
        
        if (taxDept) {
            std::cout << "Total Revenue (from taxes): $" << taxDept->getTotalRevenue() << "\n";
            std::cout << "Current Tax Rate: " << taxDept->getTaxRate() * 100 << "%\n";
        }
        if (budgetDept) {
            std::cout << "Total Budget: $" << budgetDept->getTotalBudget() << "\n";
            std::cout << "Available Budget: $" << budgetDept->getAvailableBudget() << "\n";
        }
    }

    // Policies and Services
    Policies* policiesDept = government->getPoliciesDepartment();
    Services* servicesDept = government->getServicesDepartment();
    
    if (policiesDept) {
        std::cout << "Active Policies: " << policiesDept->getActivePoliciesCount() << "\n";  // Assuming this method exists
    }
    if (servicesDept) {
        std::cout << "Healthcare Facilities: " << servicesDept->getHealthcareFacilities() << "\n";  // Assuming getter exists
        std::cout << "Educational Institutions: " << servicesDept->getEducationalInstitutions() << "\n";
    }

    std::cout << MAGENTA << "=============================\n" << RESET;
}
//**********6. SHOW STATS OPTION**********/

//**********7. INCREASE POPULATION OPTION**********/
void increasePopulation(City* city) {
    cout << "You want to have more people in your city.\nBy how much do you want to increase the population: ";
    double increase;
    cin >> increase;
    // Create Residential Building
    Residential* residentialBuilding = new Residential(
        "Wizard’s Haven", 30, 5000, 300, true, 1, true, 300, "Residential District"
    );

    // Create Commercial Building
    Commercial* commercialBuilding = new Commercial(
        "Potion Emporium", 20, 30000, 1000, true, 1, true, 50, "Market Square"
    );

    // Create Industrial Building
    Industrial* industrialBuilding = new Industrial(
        "Alchemy Workshop", 10, 20000, 2000, true, 1, true, 350, "Industrial Zone"
    );

    // Create Landmark Building
    Landmark* landmarkBuilding = new Landmark(
        "Mystic Fountain", 50, 100000, 500, true, 1, true, 100, "Central Plaza"
    );

    // Set up the chain of responsibility
    Population populationHandler(increase);
    Housing housingHandler(increase * 0.5, residentialBuilding);
    Economic economicHandler(increase * 0.2);
    Infrastructure infrastructureHandler(increase * 0.3, commercialBuilding, industrialBuilding, landmarkBuilding);

    populationHandler.setNextHandler(&housingHandler);
    housingHandler.setNextHandler(&economicHandler);
    economicHandler.setNextHandler(&infrastructureHandler);

    // Start the chain
    populationHandler.handleRequest(increase, city);

    // // Output results
    // cout << "Population increase processed through the city infrastructure." << endl;
    // cout << "Residential Building Occupancy: " << residentialBuilding->getCurrentOccupancy() << endl;
    // cout << "Commercial Building Visitors: " << commercialBuilding->getVisitors() << endl;
    // cout << "Industrial Building Production Level: " << industrialBuilding->getProductionLevel() << endl;
    // cout << "Landmark Maintenance Level: " << landmarkBuilding->getMaintenanceLevel() << endl;

    // Clean up
    delete residentialBuilding;
    delete commercialBuilding;
    delete industrialBuilding;
    delete landmarkBuilding;
}
//**********7. INCREASE POPULATION OPTION**********/

void bigTestingMain() {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed for random events

    // Story-driven introduction and city creation
    std::cout << BOLD << BLUE << "\n========== Welcome, Traveler ==========\n" << RESET;
    std::cout << CYAN << "You are a powerful wizard, wandering the lands in search of new challenges.\n"
              << "One day, you stumble upon a vast, untouched landscape. A voice echoes in your mind:\n\n"
              << BOLD << "\"Welcome, wizard. This land is yours to shape. Build a city, nurture its growth, and guide its people.\"\n\n"
              << RESET;
    std::cout << "With a wave of your hand, you decide to bring forth a city from the earth...\n";

    // Prompt for the city name
    std::string cityName;
    std::cout << GREEN << "Enter the name of your new city: " << RESET;
    std::getline(std::cin, cityName);

    // Create the city with the entered name
    City* ourCity = new City(cityName);
    std::cout << BOLD << YELLOW << "\nThe city of " << cityName << " has risen from the ground!\n" << RESET;

    //Initial setup of city
    pauseForUser();
    createInitialBuildings(ourCity);
    createAndAssignUtilities(ourCity);
    createAndAssignTransport(ourCity);
    setupGovernment(ourCity);
    createAndAssignCitizens(ourCity);
    displayCityStats(ourCity);

    bool running = true;
    while (running) {
        showMainMenu();
        
        int choice;
        std::cin >> choice;
        
        // Check for invalid input
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the invalid input
            std::cout << RED << "Invalid input. Please enter a number between 1 and 6.\n" << RESET;
            continue; // Restart the loop
        }

        std::cin.ignore();

        switch (choice) {
            case 1:
                // Manage Government
                std::cout << YELLOW << "\nYou open the grand doors to the city hall...\n" << RESET;
                // Call a function to handle government actions (taxes, policies, etc.)
                manageGovernment(ourCity);
                break;

            case 2:
                // Build and Manage Buildings
                std::cout << CYAN << "\nYou look out over the land, ready to build...\n" << RESET;
                // Call a function to handle building creation and management
                manageBuildings(ourCity);
                break;

            case 3:
                // Manage Citizens
                std::cout << GREEN << "\nThe citizens look up to you for guidance...\n" << RESET;
                // Call a function to manage citizens
                manageCitizens(ourCity);
                break;

            case 4:
                // Provide Utilities
                std::cout << MAGENTA << "\nWith a wave of your wand, the essential utilities spring to life...\n" << RESET;
                // Call a function to manage utilities
                manageUtilities(ourCity);
                break;

            case 5:
                // Manage Transport
                manageTransport(ourCity);  
                break;

            case 6:
                // Show City Status
                std::cout << BLUE << "\nCurrent status of " << ourCity->getName() << ":\n" << RESET;
                displayCityStats(ourCity);
                break;
           
            case 7:
                // Grow population
                std::cout << BLUE << "\nCurrent population " << ourCity->citizens.size() << ":\n" << RESET;
                increasePopulation(ourCity);
                break;

            case 8:
                //Exit Simulation
                std::cout << BOLD << RED << "\nThank you for guiding the city. Farewell, wizard.\n" << RESET;
                running = false;
                break;

            default:
                std::cout << RED << "Invalid option. Please try again.\n" << RESET;
                break;
        }
    }

    // Clean up dynamically allocated resources
    delete ourCity;
}




int main(){
    bigTestingMain();
    return 0;
}




//TESTING INDIVIDUAL PATTERNS - IGNORE
// void testFactoryUtilities() {
//     // Water Factory
//     WaterFactory waterFactory;
//     Utilities* waterUtility = waterFactory.createUtility();
//     cout << "Testing Water Utility:\n";
//     waterUtility->displayInfo();
//     waterUtility->generateResources();
//     waterUtility->requestMaintenance(101);
//     cout << endl;

//     // Waste Factory
//     WasteFactory wasteFactory;
//     Utilities* wasteUtility = wasteFactory.createUtility();
//     cout << "Testing Waste Utility:\n";
//     wasteUtility->displayInfo();
//     wasteUtility->generateResources();
//     wasteUtility->requestMaintenance(102);
//     cout << endl;

//     // Sewage Factory
//     SewageFactory sewageFactory;
//     Utilities* sewageUtility = sewageFactory.createUtility();
//     cout << "Testing Sewage Utility:\n";
//     sewageUtility->displayInfo();
//     sewageUtility->generateResources();
//     sewageUtility->requestMaintenance(103);
//     cout << endl;

//     // PowerPlant Factory
//     PowerPlantFactory powerPlantFactory;
//     Utilities* powerPlantUtility = powerPlantFactory.createUtility();
//     cout << "Testing Power Plant Utility:\n";
//     powerPlantUtility->displayInfo();
//     powerPlantUtility->generateResources();
//     powerPlantUtility->requestMaintenance(104);
//     cout << endl;

//     // Clean up
//     delete waterUtility;
//     delete wasteUtility;
//     delete sewageUtility;
//     delete powerPlantUtility;
// }

// void testComposite(){
//      std::cout << "City Simulation using Composite Pattern\n";

//     // Create a Government (composite)
//     Government* cityGovernment = new Government(0.15, 0.05);

//     // Create individual departments (leaves)
//     Department* taxDept = new Tax("Tax Department", 15.0f);
//     Department* budgetDept = new Budget("Budget Department", 10000.0);
//     Department* policiesDept = new Policies("Policies Department");
//     Department* servicesDept = new Services("Public Services", 5, 10, 3);

//     // Add policies to the Policies Department
//     dynamic_cast<Policies*>(policiesDept)->addPolicy("Environmental Protection");
//     dynamic_cast<Policies*>(policiesDept)->addPolicy("Healthcare Reform");

//     // Add service programs to the Services Department
//     dynamic_cast<Services*>(servicesDept)->addServiceProgram("Free Education Initiative");
//     dynamic_cast<Services*>(servicesDept)->addServiceProgram("Healthcare for All");

//     // Add departments to the Government composite
//     cityGovernment->add(taxDept);
//     cityGovernment->add(budgetDept);
//     cityGovernment->add(policiesDept);
//     cityGovernment->add(servicesDept);

//     std::cout << "\nGovernment operates all departments:\n";
//     cityGovernment->operate();  // Government will operate all added departments

//     // Remove the Tax department and re-operate
//     std::cout << "\nRemoving Tax Department...\n";
//     cityGovernment->remove(taxDept);
//     cityGovernment->operate();

//     std::cout << "Simulation ended.\n";

//     // Clean up dynamically allocated memory
//     delete taxDept;
//     delete budgetDept;
//     delete policiesDept;
//     delete servicesDept;
//     delete cityGovernment;

    
// }
  
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

// void testSatisfactionChecker(){
//     Citizen* citizen = new Citizen("Tony", 1000);
//     Citizen* citizen2 = new Citizen("Sherlock", 1000);
//     Commercial* commercial = new Commercial("Mall", 20, 30000, 1000, true, 1, true, 300, "Downtown");
//     commercial->attach(citizen);
//     commercial->attach(citizen2);
//     commercial->getCitizenSatisfactionForBuilding();
//     commercial->doImprovements();
//     commercial->getCitizenSatisfactionForBuilding();
//     SatisfactionChecker* satisfactionChecker = new SatisfactionChecker(); 
//     std::cout << "City satisfaction for " << commercial->getType() << ": \n";
//     commercial->acceptCitySatisfactionChecker(satisfactionChecker);
//     citizen->acceptCitySatisfactionChecker(satisfactionChecker);
//     commercial->setBuildingValue(100000);
//     // alternatively can actually cout the "satisfaction for [building name]:" and then create
//     // a satisfactionChecker object and call buildingSatisfaction but i don't think it scales well
//     // don't use visit for satisfactionChecker. 
// }

// void taxCollection(){
//     Tax* taxDept = new Tax("Tax Department", 0.15);
//     City* city = new City("Stark City");
//     Building* industrial = new Industrial();
//     Building* commercial = new Commercial();
//     industrial->setBuildingValue(100000);
//     commercial->setBuildingValue(85000);
//     commercial->generateRevenue();
//     city->attach(industrial);
//     city->attach(commercial);
//     Citizen* c1 = new Citizen("Tony", 10000);
//     Citizen * c2 = new Citizen("Sherlock", 8000);
//     city->attach(c1);
//     city->attach(c2);
//     CollectTax* collectTax = new CollectTax();
//     collectTax->addBuildingVector(city->buildings);
//     collectTax->addCitizenVector(city->citizens);
//     collectTax->execute();
//     TaxCollector* taxCollector = new TaxCollector();
//     for (int i = 0 ; i < city->citizens.size() ; i++){
//         taxCollector->visit(city->citizens[i]);
//     }
//     for (int i = 0 ; i < city->buildings.size() ; i++){
//         taxCollector->visit(city->buildings[i]);
//     }
//     taxDept->collectTaxes(taxCollector->taxCollected);
// }









