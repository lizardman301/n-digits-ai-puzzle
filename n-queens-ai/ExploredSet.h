#ifndef EXPLOREDSET_H
#define EXPLOREDSET_H

#include "Node.h"
#include <map>

typedef std::map<std::string,int> ExploredNodes;

class ExploredSet {
public:
    ExploredSet();
    ~ExploredSet();
    bool check(Node* n);
    bool add(Node* n);
    void print() const;
private:
    ExploredNodes exset;
};

#endif
