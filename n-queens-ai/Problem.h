#ifndef PROBLEM_H
#define PROBLEM_H

#include <vector>
#include <string>
#include "State.h"
#include "Node.h"


struct Neighbor {
    State name;
    double dist=0;
};

class CityLink;
typedef std::vector<Neighbor> CityList;
typedef std::vector<CityLink> CityLinks;

/*
   This contains a list of city pairs with the distance between them.
   To keep things simple (at the cost of some memory) all pairs are entered
   twice, forward and backward.   This also allows asymmetrical distances, 
   so it would be possible for Arad to Sibiu to be 100 KM and Sibiu to Arad
   to be 90 KM.   This may actually be useful.
*/
class CityLink {
public:
    CityLink(std::string,std::string,double);
    bool operator==(const CityLink&) const;
    void getVals(std::string&,std::string&,double&) const;  // get values
private:
    std::string a;
    std::string b;
    double cost;
};

class Problem {
public:
    Problem();
    bool init(std::string initfile);    //textfile with city pairs and dist 
    bool insert(CityLink);
    CityList findNeighbors(State);  
    Node* findNextMove(Node* n);
    Node* shuffle(Node*);
    int lookup(State);
    void print() const;
private:
    CityLinks cmap;
};

#endif
