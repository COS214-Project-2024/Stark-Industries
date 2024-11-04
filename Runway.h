#ifndef RUNWAY_H
#define RUNWAY_H

#include "TransportInfrastructure.h"

class Runway : public TransportInfrastructure {

private:
	double length;
    double width;
    bool isUnderConstruction;
    static int runwayCount;

public:
	Runway(double runwayLength=2.0, double runwayWidth=0.05);
    void build() override;
    double getCost() override;
    bool getConstructionStatus();
	void updateCapacity(double newLength, double newWidth);
    static int getRunwayCount();
    ~Runway();
};

#endif
