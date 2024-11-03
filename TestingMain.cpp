#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "CollectTax.h"
#include "SatisfactionChecker.h"
#include "Citizen.h"
#include "Industrial.h"
#include "WaterFactory.h"
#include "WasteFactory.h"
#include "SewageFactory.h"
#include "PowerPlantFactory.h"
#include "ResourceManagerment.h"

#include "Government.h"  
#include "Tax.h"
#include "Budget.h"
#include "Policies.h"
#include "Services.h"
#include "Department.h"
#include "Utilities.h"
#include "IncreaseTax.h"
#include "City.h"
#include "Visitor.h"
#include "Command.h"
#include "TaxCollector.h"

#include "Citizen.h"
#include "Building.h"
#include "Residential.h"
#include "Commercial.h"
#include "Industrial.h"
#include "Landmark.h"


TEST_CASE("Citizen Collect Tax"){
    Citizen* citizen = new Citizen("Tony", 1000);
    Industrial * industrial = new Industrial();
    CollectTax* ct = new CollectTax(citizen, industrial);
    ct->execute();
    //REQUIRE(ct->execute() == "Property Tax collected from Industrial Building\nProperty Tax of: 0 collected\nIncome Tax collected from citizens\nTime to collect Income Tax from citizens\nTax paid: 150");
}

// //Testing BuildingObserver
// // Test case for Building Observer functionality
// TEST_CASE("Building Observer Notifications", "[ObserverPattern]") {
//     // Create citizens
//     Citizen alice("Alice", 50000, 250000);
//     Citizen bob("Bob", 60000, 300000);
//     Citizen charlie("Charlie", 70000, 350000);

//     // Create different types of buildings
//     Residential apartment("Sunset Apartments", 80, 5000, 200, true, 1, true, 150, "Suburb");
//     Commercial mall("City Mall", 75, 10000, 500, true, 1, true, 1000, "Suburb");
//     Industrial factory("Steel Factory", 70, 15000, 1000, true, 1, true, 300, "Industrial");
//     Landmark monument("Freedom Monument", 90, 8000, 500, true, 1, true, 70, "Suburb");

//     // Attach citizens to different buildings
//     apartment.attach(&alice);
//     mall.attach(&alice);
//     factory.attach(&bob);
//     monument.attach(&charlie);

//     SECTION("Notify citizens about improvements in Residential Building") {
//         apartment.doImprovements();  
//         REQUIRE(alice.isNotified() == true);
//         alice.resetNotification();
//     }

//     SECTION("Notify citizens about improvements in Commercial Building") {
//         mall.doImprovements();  
//         REQUIRE(alice.isNotified() == true);
//         alice.resetNotification();
//     }

//     SECTION("Notify citizens about improvements in Industrial Building") {
//         factory.doImprovements();  
//         REQUIRE(bob.isNotified() == true);
//         bob.resetNotification();
//     }

//     SECTION("Notify citizens about improvements in Landmark") {
//         monument.doImprovements();  
//         REQUIRE(charlie.isNotified() == true);
//         charlie.resetNotification();
//     }

//     SECTION("Detach citizen and verify no notification") {
//         mall.detach(&alice);
//         mall.doImprovements();
//         REQUIRE(alice.isNotified() == false);  // Alice should not be notified
//     }
// }



// //Testing Composite
// TEST_CASE("Government operates all departments") {
//     Government cityGovernment(0.15, 0.05);

//     // Creating departments
//     Tax taxDept("Tax Department", 15.0f);
//     Budget budgetDept("Budget Department", 10000.0);
//     Policies policiesDept("Policies Department");
//     Services servicesDept("Public Services", 5, 10, 3);

//     // Adding policies and service programs
//     policiesDept.addPolicy("Environmental Protection");
//     policiesDept.addPolicy("Healthcare Reform");
//     servicesDept.addServiceProgram("Free Education Initiative");
//     servicesDept.addServiceProgram("Healthcare for All");

//     // Adding departments to the Government composite
//     cityGovernment.add(&taxDept);
//     cityGovernment.add(&budgetDept);
//     cityGovernment.add(&policiesDept);
//     cityGovernment.add(&servicesDept);

//     // Operating government
//     cityGovernment.operate();
//     REQUIRE(cityGovernment.getChild(0) == &taxDept);  // Verify child exists
// }

// TEST_CASE("Adding and Removing Departments in Government") {
//     Government cityGovernment(0.15, 0.05);

//     Tax taxDept("Tax Department", 15.0f);
//     Budget budgetDept("Budget Department", 10000.0);

//     cityGovernment.add(&taxDept);
//     REQUIRE(cityGovernment.getChild(0) == &taxDept);

//     cityGovernment.add(&budgetDept);
//     REQUIRE(cityGovernment.getChild(1) == &budgetDept);

//     // Removing tax department
//     cityGovernment.remove(&taxDept);
//     REQUIRE(cityGovernment.getChild(0) == &budgetDept);
// }

// TEST_CASE("Policies and Services operate correctly") {
//     Policies policiesDept("Policies Department");
//     Services servicesDept("Public Services", 5, 10, 3);

//     policiesDept.addPolicy("Environmental Protection");
//     REQUIRE(policiesDept.getName() == "Policies Department");

//     servicesDept.addServiceProgram("Free Education Initiative");
//     REQUIRE(servicesDept.getName() == "Public Services");

//     policiesDept.operate();
//     servicesDept.operate();
// }

// TEST_CASE("Tax department sets and tracks revenue correctly") {
//     Tax taxDept("Tax Department", 10.0f);
//     taxDept.setTaxRate(0.2f);
//     REQUIRE(taxDept.getTaxRate() == 0.2f);

//     taxDept.trackRevenue(1000.0);
//     REQUIRE(taxDept.getTaxRate() == 0.2f);
// }

// //Testing Utility Factories
// // Example test for WaterFactory and Water utility
// TEST_CASE("WaterFactory creates Water utility") {
//     WaterFactory waterFactory;
//     Utilities* waterUtility = waterFactory.createUtility();

//     REQUIRE(waterUtility != nullptr);  // Check that utility was created
//     REQUIRE_NOTHROW(waterUtility->displayInfo());  // Ensure displayInfo doesn't throw
//     REQUIRE_NOTHROW(waterUtility->generateResources());  // Ensure generateResources doesn't throw
//     REQUIRE_NOTHROW(waterUtility->requestMaintenance(101));  // Ensure requestMaintenance doesn't throw

//     delete waterUtility;  // Clean up dynamically allocated memory
// }

// // Example test for WasteFactory and Waste utility
// TEST_CASE("WasteFactory creates Waste utility") {
//     WasteFactory wasteFactory;
//     Utilities* wasteUtility = wasteFactory.createUtility();

//     REQUIRE(wasteUtility != nullptr);  // Check that utility was created
//     REQUIRE_NOTHROW(wasteUtility->displayInfo());  // Ensure displayInfo doesn't throw
//     REQUIRE_NOTHROW(wasteUtility->generateResources());  // Ensure generateResources doesn't throw
//     REQUIRE_NOTHROW(wasteUtility->requestMaintenance(102));  // Ensure requestMaintenance doesn't throw

//     delete wasteUtility;  // Clean up dynamically allocated memory
// }

// // Example test for SewageFactory and Sewage utility
// TEST_CASE("SewageFactory creates Sewage utility") {
//     SewageFactory sewageFactory;
//     Utilities* sewageUtility = sewageFactory.createUtility();

//     REQUIRE(sewageUtility != nullptr);  // Check that utility was created
//     REQUIRE_NOTHROW(sewageUtility->displayInfo());  // Ensure displayInfo doesn't throw
//     REQUIRE_NOTHROW(sewageUtility->generateResources());  // Ensure generateResources doesn't throw
//     REQUIRE_NOTHROW(sewageUtility->requestMaintenance(103));  // Ensure requestMaintenance doesn't throw

//     delete sewageUtility;  // Clean up dynamically allocated memory
// }

// // Example test for PowerPlantFactory and PowerPlant utility
// TEST_CASE("PowerPlantFactory creates PowerPlant utility") {
//     PowerPlantFactory powerPlantFactory;
//     Utilities* powerPlantUtility = powerPlantFactory.createUtility();

//     REQUIRE(powerPlantUtility != nullptr);  // Check that utility was created
//     REQUIRE_NOTHROW(powerPlantUtility->displayInfo());  // Ensure displayInfo doesn't throw
//     REQUIRE_NOTHROW(powerPlantUtility->generateResources());  // Ensure generateResources doesn't throw
//     REQUIRE_NOTHROW(powerPlantUtility->requestMaintenance(104));  // Ensure requestMaintenance doesn't throw

//     delete powerPlantUtility;  // Clean up dynamically allocated memory
// }

// TEST_CASE("Building improvement and satisfaction"){
//     Citizen* citizen = new Citizen("Tony", 1000);
//     Commercial* commercial = new Commercial("Mall", 20, 30000, 1000, true, 1, true, 300, "Downtown");
//     commercial->attach(citizen);
//     SatisfactionChecker* satisfactionChecker = new SatisfactionChecker();
//     satisfactionChecker->buildingSatisfaction(citizen);
//     commercial->doImprovements();
//     satisfactionChecker->buildingSatisfaction(citizen);
    
//     //REQUIRE(ct->execute() == "Property Tax collected from Industrial Building\nProperty Tax of: 0 collected\nIncome Tax collected from citizens\nTime to collect Income Tax from citizens\nTax paid: 150");
// }


// TEST_CASE("ResourceManagement: createResources initializes resources correctly", "[ResourceManagement]") {
//     ResourceManagement& resources = ResourceManagement::getInstance();
//     resources.resetResources(); // Reset state before test
//     resources.createResources();

//     std::ostringstream output;
//     std::streambuf* oldCoutBuf = std::cout.rdbuf();
//     std::cout.rdbuf(output.rdbuf());

//     resources.displayResourceStatus();
//     std::cout.rdbuf(oldCoutBuf);

//     std::string expectedOutput = "Current Resource Status:\nWood: 1000\nSteel: 500\nConcrete: 300\n"
//                                  "Energy: 2000\nWater: 1500\nBudget: 10000\n";

//     REQUIRE(output.str() == expectedOutput);
// }

// TEST_CASE("ResourceManagement: supplyResources deducts resources when sufficient", "[ResourceManagement]") {
//     ResourceManagement& resources = ResourceManagement::getInstance();
//     resources.resetResources();
//     resources.createResources();

//     resources.supplyResources();

//     std::ostringstream output;
//     std::streambuf* oldCoutBuf = std::cout.rdbuf();
//     std::cout.rdbuf(output.rdbuf());

//     resources.displayResourceStatus();
//     std::cout.rdbuf(oldCoutBuf);

//     std::string expectedOutput = "Current Resource Status:\nWood: 900\nSteel: 450\nConcrete: 270\n"
//                                  "Energy: 1800\nWater: 1350\nBudget: 9500\n";

//     REQUIRE(output.str() == expectedOutput);
// }

// TEST_CASE("ResourceManagement: supplyResources does not alter resources when insufficient", "[ResourceManagement]") {
//     ResourceManagement& resources = ResourceManagement::getInstance();
//     resources.resetResources();
//     resources.createResources();

//     resources.updateMaterials(-900, -500, -300);
//     resources.updateEnergy(-1800);
//     resources.updateWater(-1350);
//     resources.updateBudget(-9500);

//     resources.supplyResources();

//     std::ostringstream output;
//     std::streambuf* oldCoutBuf = std::cout.rdbuf();
//     std::cout.rdbuf(output.rdbuf());

//     resources.displayResourceStatus();
//     std::cout.rdbuf(oldCoutBuf);

//     std::string expectedOutput = "Current Resource Status:\nWood: 100\nSteel: 0\nConcrete: 0\n"
//                                  "Energy: 200\nWater: 150\nBudget: 500\n";

//     REQUIRE(output.str() == expectedOutput);
// }

TEST_CASE("Increase Tax Command Execution") {
    Citizen* citizen = new Citizen("Tony", 10000);
    Command* incTax = new IncreaseTax();
    incTax->execute();
    REQUIRE(citizen->getTaxRate() == Approx(0.15)); // Assuming initial tax rate is 0 and increase is 0.02
    delete incTax;
    delete citizen;
}

