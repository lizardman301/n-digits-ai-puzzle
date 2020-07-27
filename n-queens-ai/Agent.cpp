#include "Agent.h"
#include <iostream>

using namespace std;

Agent::Agent(){
	search_val = 0;
}

void
Agent::setFile(std::string f) {
	p.init(f);
}

void
Agent::setSearchType(int v){
	search_val = v;
}

void
Agent::setHeursticType(int v) {
	return;
}

void
Agent::setSearchVals(State a, State b) {
	init = a;
	dest = b;
}

Node*
Agent::search() {
	//only one approach so don't check for search_val
	//same approach as n queens puzzle solve
	Node* n1 = new Node(nullptr, init, 0, 0, p.lookup(init));
	Node* next_move;
	int plat_check = 0;
	while (true) {
		//hill climbing approach
		if (plat_check >= 2) {
			//probably at plat, randomize and try again
			n1 = p.shuffle(n1); //shuffles
			plat_check = 0;
		}

		//get shallowest node
		next_move = p.findNextMove(n1);
		//next_move->print();

		if (next_move->getDistance() < n1->getDistance()) {
			if (next_move->getDistance() == 0) {//no conflicts, done
				return next_move;
			}
			//replace n1 with best neighbor found
			n1 = next_move;
		}
		else {
			plat_check++;
		}
		//check for list and add to frontier if not in frontier or explored
		
	}
}
