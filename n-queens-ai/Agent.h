#ifndef AGENT_H
#define AGENT_H

#include "Node.h"
#include "Problem.h"
#include "PriorityQueue.h"
#include "State.h"

class Agent {
public:
	Agent();
	void setFile(std::string);
	void setSearchType(int);
	void setHeursticType(int);
	void setSearchVals(State, State);
	Node* search();
private:
	Problem p;
	PriorityQueue pq;
	int search_val;
	State init;
	State dest;
};

#endif