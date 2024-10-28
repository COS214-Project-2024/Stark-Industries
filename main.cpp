#include <iostream>
#include <vector>
#include "ResidentialCreator.h"
#include "LandmarkCreator.h"
#include "CommercialCreator.h"
#include "IndustrialCreator.h"
#include "Building.h"

using namespace std;

void factoryBuildings() {
    // Initialize creators for each building type
    ResidentialCreator residentialCreator;
    LandmarkCreator landmarkCreator;
    CommercialCreator commercialCreator;
    IndustrialCreator industrialCreator;

    // Create Residential Building
    Building* residentialBuilding = residentialCreator.createBuilding("Residential Block", 30, 5000, 300, true, 1, true, 200);
    cout << "Residential Building Created:" << endl;
    cout << "Type: " << residentialBuilding->getType() << endl;
    cout << "Satisfaction: " << residentialBuilding->calculateSatisfaction() << endl;
    cout << "Economic Impact: " << residentialBuilding->calculateEconomicImpact() << endl;
    cout << "Resource Consumption: " << residentialBuilding->calculateResourceConsumption() << endl;
    residentialBuilding->doImprovements();
    cout << "Satisfaction after improvement: " << residentialBuilding->calculateSatisfaction() << endl;

    // Create Landmark Building
    Building* landmarkBuilding = landmarkCreator.createBuilding("Statue of Liberty", 50, 100000, 500, true, 1, true, 500);
    cout << "\nLandmark Building Created:" << endl;
    cout << "Type: " << landmarkBuilding->getType() << endl;
    cout << "Satisfaction: " << landmarkBuilding->calculateSatisfaction() << endl;
    cout << "Economic Impact: " << landmarkBuilding->calculateEconomicImpact() << endl;
    cout << "Resource Consumption: " << landmarkBuilding->calculateResourceConsumption() << endl;
    landmarkBuilding->doImprovements();
    cout << "Satisfaction after improvement: " << landmarkBuilding->calculateSatisfaction() << endl;

    // Create Commercial Building
    Building* commercialBuilding = commercialCreator.createBuilding("Mall", 20, 30000, 1000, true, 1, true, 300);
    cout << "\nCommercial Building Created:" << endl;
    cout << "Type: " << commercialBuilding->getType() << endl;
    cout << "Satisfaction: " << commercialBuilding->calculateSatisfaction() << endl;
    cout << "Economic Impact: " << commercialBuilding->calculateEconomicImpact() << endl;
    cout << "Resource Consumption: " << commercialBuilding->calculateResourceConsumption() << endl;
    commercialBuilding->doImprovements();
    cout << "Satisfaction after improvement: " << commercialBuilding->calculateSatisfaction() << endl;

    // Create Industrial Building
    Building* industrialBuilding = industrialCreator.createBuilding("Factory", 10, 20000, 2000, true, 1, true, 400);
    cout << "\nIndustrial Building Created:" << endl;
    cout << "Type: " << industrialBuilding->getType() << endl;
    cout << "Satisfaction: " << industrialBuilding->calculateSatisfaction() << endl;
    cout << "Economic Impact: " << industrialBuilding->calculateEconomicImpact() << endl;
    cout << "Resource Consumption: " << industrialBuilding->calculateResourceConsumption() << endl;
    industrialBuilding->doImprovements();
    cout << "Satisfaction after improvement: " << industrialBuilding->calculateSatisfaction() << endl;

    // Clean up
    delete residentialBuilding;
    delete landmarkBuilding;
    delete commercialBuilding;
    delete industrialBuilding;
}

int main() {
    factoryBuildings();
    return 0;
}