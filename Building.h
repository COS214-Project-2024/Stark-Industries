#ifndef BUILDING_H
#define BUILDING_H

#include "Element.h"
#include "Utilities.h"
#include "Citizen.h"
#include "Visitor.h"
#include <string>
#include <vector>

class SatisfactionChecker;
using namespace std;

class Building : public Element {

protected:
    vector<Utilities*> utilities;

private:
    string name;
    int satisfaction;
    double economicImpact;
    double resourceConsumption;
    bool constructionStatus;
    int improvementLevel;
    bool resourcesAvailable;
    int capacity;
    string area;

protected:
    double buildingRevenue;
    double buildingValue;

public:
    Building(string name, int satisfaction, double economicImpact, double resourceConsumption, 
             bool constructionStatus, int improvementLevel, bool resourcesAvailable, 
             int capacity, string area);

    Building();
    virtual ~Building() = default;
    void get();

    virtual string getType() = 0;
    virtual int calculateSatisfaction() = 0;
    virtual double calculateEconomicImpact() = 0;
    virtual double calculateResourceConsumption() = 0;
    virtual bool constructionComplete() = 0;
    virtual void doImprovements() = 0;

    void attach(Citizen* observer);
    void detach(Citizen* observer);
    virtual void notifyCitizens() = 0;

    virtual Building* clone() const = 0;
    virtual void performAction(int type) = 0;
    virtual void payTax(float taxRate) = 0;
    double taxPaid;
    virtual void acceptTaxCollector(Visitor * taxCollector) = 0;
    virtual void acceptCitySatisfactionChecker(Visitor* satisfactionChecker) {};
    int citySatisfaction = 80;

    virtual void collectRent() {}; 
    double rent;
    virtual void setRentalRate(double newRent);
    virtual double getRent();
    virtual bool populateBuilding() = 0;
    virtual void setBuildingValue(double value);
    virtual void generateRevenue(){};

    virtual void addUtility(Utilities* utility);
    virtual std::string getBuildingType() = 0;

    std::vector<Citizen*> observerList;
};

#endif // BUILDING_H