/**
 * @file Element.cpp
 * @brief Defines the Element class, which provides a base for elements in a system that can accept visitors.
 */

#include "Element.h"

/**
 * @brief Accepts a visitor for processing this element.
 * 
 * This method is part of the Visitor pattern, allowing operations to be performed 
 * on an Element object without modifying its class. Currently, the method is not implemented.
 * 
 * @throws std::runtime_error Always throws "Not yet implemented" as a placeholder.
 */
void Element::accept() {
    // TODO - implement Element::accept
    throw "Not yet implemented";
}
