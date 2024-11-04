/**
 * @class CityFacade
 * @brief A facade class that provides a high-level interface for managing a city simulation.
 * 
 * The CityFacade class is designed to encapsulate complex interactions within the city 
 * management system, providing easy-to-use methods to control and manage various aspects 
 * of city operations, buildings, citizens, transport, and more.
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <ctime>
#include <algorithm>
#include <regex>

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

/**
 * @brief Default constructor for the CityFacade class.
 */
CityFacade::CityFacade() {
}

/**
 * @brief Main function to start and manage the city simulation.
 * 
 * This function introduces the simulation with a story-driven prompt, guides the user
 * through the process of naming and creating the city, setting up initial buildings, utilities, 
 * transport, government, and citizens, and provides a menu for managing various aspects of the city.
 * 
 * The user can interactively choose options to manage government, buildings, citizens, 
 * transport, and city statistics. The simulation continues until the user decides to exit.
 * 
 * @details 
 * - A city name is prompted from the user and used to create a new City object.
 * - The city is initialized with essential structures, utilities, and citizens.
 * - A looped main menu presents options for city management and viewing city stats.
 * - Proper input handling ensures robustness against invalid inputs.
 * - Resources are cleaned up upon exiting the simulation.
 */
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
    std::regex nameRegex("^[A-Za-z ]{1,50}$"); // Allows only alphabets and spaces, up to 50 characters

    while (true) {
        std::cout << GREEN << "🏙️  Enter the name of your new city: " << RESET;
        std::getline(std::cin, cityName);

        if (cityName.empty()) {
            std::cout << RED << "❗ City name cannot be empty. Please enter a valid name.\n" << RESET;
        } else if (!std::regex_match(cityName, nameRegex)) {
            std::cout << RED << "❗ Invalid name. The city name can only contain alphabets and spaces, and must be up to 50 characters.\n" << RESET;
        } else {
            break; // Name is valid
        }
    }

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

        // std::cin.ignore();

        switch (choice) {
            case 1:
                // Manage Government
                std::cout << YELLOW << "\n🏛️  You open the grand doors to the city hall...\n" << RESET;
                manageGovernment(ourCity);
                break;

            case 2:
                // Build and Manage Buildings
                std::cout << CYAN << "\n🏗️  You look out over the land, ready to build...\n" << RESET;
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
/**
 * @brief Pauses the simulation, prompting the user to press enter to continue.
 * 
 * This method displays a message to the user, requesting them to press the enter key,
 * which allows for pacing between stages of the city simulation.
 */
void CityFacade::pauseForUser() {
    std::cout << BOLD << BLUE << "\nPress enter to continue..." << RESET;
    std::cin.get();
}

/**
 * @brief Initializes the city's resources at the start of the simulation.
 * 
 * This method calls the singleton instance of the `ResourceManagement` class 
 * and initializes base resources needed for city operations.
 */
void CityFacade::initializeResources() {
    ResourceManagement& resourceManager = ResourceManagement::getInstance();
    resourceManager.createResources();  // Initialize base resources
}

/**
 * @brief Initializes and adds the foundational buildings to the city.
 * 
 * This function creates an initial set of buildings, including a residential building,
 * a commercial building, an industrial building, and a landmark. Each building is given
 * a name, satisfaction rating, economic impact, resource consumption, construction status,
 * improvement level, and specific location within the city. After creation, each building
 * is added to the city and displayed to the user.
 * 
 * @param city Pointer to the City object where the buildings are added.
 */
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


/**
 * @brief Creates and assigns essential utilities to the city and its buildings.
 * 
 * This function initializes the primary utilities for the city, including water, waste management,
 * sewage, and power. Each utility is created using its respective factory, added to the city, and 
 * allocated resources through the resource manager. After creating utilities, they are assigned to
 * each building in the city.
 * 
 * @param city Pointer to the City object where utilities are added and assigned to buildings.
 */
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

/**
 * @brief Creates and assigns essential transport infrastructure to the city.
 * 
 * This method utilizes factory classes to create primary city transport systems,
 * including roads, railways, and runways. Each infrastructure element is built and 
 * added to the city's infrastructure.
 * 
 * @param city Pointer to the City object where infrastructure is added.
 */
void CityFacade::createAndAssignTransport(City* city) {
    std::cout << PURPLE << BOLD << "\n🛤️  The wizard conjures essential transport infrastructure for the city...\n" << RESET;

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

/**
 * @brief Sets up a government with various departments to manage the city.
 * 
 * This function creates a government structure with departments for budget, policies, 
 * services, and taxation. It assigns the government to the city to handle administrative 
 * and civic responsibilities.
 * 
 * @param city Pointer to the City object to which the government is assigned.
 */
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
    std::cout << PURPLE << BOLD << "\n🏛️  Government and departments successfully established for the city.\n" << RESET;
    pauseForUser();
}

/**
 * @brief Creates an initial population of citizens and assigns them to the city.
 * 
 * This function generates a small group of citizens with randomized names, incomes, 
 * property values, and jobs, using a prototype citizen for predefined attributes. 
 * Each citizen is assigned to an available residential building if space permits.
 * 
 * @param city Pointer to the City object where citizens are created and assigned.
 */
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
/**
 * @brief Displays the main menu of the city simulation.
 * 
 * This function presents options for managing various aspects of the city,
 * including government, buildings, citizens, transport, population, and city status.
 * The user is prompted to select an option to proceed with the simulation.
 */
void CityFacade::showMainMenu() {
    std::cout << BOLD << BLUE << "\n========== 🏙️  Main Menu  🏙️ ==========\n" << RESET;
    std::cout << GREEN << "1. 🏛️  Manage Government\n";
    std::cout << "2. 🏢 Build and Manage Buildings\n";
    std::cout << "3. 👥 Manage Citizens\n";
    std::cout << "4. 🚗 Manage Transport\n";
    std::cout << "5. 🌆 Change City Population\n";
    std::cout << "6. 📊 Show City Status\n";
    std::cout << "7. 🚪 Exit Simulation\n" << RESET;
    std::cout << BOLD << ORANGE << "\nPlease select an option: " << RESET;
}
//**********MAIN MENU**********/

/**
 * @brief Adds tax-related commands to the Tax department.
 * 
 * This function creates and configures tax-related commands, such as collecting
 * and increasing taxes. These commands are then added to the Tax department.
 * It also links the city's citizens and buildings to the commands for effective
 * operation on each entity in the city.
 * 
 * @param taxDept Pointer to the Tax department where commands will be added.
 * @param city Pointer to the City containing the citizens and buildings.
 */
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

/**
 * @brief Executes the tax collection process using the Visitor pattern.
 * 
 * This function initializes building values, collects rent or revenue based on
 * building type, and adds necessary commands to the Tax department for tax-related
 * operations. The TaxCollector visitor then traverses the city’s citizens and buildings,
 * applying tax calculations to each entity. Finally, the total collected tax is returned.
 * 
 * @param taxDept Pointer to the Tax department managing tax operations.
 * @param city Pointer to the City containing citizens and buildings for tax collection.
 * @return The total amount of tax collected from citizens and buildings.
 */
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
/**
 * @brief Manages the Tax Department, allowing for tax rate increases, tax collection,
 * and viewing total revenue collected.
 * 
 * @param taxDept Pointer to the Tax department for managing tax operations.
 * @param budgetDept Pointer to the Budget department to allocate collected taxes.
 * @param city Pointer to the City containing citizens and buildings to be taxed.
 */
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
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the invalid input
            std::cout << RED << "❗ Invalid input. Please enter a number between 1 and 4.\n" << RESET;
            continue; // Restart the loop
        }

        // std::cin.ignore();

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


/**
 * @brief Manages the Budget Department, allowing for fund allocation and budget details viewing.
 * 
 * This function provides options to allocate funds from the budget and display the
 * current budget details, which are operated within the Budget department.
 * 
 * @param budgetDept Pointer to the Budget department for budget operations.
 */
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
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the invalid input
            std::cout << RED << "❗ Invalid input. Please enter a number between 1 and 3.\n" << RESET;
            continue; // Restart the loop
        }

        // std::cin.ignore();

        switch (choice) {
            case 1: {
                double amount;
                while (true) {
                    std::cout << ORANGE << "💰 Enter amount to allocate (1 - 10,000): " << RESET;
                    std::cin >> amount;

                    // Validate that the input is within range and is a number
                    if (std::cin.fail() || amount < 1 || amount > 10000) {
                        std::cin.clear(); // Clear the error flag
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
                        std::cout << RED << "❌ Invalid amount. Please enter a number between 1 and 10,000.\n" << RESET;
                    } else {
                        break; // Valid input
                    }
                }

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


/**
 * @brief Manages the Policies Department, enabling policy addition, removal, and viewing active policies.
 * 
 * This function facilitates the addition and removal of city policies and displays
 * a list of all active policies managed by the Policies department.
 * 
 * @param policiesDept Pointer to the Policies department for policy management.
 */
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
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the invalid input
            std::cout << RED << "❗ Invalid input. Please enter a number between 1 and 4.\n" << RESET;
            continue; // Restart the loop
        }

        // std::cin.ignore();

        switch (choice) {
            case 1: {
                std::string policy;
                std::cout << ORANGE << "📝 Enter policy to add " << RESET;
                std::getline(std::cin, policy);

                // Validate policy input
                if (policy.length() > 20 || !std::regex_match(policy, std::regex("^[a-zA-Z0-9 ]+$"))) {
                    std::cout << RED << "❌ Invalid policy name. Ensure it contains only letters, numbers, and spaces, and is no longer than 20 characters.\n" << RESET;
                } else {
                    policiesDept->addPolicy(policy);
                    std::cout << GREEN << "✅ Policy added: \"" << policy << "\"\n" << RESET;
                }
                break;
            }
            case 2: {
                std::string policy;
                std::cout << ORANGE << "📄 Current Active Policies:\n" << RESET;
                std::vector<std::string> activePolicies = policiesDept->getActivePolicies();  // Assume this method returns a vector of active policy names
                for (const auto& activePolicy : activePolicies) {
                    std::cout << " - " << activePolicy << "\n";
                }

                std::cout << ORANGE << "🗑️  Enter policy to remove: " << RESET;
                std::getline(std::cin, policy);

                // Check if policy is in the list of active policies
                if (std::find(activePolicies.begin(), activePolicies.end(), policy) != activePolicies.end()) {
                    policiesDept->removePolicy(policy);
                    std::cout << GREEN << "✅ Policy removed: \"" << policy << "\"\n" << RESET;
                } else {
                    std::cout << RED << "❌ Policy \"" << policy << "\" does not exist in active policies.\n" << RESET;
                }
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


/**
 * @brief Manages the Services Department, allowing for the addition of new service programs
 * and viewing current services.
 * 
 * This function allows the addition of various city service programs and displays a list
 * of current service programs managed by the Services department.
 * 
 * @param servicesDept Pointer to the Services department for service program management.
 */
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
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the invalid input
            std::cout << RED << "❗ Invalid input. Please enter a number between 1 and 3.\n" << RESET;
            continue; // Restart the loop
        }

        // std::cin.ignore();

        switch (choice) {
            case 1: {
                std::string program;
                std::cout << ORANGE << "📝 Enter service program to add (letters, numbers, spaces; max 20 chars): " << RESET;
                std::getline(std::cin, program);
                
                // Validate input to ensure only letters, numbers, and spaces, and max length of 20
                if (program.size() > 20 || !std::all_of(program.begin(), program.end(), [](char c) { return std::isalnum(c) || std::isspace(c); })) {
                    std::cout << RED << "❌ Invalid service program name. Please use only letters, numbers, and spaces, up to 20 characters.\n" << RESET;
                } else {
                    servicesDept->addServiceProgram(program);
                    std::cout << GREEN << "✅ Service program added: \"" << program << "\"\n" << RESET;
                }
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


/**
 * @brief Handles the main Government Management menu, allowing access to different departments.
 * 
 * This function displays options to manage various government departments, including Tax,
 * Budget, Policies, and Services. It enables interaction with each department based on user choice.
 * 
 * @param city Pointer to the City containing the government and its departments.
 */
void CityFacade::manageGovernment(City* city) {
    bool managingGovernment = true;
    while (managingGovernment) {
        std::cout << "\n" << BOLD << CYAN << "🏛️ Manage Government 🏛️\n" << RESET;
        std::cout << GREEN << "1. 💰 Tax Department\n";
        std::cout << "2. 💵 Budget Department\n";
        std::cout << "3. 📜 Policies Department\n";
        std::cout << "4. 🛠️  Services Department\n";
        std::cout << "5. 🔙 Return to Main Menu\n" << RESET;
        std::cout << BOLD << ORANGE << "Select an option: " << RESET;

        int choice;
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the invalid input
            std::cout << RED << "❗ Invalid input. Please enter a number between 1 and 5.\n" << RESET;
            continue; // Restart the loop
        }

        // std::cin.ignore();

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
/**
 * @brief Constructs a new building based on user input and adds it to the city.
 *
 * This function asks the user for the type of building to construct, its name, and
 * then uses the appropriate creator to create the building. It also checks if the
 * city's budget can cover the cost of the building and deducts the cost from the
 * budget if possible.
 *
 * @param city The city object to add the new building to.
 */
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
            std::cout << "🏗️  Building constructed: " << newBuilding->getType() << "\n" << RESET;
        }
    } else {
        std::cout << RED << "🚫 Insufficient budget to construct this building.\n" << RESET;
        delete newBuilding;  // Clean up the allocated memory
    }
}



/**
 * @brief Allows the user to inspect a building in the city by selecting it from a list.
 * 
 * This function lists all buildings in the city, prompts the user to select a building to inspect, 
 * and displays details of the selected building.
 * 
 * @param city Pointer to the City containing buildings to inspect.
 */
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


/**
 * @brief Allows the user to improve a building in the city.
 * 
 * This function lists all buildings in the city, prompts the user to select a building to improve,
 * and performs the improvement on the selected building.
 * 
 * @param city Pointer to the City containing buildings to improve.
 */

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

/**
 * @brief Removes a building from the city, checking if it is a residential building with occupants.
 * 
 * This function lists all buildings, prompts the user to select one for removal, and deletes the
 * selected building if it is not occupied (for residential buildings).
 * 
 * @param city Pointer to the City containing buildings to remove.
 */
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

/**
 * @brief Calculates and returns the city satisfaction level for a specified building.
 * 
 * Uses a SatisfactionChecker to assess the satisfaction impact the building has on the city.
 * 
 * @param building Pointer to the Building whose city satisfaction level will be calculated.
 * @return double representing the city satisfaction impact of the building.
 */
double CityFacade::buildingCitySatisfaction(Building* building) {
    SatisfactionChecker* satisfactionChecker = new SatisfactionChecker();
    building->acceptCitySatisfactionChecker(satisfactionChecker);
    double satisfaction = satisfactionChecker->citySatisfactionTotal;
    delete satisfactionChecker;
    return satisfaction;
}

/**
 * @brief Calculates and returns the average citizen satisfaction level for a specified building.
 * 
 * Uses a SatisfactionChecker to calculate the average satisfaction level of citizens observing the building.
 * 
 * @param building Pointer to the Building for which citizen satisfaction is calculated.
 * @return double representing the average citizen satisfaction in the building.
 */
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

/**
 * @brief Displays a summary of all buildings in the city, including city satisfaction and economic impact.
 * 
 * This function iterates through all buildings in the city and prints details for each, 
 * including city satisfaction, economic impact, and average citizen satisfaction (for residential buildings).
 * 
 * @param city Pointer to the City containing buildings to display.
 */
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

/**
 * @brief Increases the rent for a selected residential building in the city.
 * 
 * This function lists all residential buildings, prompts the user to select one, and increases its rent.
 * The new rent must be greater than the current rent.
 * 
 * @param city Pointer to the City containing residential buildings to adjust rent.
 */
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

/**
 * @brief Manages building-related operations within the city.
 * 
 * This function provides options to build, inspect, improve, remove, view, and manage rent for buildings 
 * in the city, allowing the user to interact with each operation through a menu.
 * 
 * @param city Pointer to the City containing buildings to manage.
 */
void CityFacade::manageBuildings(City* city) {
    bool buildingManagement = true;
    while (buildingManagement) {
        std::cout << "\n" << CYAN << BOLD << "🏢  Manage Buildings 🏢\n" << RESET;
        std::cout << GREEN << "1. 🏗️  Build New Building\n";
        std::cout << "2. 🔍 Inspect Building\n";
        std::cout << "3. 🔧 Improve Building\n";
        std::cout << "4. 🗑️  Remove Building\n";
        std::cout << "5. 📋 View All Buildings\n";
        std::cout << "6. 💸 Increase Rent of Residential Building\n";
        std::cout << "7. 🔙 Back to Main Menu\n" << RESET;
        std::cout << "Select an option: ";

        int choice;
        std::cin >> choice;
        // Check for invalid input
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the invalid input
            std::cout << RED << "❗ Invalid input. Please enter a number between 1 and 7.\n" << RESET;
            continue; // Restart the loop
        }

        // std::cin.ignore();

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

/**
 * @brief Adds a custom citizen to the city with specified attributes.
 * 
 * Prompts the user to input a citizen's name, job, income, and property value.
 * Attempts to assign the citizen to a residential building with available space.
 * If no space is available, the citizen is not added.
 * 
 * @param city Pointer to the City where the citizen will be added.
 */
void CityFacade::addCustomCitizen(City* city) {
    // if (city->getTotalPopulation() >= 200) {
    //     std::cout << RED << "🚫 Maximum population reached. Cannot add more citizens.\n" << RESET;
    //     return;
    // }

    std::string name, job;
    int income;
    double propertyValue;

    // Validate the citizen's name
    while (true) {
        std::cout << "👤 Enter the name of the new citizen: ";
        std::getline(std::cin, name);

        if (name.size() <= 25 && std::all_of(name.begin(), name.end(), [](char c) { return std::isalpha(c) || std::isspace(c); })) {
            break;
        } else {
            std::cout << RED << "❌ Invalid name. Please use only letters and spaces, up to 25 characters.\n" << RESET;
        }
    }

    // Validate the citizen's job
    while (true) {
        std::cout << "💼 Enter the job of the new citizen: ";
        std::getline(std::cin, job);

        if (job.size() <= 25 && std::all_of(job.begin(), job.end(), [](char c) { return std::isalpha(c) || std::isspace(c); })) {
            break;
        } else {
            std::cout << RED << "❌ Invalid job title. Please use only letters and spaces, up to 25 characters.\n" << RESET;
        }
    }

    // Validate the citizen's income
    while (true) {
        std::cout << "💵 Enter the income of the new citizen (max 100,000): ";
        std::cin >> income;

        if (std::cin.fail() || income < 0 || income > 100000) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore invalid input
            std::cout << RED << "❌ Invalid income. Please enter a positive number up to 100,000.\n" << RESET;
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear any leftover input
            break;
        }
    }

    // Validate the citizen's property value
    while (true) {
        std::cout << "🏡 Enter the property value owned by the new citizen (between 50,000 and 1,000,000): ";
        std::cin >> propertyValue;

        if (std::cin.fail() || propertyValue < 50000 || propertyValue > 1000000) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore invalid input
            std::cout << RED << "❌ Invalid property value (between 50,000 and 1,000,000)\n" << RESET;
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear any leftover input
            break;
        }
    }

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


/**
 * @brief Adds multiple randomly generated citizens to the city.
 * 
 * Prompts the user to specify the number of citizens to add (between 1 and 10).
 * Each citizen is generated with random attributes and assigned to a residential
 * building if available.
 * 
 * @param city Pointer to the City where the citizens will be added.
 */
void CityFacade::addMultipleCitizens(City* city) {
    int numberOfCitizens;
    std::cout << "👥 Enter the number of citizens to add (1 to 10): ";
    std::cin >> numberOfCitizens;

    if (numberOfCitizens < 1 || numberOfCitizens > 10) {
        std::cout << RED << "❌ Invalid number. Please enter a value between 1 and 10.\n" << RESET;
        return;
    }

    int currentPopulation = city->getTotalPopulation();
    // if (currentPopulation + numberOfCitizens > 200) {
    //     std::cout << RED << "🚫 Adding " << numberOfCitizens << " citizens would exceed the maximum population limit of 200.\n" << RESET;
    //     return;
    // }

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


/**
 * @brief Displays detailed information for a selected citizen.
 * 
 * Lists all citizens in the city and prompts the user to select one.
 * Displays the selected citizen's details, including name, income, job,
 * property value, and satisfaction level.
 * 
 * @param city Pointer to the City containing citizens to view.
 */
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


/**
 * @brief Displays a summary of all citizens in the city.
 * 
 * Iterates over all citizens in the city and prints their name, income, and job.
 * 
 * @param city Pointer to the City containing citizens to display.
 */
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

/**
 * @brief Removes a citizen from the city.
 * 
 * Lists all citizens in the city and prompts the user to select one to remove.
 * The selected citizen is deleted from memory and removed from the city's list of citizens.
 * 
 * @param city Pointer to the City containing citizens to remove.
 */
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

/**
 * @brief Calculates the average transport satisfaction level of all citizens.
 * 
 * Uses a SatisfactionChecker to assess the average transport satisfaction
 * of all citizens in the city.
 * 
 * @param city Pointer to the City containing citizens to assess.
 * @return double representing the average transport satisfaction.
 */
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


/**
 * @brief Manages transport selection for a specified citizen.
 * 
 * Lists all citizens and prompts the user to select one. Then presents transport options 
 * (Car, Bus, Plane, or Train) and allows the user to assign the selected transport to the citizen.
 * Optionally, the user can choose to transport the citizen immediately.
 * 
 * @param city Pointer to the City containing citizens to manage transport for.
 */
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

/**
 * @brief Calculates the overall city satisfaction level.
 * 
 * Uses a SatisfactionChecker to calculate the city satisfaction level by
 * assessing the satisfaction of all citizens and buildings in the city.
 * 
 * @param city Pointer to the City to calculate satisfaction for.
 * @return double representing the total city satisfaction level.
 */
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

/**
 * @brief Manages citizen-related operations within the city.
 * 
 * Provides options to add custom citizens, add multiple citizens, view citizen information,
 * view all citizens, remove citizens, manage transport, and return to the main menu.
 * 
 * @param city Pointer to the City containing citizens to manage.
 */
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
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the invalid input
            std::cout << RED << "❗ Invalid input. Please enter a number between 1 and 7.\n" << RESET;
            continue; // Restart the loop
        }

        // std::cin.ignore();

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
/**
 * @brief Manages the transport infrastructure within the city by providing options to build roads, runways, or railways.
 * 
 * Prompts the user to select a type of transport infrastructure to improve. Depending on the choice,
 * it further asks for specific attributes like the number of lanes for a road, length and width for a runway, 
 * or length for a railway. Once the inputs are validated, the corresponding infrastructure is created, built, 
 * and added to the city.
 * 
 * @param city Pointer to the City where the transport infrastructure will be added.
 */
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

/**
 * @brief Increases the city's population based on a user-defined growth factor.
 * 
 * Prompts the user to specify a growth factor to control the population increase (0 to 100). 
 * The function validates the input, initializes buildings for potential expansion, and sets up a chain of responsibility 
 * to manage population, housing, economic impact, and infrastructure adjustments accordingly. 
 * The chain of responsibility includes `Population`, `Housing`, `Economic`, and `Infrastructure` handlers, 
 * which process the increase request and make necessary changes to the city.
 * 
 * @param city Pointer to the City where the population growth will be managed.
 */
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

/**
 * @brief Displays comprehensive statistics of the city, including population, building types, utilities, transport infrastructure, and government financials.
 * 
 * This function provides a detailed report of the city's current status, showing key metrics across various domains:
 * - **Population**: Total number of citizens and average city satisfaction.
 * - **Building Statistics**: Total count of each building type (residential, commercial, industrial, landmarks).
 * - **Utility Usage**: Displays each utility's capacity and usage.
 * - **Transport Infrastructure**: Number of roads, railways, and runways in the city.
 * - **Economic and Financial Overview**: Tax revenue, tax rate, and budget information from the government.
 * - **Policies and Services**: Active policies and availability of healthcare and educational services.
 * 
 * @param city Pointer to the City object for which statistics are displayed.
 */
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