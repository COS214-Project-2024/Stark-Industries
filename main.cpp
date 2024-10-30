<<<<<<< HEAD
=======
#include <iostream>
#include "Citizen.h"
#include "Transport.h"
#include "Public.h"
#include "Train.h"
#include "Air.h"

// Function to test transport selection based on seat availability and maintenance status
void testTransportSelection(Citizen& citizen, Transport& transport) {
    std::cout << "\n=== " << citizen.getName() << " tries to choose " << transport.getType() << " transport ===\n";
    citizen.chooseTransport(&transport);
}

// Function to test if citizens can afford the transport fee
void testTransportAffordability(Citizen& citizen, Transport& transport) {
    std::cout << "\n=== Testing affordability for " << citizen.getName() << " with income " << citizen.getIncome() << " ===\n";
    if (citizen.getIncome() < transport.getFee()) {
        std::cout << citizen.getName() << " cannot afford " << transport.getType() << " transport.\n";
    } else {
        std::cout << citizen.getName() << " can afford " << transport.getType() << " transport.\n";
        citizen.chooseTransport(&transport);
    }
}

// Function to test seat availability for a given transport
void testSeatAvailability(Citizen& citizen, Transport& transport) {
    std::cout << "\n=== Testing seat availability for " << citizen.getName() << " on " << transport.getType() << " ===\n";
    if (transport.getAvailableSeats()>=1) {
        std::cout << "Seats are available on " << transport.getType() << ".\n";
        citizen.chooseTransport(&transport);
    } else {
        std::cout << "No seats available on " << transport.getType() << ".\n";
    }
}

// Function to test citizen feedback and satisfaction level
void testCitizenSatisfaction(Citizen& citizen) {
    std::cout << "\n=== Testing satisfaction level for " << citizen.getName() << " ===\n";
    citizen.leaveFeedback();
    if (citizen.getSatisfaction()>60) {
        std::cout << citizen.getName() << " is satisfied with the transportation.\n";
    } else {
        std::cout << citizen.getName() << " is unsatisfied with the transportation.\n";
    }
}

// Function to simulate citizen disembarking from transport
void testDisembark(Citizen& citizen) {
    std::cout << "\n=== " << citizen.getName() << " disembarks from transport ===\n";
    citizen.disembark();
}
>>>>>>> f85c17a (Testing strategy)

#include <iostream>
#include "RunwayFactory.h"
#include "RoadFactory.h"
#include "RailwayFactory.h"

void testRunway() {
    RunwayFactory runwayFactory;
    runwayFactory.buildInfrastructure();
    TransportInfrastructure* runway = runwayFactory.createInfrastructure();

    std::cout << "Runway construction status: " 
              << (static_cast<Runway*>(runway)->getConstructionStatus() ? "Under construction" : "Completed") << std::endl;

    runway->build();

    std::cout << "Runway construction status after building: " 
              << (static_cast<Runway*>(runway)->getConstructionStatus() ? "Under construction" : "Completed") << std::endl;

    std::cout << "Runway cost: " << runway->getCost() << std::endl;

    delete runway;
}

void testRoad() {
    RoadFactory roadFactory;
    roadFactory.buildInfrastructure();
    TransportInfrastructure* road = roadFactory.createInfrastructure();

    std::cout << "Road construction status: " 
              << (static_cast<Road*>(road)->getConstructionStatus() ? "Under construction" : "Completed") << std::endl;

    // Build the road
    road->build();

    std::cout << "Road construction status after building: " 
              << (static_cast<Road*>(road)->getConstructionStatus() ? "Under construction" : "Completed") << std::endl;

    std::cout << "Road cost: " << road->getCost() << std::endl;

    delete road;
}

void testRailway() {
    RailwayFactory railwayFactory;
    railwayFactory.buildInfrastructure();
    TransportInfrastructure* railway = railwayFactory.createInfrastructure();

    std::cout << "Railway construction status: " 
              << (static_cast<Railway*>(railway)->getConstructionStatus() ? "Under construction" : "Completed") << std::endl;

    railway->build();

    std::cout << "Railway construction status after building: " 
              << (static_cast<Railway*>(railway)->getConstructionStatus() ? "Under construction" : "Completed") << std::endl;


    std::cout << "Railway cost: " << railway->getCost() << std::endl;

    delete railway;
}

void testCustomInfrastructures() {
    Runway customRunway(3.0, 0.1);
    std::cout << "Custom Runway cost: " << customRunway.getCost() << std::endl;

    Road customRoad(4, 2.0);
    std::cout << "Custom Road cost: " << customRoad.getCost() << std::endl;

    Railway customRailway(2.0, false);
    std::cout << "Custom non-electrified Railway cost: " << customRailway.getCost() << std::endl;
}
int main() {
<<<<<<< HEAD
    testRunway();
    testRoad();
    testRailway();
    testCustomInfrastructures();
    return 0;
}

=======
    // Create transport options
Public bus("Bus",30,5, 20); // Bus with 5 seats and a fee of 20
    Train train("Train1",10,10, 15,3); // Train with 10 seats and a fee of 15
    Air air("Plane1",20,2, 100,4); // Air transport with 2 seats and a fee of 100

    // Create citizens with different incomes
    Citizen alice("Alice", 30,2);
    Citizen bob("Bob", 10,0);
    Citizen charlie("Charlie", 200,15);

    // Test various functionalities using individual functions

    // Test transport selection
    testTransportSelection(alice, bus);
    testTransportSelection(bob, bus); // Bob can't afford

    // Test transport affordability
    testTransportAffordability(bob, train);
    testTransportAffordability(charlie, air);

    // Test seat availability for bus and air transport
    testSeatAvailability(alice, air); // Alice should be able to select the air transport
    testSeatAvailability(charlie, air); // Seats might be full if Alice took the last seat

    // Test disembarking and choosing new transport
    testDisembark(alice);
    testTransportSelection(alice, air); // Alice tries air transport again after disembarking

    // Test citizen satisfaction feedback and satisfaction check
    testCitizenSatisfaction(alice);
    testCitizenSatisfaction(bob);
    testCitizenSatisfaction(charlie);

    return 0;
}
>>>>>>> f85c17a (Testing strategy)
