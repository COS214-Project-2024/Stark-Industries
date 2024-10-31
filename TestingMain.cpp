#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "CollectTax.h"
#include "Citizen.h"
#include "Industrial.h"

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

// Test case for Building Observer functionality
TEST_CASE("Building Observer Notifications", "[ObserverPattern]") {
    // Create citizens
    Citizen alice("Alice", 50000, 250000);
    Citizen bob("Bob", 60000, 300000);
    Citizen charlie("Charlie", 70000, 350000);

    // Create different types of buildings
    Residential apartment("Sunset Apartments", 80, 5000, 200, true, 1, true, 5);
    Commercial mall("City Mall", 75, 10000, 500, true, 1, true, 10);
    Industrial factory("Steel Factory", 70, 15000, 1000, true, 1, true, 8);
    Landmark monument("Freedom Monument", 90, 8000, 500, true, 1, true, 10);

    // Attach citizens to different buildings
    apartment.attach(&alice);
    mall.attach(&alice);
    factory.attach(&bob);
    monument.attach(&charlie);

    SECTION("Notify citizens about improvements in Residential Building") {
        apartment.doImprovements();  
        REQUIRE(alice.isNotified() == true);
        alice.resetNotification();
    }

    SECTION("Notify citizens about improvements in Commercial Building") {
        mall.doImprovements();  
        REQUIRE(alice.isNotified() == true);
        alice.resetNotification();
    }

    SECTION("Notify citizens about improvements in Industrial Building") {
        factory.doImprovements();  
        REQUIRE(bob.isNotified() == true);
        bob.resetNotification();
    }

    SECTION("Notify citizens about improvements in Landmark") {
        monument.doImprovements();  
        REQUIRE(charlie.isNotified() == true);
        charlie.resetNotification();
    }

    SECTION("Detach citizen and verify no notification") {
        mall.detach(&alice);
        mall.doImprovements();
        REQUIRE(alice.isNotified() == false);  // Alice should not be notified
    }
}