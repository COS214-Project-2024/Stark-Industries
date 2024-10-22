#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <string>

class Department {

private:
	std::string name;

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
};

#endif
