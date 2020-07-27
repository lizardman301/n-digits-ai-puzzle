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
    Node* parent; // used in tree based searches
    State name;   
    int search_type; // if we had multiple search types, it would use this to determine which one to do
    double ucost;	// unit cost:  distance to parent UNUSED
    double pcost;	// total path cost: distance to root
    double hcost;
    double handpcost;
};

#endif
