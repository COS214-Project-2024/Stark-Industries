#ifndef ROAD_H
#define ROAD_H

#include "TransportInfrastructure.h"
#include <string>
#include <map>
#include <vector>

enum class RoadType {
    LOCAL,
    COLLECTOR,
    ARTERIAL,
    HIGHWAY
};

class Road : public TransportInfrastructure {

private:
	RoadType type;
	int lanes;
    double length;
    bool isUnderConstruction;
    double speedLimit;
    std::map<int, int> hourlyTrafficVolume;
    std::vector<double> trafficLights;
    bool needsRepaving;

public:
	Road(int numLanes=2, double roadLength=1.0);
	void build();
	void updateTraffic(int time);
    double getCost() override;
    bool getConstructionStatus();
    void deteriorate(double deteriorationFactor);
	void updateCapacity(int newLanes, RoadType newType);
	void addTrafficLight(double position);
    void removeTrafficLight(double position);
    std::vector<double> getTrafficLights();
};

#endif
