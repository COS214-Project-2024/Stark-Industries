#ifndef CITIZEN_H
#define CITIZEN_H

#include "CitizenPrototype.h"
#include "Transport.h"
#include "TransportSystem.h"
// #include "Building.h"
#include <string>
#include "Visitor.h"
#include <array>
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
	int numCitizens;

public:
	// Array of 200 potential citizen names
	const std::array<std::string, 200> citizenNames = {
		"Alex", "Jordan", "Taylor", "Casey", "Riley", "Morgan", "Jamie", "Avery", "Quinn", "Dakota",
		"Skyler", "Reese", "Drew", "Finley", "Sawyer", "Harper", "Rowan", "Elliot", "Phoenix", "Emerson",
		"Blake", "Kendall", "Ari", "Ainsley", "Arden", "Bellamy", "Channing", "Hayden", "Jayden", "Sasha",
		"Peyton", "Devon", "Emery", "Keegan", "Lennon", "Logan", "Nico", "Rylan", "Spencer", "Sydney",
		"Tatum", "Teagan", "Tyler", "River", "Parker", "Shawn", "Skylar", "Addison", "Aspen", "Bailey",
		"Charlie", "Cameron", "Dallas", "Dylan", "Easton", "Gray", "Jesse", "Jordan", "Jules", "Karter",
		"Lake", "Lennox", "Luca", "Maddox", "Marley", "Micah", "Payton", "Presley", "Remy", "Rory",
		"Sam", "Shiloh", "Stevie", "Terry", "Winter", "Wren", "Zion", "Angel", "Archer", "Arlo",
		"Atlas", "August", "Baylor", "Blaine", "Briar", "Brooks", "Callan", "Carson", "Chase", "Cruz",
		"Dane", "Dax", "Eli", "Ezra", "Finn", "Flynn", "Gage", "Gentry", "Gio", "Grady", "Harlow",
		"Hendrix", "Hudson", "Huxley", "Indigo", "Jacoby", "Jagger", "Jax", "Jett", "Jude", "Justice",
		"Kasen", "Knox", "Landry", "Lennox", "Levi", "Maverick", "Max", "Monroe", "Oakley", "Orion",
		"Phoenix", "Rocco", "Ryder", "Ryker", "Sailor", "Sloan", "Sterling", "Sullivan", "Tanner",
		"Thatcher", "Tristan", "Vaughn", "Wilder", "Xander", "Zephyr", "Ace", "Apollo", "Bo", "Cash",
		"Colby", "Cooper", "Dane", "Dash", "Dex", "Ford", "Hank", "Holt", "Jax", "Jed", "Kai",
		"Kade", "Knox", "Lance", "Miles", "Nash", "Reid", "Rex", "Zane", "Zeke", "Arden", "Ash",
		"Blake", "Corbin", "Crew", "Cruz", "Drew", "Finn", "Ford", "Graham", "Gus", "Hale",
		"Holt", "Ike", "Jack", "Jace", "Jay", "Jett", "Joss", "Kip", "Luke", "Mark", "Nico", "Noah",
		"Quinn", "Rhys", "Ridge", "Sam", "Scout", "Shane", "Tate", "Trey", "Wade", "Wes", "Zeke"
	};

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

	int getNumCitizens();
	void setNumCitizens(int num); 
	Citizen();
};

#endif