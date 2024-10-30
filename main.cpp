
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
    testRunway();
    testRoad();
    testRailway();
    testCustomInfrastructures();
    return 0;
}

