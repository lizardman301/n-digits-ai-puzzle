#include "Node.h"
#include <iostream>
#include <string>
#include <vector>

Node::Node() {
	parent = NULL;
	handpcost = 0;
	hcost = 0;
	ucost = 0;
	pcost = 0;
	search_type = 0;
}

Node::Node(Node* p, State s, double c, int st, double hc) {
	parent = p;
	name = s;
	ucost = c;
	if (parent != NULL) {
		pcost = parent->pcost + ucost; //pcost = previous p cost + ucost
	}
	else {
		pcost = 0;
	}
	search_type = st;
	hcost = hc;
	handpcost = hcost + pcost;
}

State 
Node::getState() const{
	return name;
}

bool 
Node::operator==(const Node& n){
	return this->name == n.name;
}

bool
Node::operator<(const Node& n) {//checks pcost
	return this->getDistance() < n.getDistance();
}

void
Node::print() const {
	std::vector<int> v = name.getVector();
	std::vector<int>::iterator vit;
	for (vit = v.begin(); vit != v.end(); vit++) {
		std::cout << *vit;
	}
	std::cout << std::endl;
}

void
Node::traceBack() {
	//goes back into time while temp does not equal NULL
	//used if you need to trace a path if you are using a tree of nodes
	std::vector<std::string> output;
	std::string start = std::to_string(int(this->getPCost())) + " " + name.getStringState() + " " + name.returnMove();
	output.push_back(start);
	Node* temp = parent;
	while (temp) {
		start = std::to_string(int(temp->getPCost())) + " " + temp->getState().getStringState() + " " + temp->getState().returnMove();
		//inserts at the beginning of the vector
		output.insert(output.begin(),start);
		temp = temp->parent;
	}

	//outputs everything in order
	for (int i = 0; i < output.size(); i++) {
		std::cout << output[i] << std::endl;
	}
}

double
Node::getPCost() const{
	return pcost;
}

double
Node::getUCost() const {
	return ucost;
}

double
Node::getDistance() const{
		return hcost;
}