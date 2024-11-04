#include "GrowthHandler.h"
#include <iostream>
using namespace std;

GrowthHandler::GrowthHandler() : nextHandler(nullptr) {}

void GrowthHandler::setNextHandler(GrowthHandler* handler) {
    nextHandler = handler;
}

void GrowthHandler::handleRequest(int growthFactor, City* city) {
    if (nextHandler && growthFactor < 101 && growthFactor > 0) {
        nextHandler->handleRequest(growthFactor, city);
    } else if (nextHandler) {
        cout << "No handler available to process the request." << endl;
    }
}


