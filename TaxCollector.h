#ifndef TAXCOLLECTOR_H
#define TAXCOLLECTOR_H

#include "CitizenVisitor.h"
#include "Citizen.h"
#include <string>
using namespace std;

class TaxCollector : CitizenVisitor {
    void visit(Citizen* citizen);
    void visit(Building* building);
};

#endif
