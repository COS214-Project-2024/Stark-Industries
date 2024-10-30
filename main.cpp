#include <iostream>
#include "Citizen.h"
#include "CollectTax.h"
#include "Industrial.h"
#include "Residential.h"
#include "Commercial.h"
#include "IncreaseTax.h"
#include "TaxCollector.h"
#include "City.h"

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

void testIncreaseTax(){
    Citizen* citizen = new Citizen("Tony", 10000);
    Command * incTax = new IncreaseTax(citizen);
    incTax->execute(); 
}

void testTaxCollector(){
    TaxCollector* taxCollector = new TaxCollector();
    Citizen* citizen = new Citizen("Tony", 1000);
    Citizen* citizen2 = new Citizen("Sherlock", 1000);
    City * city = new City();
    CollectTax* collectTax = new CollectTax(citizen, nullptr);
    collectTax->addCitizen(citizen2);
    collectTax->execute();
    city->attach(citizen);
    city->attach(citizen2);
    for (int i = 0 ; i < city->citizens.size() ; i++){
        taxCollector->visit(city->citizens[i]);
    }
}

int main() {
    //testCollectTax();
    testIncreaseTax();
    testTaxCollector();
}

