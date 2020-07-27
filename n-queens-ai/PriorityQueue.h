#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include <string>
#include <set>

#include "Node.h"


// we will order the queue based on State score.  The score is a crude
// estimate how far we are from the start, so we sort from low to high
class InsertCompare {
public:
    bool operator()(const Node* lhs, const Node* rhs) const {
        return lhs->getDistance() < rhs->getDistance();
    }
};

typedef std::multiset<Node*,InsertCompare> PriorityQ; 

class PriorityQueue {
public:
    PriorityQueue();
    ~PriorityQueue();
    void add(Node*);
    bool isInPQ(State);
    Node* pop();
    bool remove(Node*);
    bool isEmpty();
    void print() const;
private:
    PriorityQ pq;
};

#endif
