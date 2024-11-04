/**
 * @file Citizen.cpp
 * @brief Implements the Citizen class, representing an individual in a city with attributes like income, property value, and satisfaction level. 
 * Citizens can choose transport, pay taxes, receive notifications, and perform other interactions in the city.
 */

#include "Citizen.h"
#include <iostream>
#include "Road.h"
#include "Railway.h"
#include "Runway.h"
#include "Train.h"
#include "Air.h"

int Citizen::numCitizens = 0;
int Citizen::satisfactionLevelTrans = 80;

/**
 * @brief Constructs a Citizen with specified attributes.
 * 
 * @param name Name of the citizen.
 * @param income Income of the citizen.
 * @param propertyValue Value of the citizen's property.
 * @param job Job title of the citizen.
 */
Citizen::Citizen(const std::string& name, int income, double propertyValue, std::string job)
    : name(name), income(income), propertyValue(propertyValue), commuteTime(0),
      isSatisfiedTrans(0), hasPaid(false), job(job) 
{
    numCitizens++;
}

/**
 * @brief Constructs a Citizen with specified attributes including cargo.
 * 
 * @param name Name of the citizen.
 * @param income Income of the citizen.
 * @param cargo Amount of cargo the citizen needs to transport.
 */
Citizen::Citizen(const std::string& name, int income, int cargo)
    : name(name), income(income), commuteTime(0), hasPaid(false), cargo(cargo), chosenTransport(nullptr) 
{
    numCitizens++;
}

/**
 * @brief Constructs a Citizen with a name and base income.
 * 
 * @param name Name of the citizen.
 * @param baseIncome Base income of the citizen.
 */
Citizen::Citizen(std::string name, double baseIncome) {
    this->name = name;
    this->income = baseIncome;
    numCitizens++;
}

/**
 * @brief Gets the total number of citizens.
 * 
 * @return Total number of citizens as an integer.
 */
int Citizen::getNumCitizens() {
    return numCitizens;
}

/**
 * @brief Updates the citizen as an observer when notified by city or building.
 * 
 * @param type Type of notification source ("City" or "Building").
 */
void Citizen::observerUpdate(std::string type) {
    if (type == "City") {
        std::cout << "Citizen " << name << " has been notified of a city change.\n";
    } else if (type == "Building") {
        std::cout << "Citizen " << name << " has been notified of a building change.\n";
    }
    satisfaction++;
    wasNotified = true;
}

/**
 * @brief Checks if the citizen has been notified.
 * 
 * @return True if notified, otherwise false.
 */
bool Citizen::isNotified() const {
    return wasNotified; 
}

/**
 * @brief Resets the citizen's notification status.
 */
void Citizen::resetNotification() {
    wasNotified = false;
} 

/**
 * @brief Calculates and returns citizen satisfaction level.
 * 
 * @return Satisfaction level as an integer.
 */
int Citizen::calculateSatisfaction() {
    return satisfaction; // Mock implementation for testing
}

/**
 * @brief Citizen chooses a transport if it meets availability, affordability, and cargo requirements.
 * 
 * @param trans Pointer to the Transport the citizen is choosing.
 */
void Citizen::chooseTransport(Transport* trans) {
    if(dynamic_cast<Air*>(trans) && Runway::getRunwayCount() < 1) {
        std::cout << "Unable to choose Air transport as runways have not yet been built\n";
        return;
    } else if(dynamic_cast<Train*>(trans) && Railway::getRailwayCount() < 1) {
        std::cout << "Unable to choose Train transport as railways have not yet been built\n";
        return;
    } else if (Road::getRoadCount() < 1) {
        std::cout << "Unable to choose Car and Public transport as roads have not yet been built\n";
        return;
    }
  
    if (!trans->isAvailable()) {
        std::cout << name << " tried to choose transport, but it is under maintenance.\n";
        leaveFeedback();
        return;
    }
    if (income < trans->getFee()) {
        std::cout << name << " cannot afford this transport.\n";
        return;
    }
    if (trans->getAvailableSeats() < 1) {
        std::cout << name << " tried to choose " << trans->getType() << " transport, but no seats are available.\n";
        leaveFeedback();
        return;
    }

    if(cargo >= 1) {
        if(!trans->hasCargoCapacity()) {
            std::cout << name << " tried to choose " << trans->getType() << " transport, but it doesn't support cargo.\n";
            leaveFeedback();
            return;
        }
        if(trans->getAvailableCargoSpace() < cargo) {
            std::cout << name << " tried to choose " << trans->getType() << " transport, but there is not enough space for their cargo.\n";
            leaveFeedback();
            return;
        } else {
            trans->loadCargo(cargo);
        }
    }

    chosenTransport = trans;
    income -= trans->getFee();
    commuteTime = trans->commuteTime();
    trans->reserveSeat();
    hasPaid = true;
    std::cout << name << " chose " << trans->getType() << " transport.\n";
    updateSatisfaction();
}

/**
 * @brief Citizen leaves feedback, decreasing satisfaction if transport experience was unsatisfactory.
 */
void Citizen::leaveFeedback() {
    std::cout << name << " left feedback: Unsatisfied with the transportation.\n";
    satisfactionLevelTrans -= 10;
}

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
}

/**
 * @brief Citizen disembarks from chosen transport, releases seat, and manages cargo if applicable.
 */
void Citizen::disembark() {
    if (chosenTransport) {
        chosenTransport->releaseSeat();
        std::cout << name << " has disembarked from " << chosenTransport->getType() << " transport.\n";
        if (chosenTransport->hasCargoCapacity()) {
            chosenTransport->unloadCargo(cargo);
        }
        if (getSatisfactionTransport() < 60) {
            chosenTransport->doMaintenance();
        }
        chosenTransport = nullptr;
    }
}

/**
 * @brief Get the satisfaction level of the citizen related to transport.
 * @return Satisfaction level as an integer.
 */
int Citizen::getSatisfactionTransport() {
    return satisfactionLevelTrans;
}

/**
 * @brief Get the income of the citizen.
 * @return Income as an integer.
 */
int Citizen::getIncome() {
    return income;
}

/**
 * @brief Get the name of the citizen.
 * @return Name as a string.
 */
std::string Citizen::getName() {
    return name;
}

// Command functions

/**
 * @brief Performs a specified action for tax purposes.
 * 
 * @param type Type of action: 0 for collecting tax, 1 for increasing tax, 2 for allocating tax.
 */
void Citizen::performAction(int type) {
    if (type == 0) {
        payTax();
    } else if (type == 1) {
        setTaxRate();
        citySatisfaction -= 10;
    } else if (type == 2) {
        std::cout << "Tax allocated\n";
    } else {
        std::cout << "Invalid command\n";
    }
}

/**
 * @brief Collects income tax from the citizen.
 */
void Citizen::payTax() {
    double tax = income * taxRate;
    income -= tax;
    taxPaid += tax;
    std::cout << "Income Tax paid: " << tax << " by " << name << std::endl;
}

/**
 * @brief Increases the citizen's income.
 * 
 * @param income Amount of income to add.
 */
void Citizen::getPaid(double income) {
    this->income += income;
}

/**
 * @brief Sets a new tax rate for the citizen.
 * 
 * @return The updated tax rate.
 */
double Citizen::setTaxRate() {
    taxRate += 0.02;
    return taxRate;
}

/**
 * @brief Accepts a tax collector visitor.
 * 
 * @param taxCollector Pointer to the Visitor object for tax collection.
 */
void Citizen::acceptTaxCollector(Visitor* taxCollector) {
    taxCollector->visit(this);
}

/**
 * @brief Transports the citizen using their chosen mode of transport.
 */
void Citizen::transport() {
    if (chosenTransport == nullptr) {
        std::cout << "Citizen has not yet selected their preferred transport";
    } else {
        double time = chosenTransport->commuteTime();
        std::cout << name << " is transporting via " << chosenTransport->getType() << " and the total time will be " << time << std::endl;
        std::cout << time << " minutes later...\n";
        disembark();
    }
}

/**
 * @brief Accepts a transport satisfaction checker visitor.
 * 
 * @param satisfactionChecker Pointer to the Visitor object for checking transport satisfaction.
 */
void Citizen::acceptTransportSatisfactionChecker(Visitor* satisfactionChecker) {
    satisfactionChecker->transportSatisfaction(this);
}

/**
 * @brief Accepts a building satisfaction checker visitor.
 * 
 * @param satisfactionChecker Pointer to the Visitor object for checking building satisfaction.
 */
void Citizen::acceptBuildingSatisfactionChecker(Visitor* satisfactionChecker) {
    satisfactionChecker->buildingSatisfaction(this);
}

/**
 * @brief Accepts a city satisfaction checker visitor.
 * 
 * @param satisfactionChecker Pointer to the Visitor object for checking city satisfaction.
 */
void Citizen::acceptCitySatisfactionChecker(Visitor* satisfactionChecker) {
    satisfactionChecker->citySatisfaction(this);
}

/**
 * @brief Deducts rent from the citizen's income.
 * 
 * @param rent Rent amount to be paid.
 */
void Citizen::payRent(double rent) {
    income -= rent;
}

/**
 * @brief Sets the total number of citizens.
 * 
 * @param num Total number of citizens.
 */
void Citizen::setNumCitizens(int num) {
    numCitizens = num;
}

/**
 * @brief Default constructor for Citizen class.
 */
Citizen::Citizen() {}

/**
 * @brief Gets the current tax rate.
 * 
 * @return Tax rate as a double.
 */
double Citizen::getTaxRate() {
    return taxRate;
}
