#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "CollectTax.h"
#include "Citizen.h"
#include "Industrial.h"
#include "Road.h"
#include "Railway.h"
#include "Runway.h"
#include "Air.h"
#include "Car.h"
#include "Public.h"
#include "Train.h"

TEST_CASE("Citizen Collect Tax"){
    Citizen* citizen = new Citizen("Tony", 1000);
    Industrial * industrial = new Industrial();
    CollectTax* ct = new CollectTax(citizen, industrial);
    ct->execute();
    //REQUIRE(ct->execute() == "Property Tax collected from Industrial Building\nProperty Tax of: 0 collected\nIncome Tax collected from citizens\nTime to collect Income Tax from citizens\nTax paid: 150");
}



TEST_CASE("Road Construction and Status") {
    // Test road initialization and construction status
    Road* road = new Road(2, 10.0);  // 2 lanes, 10 km length
    REQUIRE(road->getConstructionStatus() == true);

    // Test build function
    road->build();
    REQUIRE(road->getConstructionStatus() == false);

    delete road;
}

TEST_CASE("Road Cost Calculation") {
    // Test road cost based on lanes and length
    Road* road = new Road(3, 5.0);  // 3 lanes, 5 km length
    REQUIRE(road->getCost() == Approx(15000.0)); // 3 lanes * 5 km * 1000 cost per km per lane

    delete road;
}

TEST_CASE("Traffic Light Management") {
    Road* road = new Road(2, 5.0);  // 2 lanes, 5 km length

    // Add a traffic light and verify
    road->addTrafficLight(2.0);
    REQUIRE(road->getTrafficLights().size() == 1);

    // Attempt to add a duplicate traffic light and check that it's not added again
    road->addTrafficLight(2.0);
    REQUIRE(road->getTrafficLights().size() == 1);

    // Add another traffic light
    road->addTrafficLight(4.5);
    REQUIRE(road->getTrafficLights().size() == 2);

    // Remove a traffic light and verify
    road->removeTrafficLight(2.0);
    REQUIRE(road->getTrafficLights().size() == 1);

    delete road;
}


TEST_CASE("Road Capacity Update") {
    Road* road = new Road(2, 10.0);  // 2 lanes, 10 km length

    // Update capacity and road type
    road->updateCapacity(4, RoadType::HIGHWAY);  // Changing to 4 lanes and HIGHWAY type
    REQUIRE(road->getCost() == Approx(40000.0));  // Based on updated lanes and highway construction cost

    delete road;
}

TEST_CASE("Railway Construction and Cost Calculation") {
    Railway railway(5.0, true);  // Create a 5 km electrified railway

    SECTION("Initial Construction Status") {
        REQUIRE(railway.getConstructionStatus() == true);  // Should be under construction initially
    }

    SECTION("Build Railway") {
        railway.build();
        REQUIRE(railway.getConstructionStatus() == false);  // Should not be under construction after building
    }

    SECTION("Cost Calculation - Electrified Railway") {
        REQUIRE(railway.getCost() == 5.0 * 2000);  // Cost for electrified railway
    }

    SECTION("Update Capacity and Check Cost - Non-electrified Railway") {
        railway.updateCapacity(10.0, false);  // Update to 10 km non-electrified railway
        REQUIRE(railway.getCost() == 10.0 * 1500);  // Check cost for non-electrified railway
    }
}

TEST_CASE("Runway Construction and Cost Calculation") {
    Runway runway(3.0, 0.1);  // Create a 3 km length, 0.1 km width runway

    SECTION("Initial Construction Status") {
        REQUIRE(runway.getConstructionStatus() == true);  // Runway should be under construction initially
    }

    SECTION("Build Runway") {
        runway.build();
        REQUIRE(runway.getConstructionStatus() == false);  // Should not be under construction after building
    }

    SECTION("Cost Calculation") {
        REQUIRE(runway.getCost() == 3.0 * 0.1 * 5000);  // Cost based on length and width
    }

    SECTION("Update Capacity and Check Cost") {
        runway.updateCapacity(4.0, 0.2);  // Update to a new length and width
        REQUIRE(runway.getCost() == 4.0 * 0.2 * 5000);  // Verify updated cost
    }
}

TEST_CASE("Air Transport Construction and Initial Status") {
    Air air("City Airport", 45.0, 100.0, 150, 50);

    SECTION("Check initial maintenance status") {
        REQUIRE(air.isAvailable() == true);  // Should be available initially
    }

    SECTION("Check commute time") {
        REQUIRE(air.commuteTime() == Approx(45.0));
    }

    SECTION("Check fee") {
        REQUIRE(air.getFee() == Approx(100.0));
    }

    SECTION("Check seating and cargo capacities") {
        REQUIRE(air.getSeatingCapacity() == 150);
        REQUIRE(air.getCargoCapacity() == 50);
    }
}

TEST_CASE("Air Transport Maintenance and Availability") {
    Air air("City Airport", 45.0, 100.0, 150, 50);

    // Perform maintenance and check availability
    air.doMaintenance();
    REQUIRE(air.isAvailable() == true);  // Should be available after maintenance
}

TEST_CASE("Air Transport Seat Reservation and Release") {
    Air air("City Airport", 45.0, 100.0, 150, 50);

    SECTION("Reserve a seat") {
        REQUIRE(air.reserveSeat() == true);
        REQUIRE(air.getAvailableSeats() == 149);
    }

    SECTION("Release a seat") {
        air.reserveSeat();
        air.releaseSeat();
        REQUIRE(air.getAvailableSeats() == 150);
    }
}

TEST_CASE("Air Transport Cargo Loading and Unloading") {
    Air air("City Airport", 45.0, 100.0, 150, 50);

    SECTION("Load cargo within capacity") {
        REQUIRE(air.loadCargo(30) == true);
        REQUIRE(air.getAvailableCargoSpace() == 20);
    }

    SECTION("Unload cargo") {
        air.loadCargo(30);
        air.unloadCargo(20);
        REQUIRE(air.getAvailableCargoSpace() == 40);
    }

    SECTION("Attempt to load cargo beyond capacity") {
        REQUIRE(air.loadCargo(60) == false);
        REQUIRE(air.getAvailableCargoSpace() == 50);
    }
}

TEST_CASE("Train Transport Construction and Initial Status") {
    Train train("City Rail", 60.0, 80.0, 200, 70);

    SECTION("Check initial maintenance status") {
        REQUIRE(train.isAvailable() == true);  // Should be available initially
    }

    SECTION("Check commute time") {
        REQUIRE(train.commuteTime() == Approx(60.0));
    }

    SECTION("Check fee") {
        REQUIRE(train.getFee() == Approx(80.0));
    }

    SECTION("Check seating and cargo capacities") {
        REQUIRE(train.getSeatingCapacity() == 200);
        REQUIRE(train.getCargoCapacity() == 70);
    }
}

TEST_CASE("Train Transport Maintenance and Availability") {
    Train train("City Rail", 60.0, 80.0, 200, 70);

    train.doMaintenance();
    REQUIRE(train.isAvailable() == true);  // Should be available after maintenance
}

TEST_CASE("Train Transport Seat Reservation and Release") {
    Train train("City Rail", 60.0, 80.0, 200, 70);

    SECTION("Reserve a seat") {
        REQUIRE(train.reserveSeat() == true);
        REQUIRE(train.getAvailableSeats() == 199);
    }

    SECTION("Release a seat") {
        train.reserveSeat();
        train.releaseSeat();
        REQUIRE(train.getAvailableSeats() == 200);
    }
}

TEST_CASE("Train Transport Cargo Loading and Unloading") {
    Train train("City Rail", 60.0, 80.0, 200, 70);

    SECTION("Load cargo within capacity") {
        REQUIRE(train.loadCargo(50) == true);
        REQUIRE(train.getAvailableCargoSpace() == 20);
    }

    SECTION("Unload cargo") {
        train.loadCargo(50);
        train.unloadCargo(30);
        REQUIRE(train.getAvailableCargoSpace() == 50);
    }

    SECTION("Attempt to load cargo beyond capacity") {
        REQUIRE(train.loadCargo(100) == false);
        REQUIRE(train.getAvailableCargoSpace() == 70);
    }
}

TEST_CASE("Car Transport Construction and Initial Status") {
    Car car("City Car", 20.0, 4);

    SECTION("Check initial maintenance status") {
        REQUIRE(car.isAvailable() == true);  // Should be available initially
    }

    SECTION("Check commute time") {
        REQUIRE(car.commuteTime() == Approx(20.0));
    }

    SECTION("Check fee") {
        REQUIRE(car.getFee() == Approx(0.0));  // Cars have no fee
    }

    SECTION("Check seating capacity") {
        REQUIRE(car.getSeatingCapacity() == 4);
    }
}

TEST_CASE("Car Transport Seat Reservation and Release") {
    Car car("City Car", 20.0, 4);

    SECTION("Reserve a seat") {
        REQUIRE(car.reserveSeat() == true);
        REQUIRE(car.getAvailableSeats() == 3);
    }

    SECTION("Release a seat") {
        car.reserveSeat();
        car.releaseSeat();
        REQUIRE(car.getAvailableSeats() == 4);
    }
}

TEST_CASE("Car Transport Maintenance") {
    Car car("City Car", 20.0, 4);

    car.doMaintenance();
    REQUIRE(car.isAvailable() == true);  // Should be available after maintenance
}

TEST_CASE("Car Transport Cargo Unsupported") {
    Car car("City Car", 20.0, 4);

    SECTION("Check if cargo is supported") {
        REQUIRE(car.hasCargoCapacity() == false);
    }

    SECTION("Attempt to load cargo") {
        REQUIRE(car.loadCargo(10) == false);
    }
}

TEST_CASE("Public Transport Construction and Initial Status") {
    Public publicTransport("City Bus", 25.0, 2.5, 30);

    SECTION("Check initial maintenance status") {
        REQUIRE(publicTransport.isAvailable() == true);  // Should be available initially
    }

    SECTION("Check commute time") {
        REQUIRE(publicTransport.commuteTime() == Approx(25.0));
    }

    SECTION("Check fee") {
        REQUIRE(publicTransport.getFee() == Approx(2.5));
    }

    SECTION("Check seating capacity") {
        REQUIRE(publicTransport.getSeatingCapacity() == 30);
    }
}

TEST_CASE("Public Transport Seat Reservation and Release") {
    Public publicTransport("City Bus", 25.0, 2.5, 30);

    SECTION("Reserve a seat") {
        REQUIRE(publicTransport.reserveSeat() == true);
        REQUIRE(publicTransport.getAvailableSeats() == 29);
    }

    SECTION("Release a seat") {
        publicTransport.reserveSeat();
        publicTransport.releaseSeat();
        REQUIRE(publicTransport.getAvailableSeats() == 30);
    }
}

TEST_CASE("Public Transport Maintenance") {
    Public publicTransport("City Bus", 25.0, 2.5, 30);

    publicTransport.doMaintenance();
    REQUIRE(publicTransport.isAvailable() == true);  // Should be available after maintenance
}

TEST_CASE("Public Transport Cargo Unsupported") {
    Public publicTransport("City Bus", 25.0, 2.5, 30);

    SECTION("Check if cargo is supported") {
        REQUIRE(publicTransport.hasCargoCapacity() == false);
    }

    SECTION("Attempt to load cargo") {
        REQUIRE(publicTransport.loadCargo(15) == false);
    }
}