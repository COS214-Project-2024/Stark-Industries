#ifndef CITY_H
#define CITY_H

#include "Element.h"
#include "Citizen.h"
#include "TransportInfrastructure.h"
#include "Building.h"
#include "Government.h"
#include "ResidentialCreator.h"
#include "CommercialCreator.h"
#include "IndustrialCreator.h"
#include "LandmarkCreator.h"
#include "Building.h"
#include <string>
#include <vector>
using namespace std;

class City : public Element {

private:
	std::string name;
	std::vector<Citizen*> observerList;
	std::vector<Utilities*> utilities;
	vector<TransportInfrastructure*> roads;
	Government* government;

	ResidentialCreator residentialCreator;
    CommercialCreator commercialCreator;
    IndustrialCreator industrialCreator;
    LandmarkCreator landmarkCreator;

public:
	City(const std::string& cityName);
	
	void attach(Citizen* citizen);

	void detach(Citizen* citizen);

	void notify();

	void requestBuilding(int Citizen_cit, int String_buildtype);

	void buildingComplete(int String_buildtype, int Citizen_citizen);

	bool inspectBuilding();

	void addBuilding(Building* building);  
    const std::vector<Building*>& listBuildings() const;
	std::string getName();
	void setGovernment(Government* government);
	void addUtility(Utilities* utility);

	void addInfrastructure(TransportInfrastructure* infrastructure);
	const std::vector<TransportInfrastructure*>& listInfrastructures() const;
	const std::vector<Utilities*>& listUtilities() const;
	std::vector<Building*>& listBuildings();

	vector<Citizen*> citizens;
	std::vector<Building*> buildings;

	Government* getGovernment();

	BuildingCreator* getBuildingCreator(const std::string& buildingType);

	int getTotalPopulation() const;

	int getAvailableHousingCapacity() const;

	vector<Citizen*>& getCitizens();

	void attach(Building* building);

	void detach(Building* building);
};

#endif
