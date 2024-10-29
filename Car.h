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

    virtual bool hasCargoCapacity() const = 0; // Check if this transport supports cargo
    virtual int getCargoCapacity() const = 0;
    virtual int getAvailableCargoSpace() const = 0;
    virtual bool loadCargo(int cargo) = 0;
    virtual void unloadCargo(int cargo) = 0;
};

#endif // CAR_TRANSPORT_H
