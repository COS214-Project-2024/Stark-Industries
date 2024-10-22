#ifndef TRANSPORT_H
#define TRANSPORT_H

class Transport {


public:
	virtual void transport() = 0;

	virtual void doMaintenance() = 0;

	virtual double commuteTime() = 0;

	virtual int citizenSatisfaction() = 0;
};

#endif
