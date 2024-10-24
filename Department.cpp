#include "Department.h"

Department::Department(std::string departmentName) {
	// TODO - implement Department::Department
	throw "Not yet implemented";
}

Department::Department() {
	// TODO - implement Department::Department
}

void Department::operate() {
	// TODO - implement Department::operate
	throw "Not yet implemented";
}

void Department::add(Department* department) {
	// TODO - implement Department::add
	throw "Not yet implemented";
}

void Department::remove(Department* department) {
	// TODO - implement Department::remove
	throw "Not yet implemented";
}

Department* Department::getChild(int index) {
	// TODO - implement Department::getChild
	throw "Not yet implemented";
}

void Department::getName() {
	// TODO - implement Department::getName
	throw "Not yet implemented";
}

void Department::fundsReceived() {
	// TODO - implement Department::fundsReceived
	throw "Not yet implemented";
}

//command functions
void Department::execute() {
	for (int i = 0; i < commands.size(); i++) {
        commands[i]->execute();
    }
}

void Department::addCommand(Command* command) {
	commands.push_back(command);
}

void Department::removeCommand(int i) {
	commands.erase(commands.begin() + i);
}

