#include "PriorityQueue.h"
#include <stack>
#include <cmath>
#include <limits>

using namespace std;

bool gDebug = false;

/* this is a helper class for the Priority Queue for use in find_if */
class findWorse {
public:
    findWorse(const Node* n) : node(n) { }
    bool operator()(Node *n) const {
    return (node->getState() == n->getState() &&
        node->getDistance() < n->getDistance());
    }
private:
    const Node* node;
};

/* helper class for matching states. For some problems, states will be
   non-atomic objects (not strings) */
class findState {
public:
    findState(const State n) : state(n) { }
    bool operator()(Node *n) const {
        return n->getState() == state;
    }
private:
    const State state;
};
/********************************   PriorityQueue   ******************************/

PriorityQueue::PriorityQueue() {}

// delete memory for nodes remaining in priority queue
PriorityQueue::~PriorityQueue() { 
    return;
    int i = 0;
    PriorityQ::iterator pqi; 
    for (pqi=pq.begin();pqi!=pq.end();pqi++) {
        delete *pqi;
    }
}

void 
PriorityQueue::add(Node* n) {
    pq.insert(n);
}

// search for a node in the queue with the same state as n.  If it has a worse
// score than n, then delete it from the queue and return true.   If the node
// in the queue is better than this node, do nothing an return false.
// so the way you'd use this is like this:
//  Node* newnode(...);
//  if (pq.remove(newnode)) pq.add(newnode);
//  else delete(newnode);

bool 
PriorityQueue::remove(Node* n) {
    PriorityQ::iterator pqi;
    pqi = find_if(pq.begin(),pq.end(),findWorse(n));
    if (pqi != pq.end()) {
        if (gDebug) {
            cout << "Found one, removing it: ";
            (*pqi)->print(); cout << endl;  // calls Node::print()
        }
        delete(*pqi);    // so no memory leak
        pq.erase(pqi);   // deletes it from the priority queue
        return true;
    }
    return false;
}

bool
PriorityQueue::isInPQ(State s) {
    PriorityQ::iterator pqi;
    return find_if(pq.begin(),pq.end(),findState(s)) != pq.end();
}


Node*
PriorityQueue::pop() {
    Node* ret = NULL;
    if (!pq.empty()) {
        ret = *pq.begin();
        pq.erase(pq.begin());
    }
    return ret;
}

void
PriorityQueue::print() const {
    PriorityQ::iterator pqi;
    cout << "<PQ>";
    for (pqi=pq.begin(); pqi!=pq.end(); pqi++) {
        (*pqi)->print();
    }
    cout << "</PQ>\n";
}

bool
PriorityQueue::isEmpty() {
    return pq.empty();
}