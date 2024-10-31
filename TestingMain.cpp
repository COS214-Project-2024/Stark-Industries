#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "CollectTax.h"
#include "Citizen.h"
#include "Industrial.h"

#include "Government.h"  
#include "Tax.h"
#include "Budget.h"
#include "Policies.h"
#include "Services.h"

TEST_CASE("Citizen Collect Tax"){
    Citizen* citizen = new Citizen("Tony", 1000);
    Industrial * industrial = new Industrial();
    CollectTax* ct = new CollectTax(citizen, industrial);
    ct->execute();
    //REQUIRE(ct->execute() == "Property Tax collected from Industrial Building\nProperty Tax of: 0 collected\nIncome Tax collected from citizens\nTime to collect Income Tax from citizens\nTax paid: 150");
}


//Testing Composite
TEST_CASE("Government operates all departments") {
    Government cityGovernment(0.15, 0.05);

    // Creating departments
    Tax taxDept("Tax Department", 15.0f);
    Budget budgetDept("Budget Department", 10000.0);
    Policies policiesDept("Policies Department");
    Services servicesDept("Public Services", 5, 10, 3);

    // Adding policies and service programs
    policiesDept.addPolicy("Environmental Protection");
    policiesDept.addPolicy("Healthcare Reform");
    servicesDept.addServiceProgram("Free Education Initiative");
    servicesDept.addServiceProgram("Healthcare for All");

    // Adding departments to the Government composite
    cityGovernment.add(&taxDept);
    cityGovernment.add(&budgetDept);
    cityGovernment.add(&policiesDept);
    cityGovernment.add(&servicesDept);

    // Operating government
    cityGovernment.operate();
    REQUIRE(cityGovernment.getChild(0) == &taxDept);  // Verify child exists
}

TEST_CASE("Adding and Removing Departments in Government") {
    Government cityGovernment(0.15, 0.05);

    Tax taxDept("Tax Department", 15.0f);
    Budget budgetDept("Budget Department", 10000.0);

    cityGovernment.add(&taxDept);
    REQUIRE(cityGovernment.getChild(0) == &taxDept);

    cityGovernment.add(&budgetDept);
    REQUIRE(cityGovernment.getChild(1) == &budgetDept);

    // Removing tax department
    cityGovernment.remove(&taxDept);
    REQUIRE(cityGovernment.getChild(0) == &budgetDept);
}

TEST_CASE("Policies and Services operate correctly") {
    Policies policiesDept("Policies Department");
    Services servicesDept("Public Services", 5, 10, 3);

    policiesDept.addPolicy("Environmental Protection");
    REQUIRE(policiesDept.getName() == "Policies Department");

    servicesDept.addServiceProgram("Free Education Initiative");
    REQUIRE(servicesDept.getName() == "Public Services");

    policiesDept.operate();
    servicesDept.operate();
}

TEST_CASE("Tax department sets and tracks revenue correctly") {
    Tax taxDept("Tax Department", 10.0f);
    taxDept.setTaxRate(0.2f);
    REQUIRE(taxDept.getTaxRate() == 0.2f);

    taxDept.trackRevenue(1000.0);
    REQUIRE(taxDept.getTaxRate() == 0.2f);
}
