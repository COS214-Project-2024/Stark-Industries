#ifndef CITYFACADE_H
#define CITYFACADE_H

#include "Population.h"
#include "Housing.h"
#include "Economic.h"
#include "Infrastructure.h"
#include "ResidentialCreator.h"
#include "LandmarkCreator.h"
#include "CommercialCreator.h"
#include "IndustrialCreator.h"
#include "Building.h"

#include "WaterFactory.h"
#include "WasteFactory.h"
#include "SewageFactory.h"
#include "PowerPlantFactory.h"
#include "Utilities.h"
#include "Water.h"
#include "Waste.h"
#include "Sewage.h"

#include "Tax.h"
#include "Budget.h"
#include "Policies.h"
#include "Services.h"
#include "Government.h"

#include "Residential.h"
#include "Commercial.h"
#include "Industrial.h"
#include "Landmark.h"
#include "Citizen.h"

#include "City.h"

#include "RunwayFactory.h"
#include "RoadFactory.h"
#include "RailwayFactory.h"
#include "Citizen.h"
#include "Transport.h"
#include "Public.h"
#include "Train.h"
#include "Air.h"
#include "Car.h"

#include "CollectTax.h"
#include "IncreaseTax.h"
#include "SatisfactionChecker.h"

#include "Citizen.h"
#include "CollectTax.h"
#include "Industrial.h"
#include "Residential.h"
#include "Commercial.h"
#include "IncreaseTax.h"
#include "TaxCollector.h"
#include "City.h"
#include "ResourceManagerment.h"

#include <string>
using namespace std;

class CityFacade {

private:
	City* city;
public:
	CityFacade();
	void pauseForUser();
	void initializeResources();
	void createInitialBuildings(City* city);
	void createAndAssignUtilities(City* city);
	void createAndAssignTransport(City* city);
	void setupGovernment(City* city);
	void createAndAssignCitizens(City* city);
	void showMainMenu();
	void addCommandsToTaxDepartment(Tax* taxDept, City* city);
	double taxCollectorVisitor(Tax* taxDept, City* city);
	void manageTaxDepartment(Tax* taxDept, Budget* budgetDept, City* city);
	void manageBudgetDepartment(Budget* budgetDept);
	void managePoliciesDepartment(Policies* policiesDept);
	void manageServicesDepartment(Services* servicesDept);
	void manageGovernment(City* city);
	void buildNewBuilding(City* city);
	void inspectBuilding(City* city);
	void improveBuilding(City* city);
	void removeBuilding(City* city);
	double buildingCitySatisfaction(Building* building);
	double citizenSatisfactionForBuilding(Building* building);
	void viewAllBuildings(City* city);
	void increaseRent(City* city);
	void manageBuildings(City* city);
	void addCustomCitizen(City* city);
	void addMultipleCitizens(City* city);
	void viewCitizenInformation(City* city);
	void viewAllCitizens(City* city);
	void removeCitizen(City* city);
	double averageCitizenTransportSatisfaction(City* city);
	void manageTransportForCitizen(City* city);
	double citySatisfactionChecker(City* city);
	void manageCitizens(City* city);
	void manageTransport(City* city);
	void increasePopulation(City* city);
	void displayCityStats(City* city);
	void bigTestingMain();
};

#endif
