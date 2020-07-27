//Joshua Steinberg

/*
Original puzzle question
Find a 10-digit number where the first digit is how many zeros in the number, 
the second digit is how many 1s in the number etc. until the tenth digit which is how many 9s in the number.

This has been expanded so one can test for many different n-digit numbers. Only some solutions exist in the end
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Node.h"
#include "Agent.h"
#include "Problem.h"
#include "State.h"

using namespace std;


int main(int argc, char* argv[]) {
	int n;
	cout << "Find a number of N digits where the first digit is the number of 0s in the entire number," << endl << "the second digit the number of 1s, and so on for the rest of the digits." << endl;
	cout << "Solution is only possible for N=5,7,8,9, or 10." << endl;
	cout << "Please enter a value for N:";
	cin >> n;
	if (n == 6 || n < 5 || n > 10) {
		// Gives a warning for the numbers that will have no solution.
		int junk;
		cout << "WARNING: Solution will not be found OR solution will not be valid (can't have two digits in a one digit spot)" << endl;
		cout << "Enter any value to continue the search regardless." << endl;
		cin >> junk;
	}
	
	//initalize problem
	Agent a;
	
	//This is solved heuristically so we don't know the destination before hand
	State init;
	State dest;

	//init is set to a vector of 0s equal to n
	init.setSize(n);
	vector<int> vector_for_init;
	for (int i = 0; i < n; i++) {
		vector_for_init.push_back(0);
	}
	init.setSize(n);
	init.setState(vector_for_init);

	a.setSearchVals(init, dest);


	//if there is a solution, it will return. otherwise search will continue forever
	Node* temp = a.search();
	cout << "Solution found!" << endl;
	temp->print();

	return 0;
}

