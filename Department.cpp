#include "Department.h"
#include <iostream>

Department::Department(const std::string& departmentName) : name(departmentName) {}


void Department::add(Department* department) {
	//Abstract class
}

void Department::remove(Department* department) {
	//Abstract class
}

Department* Department::getChild(int index) {
	return nullptr; //A leaf won't have children
}

std::string Department::getName() const{
	return name;
}

