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

	//command function for invoker
	void execute();
	void addCommand(Command* command);
	void removeCommand(int i);
	//command function for receiver
	virtual void performAction() = 0;

};

#endif
