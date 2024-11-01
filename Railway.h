#ifndef RAILWAY_H
#define RAILWAY_H

#include "TransportInfrastructure.h"
#include <string>
using namespace std;

class Railway : public TransportInfrastructure {

private:
	double length;
    bool isElectrified;
    bool isUnderConstruction;
    static int railwayCount;

public:
	Railway(double railLength = 1.0, bool electrified = true);
    double getCost() override;
    bool getConstructionStatus();
	void build();
	void updateCapacity(double newLength, bool electrified);
    static int getRailwayCount();
    ~Railway();
};

#endif
