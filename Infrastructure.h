// Infrastructure.h
#ifndef INFRASTRUCTURE_H
#define INFRASTRUCTURE_H

#include "GrowthHandler.h"
#include <iostream>

class Infrastructure : public GrowthHandler {
private:
    int roads;
    int capacity;

public:
    Infrastructure(int roadsBuilt, int utilityCapacity);
    void handleRequest() override;
};

#endif // INFRASTRUCTURE_H
