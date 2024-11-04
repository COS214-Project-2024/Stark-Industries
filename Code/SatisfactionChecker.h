#ifndef SATISFACTIONCHECKER_H
#define SATISFACTIONCHECKER_H

#include "Visitor.h"
#include "Citizen.h"
#include "Building.h"
#include <string>
#include <iostream>
using namespace std;

class SatisfactionChecker : public Visitor {
public:
    void transportSatisfaction(Citizen* citizen); //visit
    void buildingSatisfaction(Citizen* citizen); //visit
    void citySatisfaction(Citizen* citizen); //visit
    void citySatisfaction(Building* building); //visit
    void visit(Citizen* citizen);
    void visit(Building* building);
    double citySatisfactionTotal = 0;
    double buildingSatisfactionTotal = 0;
    double transportSatisfactionTotal = 0;
};

#endif
