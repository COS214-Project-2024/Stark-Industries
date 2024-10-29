#ifndef TRANSPORT_H
#define TRANSPORT_H

class Transport {


public:
	 virtual void doMaintenance() = 0;
    virtual double commuteTime() = 0;
    virtual int calculateSatisfaction() = 0;
    virtual bool isAvailable() const = 0;
    virtual double getFee() const = 0;
    virtual std::string getType() const = 0;

    virtual ~Transport() = default;

    virtual int getSeatingCapacity() const = 0;
    virtual int getAvailableSeats() const = 0;
    virtual bool reserveSeat() = 0;
    virtual void releaseSeat() = 0;

    virtual bool hasCargoCapacity() const = 0; // Check if this transport supports cargo
    virtual int getCargoCapacity() const = 0;
    virtual int getAvailableCargoSpace() const = 0;
    virtual bool loadCargo(int cargo) = 0;
    virtual void unloadCargo(int cargo) = 0;

};

#endif
