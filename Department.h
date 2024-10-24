#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "Command.h"

#include <string>
#include <vector>

class Department {

private:
	std::string name;
	std::vector<Command*> commands;

public:
	Department(std::string departmentName);
	Department();

public:
	void operate();
	void add(Department* department);
	void remove(Department* department);
	Department* getChild(int index);
	void getName();
	void fundsReceived();

	//command functions for invoker
	virtual void execute() = 0;
	virtual void addCommand(Command* command) = 0;
	virtual void removeCommand(int i) =	0;

};

#endif
