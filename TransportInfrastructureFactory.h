#ifndef TRANSPORTINFRASTRUCTUREFACTORY_H
#define TRANSPORTINFRASTRUCTUREFACTORY_H

#include "TransportInfrastructure.h"

class TransportInfrastructureFactory {
private:
    TransportInfrastructure* product;
public:
    void buildInfrastructure(){
        product = createInfrastructure();
    }
    virtual ~TransportInfrastructureFactory()= default;

protected:
	virtual TransportInfrastructure* createInfrastructure() = 0;
};

#endif
