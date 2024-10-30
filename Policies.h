#ifndef POLICIES_H
#define POLICIES_H

#include "Department.h"
#include <string>
using namespace std;

class Policies : public Department {


public:
	Policies(std::string name);
	std::string name = "Policies";

	void operate();

	void addPolicy(std::string policy);

	void removePolicy(std::string policy);
};

#endif
