#include "ExploredSet.h"

ExploredSet::ExploredSet() {

}

ExploredSet::~ExploredSet() {

}

bool
ExploredSet::check(Node* n) {
	std::string value = n->getState().getStringState();
	//if the key exists, return true
	if (exset.count(value) == 1) return true;
	return false;
}

bool
ExploredSet::add(Node* n) {
	//no idea what the int is for to be frank
	exset.insert(std::pair<std::string, int>(n->getState().getStringState(), 1));
	return true;
}

void 
ExploredSet::print() const {

	ExploredNodes::const_iterator it = exset.begin();
	while (it != exset.end()) {
		std::cout << "(" << "name" << ", " << "name" << ")" << std::endl;
		it++;

	}
}