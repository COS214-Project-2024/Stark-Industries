#ifndef CITY_H
#define CITY_H

#include "Element.h"
#include "Citizen.h"
#include "TransportInfrastructure.h"
#include <string>
#include <vector>
using namespace std;

class City : public Element {

private:
	//vector<Citizen*> citizens;
	vector<TransportInfrastructure*> roads;

public:
	void attach(Citizen* citizen);

	void detach(Citizen* citizen);

	void notify();

	void requestBuilding(int Citizen_cit, int String_buildtype);

	void buildingComplete(int String_buildtype, int Citizen_citizen);

	bool inspectBuilding();

	vector<Citizen*> citizens;
};

#endif
