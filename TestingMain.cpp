#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "CollectTax.h"
#include "Citizen.h"
#include "Industrial.h"
#include "WaterFactory.h"
#include "WasteFactory.h"
#include "SewageFactory.h"
#include "PowerPlantFactory.h"

TEST_CASE("Citizen Collect Tax"){
    Citizen* citizen = new Citizen("Tony", 1000);
    Industrial * industrial = new Industrial();
    CollectTax* ct = new CollectTax(citizen, industrial);
    ct->execute();
    //REQUIRE(ct->execute() == "Property Tax collected from Industrial Building\nProperty Tax of: 0 collected\nIncome Tax collected from citizens\nTime to collect Income Tax from citizens\nTax paid: 150");
}


// Example test for WaterFactory and Water utility
TEST_CASE("WaterFactory creates Water utility") {
    WaterFactory waterFactory;
    Utilities* waterUtility = waterFactory.createUtility();

    REQUIRE(waterUtility != nullptr);  // Check that utility was created
    REQUIRE_NOTHROW(waterUtility->displayInfo());  // Ensure displayInfo doesn't throw
    REQUIRE_NOTHROW(waterUtility->generateResources());  // Ensure generateResources doesn't throw
    REQUIRE_NOTHROW(waterUtility->requestMaintenance(101));  // Ensure requestMaintenance doesn't throw

    delete waterUtility;  // Clean up dynamically allocated memory
}

// Example test for WasteFactory and Waste utility
TEST_CASE("WasteFactory creates Waste utility") {
    WasteFactory wasteFactory;
    Utilities* wasteUtility = wasteFactory.createUtility();

    REQUIRE(wasteUtility != nullptr);  // Check that utility was created
    REQUIRE_NOTHROW(wasteUtility->displayInfo());  // Ensure displayInfo doesn't throw
    REQUIRE_NOTHROW(wasteUtility->generateResources());  // Ensure generateResources doesn't throw
    REQUIRE_NOTHROW(wasteUtility->requestMaintenance(102));  // Ensure requestMaintenance doesn't throw

    delete wasteUtility;  // Clean up dynamically allocated memory
}

// Example test for SewageFactory and Sewage utility
TEST_CASE("SewageFactory creates Sewage utility") {
    SewageFactory sewageFactory;
    Utilities* sewageUtility = sewageFactory.createUtility();

    REQUIRE(sewageUtility != nullptr);  // Check that utility was created
    REQUIRE_NOTHROW(sewageUtility->displayInfo());  // Ensure displayInfo doesn't throw
    REQUIRE_NOTHROW(sewageUtility->generateResources());  // Ensure generateResources doesn't throw
    REQUIRE_NOTHROW(sewageUtility->requestMaintenance(103));  // Ensure requestMaintenance doesn't throw

    delete sewageUtility;  // Clean up dynamically allocated memory
}

// Example test for PowerPlantFactory and PowerPlant utility
TEST_CASE("PowerPlantFactory creates PowerPlant utility") {
    PowerPlantFactory powerPlantFactory;
    Utilities* powerPlantUtility = powerPlantFactory.createUtility();

    REQUIRE(powerPlantUtility != nullptr);  // Check that utility was created
    REQUIRE_NOTHROW(powerPlantUtility->displayInfo());  // Ensure displayInfo doesn't throw
    REQUIRE_NOTHROW(powerPlantUtility->generateResources());  // Ensure generateResources doesn't throw
    REQUIRE_NOTHROW(powerPlantUtility->requestMaintenance(104));  // Ensure requestMaintenance doesn't throw

    delete powerPlantUtility;  // Clean up dynamically allocated memory
}