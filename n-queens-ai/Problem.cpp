#include "Problem.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

//a lot of this code is based off previous projects
//not all of it is used

CityLink::CityLink(string left, string right, double dist) {
    // Fills in values
    a = left;
    b = right;
    cost = dist;
}

bool
CityLink::operator==(const CityLink& cl) const {
    // implement me
    string l, r;
    double c;
    string test = this->a;
    //fills the values with the function
    cl.getVals(l, r, c);

    if ((l == a) && (b == r) && (cost == c)) return true;
    else return false;
    
}

// just get the contents of a CityLink
void
CityLink::getVals(string& a,string& b,double& c) const {
    a = this->a;
    b = this->b;
    c = cost;
}

Problem::Problem() {}

bool
Problem::init(string fname) {
    //unused
    //used for previous problems involving importing a file
    return true;
}

// insert one link into cmap
bool
Problem::insert(CityLink cl) {
    //unused

    //pushes the city link into the vector
    cmap.push_back(cl);
    // implement me
    return true;
}

// find all candidates and put into list
CityList
Problem::findNeighbors(State cname) {
    CityList Neighborhood;
    
    return Neighborhood;
    
}

// for debugging
void
Problem::print() const {
    //Tried to do the iterator like in findNeighbors, but const causes too many problems
    //simple for loop to get this job done for now, will work on later

   // CityLinks::const_iterator cmi;

    cout << "List of all city links: " << endl;
    for (int i = 0; i<cmap.size(); i++) {
        string a, b;
        double c;
        cmap[i].getVals(a, b, c);
        cout << a << " " << b << " " << c << endl;
    }
    cout << endl;
    return;
}

int
Problem::lookup(State s) {
    //used to assign a heuristic score to each state
    //the lower the score the better
    //
    int value = 0;
    vector<int> v = s.getVector();
    int size = v.size();

    //checking to see if each digit has the right values
    //loop to check each digit and count everything else to see if it is there
    for (int i = 0; i < size; i++) {
        //check pos 0 
        int count = 0;
        for (int j = 0; j < size; j++) {
            //if the number you are currently searching for is present, increase count by 1
            if (v.at(j) == i) count++;
        }
        //if the count is accurate for the digit, value is 0. Otherwise value is increased by the difference between ideal and actual count
        value = value + abs(v.at(i) - count); 
    }
    
    return value;
}

Node*
Problem::findNextMove(Node* n) {
    vector<int> v = n->getState().getVector();

    vector<int>::iterator vit;

    for (vit = v.begin(); vit != v.end(); vit++) {
        int temp = *vit;
        for (int i = 0; i < 10; i++) {
            //replace point in array with new number and see if we get a better result
            *vit = i;

            State cur;
            cur.setState(v);
            cur.setSize(v.size());
            Node* next_move = new Node(nullptr, cur, 0,0, lookup(cur));

            //better move found, return it
            if (next_move->getDistance() < n->getDistance()) {
                return next_move;
            }
            delete next_move; //delete and try next one
        }
        *vit = temp; // return to original value
    }

    return n; //if no better move found, give n back
}

Node*
Problem::shuffle(Node* n) {
    vector<int>v = n->getState().getVector();
    random_shuffle(v.begin(), v.end());
    State temp;
    temp.setState(v);

    return new Node(nullptr, temp, 0, 0, lookup(temp));
}