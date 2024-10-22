#ifndef GROWTHHANDLER_H
#define GROWTHHANDLER_H

class GrowthHandler {

private:
	GrowthHandler* nextHandler;

public:
	GrowthHandler(int jobs, double growthRate);

	GrowthHandler(int, int);

	GrowthHandler(int rate);

	void setNextHandler(GrowthHandler* handler);

	void handleRequest();
};

#endif
