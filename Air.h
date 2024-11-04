#ifndef AIR_H
#define AIR_H

#include "Transport.h"
#include <string>
using namespace std;

class Air : public Transport {
private:
    bool isUnderMaintenance;  
    double travelTime;       
    double fee;               
    int seatingCapacity;      
    int availableSeats;       
    int cargoCapacity;        
    int availableCargoSpace;  
    string name;              
public:
    Air(string name, double travelTime, double fee, int seatingCap, int cargoCap);
    void doMaintenance() override;
    double commuteTime() override;
    int calculateSatisfaction() override;
    bool isAvailable() const override;
    double getFee() const override;
    std::string getType() const override;
    int getSeatingCapacity() const override;
    int getAvailableSeats() const override;
    bool reserveSeat() override;
    void releaseSeat() override;
    bool hasCargoCapacity() const override;
    int getCargoCapacity() const override;
    int getAvailableCargoSpace() const override;
    bool loadCargo(int cargo) override;
    void unloadCargo(int cargo) override;
};

#endif
