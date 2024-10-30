#ifndef CITIZEN_H
#define CITIZEN_H

#include "CitizenPrototype.h"
#include "Transport.h"
#include "TransportSystem.h"
// #include "Building.h"
#include <string>
#include "Visitor.h"
using namespace std;

/**
 * @class Citizen
 * @brief Represents a citizen in the city simulation who interacts with transport and utilities.
 * 
 * The Citizen class manages properties such as income, property value, and transport choices,
 * as well as satisfaction levels and requests for building and utility services.
 */
class Citizen : CitizenPrototype {

private:
	// Building* observerList; //Building is abstract
	string name;                 /**< Name of the citizen. */
    int income;                       /**< Income level of the citizen. */
    double propertyValue;             /**< Property value owned by the citizen. */
    double commuteTime;               /**< Commute time for the citizen. */
	//bool isSatisfiedTrans;
	static int satisfactionLevelTrans;       /**< Satisfaction level related to transport. */
    Transport* chosenTransport;       /**< Pointer to the chosen transport mode. */
    int cargo;                        /**< Size of cargo the citizen wants to transport. */
    bool hasPaid;                     /**< Flag indicating if the citizen has paid their taxes. */
	int isSatisfiedTrans;
	double satisfaction;
	bool wasNotified;
	double taxRate = 0.15;

public:

	Citizen(const std::string& name, int income, double propertyValue);

	Citizen(const std::string& name, int income,int cargo);

	void get();
	void set();
	CitizenPrototype* clone();
	int calculateSatisfaction();
	void requestBuilding(int City_city, int String_buildtype);
	void recieveMoveinDate();
	void choseTransport(int Transport_trans);

	void requestUtilitiesService();

	/**
     * @brief Chooses a transport for the citizen.
     * @param trans Pointer to the selected Transport object.
     */
	void chooseTransport(Transport* trans);

	/**
     * @brief Updates the citizen’s satisfaction level based on the chosen transport.
     */
	 void updateSatisfaction();
      //  bool checkSatisfaction();

	  /**
     * @brief Allows the citizen to disembark from the chosen transport.
     */
	    void disembark();

	/**
     * @brief Citizen leaves feedback on their transport experience.
     */
    void leaveFeedback() ;

	/**
     * @brief Retrieves the citizen's transport satisfaction level.
     * @return Satisfaction level as an integer.
     */
	int getSatisfactionTransport();

	/**
     * @brief Retrieves the citizen's income.
     * @return Income level as an integer.
     */
	int getIncome();

	/**
     * @brief Retrieves the citizen's name.
     * @return Name as a string.
     */
     std::string getName();


	//Observer
	void observerUpdate(string type);
	bool isNotified() const;
    void resetNotification();
	void requestUtilitieService();
	void getPaid(double income);
	Citizen(string name, double baseIncome);
	//command functions
	void performAction(int type);
	//visitor functions
	void payTax();
	void setTaxRate();
	double taxPaid;
	void acceptTaxCollector(Visitor * taxCollector);
	int citySatisfaction = 50;
	int buildingSatisfaction = 50;
	void acceptTransportSatisfactionChecker(Visitor * satisfactionChecker);
	void acceptBuildingSatisfactionChecker(Visitor* satisfactionChecker);
	void acceptCitySatisfactionChecker(Visitor* satisfactionChecker);
	void payRent(double rent);

};

#endif