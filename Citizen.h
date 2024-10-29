#ifndef CITIZEN_H
#define CITIZEN_H

#include "CitizenPrototype.h"
#include "Transport.h"
#include "TransportSystem.h"
// #include "Building.h"
#include <string>
using namespace std;

class Citizen : CitizenPrototype {

private:
	// Building* observerList; //Building is abstract
	string name;
	int income;
	double propertyValue;
	double commuteTime;
	//bool isSatisfiedTrans;
	  int satisfactionLevelTrans;
	Transport* chosenTransport;
	int cargo; // Size of cargo the citizen wants to transport
	bool hasPaid;

public:
	void get();

	void set();

	CitizenPrototype* clone();

	void observerUpdate();

	

	void taxPaid();

	void requestBuilding(int City_city, int String_buildtype);

	void recieveMoveinDate();

	

	void requestUtilitieService();

	void chooseTransport(Transport* trans);
	 void updateSatisfaction();
        bool checkSatisfaction();
	    void disembark();
    void leaveFeedback() ;
};

#endif
