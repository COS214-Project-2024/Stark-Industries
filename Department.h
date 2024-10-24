#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <string>
#include <vector>

class Department {

private:
	std::string name;

public:
	Department(const std::string& departmentName);	
	virtual ~Department();
	virtual void operate() = 0;
	virtual void add(Department* department);
	virtual void remove(Department* department);
	virtual Department* getChild(int index);
	std::string getName();
	virtual void fundsReceived(double amount);
	virtual void displayInfo() const;
};

#endif
