#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "CollectTax.h"
#include "SatisfactionChecker.h"
#include "Citizen.h"
#include "Industrial.h"
#include "Road.h"
#include "Railway.h"
#include "Runway.h"
#include "Air.h"
#include "Car.h"
#include "Public.h"
#include "Train.h"
#include "TransportSystem.h"
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

#include "TaxCollector.h"
#include "SatisfactionChecker.h"
#include "IncreaseTax.h"
#include "CollectTax.h"
#include "City.h"

#include "Citizen.h"
#include "Building.h"
#include "Residential.h"
#include "Commercial.h"
#include "Industrial.h"
#include "Landmark.h"
#include "ResidentialCreator.h"
#include "CommercialCreator.h"
#include "IndustrialCreator.h"
#include "LandmarkCreator.h"

#include "Population.h"
#include "Housing.h"
#include "Economic.h"
#include "Infrastructure.h"
#include "City.h"

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

TEST_CASE("TransportSystem Strategy Setting and Type Check") {
    TransportSystem ts;

    SECTION("Set Air Transport Strategy") {
        Air* air = new Air("City Airport", 45.0, 100.0, 150, 50);
        ts.setTransportStrategy(air);
        REQUIRE(ts.getTransportType() == "Air Transport");
    }

    SECTION("Set Train Transport Strategy") {
        Train* train = new Train("City Rail", 60.0, 80.0, 200, 70);
        ts.setTransportStrategy(train);
        REQUIRE(ts.getTransportType() == "Train Transport");
    }

    SECTION("Set Car Transport Strategy") {
        Car* car = new Car("City Car", 20.0, 4);
        ts.setTransportStrategy(car);
        REQUIRE(ts.getTransportType() == "Car Transport");
    }

    SECTION("Set Public Transport Strategy") {
        Public* publicTransport = new Public("City Bus", 25.0, 2.5, 30);
        ts.setTransportStrategy(publicTransport);
        REQUIRE(ts.getTransportType() == "Public Transport");
    }

    SECTION("No Transport Strategy Set") {
        REQUIRE(ts.getTransportType() == "None");
    }
}

TEST_CASE("TransportSystem Maintenance and Availability") {
    TransportSystem ts;
    Train* train = new Train("City Rail", 60.0, 80.0, 200, 70);
    ts.setTransportStrategy(train);

    SECTION("Perform maintenance on Train Transport") {
        ts.performMaintenance();
        REQUIRE(ts.isTransportAvailable() == true);  // Train should be available after maintenance
    }

    SECTION("No Transport Strategy Set - Maintenance") {
        TransportSystem ts2;
        REQUIRE_NOTHROW(ts2.performMaintenance());
    }
}

TEST_CASE("TransportSystem Seat Reservation and Release") {
    TransportSystem ts;
    Public* publicTransport = new Public("City Bus", 25.0, 2.5, 30);
    ts.setTransportStrategy(publicTransport);

    SECTION("Check initial seat availability") {
        REQUIRE(ts.checkSeatAvailability() == true);
    }

    SECTION("Reserve a seat and check availability") {
        REQUIRE(ts.reserveSeat() == true);
        REQUIRE(publicTransport->getAvailableSeats() == 29);
    }

    SECTION("Release a reserved seat") {
        ts.reserveSeat();
        ts.releaseSeat();
        REQUIRE(publicTransport->getAvailableSeats() == 30);
    }
}

TEST_CASE("TransportSystem Cargo Loading and Unloading") {
    TransportSystem ts;
    Train* train = new Train("City Rail", 60.0, 80.0, 200, 70);
    ts.setTransportStrategy(train);

    SECTION("Check initial cargo availability and load cargo") {
        REQUIRE(ts.checkCargoAvailability(30) == true);
        REQUIRE(ts.loadCargo(30) == true);
        REQUIRE(train->getAvailableCargoSpace() == 40);
    }

    SECTION("Attempt to load cargo exceeding capacity") {
        REQUIRE(ts.checkCargoAvailability(80) == false);
        REQUIRE(ts.loadCargo(80) == false);
    }

    SECTION("Unload cargo") {
        ts.loadCargo(30);
        ts.unloadCargo(20);
        REQUIRE(train->getAvailableCargoSpace() == 60);
    }
}

TEST_CASE("TransportSystem Commute Time and Fee Retrieval") {
    TransportSystem ts;
    Air* air = new Air("City Airport", 45.0, 100.0, 150, 50);
    ts.setTransportStrategy(air);

    SECTION("Retrieve commute time") {
        REQUIRE(ts.getCommuteTime() == Approx(45.0));
    }

    SECTION("Retrieve transport fee") {
        REQUIRE(ts.getTransportFee() == Approx(100.0));
    }

    SECTION("No Strategy Set - Commute Time and Fee") {
        TransportSystem ts2;
        REQUIRE(ts2.getCommuteTime() == Approx(0.0));
        REQUIRE(ts2.getTransportFee() == Approx(0.0));
    }
}

TEST_CASE("TransportSystem Satisfaction Calculation") {
    TransportSystem ts;
    Car* car = new Car("City Car", 20.0, 4);
    ts.setTransportStrategy(car);

    SECTION("Calculate satisfaction for Car Transport") {
        REQUIRE(ts.calculateSatisfaction() == 85);
    }

    SECTION("Calculate satisfaction with no strategy set") {
        TransportSystem ts2;
        REQUIRE(ts2.calculateSatisfaction() == 0);
    }
}

//Testing BuildingObserver
// Test case for Building Observer functionality
TEST_CASE("Building Observer Notifications", "[ObserverPattern]") {
    // Create citizens
    Citizen alice("Alice", 50000, 250000);
    Citizen bob("Bob", 60000, 300000);
    Citizen charlie("Charlie", 70000, 350000);

    // Create different types of buildings
    Residential apartment("Sunset Apartments", 80, 5000, 200, true, 1, true, 150, "Suburb");
    Commercial mall("City Mall", 75, 10000, 500, true, 1, true, 1000, "Suburb");
    Industrial factory("Steel Factory", 70, 15000, 1000, true, 1, true, 300, "Industrial");
    Landmark monument("Freedom Monument", 90, 8000, 500, true, 1, true, 70, "Suburb");

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



//Testing Composite
TEST_CASE("Government operates all departments") {
    Government cityGovernment(0.15, 0.05);

    // Creating departments
    Tax taxDept("Tax Department", 15.0f);
    Budget budgetDept("Budget Department", 10000.0);
    Policies policiesDept("Policies Department");
    Services servicesDept("Public Services", 5, 10, 3);

    // Adding policies and service programs
    policiesDept.addPolicy("Environmental Protection");
    policiesDept.addPolicy("Healthcare Reform");
    servicesDept.addServiceProgram("Free Education Initiative");
    servicesDept.addServiceProgram("Healthcare for All");

    // Adding departments to the Government composite
    cityGovernment.add(&taxDept);
    cityGovernment.add(&budgetDept);
    cityGovernment.add(&policiesDept);
    cityGovernment.add(&servicesDept);

    // Operating government
    cityGovernment.operate();
    REQUIRE(cityGovernment.getChild(0) == &taxDept);  // Verify child exists
}

TEST_CASE("Adding and Removing Departments in Government") {
    Government cityGovernment(0.15, 0.05);

    Tax taxDept("Tax Department", 15.0f);
    Budget budgetDept("Budget Department", 10000.0);

    cityGovernment.add(&taxDept);
    REQUIRE(cityGovernment.getChild(0) == &taxDept);

    cityGovernment.add(&budgetDept);
    REQUIRE(cityGovernment.getChild(1) == &budgetDept);

    // Removing tax department
    cityGovernment.remove(&taxDept);
    REQUIRE(cityGovernment.getChild(0) == &budgetDept);
}

TEST_CASE("Policies and Services operate correctly") {
    Policies policiesDept("Policies Department");
    Services servicesDept("Public Services", 5, 10, 3);

    policiesDept.addPolicy("Environmental Protection");
    REQUIRE(policiesDept.getName() == "Policies Department");

    servicesDept.addServiceProgram("Free Education Initiative");
    REQUIRE(servicesDept.getName() == "Public Services");

    policiesDept.operate();
    servicesDept.operate();
}

TEST_CASE("Tax department sets and tracks revenue correctly") {
    Tax taxDept("Tax Department", 10.0f);
    taxDept.setTaxRate(0.2f);
    REQUIRE(taxDept.getTaxRate() == 0.2f);

    taxDept.trackRevenue(1000.0);
    REQUIRE(taxDept.getTaxRate() == 0.2f);
}

//Testing Utility Factories
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

TEST_CASE("Building improvement and satisfaction"){
    Citizen* citizen = new Citizen("Tony", 1000);
    Commercial* commercial = new Commercial("Mall", 20, 30000, 1000, true, 1, true, 300, "Downtown");
    commercial->attach(citizen);
    SatisfactionChecker* satisfactionChecker = new SatisfactionChecker();
    satisfactionChecker->buildingSatisfaction(citizen);
    commercial->doImprovements();
    satisfactionChecker->buildingSatisfaction(citizen);
    
    //REQUIRE(ct->execute() == "Property Tax collected from Industrial Building\nProperty Tax of: 0 collected\nIncome Tax collected from citizens\nTime to collect Income Tax from citizens\nTax paid: 150");
}


TEST_CASE("ResourceManagement: createResources initializes resources correctly", "[ResourceManagement]") {
    ResourceManagement& resources = ResourceManagement::getInstance();
    resources.resetResources(); // Reset state before test
    resources.createResources();

    std::ostringstream output;
    std::streambuf* oldCoutBuf = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    resources.displayResourceStatus();
    std::cout.rdbuf(oldCoutBuf);

    std::string expectedOutput = "Current Resource Status:\nWood: 1000\nSteel: 500\nConcrete: 300\n"
                                 "Energy: 2000\nWater: 1500\nBudget: 10000\n";

    REQUIRE(output.str() == expectedOutput);
}

TEST_CASE("ResourceManagement: supplyResources deducts resources when sufficient", "[ResourceManagement]") {
    ResourceManagement& resources = ResourceManagement::getInstance();
    resources.resetResources();
    resources.createResources();

    //resources.supplyResources();

    std::ostringstream output;
    std::streambuf* oldCoutBuf = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    resources.displayResourceStatus();
    std::cout.rdbuf(oldCoutBuf);

    std::string expectedOutput = "Current Resource Status:\nWood: 900\nSteel: 450\nConcrete: 270\n"
                                 "Energy: 1800\nWater: 1350\nBudget: 9500\n";

    REQUIRE(output.str() == expectedOutput);
}

TEST_CASE("ResourceManagement: supplyResources does not alter resources when insufficient", "[ResourceManagement]") {
    ResourceManagement& resources = ResourceManagement::getInstance();
    resources.resetResources();
    resources.createResources();

    //resources.updateMaterials(-900, -500, -300);
    resources.updateEnergy(-1800);
    resources.updateWater(-1350);
    resources.updateBudget(-9500);

    //resources.supplyResources();

    std::ostringstream output;
    std::streambuf* oldCoutBuf = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    resources.displayResourceStatus();
    std::cout.rdbuf(oldCoutBuf);

    std::string expectedOutput = "Current Resource Status:\nWood: 100\nSteel: 0\nConcrete: 0\n"
                                 "Energy: 200\nWater: 150\nBudget: 500\n";

    REQUIRE(output.str() == expectedOutput);
}

TEST_CASE("Increase Tax Command Execution") {
    Citizen* citizen = new Citizen("Tony", 10000);
    Command* incTax = new IncreaseTax();
    incTax->execute();
    REQUIRE(citizen->getTaxRate() == Approx(0.15)); // Assuming initial tax rate is 0 and increase is 0.02
    delete incTax;
    delete citizen;
}

TEST_CASE("Tax Collector Execution") {
    TaxCollector* taxCollector = new TaxCollector();
    Citizen* citizen = new Citizen("Tony", 1000);
    Citizen* citizen2 = new Citizen("Sherlock", 1000);
    City* city = new City("Gotham City"); // Replace with appropriate arguments
    CollectTax* collectTax = new CollectTax(citizen, nullptr);
    collectTax->addCitizen(citizen2);
    collectTax->execute();
    city->attach(citizen);
    city->attach(citizen2);
    for (int i = 0; i < city->citizens.size(); i++) {
        taxCollector->visit(city->citizens[i]);
    }
    REQUIRE(citizen->taxPaid > 0);
    REQUIRE(citizen2->taxPaid > 0);
    delete taxCollector;
    delete collectTax;
    delete citizen;
    delete citizen2;
    delete city;
}

TEST_CASE("Satisfaction Checker Execution") {
    SatisfactionChecker* satisfactionChecker = new SatisfactionChecker();
    Citizen* citizen = new Citizen("Tony", 1000);
    Industrial* industrial = new Industrial();
    satisfactionChecker->transportSatisfaction(citizen);
    satisfactionChecker->buildingSatisfaction(citizen);
    satisfactionChecker->citySatisfaction(citizen);
    satisfactionChecker->citySatisfaction(industrial);
    REQUIRE(citizen->getSatisfactionTransport() >= 0);
    REQUIRE(citizen->buildingSatisfaction >= 0);
    REQUIRE(citizen->citySatisfaction >= 0);
    delete satisfactionChecker;
    delete citizen;
    delete industrial;
}

TEST_CASE("Rent Collection") {
    Citizen* citizen = new Citizen("Tony", 1000);
    Citizen* citizen2 = new Citizen("Sherlock", 1000);
    Residential* residential = new Residential();
    residential->attach(citizen);
    residential->attach(citizen2);
    residential->collectRent();
    REQUIRE(citizen->getIncome() < 1000);
    REQUIRE(citizen2->getIncome() < 1000);
    delete citizen;
    delete citizen2;
    delete residential;
}

TEST_CASE("Tax Collection Execution") {
    // Create tax department and city
    Tax* taxDept = new Tax("Tax Department", 0.15);
    City* city = new City("Stark City");

    // Create buildings and set their values
    Building* industrial = new Industrial();
    Building* commercial = new Commercial();
    industrial->setBuildingValue(100000);
    commercial->setBuildingValue(85000);
    commercial->generateRevenue();

    // Attach buildings to the city
    city->attach(industrial);
    city->attach(commercial);

    // Create citizens and attach them to the city
    Citizen* c1 = new Citizen("Tony", 10000);
    Citizen* c2 = new Citizen("Sherlock", 8000);
    city->attach(c1);
    city->attach(c2);

    // Create and execute CollectTax command
    CollectTax* collectTax = new CollectTax();
    collectTax->addBuildingVector(city->buildings);
    collectTax->addCitizenVector(city->citizens);
    collectTax->execute();

    // Create TaxCollector and visit citizens and buildings
    TaxCollector* taxCollector = new TaxCollector();
    for (int i = 0; i < city->citizens.size(); i++) {
        taxCollector->visit(city->citizens[i]);
    }
    for (int i = 0; i < city->buildings.size(); i++) {
        taxCollector->visit(city->buildings[i]);
    }

    // Collect taxes
    taxDept->collectTaxes(taxCollector->taxCollected);

    // Verify tax collection
    REQUIRE(taxCollector->taxCollected > 0);

    // Clean up
    delete taxDept;
    delete city;
    delete industrial;
    delete commercial;
    delete c1;
    delete c2;
    delete collectTax;
    delete taxCollector;
}

TEST_CASE("City Satisfaction Checker") {

    City* city = new City("Stark City");
    Citizen* citizen1 = new Citizen("Tony", 1000);
    Citizen* citizen2 = new Citizen("Sherlock", 1000);
    city->attach(citizen1);
    city->attach(citizen2);

    Building* commercial = new Commercial("Mall", 20, 30000, 1000, true, 1, true, 300, "Downtown");
    Building* industrial = new Industrial("Factory", 50, 50000, 2000, true, 1, true, 500, "Industrial Area");
    city->attach(commercial);
    city->attach(industrial);

    SatisfactionChecker* satisfactionChecker = new SatisfactionChecker();
    for (int i = 0; i < city->citizens.size(); i++) {
        city->citizens[i]->acceptCitySatisfactionChecker(satisfactionChecker);
    }
    for (int i = 0; i < city->buildings.size(); i++) {
        city->buildings[i]->acceptCitySatisfactionChecker(satisfactionChecker);
    }
    double citySatisfaction = satisfactionChecker->citySatisfactionTotal;
    delete satisfactionChecker;

    REQUIRE(citySatisfaction >= 0); // Ensure city satisfaction is non-negative

    delete city;
    delete citizen1;
    delete citizen2;
    delete commercial;
    delete industrial;
}

TEST_CASE("Average Citizen Transport Satisfaction Checker") {

    City* city = new City("Stark City");
    Citizen* citizen1 = new Citizen("Tony", 1000);
    Citizen* citizen2 = new Citizen("Sherlock", 1000);
    city->attach(citizen1);
    city->attach(citizen2);

    SatisfactionChecker* satisfactionChecker = new SatisfactionChecker();
    for (int i = 0; i < city->citizens.size(); i++) {
        city->citizens[i]->acceptTransportSatisfactionChecker(satisfactionChecker);
    }
    double satisfaction = satisfactionChecker->transportSatisfactionTotal;
    delete satisfactionChecker;

    double avgSatisfaction = satisfaction / city->citizens.size();

    REQUIRE(avgSatisfaction >= 0); // Ensure average satisfaction is non-negative

    delete city;
    delete citizen1;
    delete citizen2;
}
TEST_CASE("Building City Satisfaction Checker") {
    Building* commercial = new Commercial("Mall", 20, 30000, 1000, true, 1, true, 300, "Downtown");

    SatisfactionChecker* satisfactionChecker = new SatisfactionChecker();
    commercial->acceptCitySatisfactionChecker(satisfactionChecker);
    double satisfaction = satisfactionChecker->citySatisfactionTotal;
    delete satisfactionChecker;

    REQUIRE(satisfaction >= 0); // Ensure satisfaction is non-negative
    delete commercial;
}

TEST_CASE("Citizen Satisfaction for Building Checker") {
    Citizen* citizen1 = new Citizen("Tony", 1000);
    Citizen* citizen2 = new Citizen("Sherlock", 1000);
    Building* commercial = new Commercial("Mall", 20, 30000, 1000, true, 1, true, 300, "Downtown");
    commercial->attach(citizen1);
    commercial->attach(citizen2);
    SatisfactionChecker* satisfactionChecker = new SatisfactionChecker();
    for (int i = 0; i < commercial->observerList.size(); i++) {
        commercial->observerList[i]->acceptBuildingSatisfactionChecker(satisfactionChecker);
    }
    double satisfaction = satisfactionChecker->buildingSatisfactionTotal;
    double avgSatisfaction = satisfaction / commercial->observerList.size();
    delete satisfactionChecker;

    REQUIRE(avgSatisfaction >= 0); // Ensure average satisfaction is non-negative

    delete citizen1;
    delete citizen2;
    delete commercial;
}
TEST_CASE("Building Factory Creation and Properties") {
    ResidentialCreator residentialCreator;
    LandmarkCreator landmarkCreator;
    CommercialCreator commercialCreator;
    IndustrialCreator industrialCreator;

    SECTION("Residential Building Creation") {
        Building* residentialBuilding = residentialCreator.createBuilding("Residential Block", 30, 5000, 300, true, 1, true, 200, "Suburb");

        REQUIRE(residentialBuilding != nullptr);
        REQUIRE(residentialBuilding->getType() == "Residential Block");
        REQUIRE(residentialBuilding->calculateSatisfaction() >= 0);
        REQUIRE(residentialBuilding->calculateEconomicImpact() >= 0);
        REQUIRE(residentialBuilding->calculateResourceConsumption() >= 0);

        residentialBuilding->doImprovements();
        REQUIRE(residentialBuilding->calculateSatisfaction() > 0);  // Expect increased satisfaction

        // Test cloning
        Building* clonedResidentialBuilding = residentialBuilding->clone();
        REQUIRE(clonedResidentialBuilding != nullptr);
        REQUIRE(clonedResidentialBuilding->getType() == residentialBuilding->getType());
        REQUIRE(clonedResidentialBuilding->calculateSatisfaction() == residentialBuilding->calculateSatisfaction());
        REQUIRE(clonedResidentialBuilding->calculateEconomicImpact() == residentialBuilding->calculateEconomicImpact());
        REQUIRE(clonedResidentialBuilding->calculateResourceConsumption() == residentialBuilding->calculateResourceConsumption());

        delete residentialBuilding;
        delete clonedResidentialBuilding;
    }

    SECTION("Landmark Building Creation") {
        Building* landmarkBuilding = landmarkCreator.createBuilding("Statue of Liberty", 50, 100000, 500, true, 1, true, 500, "Suburb");

        REQUIRE(landmarkBuilding != nullptr);
        REQUIRE(landmarkBuilding->getType() == "Statue of Liberty");
        REQUIRE(landmarkBuilding->calculateSatisfaction() >= 0);
        REQUIRE(landmarkBuilding->calculateEconomicImpact() >= 0);
        REQUIRE(landmarkBuilding->calculateResourceConsumption() >= 0);

        landmarkBuilding->doImprovements();
        REQUIRE(landmarkBuilding->calculateSatisfaction() > 0);  // Expect increased satisfaction

        // Test cloning
        Building* clonedLandmarkBuilding = landmarkBuilding->clone();
        REQUIRE(clonedLandmarkBuilding != nullptr);
        REQUIRE(clonedLandmarkBuilding->getType() == landmarkBuilding->getType());
        REQUIRE(clonedLandmarkBuilding->calculateSatisfaction() == landmarkBuilding->calculateSatisfaction());
        REQUIRE(clonedLandmarkBuilding->calculateEconomicImpact() == landmarkBuilding->calculateEconomicImpact());
        REQUIRE(clonedLandmarkBuilding->calculateResourceConsumption() == landmarkBuilding->calculateResourceConsumption());

        delete landmarkBuilding;
        delete clonedLandmarkBuilding;
    }

    SECTION("Commercial Building Creation") {
        Building* commercialBuilding = commercialCreator.createBuilding("Mall", 20, 30000, 1000, true, 1, true, 300, "Suburb");

        REQUIRE(commercialBuilding != nullptr);
        REQUIRE(commercialBuilding->getType() == "Mall");
        REQUIRE(commercialBuilding->calculateSatisfaction() >= 0);
        REQUIRE(commercialBuilding->calculateEconomicImpact() >= 0);
        REQUIRE(commercialBuilding->calculateResourceConsumption() >= 0);

        commercialBuilding->doImprovements();
        REQUIRE(commercialBuilding->calculateSatisfaction() > 0);  // Expect increased satisfaction

        // Test cloning
        Building* clonedCommercialBuilding = commercialBuilding->clone();
        REQUIRE(clonedCommercialBuilding != nullptr);
        REQUIRE(clonedCommercialBuilding->getType() == commercialBuilding->getType());
        REQUIRE(clonedCommercialBuilding->calculateSatisfaction() == commercialBuilding->calculateSatisfaction());
        REQUIRE(clonedCommercialBuilding->calculateEconomicImpact() == commercialBuilding->calculateEconomicImpact());
        REQUIRE(clonedCommercialBuilding->calculateResourceConsumption() == commercialBuilding->calculateResourceConsumption());

        delete commercialBuilding;
        delete clonedCommercialBuilding;
    }

    SECTION("Industrial Building Creation") {
        Building* industrialBuilding = industrialCreator.createBuilding("Factory", 10, 20000, 2000, true, 1, true, 400, "Industrial");

        REQUIRE(industrialBuilding != nullptr);
        REQUIRE(industrialBuilding->getType() == "Factory");
        REQUIRE(industrialBuilding->calculateSatisfaction() >= 0);
        REQUIRE(industrialBuilding->calculateEconomicImpact() >= 0);
        REQUIRE(industrialBuilding->calculateResourceConsumption() >= 0);

        industrialBuilding->doImprovements();
        REQUIRE(industrialBuilding->calculateSatisfaction() > 0);  // Expect increased satisfaction

        // Test cloning
        Building* clonedIndustrialBuilding = industrialBuilding->clone();
        REQUIRE(clonedIndustrialBuilding != nullptr);
        REQUIRE(clonedIndustrialBuilding->getType() == industrialBuilding->getType());
        REQUIRE(clonedIndustrialBuilding->calculateSatisfaction() == industrialBuilding->calculateSatisfaction());
        REQUIRE(clonedIndustrialBuilding->calculateEconomicImpact() == industrialBuilding->calculateEconomicImpact());
        REQUIRE(clonedIndustrialBuilding->calculateResourceConsumption() == industrialBuilding->calculateResourceConsumption());

        delete industrialBuilding;
        delete clonedIndustrialBuilding;
    }
}


TEST_CASE("Chain of Responsibility with Growth Factor") {
    // Create handlers with test values
    Residential apartment("Sunset Apartments", 80, 5000, 200, true, 1, true, 150, "Suburb");
    Commercial mall("City Mall", 75, 10000, 500, true, 1, true, 1000, "Suburb");
    Industrial factory("Steel Factory", 70, 15000, 1000, true, 1, true, 300, "Industrial");
    Landmark monument("Freedom Monument", 90, 8000, 500, true, 1, true, 70, "Suburb");
    int growthFactor = 21;

    Population populationHandler(growthFactor);
    Housing housingHandler(growthFactor * 0.5, &apartment);
    Economic economicHandler(growthFactor * 0.2);
    Infrastructure infrastructureHandler(growthFactor * 0.3, &mall, &factory, &monument);

    // Set up the chain of responsibility
    populationHandler.setNextHandler(&housingHandler);
    housingHandler.setNextHandler(&economicHandler);
    economicHandler.setNextHandler(&infrastructureHandler);

    SECTION("Chain Execution with Growth Factor") {
        // Execute the chain with a growth factor
        REQUIRE_NOTHROW(populationHandler.handleRequest(growthFactor));

        // You can add checks to validate state changes or expected outcomes.
        // For example:
        REQUIRE(populationHandler.getGrowthFactor() == growthFactor);
        REQUIRE(housingHandler.getGrowthFactor() == Approx(growthFactor * 0.5));
        REQUIRE(economicHandler.getGrowthFactor() == Approx(growthFactor * 0.2));
        REQUIRE(infrastructureHandler.getGrowthFactor() == Approx(growthFactor * 0.3));
    }
}

TEST_CASE("City Observer Pattern - Notifying Citizens") {
    // Create a City object
    City city;

    // Create Citizen objects
    Citizen citizen1("Alice", 5000, 200000, "Engineer");
    Citizen citizen2("Bob", 4500, 150000, "Teacher");
    Citizen citizen3("Charlie", 3000, 100000, "Artist");

    // Attach citizens to the city as observers
    city.attach(&citizen1);
    city.attach(&citizen2);
    city.attach(&citizen3);

    // Verify initial state
    REQUIRE_FALSE(citizen1.isNotified());
    REQUIRE_FALSE(citizen2.isNotified());
    REQUIRE_FALSE(citizen3.isNotified());

    SECTION("Notifying Observers") {
        // Notify citizens about a change in the city
        city.notify();

        // Check if each citizen received the notification
        REQUIRE(citizen1.isNotified());
        REQUIRE(citizen2.isNotified());
        REQUIRE(citizen3.isNotified());
    }

    SECTION("Detach Citizen from Observer List") {
        // Detach a citizen and notify again
        city.detach(&citizen2);
        citizen1.resetNotification();
        citizen2.resetNotification();
        citizen3.resetNotification();

        // Notify remaining citizens
        city.notify();

        // Verify that only attached citizens received the notification
        REQUIRE(citizen1.isNotified());
        REQUIRE_FALSE(citizen2.isNotified());  // Citizen2 should not be notified
        REQUIRE(citizen3.isNotified());
    }
}
