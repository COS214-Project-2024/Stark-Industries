#ifndef CITIZEN_H
#define CITIZEN_H

#include "CitizenPrototype.h"
#include "Transport.h"
#include "TransportSystem.h"
// #include "Building.h"
#include <string>
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
	std::string name;                 /**< Name of the citizen. */
    int income;                       /**< Income level of the citizen. */
    double propertyValue;             /**< Property value owned by the citizen. */
    double commuteTime;               /**< Commute time for the citizen. */
	//bool isSatisfiedTrans;
	static int satisfactionLevelTrans;       /**< Satisfaction level related to transport. */
    Transport* chosenTransport;       /**< Pointer to the chosen transport mode. */
    int cargo;                        /**< Size of cargo the citizen wants to transport. */
    bool hasPaid;                     /**< Flag indicating if the citizen has paid their taxes. */

public:
Citizen(const std::string& name, int income,int cargo);
	void get();

	void set();

	CitizenPrototype* clone();

	void observerUpdate();

	

	void taxPaid();

	void requestBuilding(int City_city, int String_buildtype);

	void recieveMoveinDate();

	

	void requestUtilitieService();

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
	int getSatisfaction();

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

};

#endif