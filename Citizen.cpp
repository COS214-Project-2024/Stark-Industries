#include "Citizen.h"
#include <iostream>
#include "Road.h"
#include "Railway.h"
#include "Runway.h"
#include "Train.h"
#include "Air.h"


/**
 * @brief Constructs a Citizen with the given attributes.
 * 
 * @param name Name of the citizen.
 * @param income Income of the citizen.
 * @param propertyValue Value of the citizen's property.
 */
int Citizen::numCitizens = 0;
Citizen::Citizen(const std::string& name, int income, double propertyValue, string job)
    : name(name), income(income), propertyValue(propertyValue), commuteTime(0),
      isSatisfiedTrans(0), hasPaid(false), job(job) 
	{
		numCitizens++;
	}

int Citizen::satisfactionLevelTrans = 50;

Citizen::Citizen(const std::string& name, int income, int cargo)
    : name(name), income(income), commuteTime(0) , 
       hasPaid(false),  cargo(cargo),chosenTransport(NULL)
	{
		numCitizens++;
	}

Citizen::Citizen(std::string name, double baseIncome) {
	this->name = name;
	this->income = baseIncome;
	numCitizens++;
}

int Citizen::getNumCitizens() {
	return numCitizens;
}

void Citizen::get() {
	// TODO - implement Citizen::get
	// throw "Not yet implemented";
}

void Citizen::set() {
	// // TODO - implement Citizen::set
	// throw "Not yet implemented";
}

CitizenPrototype* Citizen::clone() {
	// TODO - implement Citizen::clone
	throw "Not yet implemented";
}

void Citizen::observerUpdate(string type) {
	if (type == "City") {
		std::cout << "Citizen " << name << " has been notified of a city change.\n";
	}
	else if (type == "Building") {
		std::cout << "Citizen " << name << " has been notified of a building change.\n";
	}
    satisfaction++; 
	wasNotified = true;
}

bool Citizen::isNotified() const {
	return wasNotified; 
}
void Citizen::resetNotification() {
	wasNotified = false;
} 

int Citizen::calculateSatisfaction() {
	return satisfaction; //Mock implementation for testing
}

void Citizen::requestBuilding(int City_city, int String_buildtype) {
	// TODO - implement Citizen::requestBuilding
	throw "Not yet implemented";
}

void Citizen::recieveMoveinDate() {
	// TODO - implement Citizen::recieveMoveinDate
	throw "Not yet implemented";
}

/**
 * @brief Citizen chooses a transport if available, affordable, and meets cargo requirements.
 * @param trans Pointer to the Transport the citizen is choosing.
 */
void Citizen::chooseTransport(Transport* trans) {
	if(dynamic_cast<Air*>(trans)){
		if(Runway::getRunwayCount()<1){
			std::cout<<"Unable to chose Air transport as runways have not yet been built"<<std::endl;
			return;
		}
	}else if(dynamic_cast<Train*>(trans)){
		if(Railway::getRailwayCount()<1){
			std::cout<<"Unable to chose Train transport as railways have not yet been built"<<std::endl;
			return;
		}
	}else{
		if(Road::getRoadCount()<1){
			std::cout<<"Unable to chose Car and Public transport as roads have not yet been built"<<std::endl;
			return;
		}
	}
  if (!trans->isAvailable()) {
        cout << name << " tried to choose transport, but it is under maintenance.\n";
        leaveFeedback();
        return;
    }
    if (income < trans->getFee()) {
        std::cout << name << " cannot afford this transport.\n";
        return;
    }
if (trans->getAvailableSeats()<1) {
        std::cout << name << " tried to choose " << trans->getType() << " transport, but no seats are available.\n";
        leaveFeedback();
        return;
    }

if(cargo>=1){
    if(!trans->hasCargoCapacity()){
        std::cout << name << " tried to choose " << trans->getType() << " transport, but it doesnt support cargo.\n";
        leaveFeedback();
       return;
    }
     if(trans->getAvailableCargoSpace()<cargo){
 std::cout << name << " tried to choose " << trans->getType() << " transport, but there is not enough space for their cargo.\n";
        leaveFeedback();
       return;
     }else{
        trans->loadCargo(cargo);
     }}


    chosenTransport = trans;
   // income=income
   income -= trans->getFee();
    commuteTime = trans->commuteTime();
     trans->reserveSeat();  // Reserve a seat on the transport
    hasPaid = true;
    
    std::cout << name << " chose " << trans->getType() << " transport.\n";
    updateSatisfaction();
}

void Citizen::requestUtilitiesService() {
	// TODO - implement Citizen::requestUtilitieService
	throw "Not yet implemented";
}


/**
 * @brief Citizen leaves feedback, decreases satisfaction if transport experience was unsatisfactory.
 */
void Citizen::leaveFeedback() {
    std::cout << name << " left feedback: Unsatisfied with the transportation.\n";
    satisfactionLevelTrans -= 10;
}

/*bool Citizen::checkSatisfaction() {
    return satisfactionLevelTrans > 50;
}*/

/**
 * @brief Updates the citizen's satisfaction based on commute time.
 */
void Citizen::updateSatisfaction() {
    if (commuteTime > 60) {
        satisfactionLevelTrans -= 20;
		citySatisfaction -= 10;
    } else {
        satisfactionLevelTrans += 5;
		citySatisfaction += 10;
    }
   // isSatisfiedTrans = (satisfactionLevelTrans > 50);
}

/**
 * @brief Citizen disembarks from chosen transport, releases seat, and manages cargo if applicable.
 */
void Citizen::disembark() {
    if (chosenTransport) {
        chosenTransport->releaseSeat();  // Release the reserved seat
        std::cout << name << " has disembarked from " << chosenTransport->getType() << " transport.\n";
        if(chosenTransport->hasCargoCapacity()){
        chosenTransport->unloadCargo(cargo);}
		if(getSatisfactionTransport()<60){
chosenTransport->doMaintenance();}
chosenTransport = NULL;
		}
        
    }

/**
 * @brief Get the satisfaction level of the citizen related to transport.
 * @return Satisfaction level as an integer.
 */
int Citizen::getSatisfactionTransport(){
	return satisfactionLevelTrans;
}

/**
 * @brief Get the income of the citizen.
 * @return Income as an integer.
 */
int Citizen::getIncome(){
    return income;
}

/**
 * @brief Get the name of the citizen.
 * @return Name as a string.
 */
std::string Citizen::getName(){
    return name;}

//command functions
void Citizen::performAction(int type) {
	if(type == 0) {
		//collect tax
		//std::cout<<"Income Tax collected from citizens"<<std::endl;
		payTax();
	}
	else if(type == 1) {
		//increase tax
		//std::cout<<"Tax increased by 2%"<<std::endl;
		setTaxRate();
		citySatisfaction -= 10;
	}
	else if(type == 2) {
		//allocate tax
		std::cout<<"Tax allocated"<<std::endl;
		//probably deleting this
	}
	else {
		std::cout<<"Invalid command"<<std::endl;
	}
}

void Citizen::payTax() {
	//std::cout<<"Time to collect Income Tax from citizens"<<std::endl;
	// citizens pay 15% of their income
	double tax = this->income * taxRate;
	income -= tax;
	taxPaid += tax;
	std::cout<<"Income Tax paid: "<<tax << " by " << this->name <<std::endl;
	//will have to send to government
}

void Citizen::getPaid(double income) {
	this->income += income;
}

double Citizen::setTaxRate() {
	taxRate += 0.02;
	return taxRate;
}

void Citizen::acceptTaxCollector(Visitor * taxCollector) {
	taxCollector->visit(this);
}


void Citizen::transport(){
        if(chosenTransport==NULL){
            std::cout<<"Citizen has not yet selected their preferred transport";
        }else{
            double time=chosenTransport->commuteTime();
         std::cout<< name<<  " is transportting via "<<chosenTransport->getType()<<" and the total time will be "<<time<<std::endl;
         std::cout<<time<<" minutes later..."<<std::endl;
         disembark();
		 }
}

void Citizen::acceptTransportSatisfactionChecker(Visitor * satisfactionChecker){
	satisfactionChecker->transportSatisfaction(this);
}

void Citizen::acceptBuildingSatisfactionChecker(Visitor* satisfactionChecker){
	satisfactionChecker->buildingSatisfaction(this);
}

void Citizen::acceptCitySatisfactionChecker(Visitor* satisfactionChecker){
	satisfactionChecker->citySatisfaction(this);
}

void Citizen::payRent(double rent){
	income -= rent;
}
void Citizen::setNumCitizens(int num) {
    numCitizens = num;
}

Citizen::Citizen() {
	
}

double Citizen::getTaxRate(){
	return taxRate;
}

