#ifndef TRANSPORTINFRASTRUCTUREFACTORY_H
#define TRANSPORTINFRASTRUCTUREFACTORY_H

#include "TransportInfrastructure.h"

class TransportInfrastructureFactory {
private:
    TransportInfrastructure* product;
public:
    void buildInfrastructure();
    virtual ~TransportInfrastructureFactory()= default;

protected:
	virtual TransportInfrastructure* createInfrastructure() = 0;
};

#endif
