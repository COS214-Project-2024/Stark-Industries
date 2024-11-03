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
    Transport* chosenTransport;       /**< Pointer to the chosen transport mode. */
    int cargo;                        /**< Size of cargo the citizen wants to transport. */
    bool hasPaid;                     /**< Flag indicating if the citizen has paid their taxes. */
	int isSatisfiedTrans;
	double satisfaction;
	bool wasNotified;
	double taxRate = 0.15;
	static int numCitizens;
	string job;

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

	const std::array<std::string, 200> jobTitles = {
		"Software Engineer", "Data Analyst", "Project Manager", "UX Designer", "Accountant",
		"HR Specialist", "Marketing Manager", "Sales Representative", "Electrical Engineer",
		"Mechanical Engineer", "Civil Engineer", "Network Administrator", "Database Administrator",
		"Cybersecurity Specialist", "Biomedical Engineer", "Teacher", "Research Scientist",
		"Chemist", "Physicist", "Statistician", "Graphic Designer", "Architect", "Consultant",
		"Copywriter", "Translator", "Financial Analyst", "Social Media Manager", "Supply Chain Manager",
		"Healthcare Administrator", "Nurse", "Physical Therapist", "Dental Hygienist", "Pharmacist",
		"Veterinarian", "Librarian", "Lawyer", "Judge", "Firefighter", "Police Officer", "Paramedic",
		"Chef", "Baker", "Software Developer", "Web Developer", "IT Support", "Game Developer",
		"Sound Engineer", "Animator", "Product Manager", "Operations Manager", "Economist",
		"Biologist", "Urban Planner", "Pilot", "Flight Attendant", "Editor", "Journalist",
		"Public Relations Specialist", "Art Director", "Musician", "Author", "Historian",
		"Psychologist", "Therapist", "Speech Therapist", "Interpreter", "Construction Worker",
		"Electrician", "Plumber", "Carpenter", "Mechanic", "Truck Driver", "Bartender", "Waiter",
		"Receptionist", "Real Estate Agent", "Insurance Agent", "Financial Planner", "Loan Officer",
		"Bank Teller", "Janitor", "Groundskeeper", "Landscaper", "Security Guard", "Laborer",
		"Roofer", "Agricultural Worker", "Marine Biologist", "Park Ranger", "Tour Guide",
		"Phlebotomist", "Nutritionist", "Event Planner", "HR Manager", "Advertising Specialist",
		"Photographer", "Videographer", "Barber", "Cosmetologist", "Makeup Artist", "Personal Trainer",
		"Fitness Instructor", "Model", "Flight Engineer", "Aerospace Engineer", "Mechanical Technician",
		"Chemical Engineer", "Energy Engineer", "Mathematician", "Actuary", "Investment Banker",
		"Economist", "Financial Advisor", "Business Analyst", "Operations Analyst", "Marketing Analyst",
		"Policy Analyst", "Sports Coach", "Athletic Trainer", "Gym Manager", "Social Worker",
		"School Counselor", "Career Counselor", "Real Estate Broker", "Property Manager", "Urban Designer",
		"Landscape Architect", "Interior Designer", "Set Designer", "Fashion Designer", "Costume Designer",
		"Modeling Agent", "Talent Agent", "Event Coordinator", "Wedding Planner", "Personal Assistant",
		"Executive Assistant", "Customer Service Representative", "Technical Support", "Help Desk Technician",
		"IT Consultant", "Data Scientist", "Machine Learning Engineer", "AI Specialist", "Robotics Engineer",
		"Environmental Engineer", "Hydrologist", "Ecologist", "Forestry Technician", "Geologist",
		"Marine Engineer", "Petroleum Engineer", "Mining Engineer", "Renewable Energy Specialist",
		"Wind Turbine Technician", "Solar Panel Installer", "Biomedical Scientist", "Geneticist",
		"Lab Technician", "Research Assistant", "Medical Assistant", "Clinical Laboratory Technician",
		"Pharmaceutical Sales", "Biotechnologist", "Forensic Scientist", "Food Scientist", "Agronomist",
		"Zoologist", "Wildlife Biologist", "Veterinary Technician", "Animal Trainer", "Pet Groomer",
		"Dog Walker", "Retail Manager", "Store Supervisor", "Cashier", "Stock Clerk", "Inventory Specialist",
		"Purchasing Manager", "Supply Chain Analyst", "Warehouse Manager", "Logistics Coordinator",
		"Shipping Manager", "Dispatcher", "Freight Forwarder", "Customs Broker", "Export Coordinator",
		"Import Specialist", "Courier", "Delivery Driver", "Truck Loader", "Pilot", "Air Traffic Controller",
		"Flight Instructor", "Ground Crew", "Aircraft Mechanic", "Travel Agent", "Tour Guide", "Concierge"
	};


	Citizen(const std::string& name, int income, double propertyValue, string job);

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
	void transport();
	virtual void acceptTaxCollector(Visitor * taxCollector);

	int getNumCitizens();


	static int satisfactionLevelTrans;       /**< Satisfaction level related to transport. */
	int buildingSatisfaction = 50;
	int citySatisfaction = 50;
	void acceptTransportSatisfactionChecker(Visitor * satisfactionChecker);
	void acceptBuildingSatisfactionChecker(Visitor* satisfactionChecker);
	void acceptCitySatisfactionChecker(Visitor*);
	void payRent(double);
	void setNumCitizens(int);
	Citizen();
};

#endif