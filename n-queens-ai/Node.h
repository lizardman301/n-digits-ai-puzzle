#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include "State.h"


class Node {
public:
    Node();
    Node(Node*,State,double cost, int, double);
    State getState() const;
    bool operator==(const Node&);
    bool operator<(const Node&);
    void print() const;
    void traceBack();
    double getDistance() const;
    double getPCost() const;
    double getUCost() const;
private:
    Node* parent;
    State name;   // the name is actually the "state"
    int search_type;
    double ucost;	// unit cost:  distance to parent
    double pcost;	// total path cost: distance to root
    double hcost;
    double handpcost;
};

#endif
