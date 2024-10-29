// Infrastructure.h
#ifndef INFRASTRUCTURE_H
#define INFRASTRUCTURE_H

#include "GrowthHandler.h"
#include <iostream>
using namespace std;

class Infrastructure : public GrowthHandler {
private:
    double growthRate;

public:
    Infrastructure(double growthRate);
    void handleRequest(int growthFactor);
};

#endif // INFRASTRUCTURE_H
