#include <iostream>
#include "Citizen.h"
#include "CollectTax.h"
#include "Industrial.h"

void testCollectTax(){
    Citizen* citizen = new Citizen("Tony", 1000);
    Building* industrial = new Industrial();
    CollectTax* collectTax = new CollectTax(citizen, industrial);
    collectTax->execute();
}

int main() {
    testCollectTax();
}

