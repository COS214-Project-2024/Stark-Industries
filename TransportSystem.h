#ifndef TRANSPORTSYSTEM_H
#define TRANSPORTSYSTEM_H

#include "Transport.h"
#include <string>
using namespace std;

class TransportSystem {

private:
	Transport* transportStrategy;

	//double totalCommuteTime;

public:
 TransportSystem();
        void setTransportStrategy(Transport* strategy);
    void performMaintenance();
    bool isTransportAvailable() const;
    double getTransportFee() const;
    double getCommuteTime() const;
    int calculateSatisfaction() const;
    std::string getTransportType() const;

 ~TransportSystem();    

  bool checkSeatAvailability() const;
    bool reserveSeat();
    void releaseSeat();

    bool checkCargoAvailability(int cargo) const;
    bool loadCargo(int cargo);
    void unloadCargo(int cargo);


	void checkAvailability(int TransportInfastructure_transInfas);
};

#endif
