#ifndef TRANSPORTINFRASTRUCTURE_H
#define TRANSPORTINFRASTRUCTURE_H
#include <string>
#include <vector>

struct TrafficData {
    int vehicleCount;
    double averageSpeed;
    int congestionLevel; // 0-100
    double peakHourUsage;
};

class TransportInfrastructure {
	protected:
    std::string name;
    double constructionCost;
    double maintenanceCostPerYear;
    int capacity;
    int currentLoad;
    bool operational;
    double condition; // 0-100%
    
    TrafficData trafficStats;


public:
	virtual double getCost()= 0;
	virtual void build() = 0;
	virtual ~TransportInfrastructure() = default;
};

#endif
