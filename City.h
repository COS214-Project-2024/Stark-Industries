#ifndef CITY_H
#define CITY_H

#include "Element.h"
#include "Citizen.h"
#include "TransportInfrastructure.h"
#include "Building.h"
#include "Government.h"
#include <string>
#include <vector>
using namespace std;

class City : public Element {

private:
	std::string name;
	std::vector<Building*> buildings;
	std::vector<Citizen*> observerList;
	std::vector<Utilities*> utilities;
	vector<TransportInfrastructure*> roads;
	Government* government;

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

	vector<Citizen*> citizens;

	Government* getGovernment();
};

#endif
