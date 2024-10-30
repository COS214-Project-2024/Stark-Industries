#include "Department.h"
#include <iostream>

/**
 * @brief Constructs a Department with the given name.
 * 
 * @param departmentName Name of the department.
 */
Department::Department(const std::string& departmentName) : name(departmentName) {}

/**
 * @brief Adds a child department to this department.
 * 
 * This function is part of the Composite pattern. 
 * Since this is a leaf department, the function does nothing.
 * 
 * @param department Pointer to the department to be added as a child.
 */
void Department::add(Department* department) {
    // Abstract class: Implementation will be in the composite class.
}

/**
 * @brief Removes a child department from this department.
 * 
 * This function is part of the Composite pattern. 
 * Since this is a leaf department, the function does nothing.
 * 
 * @param department Pointer to the department to be removed.
 */
void Department::remove(Department* department) {
    // Abstract class: Implementation will be in the composite class.
}

/**
 * @brief Gets a child department at the specified index.
 * 
 * Since leaf departments do not have children, this function returns nullptr.
 * 
 * @param index The index of the child department.
 * @return Always returns nullptr for a leaf department.
 */
Department* Department::getChild(int index) {
    return nullptr;  // A leaf department doesn't have children.
}

/**
 * @brief Gets the name of the department.
 * 
 * @return A string representing the name of the department.
 */
std::string Department::getName() const {
    return name;
}
