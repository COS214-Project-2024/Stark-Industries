#include "Department.h"
#include <iostream>

Department::Department(const std::string& departmentName)
    : name(departmentName) {}

Department::~Department() {}

void Department::operate() {
	// TODO - implement Department::operate
	throw "Not yet implemented";
}

void Department::add(Department* department) {
    std::cerr << "Add operation not supported by this department.\n";
}

void Department::remove(Department* department) {
	std::cerr << "Remove operation not supported by this department.\n";
}

Department* Department::getChild(int index) {
	std::cerr << "Get child operation not supported by this department.\n";
    return nullptr;
}

std::string Department::getName(){
	return name;
}

void Department::fundsReceived(double amount) {
	std::cout << "Department " << name << " received funds: " << amount << "\n";
}

void Department::displayInfo() const {
    std::cout << "Department Name: " << name << "\n";
}
