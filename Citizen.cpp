#include "Citizen.h"
#include <iostream>

void Citizen::get() {
	// TODO - implement Citizen::get
	throw "Not yet implemented";
}

void Citizen::set() {
	// TODO - implement Citizen::set
	throw "Not yet implemented";
}

CitizenPrototype* Citizen::clone() {
	// TODO - implement Citizen::clone
	throw "Not yet implemented";
}

void Citizen::observerUpdate() {
	// TODO - implement Citizen::observerUpdate
	throw "Not yet implemented";
}



void Citizen::taxPaid() {
	// TODO - implement Citizen::taxPaid
	throw "Not yet implemented";
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

void Citizen::requestUtilitieService() {
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
    } else {
        satisfactionLevelTrans += 5;
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
		if(getSatisfaction()<60){
chosenTransport->doMaintenance();}
chosenTransport = NULL;
		}
        
    }

/**
 * @brief Get the satisfaction level of the citizen related to transport.
 * @return Satisfaction level as an integer.
 */
int Citizen::getSatisfaction(){
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