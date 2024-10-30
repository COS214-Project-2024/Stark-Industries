#include "Government.h"

Government::Government() : Department() {

}

void Government::increaseTax(int amount) {
	// TODO - implement Government::increaseTax
	throw "Not yet implemented";
}

void Government::allocateTax() {
	for (int i = 0; i < departments.size(); i++) {
		if (departments[i]->name == "Budget"){
			departments[i]->receiveTax(taxCollected);
			break;
		}
	}
}

void Government::collectTax() {
	taxCollected = visitor->taxCollected;
}

void Government::get() {
	// TODO - implement Government::get
	throw "Not yet implemented";
}

void Government::set() {
	// TODO - implement Government::set
	throw "Not yet implemented";
}

Government* Government::getState() {
	// TODO - implement Government::getState
	throw "Not yet implemented";
}

void Government::setState() {
	// TODO - implement Government::setState
	throw "Not yet implemented";
}

void Government::add(Department* department) {
	// TODO - implement Government::add
	throw "Not yet implemented";
}

void Government::remove(Department* department) {
	// TODO - implement Government::remove
	throw "Not yet implemented";
}

Department* Government::getChild(int index) {
	// TODO - implement Government::getChild
	throw "Not yet implemented";
}

void Government::operate() {
	// TODO - implement Government::operate
	throw "Not yet implemented";
}

void Government::notifyCitizensTaxIncreased() {
	// TODO - implement Government::notifyCitizensTaxIncreased
	throw "Not yet implemented";
}
