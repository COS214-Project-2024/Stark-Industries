#ifndef CAR_H
#define CAR_H

#include "Transport.h"
#include <string>
using namespace std;

class Car : public Transport {
private:
    bool isUnderMaintenance;
    double travelTime;
    double fee;
    int seatingCapacity;
	string name;
    int availableSeats;
    //int cargoCapacity;
    //int availableCargoSpace;

public:
    Car(string name,double travelTime, int seatingCapacity);
    
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

     bool hasCargoCapacity() const ; // Check if this transport supports cargo
    int getCargoCapacity() const ;
     int getAvailableCargoSpace() const ;
    bool loadCargo(int cargo) ;
     void unloadCargo(int cargo) ;
};

#endif // CAR_TRANSPORT_H