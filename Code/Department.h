#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "Command.h"

#include <string>
#include <vector>
#include <vector>

class Department {

protected:
	//std::string name;
	std::vector<Command*> commands;

public:
	Department();
	Department(const std::string& departmentName);
	virtual ~Department() = default;
	virtual void operate() = 0;
	virtual void add(Department* department);
	virtual void remove(Department* department);
	virtual Department* getChild(int index);
	std::string getName() const;
	void fundsReceived();
	std::string name;
	//command functions for invoker
	virtual void execute() = 0;
	virtual void addCommand(Command* command) = 0;
	virtual void removeCommand(int i) =	0;
	virtual void receiveTax(double tax) {};
};

#endif
