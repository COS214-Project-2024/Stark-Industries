// GrowthHandler.h
#ifndef GROWTHHANDLER_H
#define GROWTHHANDLER_H

class GrowthHandler {
protected:
    GrowthHandler* nextHandler;

public:
    GrowthHandler() : nextHandler(nullptr) {}
    virtual ~GrowthHandler() = default;

    virtual void setNextHandler(GrowthHandler* handler) {
        nextHandler = handler;
    }

    virtual void handleRequest() = 0;
};

#endif // GROWTHHANDLER_H
