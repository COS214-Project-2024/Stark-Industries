#ifndef CITYFACADE_H
#define CITYFACADE_H

#include "ResourceManagerment.h"
#include "Building.h"
#include <string>
using namespace std;

class CityFacade : public ResourceManagement, public Building {


public:
	void createBuildlings();

	void createUtilities();

	void provideUtilityServices();

	void travel();

	void growPopulation();

	void checkCitizenSatisfaction();

	void collectTaxes();

	void supplyResources();

	void growCity();
};

#endif
