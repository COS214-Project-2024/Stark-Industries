#include "Population.h"
#include "Housing.h"
#include "Economic.h"
#include "Infrastructure.h"
#include <iostream>

void testCOR() {
    // Create handlers with test values
    int growthFactor = 101;
    Population populationHandler(growthFactor);
    Housing housingHandler(growthFactor * 0.5);
    Economic economicHandler(growthFactor * 0.75);
    Infrastructure infrastructureHandler(growthFactor * 0.3);

    // Set up the chain of responsibility
    populationHandler.setNextHandler(&housingHandler);
    housingHandler.setNextHandler(&economicHandler);
    economicHandler.setNextHandler(&infrastructureHandler);

    // Test the chain with a growth factor
    populationHandler.handleRequest(growthFactor);
}

int main ()
{
  testCOR();

  return 0;
}