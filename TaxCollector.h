#ifndef TAXCOLLECTOR_H
#define TAXCOLLECTOR_H

#include "Visitor.h"
#include "Citizen.h"
#include "Building.h"
#include <string>
#include <iostream>
using namespace std;

class TaxCollector : public Visitor {
    public:
        TaxCollector(){};
        void visit(Citizen* citizen);
        void visit(Building* building);
        //double taxCollected;

};

#endif
