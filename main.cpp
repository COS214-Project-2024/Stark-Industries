#include "Population.h"
#include "Housing.h"
#include "Economic.h"
#include "Infrastructure.h"
#include <iostream>

int main() {
      // Create handlers with test values
    Population populationHandler(5);        // 5% population growth rate
    Housing housingHandler(1000,8989);           // Demand for 1000 housing units
    Economic economicHandler(500,9979);          // 500 job opportunities
    Infrastructure infrastructureHandler(10, 200); // 10 roads and capacity of 200

    // Set up the chain of responsibility
    populationHandler.setNextHandler(&housingHandler);
    housingHandler.setNextHandler(&economicHandler);
    economicHandler.setNextHandler(&infrastructureHandler);

    // Test each handler separately by triggering requests
    std::cout << "Testing Population Growth Handler:\n";
    populationHandler.handleRequest();

    std::cout << "\nTesting Housing Growth Handler:\n";
    housingHandler.handleRequest();

    std::cout << "\nTesting Economic Growth Handler:\n";
    economicHandler.handleRequest();

    std::cout << "\nTesting Infrastructure Growth Handler:\n";
    infrastructureHandler.handleRequest();

    // Test passing requests through the chain
    std::cout << "\nTesting Chain of Responsibility:\n";
    populationHandler.handleRequest(); // This should propagate through all handlers if not handled

    // Test handling an unhandled request
    std::cout << "\nTesting Unhandled Request:\n";
    Infrastructure unhandledHandler(0, 0); // No roads or capacity
    unhandledHandler.setNextHandler(nullptr); // End of chain
    unhandledHandler.handleRequest(); // Should indicate no handler available
}