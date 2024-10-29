#include <iostream>
#include "Citizen.h"
#include "CollectTax.h"
#include "Industrial.h"
#include "Residential.h"
#include "Commercial.h"

void testCollectTax(){
    Citizen* citizen = new Citizen("Tony", 1000);
    Building* industrial = new Industrial();
    CollectTax* collectTax = new CollectTax(citizen, industrial);
    Building* residential = new Residential();
    collectTax->addBuilding(residential);
    Building* commercial = new Commercial();
    collectTax->addBuilding(commercial);
    collectTax->execute();
}

int main() {
    testCollectTax();
}

