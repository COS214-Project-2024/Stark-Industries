#ifndef POLICIES_H
#define POLICIES_H

#include "Department.h"
#include <string>
using namespace std;

class Policies : public Department {

private:
    std::vector<std::string> activePolicies;

public:
	Policies(const std::string& name);
	void operate() override;
	void addPolicy(const std::string& policy);
	void removePolicy(const std::string& policy);
};

#endif
