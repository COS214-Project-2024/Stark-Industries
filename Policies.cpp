#include "Policies.h"
#include <iostream>
#include <algorithm>

Policies::Policies(const std::string& name) : Department(name) {}

void Policies::operate() {
    std::cout << "Operating Policies Department: Active Policies:\n";
    for (const auto& policy : activePolicies) {
        std::cout << "- " << policy << "\n";
    }
}

void Policies::addPolicy(const std::string& policy) {
    activePolicies.push_back(policy);
    std::cout << "Policy added: " << policy << "\n";
}

void Policies::removePolicy(const std::string& policy) {
    auto it = std::remove(activePolicies.begin(), activePolicies.end(), policy);
    if (it != activePolicies.end()) {
        activePolicies.erase(it, activePolicies.end());
        std::cout << "Policy removed: " << policy << "\n";
    } else {
        std::cout << "Policy not found: " << policy << "\n";
    }
}
