#include "GrowthHandler.h"
#include <iostream>
using namespace std;

GrowthHandler::GrowthHandler() : nextHandler(nullptr) {}

void GrowthHandler::setNextHandler(GrowthHandler* handler) {
    nextHandler = handler;
}

void GrowthHandler::handleRequest(int growthFactor) {
    if (nextHandler && growthFactor < 100 && growthFactor > 0) {
        nextHandler->handleRequest(growthFactor);
    } else if (nextHandler) {
        cout << "No handler available to process the request." << endl;
    }
}
