#ifndef TRANSPORTINFRASTRUCTUREFACTORY_H
#define TRANSPORTINFRASTRUCTUREFACTORY_H

#include "TransportInfrastructure.h"

class TransportInfrastructureFactory {
protected:
    TransportInfrastructure* product;
public:
    // void buildInfrastructure(){
    //     product = createInfrastructure();
    // }
    virtual ~TransportInfrastructureFactory()= default;

protected:
	virtual TransportInfrastructure* createInfrastructure(int, double) = 0;
    virtual TransportInfrastructure* createInfrastructure(int, bool) = 0;
    virtual TransportInfrastructure* createInfrastructure(double, double) = 0;
};

#endif
