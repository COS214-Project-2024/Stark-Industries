// GrowthHandler.h
#ifndef GROWTHHANDLER_H
#define GROWTHHANDLER_H

#include "City.h"

class GrowthHandler {
protected:
    GrowthHandler* nextHandler;

public:
    GrowthHandler();
    virtual ~GrowthHandler() = default;

    virtual void setNextHandler(GrowthHandler* handler);

    virtual void handleRequest(int growthFactor, City* city) = 0;
};

#endif // GROWTHHANDLER_H
