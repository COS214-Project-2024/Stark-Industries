#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <ctime>
#include <algorithm>

#include "CityFacade.h"

// ANSI color codes for styling the output
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define MAGENTA "\033[35m"
#define BLUE "\033[34m"
#define ORANGE "\033[38;5;208m" 
#define PURPLE "\033[38;5;93m"

CityFacade::CityFacade() {

}

void CityFacade::bigTestingMain() {

    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed for random events

    // Story-driven introduction and city creation
    std::cout << BOLD << BLUE << "\n========== Welcome, Traveler ==========\n" << RESET;
    std::cout << CYAN << "🧙‍♂️ You are a powerful wizard, wandering the lands in search of new challenges.\n"
              << "One day, you stumble upon a vast, untouched landscape. A voice echoes in your mind:\n\n"
              << BOLD << "\"Welcome, wizard. This land is yours to shape. Build a city, nurture its growth, and guide its people.\"\n\n"
              << RESET;
    std::cout << "🌄 With a wave of your hand, you decide to bring forth a city from the earth...\n";

    // Prompt for the city name
    std::string cityName;
    std::cout << GREEN << "🏙️ Enter the name of your new city: " << RESET;
    std::getline(std::cin, cityName);

    // Create the city with the entered name
    City* ourCity = new City(cityName);
    std::cout << BOLD << YELLOW << "\n✨ The city of " << cityName << " has risen from the ground!\n" << RESET;

    // Initial setup of city
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
            std::cout << RED << "❗ Invalid input. Please enter a number between 1 and 7.\n" << RESET;
            continue; // Restart the loop
        }

        std::cin.ignore();

        switch (choice) {
            case 1:
                // Manage Government
                std::cout << YELLOW << "\n🏛️ You open the grand doors to the city hall...\n" << RESET;
                manageGovernment(ourCity);
                break;

            case 2:
                // Build and Manage Buildings
                std::cout << CYAN << "\n🏗️ You look out over the land, ready to build...\n" << RESET;
                manageBuildings(ourCity);
                break;

            case 3:
                // Manage Citizens
                std::cout << GREEN << "\n👨‍👩‍👧‍👦 The citizens look up to you for guidance...\n" << RESET;
                manageCitizens(ourCity);
                break;

            case 4:
                // Manage Transport
                std::cout << ORANGE << "\n🚗 You decide to improve the city's transport network...\n" << RESET;
                manageTransport(ourCity);  
                break;

            case 5:
                // Grow Population
                std::cout << BLUE << "\n👥 Current population: " << ourCity->citizens.size() << ".\n" << RESET;
                increasePopulation(ourCity);
                break;

            case 6:
                // Show City Status
                std::cout << PURPLE << "\n📊 Gathering statistics for " << ourCity->getName() << "...\n" << RESET;
                displayCityStats(ourCity);
                break;
           
            case 7:
                // Exit Simulation
                std::cout << BOLD << RED << "\n🧙‍♂️ Thank you for guiding the city. Farewell, wizard.\n" << RESET;
                running = false;
                break;
                
            default:
                std::cout << RED << "❗ Invalid option. Please try again.\n" << RESET;
                break;
        }
    }

    // Clean up dynamically allocated resources
    delete ourCity;
}

//**********INITIAL SETUP**********/
void CityFacade::pauseForUser() {
    std::cout << BOLD << BLUE << "\nPress enter to continue..." << RESET;
    std::cin.get();
}

void CityFacade::initializeResources() {
    ResourceManagement& resourceManager = ResourceManagement::getInstance();
    resourceManager.createResources();  // Initialize base resources
}

void CityFacade::createInitialBuildings(City* city) {
    std::cout << PURPLE << "\n🌌 The wizard raises their hands to the sky, channeling the powers of creation... 🌌\n" << RESET;
    
    // Create Residential Building
    Residential* residentialBuilding = new Residential(
        "Wizard’s Haven", 30, 5000, 300, true, 1, true, 100, "Residential District"
    );
    city->addBuilding(residentialBuilding);
    std::cout << GREEN << "🏠 A Residential Building rises: " << BOLD << residentialBuilding->getType() << RESET 
              << "\n   📍 Location: Residential District\n" << RESET;

    // Create Commercial Building
    Commercial* commercialBuilding = new Commercial(
        "Potion Emporium", 20, 30000, 1000, true, 1, true, 5, "Market Square"
    );
    city->addBuilding(commercialBuilding);
    std::cout << YELLOW << "🏬 A Commercial Building appears: " << BOLD << commercialBuilding->getType() << RESET
              << "\n   📍 Location: Market Square\n" << RESET;

    // Create Industrial Building
    Industrial* industrialBuilding = new Industrial(
        "Alchemy Workshop", 10, 20000, 2000, true, 1, true, 3, "Industrial Zone"
    );
    city->addBuilding(industrialBuilding);
    std::cout << ORANGE << "🏭 An Industrial Building is forged: " << BOLD << industrialBuilding->getType() << RESET
              << "\n   📍 Location: Industrial Zone\n" << RESET;

    // Create Landmark Building
    Landmark* landmarkBuilding = new Landmark(
        "Mystic Fountain", 50, 100000, 500, true, 1, true, 100, "Central Plaza"
    );
    city->addBuilding(landmarkBuilding);
    std::cout << CYAN << "⛲ A Landmark springs forth: " << BOLD << landmarkBuilding->getType() << RESET
              << "\n   📍 Location: Central Plaza\n" << RESET;

    pauseForUser();
}

void CityFacade::createAndAssignUtilities(City* city) {
    ResourceManagement& resourceManager = ResourceManagement::getInstance();  // Access the resource manager

    std::cout << PURPLE << BOLD << "\n✨ With a wave of the wizard's hand, the city's essential utilities begin to materialize...\n" << RESET;

    // Create Water Utility
    WaterFactory waterFactory;
    Utilities* waterUtility = waterFactory.createUtility();
    city->addUtility(waterUtility);
    std::cout << CYAN << "💧 Water Utility Created:\n" << RESET;
    resourceManager.allocateResourcesToUtility("Water Utility", /*energy*/ 0, /*water*/ 300, /*budget*/ 500.0);
    resourceManager.displayResourceStatus();

    // Create Waste Management Utility
    WasteFactory wasteFactory;
    Utilities* wasteUtility = wasteFactory.createUtility();
    city->addUtility(wasteUtility);
    std::cout << GREEN << "♻️  Waste Management Utility Created:\n" << RESET;
    resourceManager.allocateResourcesToUtility("Waste Management Utility", /*energy*/ 100, /*water*/ 0, /*budget*/ 300.0);
    resourceManager.displayResourceStatus();

    // Create Sewage Utility
    SewageFactory sewageFactory;
    Utilities* sewageUtility = sewageFactory.createUtility();
    city->addUtility(sewageUtility);
    std::cout << YELLOW << "🚰 Sewage Utility Created:\n" << RESET;
    resourceManager.allocateResourcesToUtility("Sewage Utility", /*energy*/ 50, /*water*/ 100, /*budget*/ 200.0);
    resourceManager.displayResourceStatus();

    // Create Power Plant Utility
    PowerPlantFactory powerPlantFactory;
    Utilities* powerPlantUtility = powerPlantFactory.createUtility();
    city->addUtility(powerPlantUtility);
    std::cout << ORANGE << "⚡ Power Plant Utility Created:\n" << RESET;
    resourceManager.allocateResourcesToUtility("Power Plant Utility", /*energy*/ 500, /*water*/ 0, /*budget*/ 1000.0);
    resourceManager.displayResourceStatus();
    pauseForUser();

    // Assign utilities to buildings
    std::cout << PURPLE << "\n🌟 The wizard channels the utilities to serve each building in the city...\n" << RESET;
    for (Building* building : city->listBuildings()) {
        building->addUtility(waterUtility);
        building->addUtility(wasteUtility);
        building->addUtility(sewageUtility);
        building->addUtility(powerPlantUtility);

        std::cout << GREEN << "✅ Utilities have been assigned to " << building->getType() << "\n" << RESET;
    }
    pauseForUser();
}


void CityFacade::createAndAssignTransport(City* city) {
    std::cout << PURPLE << BOLD << "\n🛤️ The wizard conjures essential transport infrastructure for the city...\n" << RESET;

    RoadFactory roadFactory;
    RailwayFactory railwayFactory;
    RunwayFactory runwayFactory;

    // Create a road
    TransportInfrastructure* road = roadFactory.createInfrastructure(4, 20.0);
    road->build();
    city->addInfrastructure(road);
    std::cout << GREEN << "🛣️  Road created with 4 lanes and length 20 km.\n" << RESET;

    // Create a railway
    TransportInfrastructure* railway = railwayFactory.createInfrastructure(15, true);
    railway->build();
    city->addInfrastructure(railway);
    std::cout << YELLOW << "🚆 Electrified railway created with length 15 km.\n" << RESET;

    // Create a runway
    TransportInfrastructure* runway = runwayFactory.createInfrastructure(3.0, 0.75);
    runway->build();
    city->addInfrastructure(runway);
    std::cout << BLUE << "🛫 Runway created with length 3.0 km and width 0.75 km.\n" << RESET;

    pauseForUser();
}


void CityFacade::setupGovernment(City* city) {
    std::cout << PURPLE << BOLD << "\n🧙‍♂️ The wizard forms a government to lead the city...\n" << RESET;

    Government* government = new Government(0.15, 0.02);  // 15% income tax, 2% property tax

    // Create departments
    Budget* budgetDept = new Budget("Budget Department", 10000.0);
    Policies* policiesDept = new Policies("Policies Department");
    Services* servicesDept = new Services("Services Department", 10, 5, 3);
    Tax* taxDept = new Tax("Tax Department", 0.15);

    // Add departments to government
    government->add(budgetDept);
    std::cout << GREEN << "💰 Budget Department created and added to the government.\n" << RESET;

    government->add(policiesDept);
    std::cout << YELLOW << "📜 Policies Department created and added to the government.\n" << RESET;

    government->add(servicesDept);
    std::cout << CYAN << "🏥 Services Department created and added to the government.\n" << RESET;

    government->add(taxDept);
    std::cout << ORANGE << "💸 Tax Department created and added to the government.\n" << RESET;

    // Assign the government to the city
    city->setGovernment(government);
    std::cout << PURPLE << BOLD << "\n🏛️ Government and departments successfully established for the city.\n" << RESET;
    pauseForUser();
}


void CityFacade::createAndAssignCitizens(City* city) {
    std::cout << CYAN << "\n🧙‍♂️ The wizard decides to populate the city with its first citizens...\n" << RESET;

    // Look for an existing residential building in the city
    Residential* residentialBuilding = nullptr;
    for (Building* building : city->listBuildings()) {
        residentialBuilding = dynamic_cast<Residential*>(building);
        if (residentialBuilding) {
            break;  // Found a residential building, so break out of the loop
        }
    }

    if (!residentialBuilding) {
        std::cout << RED << "⚠️ No residential building found. Citizens cannot be assigned.\n" << RESET;
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

        std::cout << GREEN << "👤 Citizen created: " << RESET << name 
                  << " | Job: " << job << " | Income: $" << income 
                  << " | Property Value: $" << std::fixed << std::setprecision(2) << propertyValue << "\n";

        // Try to assign the citizen to the residential building
        if (residentialBuilding->populateBuilding()) {
            city->attach(newCitizen); // Add citizen to city’s observer list
            residentialBuilding->attach(newCitizen); // Add citizen as an observer to the building
            std::cout << BLUE << "🏠 " << name << " has moved into " << residentialBuilding->getType() << "\n" << RESET;
        } else {
            std::cout << RED << "🚫 No more space in the residential building for " << name << ".\n" << RESET;
            delete newCitizen; // Delete citizen if not assigned
        }

        // Pause for user to proceed to next citizen
    }
    pauseForUser();
}

//**********INITIAL SETUP**********/


//**********MAIN MENU**********/
void CityFacade::showMainMenu() {
    std::cout << BOLD << BLUE << "\n========== 🏙️ Main Menu 🏙️ ==========\n" << RESET;
    std::cout << GREEN << "1. 🏛️ Manage Government\n";
    std::cout << "2. 🏢 Build and Manage Buildings\n";
    std::cout << "3. 👥 Manage Citizens\n";
    std::cout << "4. 🚗 Manage Transport\n";
    std::cout << "5. 🌆 Change City Population\n";
    std::cout << "6. 📊 Show City Status\n";
    std::cout << "7. 🚪 Exit Simulation\n" << RESET;
    std::cout << BOLD << ORANGE << "\nPlease select an option: " << RESET;
}
//**********MAIN MENU**********/


void CityFacade::addCommandsToTaxDepartment(Tax* taxDept, City* city) {
    // Create command objects
    Command* collectTax = new CollectTax();
    Command* increaseTax = new IncreaseTax();

    //add vectors
    collectTax->addCitizenVector(city->citizens);
    collectTax->addBuildingVector(city->buildings);
    increaseTax->addCitizenVector(city->citizens);

    //add commands
    taxDept->addCommand(collectTax);
    taxDept->addCommand(increaseTax);
}

double CityFacade::taxCollectorVisitor(Tax* taxDept, City* city) {
    for (int i = 0 ; i < city->buildings.size() ; i++){
        city->buildings[i]->setBuildingValue((i+1)*10000);
        if (city->buildings[i]->getBuildingType() == "Residential"){
            city->buildings[i]->collectRent();
        }
        else if (city->buildings[i]->getBuildingType() == "Commercial"){
            city->buildings[i]->generateRevenue();
        }
    }
    addCommandsToTaxDepartment(taxDept, city);
    taxDept->collectTaxes();
    TaxCollector taxCollector;
    for (int i = 0; i < city->citizens.size(); i++) {
        city->citizens[i]->acceptTaxCollector(&taxCollector);
    }
    for (int i = 0; i < city->buildings.size(); i++) {
        city->buildings[i]->acceptTaxCollector(&taxCollector);
    }
    taxDept->collectTaxes(taxCollector.taxCollected);
    return taxCollector.taxCollected;
}

//**********1. MANAGE GOVERNMENT OPTION**********/
void CityFacade::manageTaxDepartment(Tax* taxDept, Budget* budgetDept, City* city) { // Pass Budget pointer as parameter
    bool managingTax = true;
    while (managingTax) {
        std::cout << "\n" << CYAN << "🏦 Manage Tax Department 🏦\n" << RESET;
        std::cout << GREEN << "1. 📈 Increase Tax\n";
        std::cout << "2. 💰 Collect Taxes\n";
        std::cout << "3. 📊 View Total Revenue\n";
        std::cout << "4. 🔙 Back to Government Menu\n" << RESET;
        std::cout << BOLD << ORANGE << "Select an option: " << RESET;

        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear input buffer

        switch (choice) {
            case 1: {
                addCommandsToTaxDepartment(taxDept, city);
                taxDept->increaseTax();
                double newRate = city->citizens[0]->getTaxRate();
                std::cout << GREEN << "✅ Tax rate increased to " << newRate << "%\n" << RESET;
                break;
            }
            case 2: {
                double tax = taxCollectorVisitor(taxDept, city);
                std::cout << GREEN << "💵 Total Tax Collected: $" << tax << "\n" << RESET;
                budgetDept->addCollectedTaxes(tax);
                break;
            }
            case 3:
                std::cout << YELLOW << "📊 Total Revenue: $" << taxDept->getTotalRevenue() << "\n" << RESET;
                break;
            case 4:
                managingTax = false;
                break;
            default:
                std::cout << RED << "❌ Invalid option. Please select again.\n" << RESET;
        }
    }
}



void CityFacade::manageBudgetDepartment(Budget* budgetDept) {
    bool managingBudget = true;
    while (managingBudget) {
        std::cout << "\n" << CYAN << "💼 Manage Budget Department 💼\n" << RESET;
        std::cout << GREEN << "1. 💸 Allocate Funds\n";
        std::cout << "2. 📋 View Budget Details\n";
        std::cout << "3. 🔙 Back to Government Menu\n" << RESET;
        std::cout << BOLD << ORANGE << "Select an option: " << RESET;

        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear input buffer

        switch (choice) {
            case 1: {
                double amount;
                std::cout << ORANGE << "💰 Enter amount to allocate: " << RESET;
                std::cin >> amount;
                budgetDept->allocateFunds(amount);
                std::cout << GREEN << "✅ Funds allocated: $" << amount << "\n" << RESET;
                break;
            }
            case 2:
                std::cout << YELLOW << "📊 Budget Details:\n" << RESET;
                budgetDept->operate();  // Displays budget details
                break;
            case 3:
                managingBudget = false;
                break;
            default:
                std::cout << RED << "❌ Invalid option. Please try again.\n" << RESET;
        }
    }
}



void CityFacade::managePoliciesDepartment(Policies* policiesDept) {
    bool managingPolicies = true;
    while (managingPolicies) {
        std::cout << "\n" << CYAN << "📜 Manage Policies Department 📜\n" << RESET;
        std::cout << GREEN << "1. ➕ Add Policy\n";
        std::cout << "2. ➖ Remove Policy\n";
        std::cout << "3. 📄 View Active Policies\n";
        std::cout << "4. 🔙 Back to Government Menu\n" << RESET;
        std::cout << BOLD << ORANGE << "Select an option: " << RESET;

        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear input buffer

        switch (choice) {
            case 1: {
                std::string policy;
                std::cout << ORANGE << "📝 Enter policy to add: " << RESET;
                std::getline(std::cin, policy);
                policiesDept->addPolicy(policy);
                std::cout << GREEN << "✅ Policy added: \"" << policy << "\"\n" << RESET;
                break;
            }
            case 2: {
                std::string policy;
                std::cout << ORANGE << "🗑️ Enter policy to remove: " << RESET;
                std::getline(std::cin, policy);
                policiesDept->removePolicy(policy);
                std::cout << GREEN << "✅ Policy removed: \"" << policy << "\"\n" << RESET;
                break;
            }
            case 3:
                std::cout << YELLOW << "📄 Active Policies:\n" << RESET;
                policiesDept->operate();  // Displays active policies
                break;
            case 4:
                managingPolicies = false;
                break;
            default:
                std::cout << RED << "❌ Invalid option. Please try again.\n" << RESET;
        }
    }
}



void CityFacade::manageServicesDepartment(Services* servicesDept) {
    bool managingServices = true;
    while (managingServices) {
        std::cout << "\n" << CYAN << "🛠️ Manage Services Department 🛠️\n" << RESET;
        std::cout << GREEN << "1. ➕ Add Service Program\n";
        std::cout << "2. 📋 View Services\n";
        std::cout << "3. 🔙 Back to Government Menu\n" << RESET;
        std::cout << BOLD << ORANGE << "Select an option: " << RESET;

        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear input buffer

        switch (choice) {
            case 1: {
                std::string program;
                std::cout << ORANGE << "📝 Enter service program to add: " << RESET;
                std::getline(std::cin, program);
                servicesDept->addServiceProgram(program);
                std::cout << GREEN << "✅ Service program added: \"" << program << "\"\n" << RESET;
                break;
            }
            case 2:
                std::cout << YELLOW << "📋 Current Service Programs:\n" << RESET;
                servicesDept->operate();  // Displays service details
                break;
            case 3:
                managingServices = false;
                break;
            default:
                std::cout << RED << "❌ Invalid option. Please try again.\n" << RESET;
        }
    }
}


// Function to handle the government management menu
void CityFacade::manageGovernment(City* city) {
    bool managingGovernment = true;
    while (managingGovernment) {
        std::cout << "\n" << BOLD << CYAN << "🏛️ Manage Government 🏛️\n" << RESET;
        std::cout << GREEN << "1. 💰 Tax Department\n";
        std::cout << "2. 💵 Budget Department\n";
        std::cout << "3. 📜 Policies Department\n";
        std::cout << "4. 🛠️ Services Department\n";
        std::cout << "5. 🔙 Return to Main Menu\n" << RESET;
        std::cout << BOLD << ORANGE << "Select an option: " << RESET;

        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear input buffer

        switch (choice) {
            case 1: {
                Tax* taxDept = city->getGovernment()->getTaxDepartment();
                Budget* budgetDept = city->getGovernment()->getBudgetDepartment();
                if (taxDept && budgetDept) {
                    manageTaxDepartment(taxDept, budgetDept, city);
                } else {
                    std::cout << RED << "❌ Failed to access Tax or Budget Department.\n" << RESET;
                }
                break;
            }
            case 2: {
                Budget* budgetDept = city->getGovernment()->getBudgetDepartment();
                if (budgetDept) {
                    manageBudgetDepartment(budgetDept);
                } else {
                    std::cout << RED << "❌ Failed to access Budget Department.\n" << RESET;
                }
                break;
            }
            case 3: {
                Policies* policiesDept = city->getGovernment()->getPoliciesDepartment();
                if (policiesDept) {
                    managePoliciesDepartment(policiesDept);
                } else {
                    std::cout << RED << "❌ Failed to access Policies Department.\n" << RESET;
                }
                break;
            }
            case 4: {
                Services* servicesDept = city->getGovernment()->getServicesDepartment();
                if (servicesDept) {
                    manageServicesDepartment(servicesDept);
                } else {
                    std::cout << RED << "❌ Failed to access Services Department.\n" << RESET;
                }
                break;
            }
            case 5:
                managingGovernment = false;
                break;
            default:
                std::cout << RED << "❌ Invalid option. Please select again.\n" << RESET;
        }
    }
}


//**********1. MANAGE GOVERNMENT OPTION**********/


//**********2. MANAGE BUILDINGS OPTION**********/
void CityFacade::buildNewBuilding(City* city) {
    int buildingType;
    std::string buildingName;
    double buildingCost = 0;  // Track the cost of the building

    std::cout << BOLD << BLUE << "\n🏗️ Select the type of building to construct:\n" << RESET;
    std::cout << GREEN << "1. 🏠 Residential\n";
    std::cout << "2. 🏬 Commercial\n";
    std::cout << "3. 🏭 Industrial\n";
    std::cout << "4. 🏛️ Landmark\n" << RESET;
    std::cout << ORANGE << "Select an option: " << RESET;
    std::cin >> buildingType;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear input buffer

    // Prompt for the building name
    std::cout << ORANGE << "Enter the name of the new building: " << RESET;
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
            std::cout << RED << "❌ Invalid option. Returning to main menu.\n" << RESET;
            return;
    }

    // Check if budget can cover the cost
    Budget* budgetDept = dynamic_cast<Budget*>(city->getGovernment()->getBudgetDepartment());
    if (budgetDept && budgetDept->getAvailableBudget() >= buildingCost) {
        budgetDept->allocateFunds(buildingCost);  // Deduct cost from the budget

        if (newBuilding) {
            city->addBuilding(newBuilding);
            std::cout << GREEN << "✅ Building added to the city: " << buildingName << "\n";
            std::cout << "🏗️ Building constructed: " << newBuilding->getType() << "\n" << RESET;
        }
    } else {
        std::cout << RED << "🚫 Insufficient budget to construct this building.\n" << RESET;
        delete newBuilding;  // Clean up the allocated memory
    }
}




void CityFacade::inspectBuilding(City* city) {
    int buildingIndex;
    const auto& buildings = city->listBuildings();

    if (buildings.empty()) {
        std::cout << RED << "🚫 No buildings in the city to inspect.\n" << RESET;
        return;
    }

    std::cout << BOLD << BLUE << "\n🏢 Select a building to inspect:\n" << RESET;
    for (size_t i = 0; i < buildings.size(); ++i) {
        std::cout << ORANGE << i + 1 << ". " << buildings[i]->getType() << "\n" << RESET;
    }

    std::cout << ORANGE << "Enter your choice: " << RESET;
    std::cin >> buildingIndex;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear input buffer

    if (buildingIndex < 1 || buildingIndex > buildings.size()) {
        std::cout << RED << "❌ Invalid selection. Please choose a valid building number.\n" << RESET;
        return;
    }

    std::cout << GREEN << "\n🔍 Inspecting building details...\n" << RESET;
    buildings[buildingIndex - 1]->get();  // Display details of selected building
    std::cout << MAGENTA << "Inspection complete for " << buildings[buildingIndex - 1]->getType() << ".\n" << RESET;
}



void CityFacade::improveBuilding(City* city) {
    int buildingIndex;
    const auto& buildings = city->listBuildings();

    if (buildings.empty()) {
        std::cout << RED << "🚫 No buildings in the city to improve.\n" << RESET;
        return;
    }

    std::cout << BOLD << BLUE << "\n🏗️  Select a building to improve:\n" << RESET;
    for (size_t i = 0; i < buildings.size(); ++i) {
        std::cout << ORANGE << i + 1 << ". " << buildings[i]->getType() << "\n" << RESET;
    }

    std::cout << ORANGE << "Enter your choice: " << RESET;
    std::cin >> buildingIndex;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear input buffer

    if (buildingIndex < 1 || buildingIndex > buildings.size()) {
        std::cout << RED << "❌ Invalid selection. Please choose a valid building number.\n" << RESET;
        return;
    }

    std::cout << GREEN << "\n🔨 Improving " << buildings[buildingIndex - 1]->getType() << "...\n" << RESET;
    buildings[buildingIndex - 1]->doImprovements();
    std::cout << MAGENTA << "✨ Improvements complete for " << buildings[buildingIndex - 1]->getType() << ".\n" << RESET;
}


void CityFacade::removeBuilding(City* city) {
    int buildingIndex;
    auto& buildings = city->listBuildings();  // Non-const to allow modifications

    if (buildings.empty()) {
        std::cout << RED << "🚫 No buildings available to remove.\n" << RESET;
        return;
    }

    std::cout << BOLD << BLUE << "\n🏢 Select a building to remove:\n" << RESET;
    for (size_t i = 0; i < buildings.size(); ++i) {
        std::cout << ORANGE << i + 1 << ". " << buildings[i]->getType() << "\n" << RESET;
    }

    std::cout << ORANGE << "Enter your choice: " << RESET;
    std::cin >> buildingIndex;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear input buffer

    if (buildingIndex < 1 || buildingIndex > buildings.size()) {
        std::cout << RED << "❌ Invalid selection. Please choose a valid building number.\n" << RESET;
        return;
    }

    Building* building = buildings[buildingIndex - 1];

    // Check if the building is residential and occupied
    Residential* residentialBuilding = dynamic_cast<Residential*>(building);
    if (residentialBuilding && residentialBuilding->getOccupantCount() > 0) {
        std::cout << RED << "⚠️ Cannot remove " << building->getType()
                  << " because it has residents. Please relocate them first.\n" << RESET;
        return;
    }

    // Proceed with deletion if no residents
    std::cout << GREEN << "🛠️ Removing " << building->getType() << "...\n" << RESET;
    delete building;  // Free memory
    buildings.erase(buildings.begin() + buildingIndex - 1);
    std::cout << MAGENTA << "✅ Building successfully removed from the city.\n" << RESET;
}


double CityFacade::buildingCitySatisfaction(Building* building) {
    SatisfactionChecker* satisfactionChecker = new SatisfactionChecker();
    building->acceptCitySatisfactionChecker(satisfactionChecker);
    double satisfaction = satisfactionChecker->citySatisfactionTotal;
    delete satisfactionChecker;
    return satisfaction;
}

double CityFacade::citizenSatisfactionForBuilding(Building* building) {
    SatisfactionChecker* satisfactionChecker = new SatisfactionChecker();
    for (int i = 0 ; i < building->observerList.size() ; i++){
        building->observerList[i]->acceptBuildingSatisfactionChecker(satisfactionChecker);
    }
    double satisfaction = satisfactionChecker->buildingSatisfactionTotal;
    double avg = satisfaction / building->observerList.size();
    delete satisfactionChecker;
    return avg;
}

void CityFacade::viewAllBuildings(City* city) {
    const auto& buildings = city->listBuildings();

    if (buildings.empty()) {
        std::cout << RED << "🚫 No buildings in the city.\n" << RESET;
        return;
    }

    std::cout << BOLD << CYAN << "\n🏙️ === All Buildings in the City ===\n" << RESET;
    for (const auto& building : buildings) {
        std::cout << ORANGE << "🏢 Building: " << building->getType() << RESET
                  << "\n   🌆 City Satisfaction: " << buildingCitySatisfaction(building)
                  << "\n   💰 Economic Impact: " << building->calculateEconomicImpact();
        
        if (building->getBuildingType() == "Residential") {
            double avgSatisfaction = citizenSatisfactionForBuilding(building);
            std::cout << "\n   😊 Avg Citizen Satisfaction in Building: " << avgSatisfaction;
        }
        std::cout << "\n";
    }
    std::cout << MAGENTA << "=============================\n" << RESET;
}


void CityFacade::increaseRent(City* city) {
    int buildingIndex;
    const auto& buildings = city->listBuildings();

    if (buildings.empty()) {
        std::cout << RED << "🚫 No buildings in the city.\n" << RESET;
        return;
    }

    std::cout << CYAN << "🏠 Select a residential building to increase rent:\n" << RESET;
    std::vector<int> residentialIndices;
    for (size_t i = 0; i < buildings.size(); ++i) {
        if (buildings[i]->getBuildingType() == "Residential") {
            residentialIndices.push_back(i);
            std::cout << residentialIndices.size() << ". " << buildings[i]->getType() << " (Current Rent: " 
                      << buildings[i]->getRent() << ")\n";
        }
    }

    if (residentialIndices.empty()) {
        std::cout << RED << "🚫 No residential buildings available to increase rent.\n" << RESET;
        return;
    }

    int selection;
    std::cin >> selection;

    if (selection < 1 || selection > residentialIndices.size()) {
        std::cout << RED << "🚫 Invalid selection. Returning to menu.\n" << RESET;
        return;
    }

    int selectedBuildingIndex = residentialIndices[selection - 1];
    double currentRent = buildings[selectedBuildingIndex]->getRent();
    double newRent = 0.0;

    while (newRent <= currentRent) {
        std::cout << YELLOW << "💵 Enter a new rental rate greater than the current rent (" << currentRent << "): " << RESET;
        std::cin >> newRent;
    }

    buildings[selectedBuildingIndex]->setRentalRate(newRent);
    std::cout << GREEN << "✅ Rent increased to: " << newRent << "\n" << RESET;
}

void CityFacade::manageBuildings(City* city) {
    bool buildingManagement = true;
    while (buildingManagement) {
        std::cout << "\n" << CYAN << BOLD << "🏢 Manage Buildings 🏢\n" << RESET;
        std::cout << GREEN << "1. 🏗️ Build New Building\n";
        std::cout << "2. 🔍 Inspect Building\n";
        std::cout << "3. 🔧 Improve Building\n";
        std::cout << "4. 🗑️ Remove Building\n";
        std::cout << "5. 📋 View All Buildings\n";
        std::cout << "6. 💸 Increase Rent of Residential Building\n";
        std::cout << "7. 🔙 Back to Main Menu\n" << RESET;
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
                increaseRent(city);
                break;
            case 7:
                buildingManagement = false;
                break;
            default:
                std::cout << RED << "🚫 Invalid option. Please select again.\n" << RESET;
        }
    }
}

//**********2. MANAGE BUILDINGS OPTION**********/



//**********3. MANAGE CITIZENS OPTION**********/
void CityFacade::addCustomCitizen(City* city) {
    if (city->getTotalPopulation() >= 200) {
        std::cout << RED << "🚫 Maximum population reached. Cannot add more citizens.\n" << RESET;
        return;
    }

    std::string name, job;
    int income;
    double propertyValue;

    std::cout << "👤 Enter the name of the new citizen: ";
    std::getline(std::cin, name);

    std::cout << "💼 Enter the job of the new citizen: ";
    std::getline(std::cin, job);

    std::cout << "💵 Enter the income of the new citizen: ";
    std::cin >> income;

    std::cout << "🏡 Enter the property value owned by the new citizen: ";
    std::cin >> propertyValue;

    Citizen* newCitizen = new Citizen(name, income, propertyValue, job);

    // Check if there's space in a residential building
    Residential* residentialBuilding = nullptr;
    for (Building* building : city->listBuildings()) {
        residentialBuilding = dynamic_cast<Residential*>(building);
        if (residentialBuilding && residentialBuilding->populateBuilding()) {
            city->attach(newCitizen);
            residentialBuilding->attach(newCitizen);
            std::cout << GREEN << "✅ Citizen " << name << " has moved into " 
                      << residentialBuilding->getType() << "\n" << RESET;
            return;
        }
    }

    std::cout << RED << "🏚️ No residential building with available capacity. Consider building more housing.\n" << RESET;
    delete newCitizen; // Delete citizen if not assigned
}



void CityFacade::addMultipleCitizens(City* city) {
    int numberOfCitizens;
    std::cout << "👥 Enter the number of citizens to add (1 to 10): ";
    std::cin >> numberOfCitizens;

    if (numberOfCitizens < 1 || numberOfCitizens > 10) {
        std::cout << RED << "❌ Invalid number. Please enter a value between 1 and 10.\n" << RESET;
        return;
    }

    int currentPopulation = city->getTotalPopulation();
    if (currentPopulation + numberOfCitizens > 200) {
        std::cout << RED << "🚫 Adding " << numberOfCitizens << " citizens would exceed the maximum population limit of 200.\n" << RESET;
        return;
    }

    // Check available capacity across residential buildings
    int availableCapacity = city->getAvailableHousingCapacity();
    if (numberOfCitizens > availableCapacity) {
        std::cout << RED << "🏚️ Not enough housing capacity for " << numberOfCitizens 
                  << " citizens. Consider building more housing before adding more citizens.\n" << RESET;
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
                residentialBuilding->attach(newCitizen); // Add citizen as an observer to the building
                std::cout << GREEN << "🏠 " << name << " has moved into " << residentialBuilding->getType() << "\n" << RESET;
                assigned = true;
                break;
            }
        }

        if (!assigned) {
            std::cout << RED << "❌ No more space in available residential buildings for " << name << ".\n" << RESET;
            delete newCitizen; // Delete citizen if not assigned
        }
    }
}



void CityFacade::viewCitizenInformation(City* city) {
    const auto& citizens = city->getCitizens();

    if (citizens.empty()) {
        std::cout << RED << "❌ No citizens available.\n" << RESET;
        return;
    }

    std::cout << "👤 Select a citizen to view details:\n";
    for (size_t i = 0; i < citizens.size(); ++i) {
        std::cout << i + 1 << ". " << citizens[i]->getName() << "\n";
    }

    int citizenIndex;
    std::cin >> citizenIndex;

    if (citizenIndex < 1 || citizenIndex > static_cast<int>(citizens.size())) {
        std::cout << RED << "⚠️ Invalid selection.\n" << RESET;
        return;
    }

    Citizen* citizen = citizens[citizenIndex - 1];

    std::cout << BLUE << "\n📄 Citizen Details:\n" << RESET;
    std::cout << "🔹 Name: " << citizen->getName() << "\n";
    std::cout << "💰 Income: $" << citizen->getIncome() << "\n";
    std::cout << "💼 Job: " << citizen->job << "\n";  
    std::cout << "🏠 Property Value: $" << std::fixed << std::setprecision(2) << citizen->propertyValue << "\n";
    std::cout << "😊 Satisfaction: " << citizen->citySatisfaction << "\n";  
}



void CityFacade::viewAllCitizens(City* city) {
    const auto& citizens = city->getCitizens();

    if (citizens.empty()) {
        std::cout << RED << "❌ No citizens available.\n" << RESET;
        return;
    }

    std::cout << CYAN << "\n=== 👥 All Citizens in the City ===\n" << RESET;
    for (const auto& citizen : citizens) {
        std::cout << "🔹 Name: " << citizen->getName()
                  << " | 💰 Income: $" << citizen->getIncome()
                  << " | 💼 Job: " << citizen->job << "\n"; 
    }
    std::cout << MAGENTA << "=================================\n" << RESET;
}


void CityFacade::removeCitizen(City* city) {
    auto& citizens = city->getCitizens();  // Non-const to allow modifications

    if (citizens.empty()) {
        std::cout << RED << "❌ No citizens available to remove.\n" << RESET;
        return;
    }

    std::cout << CYAN << "👤 Select a citizen to remove:\n" << RESET;
    for (size_t i = 0; i < citizens.size(); ++i) {
        std::cout << i + 1 << ". " << citizens[i]->getName() << "\n";
    }

    int citizenIndex;
    std::cout << "Enter your choice: ";
    std::cin >> citizenIndex;

    if (citizenIndex < 1 || citizenIndex > citizens.size()) {
        std::cout << RED << "⚠️ Invalid selection. Please choose a valid citizen.\n" << RESET;
        return;
    }

    delete citizens[citizenIndex - 1];  // Free memory
    citizens.erase(citizens.begin() + citizenIndex - 1);  // Remove from vector
    std::cout << GREEN << "✅ Citizen removed from the city.\n" << RESET;
}

double CityFacade::averageCitizenTransportSatisfaction(City* city) {
    if (city->getCitizens().empty()) {
        std::cout << RED << "❌ No citizens available to calculate transport satisfaction.\n" << RESET;
        return 0.0;
    }

    SatisfactionChecker* satisfactionChecker = new SatisfactionChecker;
    for (Citizen* citizen : city->getCitizens()) {
        citizen->acceptTransportSatisfactionChecker(satisfactionChecker);
    }

    double satisfaction = satisfactionChecker->transportSatisfactionTotal;
    delete satisfactionChecker;

    double averageSatisfaction = satisfaction / city->getCitizens().size();
    std::cout << ORANGE << "🚗 Average Transport Satisfaction: " << averageSatisfaction << "\n" << RESET;
    return averageSatisfaction;
}



void CityFacade::manageTransportForCitizen(City* city) {
    const auto& citizens = city->getCitizens();

    if (citizens.empty()) {
        std::cout << RED << "❌ No citizens available.\n" << RESET;
        return;
    }

    std::cout << CYAN << "👤 Select a citizen to manage transport:\n" << RESET;
    for (size_t i = 0; i < citizens.size(); ++i) {
        std::cout << i + 1 << ". " << citizens[i]->getName() << "\n";
    }
    int citizenIndex;
    std::cout << "Enter your choice: ";
    std::cin >> citizenIndex;

    if (citizenIndex < 1 || citizenIndex > citizens.size()) {
        std::cout << RED << "⚠️ Invalid citizen selection.\n" << RESET;
        return;
    }

    Citizen* citizen = citizens[citizenIndex - 1];

    // Present transport options to the user
    std::cout << ORANGE << "🚗 Select a transport type:\n" << RESET;
    std::cout << "1. City Car\n";
    std::cout << "2. City Bus\n";
    std::cout << "3. City Plane\n";
    std::cout << "4. City Train\n";
    int transportType;
    std::cout << "Enter your choice: ";
    std::cin >> transportType;

    // Create or retrieve the selected transport type
    Transport* chosenTransport = nullptr;
    switch (transportType) {
        case 1:
            chosenTransport = new Car("City Car", 20, 5);  // Assuming Car is derived from Transport
            break;
        case 2:
            chosenTransport = new Public("City Bus", 30, 10, 30); // Assuming Public is derived from Transport
            break;
        case 3:
            chosenTransport = new Air("City Plane", 60, 40, 80, 50);  // Assuming Air is derived from Transport
            break;
        case 4:
            chosenTransport = new Train("City Train", 45, 30, 90, 30);  // Assuming Train is derived from Transport
            break;
        default:
            std::cout << RED << "⚠️ Invalid transport selection.\n" << RESET;
            return;
    }

    // Assign the chosen transport to the citizen
    citizen->chooseTransport(chosenTransport);
    std::cout << GREEN << "✅ " << citizen->getName() << " has selected " << chosenTransport->getType() << ".\n" << RESET;

    if (chosenTransport != nullptr) {
        std::cout << "🚀 Would you like to transport now? (Please select an option below)\n";
        std::cout << "1. Yes\n";
        std::cout << "2. No\n";
        int ans;
        std::cout << "Enter your choice: ";
        std::cin >> ans;

        switch (ans) {
            case 1:
                citizen->transport();
                std::cout << GREEN << "🚗 " << citizen->getName() << " is now traveling with " << chosenTransport->getType() << ".\n" << RESET;
                break;
            case 2:
                std::cout << YELLOW << "🕒 Transport scheduled for later.\n" << RESET;
                break;
            default:
                std::cout << RED << "⚠️ Invalid selection.\n" << RESET;
                return;
        }
    }
}


double CityFacade::citySatisfactionChecker(City* city) {
    SatisfactionChecker* satisfactionChecker = new SatisfactionChecker();
    for (int i = 0; i < city->citizens.size(); i++) {
        city->citizens[i]->acceptCitySatisfactionChecker(satisfactionChecker);
    }
    for (int i = 0 ; i < city->buildings.size() ; i++){
        city->buildings[i]->acceptCitySatisfactionChecker(satisfactionChecker);
    }
    double citySatisfaction = satisfactionChecker->citySatisfactionTotal;
    delete satisfactionChecker;
    return citySatisfaction;
}


void CityFacade::manageCitizens(City* city) {
    bool managingCitizens = true;
    while (managingCitizens) {
        std::cout << "\n" << CYAN << "👥 Manage Citizens\n" << RESET;
        std::cout << GREEN << "1. Add Custom Citizen\n";
        std::cout << "2. Add Multiple Citizens\n";
        std::cout << "3. View Citizen Information\n";
        std::cout << "4. View All Citizens\n";
        std::cout << "5. Remove Citizen\n";
        std::cout << "6. Manage Transport for Citizen\n"; 
        std::cout << "7. Back to Main Menu\n" << RESET;
        std::cout << "Please select an option: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear input buffer

        switch (choice) {
            case 1:
                std::cout << CYAN << "\n🔹 Adding Custom Citizen...\n" << RESET;
                addCustomCitizen(city);
                break;
            case 2:
                std::cout << CYAN << "\n🔹 Adding Multiple Citizens...\n" << RESET;
                addMultipleCitizens(city);
                break;
            case 3:
                std::cout << CYAN << "\n🔹 Viewing Citizen Information...\n" << RESET;
                viewCitizenInformation(city);
                break;
            case 4:
                std::cout << CYAN << "\n🔹 Viewing All Citizens...\n" << RESET;
                viewAllCitizens(city);
                break;
            case 5:
                std::cout << CYAN << "\n🔹 Removing Citizen...\n" << RESET;
                removeCitizen(city);
                break;
            case 6:
                std::cout << CYAN << "\n🔹 Managing Transport for Citizen...\n" << RESET;
                manageTransportForCitizen(city);
                break;
            case 7:
                std::cout << GREEN << "Returning to Main Menu...\n" << RESET;
                managingCitizens = false;
                break;      
            default:
                std::cout << RED << "❌ Invalid option. Please select again.\n" << RESET;
        }
    }
}



//**********3. MANAGE CITIZENS OPTION**********/



//**********4. MANAGE TRANSPORT OPTION**********/
void CityFacade::manageTransport(City* city) {
    std::cout << CYAN << "\n🚇 How do you want to improve the transport system? \n" << RESET;
    std::cout << GREEN << "1. Build another road\n";
    std::cout << "2. Build another runway\n";
    std::cout << "3. Build another railway\n";
	std::cout << "4. Back to Main Menu\n" << RESET;
    std::cout << "Select an option: ";

    int ans;
    std::cin >> ans;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear input buffer

    switch (ans) {
        case 1: {  // Build a road
            RoadFactory roadFactory;
            int lanes = 0;
            double length = 0.0;

            std::cout << CYAN << "\n🚗 Building a Road...\n" << RESET;

            // Ask for the number of lanes
            do {
                std::cout << "How many lanes would you like your road to have?\n";
                std::cout << "1. 1 lane\n";
                std::cout << "2. 2 lanes\n";
                std::cout << "3. 3 lanes\n";
                std::cout << "4. 4 lanes\n";
                std::cin >> lanes;
            } while (lanes < 1 || lanes > 4);

            // Ask for the length of the road
            do {
                std::cout << "What length would you like your road to have? (Please type a value between 10 and 100 km)\n";
                std::cin >> length;
            } while (length < 10 || length > 100);

            // Create and build the road infrastructure
            TransportInfrastructure* road = roadFactory.createInfrastructure(lanes, length);
            road->build();
            city->addInfrastructure(road);

            std::cout << GREEN << "🚧 Road created with " << lanes << " lanes and length " << length << " km\n" << RESET;
            break;
        }

        case 2: {  // Build a runway
            RunwayFactory runwayFactory;
            double runwayLength = 0.0;
            double width = 0.0;

            std::cout << CYAN << "\n🛫 Building a Runway...\n" << RESET;

            // Ask for the length of the runway
            do {
                std::cout << "How long do you want your runway to be? (Please type a number between 3 to 7 km)\n";
                std::cin >> runwayLength;
            } while (runwayLength < 3 || runwayLength > 7);

            // Ask for the width of the runway
            do {
                std::cout << "What width would you like your runway to be? (Please type a value between 0.5 to 3 km)\n";
                std::cin >> width;
            } while (width < 0.5 || width > 3);

            // Create and build the runway infrastructure
            TransportInfrastructure* runway = runwayFactory.createInfrastructure(runwayLength, width);
            runway->build();
            city->addInfrastructure(runway);

            std::cout << GREEN << "🛬 Runway created with " << runwayLength << " km length and " << width << " km width\n" << RESET;
            break;
        }

        case 3: {  // Build a railway
            RailwayFactory railwayFactory;
            int railwayLength = 0;

            std::cout << CYAN << "\n🚆 Building a Railway...\n" << RESET;

            // Ask for the length of the railway
            do {
                std::cout << "How long do you want your railway to be? (Please type a number between 10 to 100 km)\n";
                std::cin >> railwayLength;
            } while (railwayLength < 10 || railwayLength > 100);

            // Create and build the railway infrastructure
            TransportInfrastructure* railway = railwayFactory.createInfrastructure(railwayLength, true);
            railway->build();
            city->addInfrastructure(railway);

            std::cout << GREEN << "🚄 Electrified railway created with " << railwayLength << " km in length\n" << RESET;
            break;
        }

        default:
            std::cout << RED << "❌ Invalid selection. Please try again.\n" << RESET;
            return;
    }
}

//**********4. MANAGE TRANSPORT OPTION**********/

//**********5. INCREASE POPULATION OPTION**********/
void CityFacade::increasePopulation(City* city) {
    std::cout << MAGENTA << "✨ You wish to welcome more people into your city!\n"
              << "By what growth factor would you like to increase the population (enter a number between 0 and 100): " << RESET;
    double increase;
    std::cin >> increase;

    // Validate population increase input
    if (increase < 0 || increase > 100) {
        std::cout << RED << "❌ Invalid input. Please enter a value between 0 and 100.\n" << RESET;
        return;
    }

    // Create Buildings for Potential Expansion
    Residential* residentialBuilding = new Residential(
        "Wizard’s Haven", 30, 5000, 300, true, 1, true, 300, "Residential District"
    );
    Commercial* commercialBuilding = new Commercial(
        "Potion Emporium", 20, 30000, 1000, true, 1, true, 50, "Market Square"
    );
    Industrial* industrialBuilding = new Industrial(
        "Alchemy Workshop", 10, 20000, 2000, true, 1, true, 350, "Industrial Zone"
    );
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

    // Clean up
    delete residentialBuilding;
    delete commercialBuilding;
    delete industrialBuilding;
    delete landmarkBuilding;

}

//**********5. INCREASE POPULATION OPTION**********/



//**********6. SHOW STATS OPTION**********/
void CityFacade::displayCityStats(City* city) {
    std::cout << CYAN << "\n=== City Statistics ===\n" << RESET;

    // Population and Citizen Stats
    std::cout << ORANGE << "Population: " << RESET << city->citizens.size() << " citizens\n";
    
    double citySatisfaction = citySatisfactionChecker(city);
    double averageSatisfaction = citySatisfaction / (city->citizens.size() + city->listBuildings().size());
    std::cout << ORANGE << "Average City Satisfaction Across Buildings and Citizens: " << RESET
              << averageSatisfaction << "%\n";

    // Building Stats
    std::cout << BLUE << "\nBuilding Statistics:\n" << RESET;
    std::cout << " - Total Buildings: " << city->listBuildings().size() << "\n";
    int residentialCount = 0, commercialCount = 0, industrialCount = 0, landmarkCount = 0;
    for (Building* building : city->listBuildings()) {
        if (dynamic_cast<Residential*>(building)) ++residentialCount;
        else if (dynamic_cast<Commercial*>(building)) ++commercialCount;
        else if (dynamic_cast<Industrial*>(building)) ++industrialCount;
        else if (dynamic_cast<Landmark*>(building)) ++landmarkCount;
    }
    std::cout << "   * Residential Buildings: " << residentialCount << "\n";
    std::cout << "   * Commercial Buildings: " << commercialCount << "\n";
    std::cout << "   * Industrial Buildings: " << industrialCount << "\n";
    std::cout << "   * Landmarks: " << landmarkCount << "\n";

    // Utility Stats
    std::cout << BLUE << "\nUtility Capacity and Usage:\n" << RESET;
    for (Utilities* utility : city->listUtilities()) {
        utility->displayInfo();  // Assuming displayInfo shows capacity and usage
    }

    // Transport Infrastructure
    std::cout << BLUE << "\nTransport Infrastructure:\n" << RESET;
    int roadCount = 0, railwayCount = 0, runwayCount = 0;
    for (TransportInfrastructure* infrastructure : city->listInfrastructures()) {
        if (dynamic_cast<Road*>(infrastructure)) ++roadCount;
        else if (dynamic_cast<Railway*>(infrastructure)) ++railwayCount;
        else if (dynamic_cast<Runway*>(infrastructure)) ++runwayCount;
    }
    std::cout << "   * Roads: " << roadCount << "\n";
    std::cout << "   * Railways: " << railwayCount << "\n";
    std::cout << "   * Runways: " << runwayCount << "\n";

    // Economic and Financial Stats
    Government* government = city->getGovernment();
    if (government) {
        std::cout << BLUE << "\nEconomic and Financial Statistics:\n" << RESET;
        Tax* taxDept = government->getTaxDepartment();
        Budget* budgetDept = government->getBudgetDepartment();
        
        if (taxDept) {
            std::cout << "   * Total Revenue (from taxes): $" << taxDept->getTotalRevenue() << "\n";
            std::cout << "   * Current Tax Rate: " << taxDept->getTaxRate() * 100 << "%\n";
        }
        if (budgetDept) {
            std::cout << "   * Total Budget: $" << budgetDept->getTotalBudget() << "\n";
            std::cout << "   * Available Budget: $" << budgetDept->getAvailableBudget() << "\n";
        }
    }

    // Policies and Services
    std::cout << BLUE << "\nPolicies and Services:\n" << RESET;
    Policies* policiesDept = government->getPoliciesDepartment();
    Services* servicesDept = government->getServicesDepartment();
    
    if (policiesDept) {
        std::cout << "   * Active Policies: " << policiesDept->getActivePoliciesCount() << "\n";  // Assuming this method exists
    }
    if (servicesDept) {
        std::cout << "   * Healthcare Facilities: " << servicesDept->getHealthcareFacilities() << "\n";  // Assuming getter exists
        std::cout << "   * Educational Institutions: " << servicesDept->getEducationalInstitutions() << "\n";
    }

    std::cout << MAGENTA << "=============================\n" << RESET;
}

//**********6. SHOW STATS OPTION**********/