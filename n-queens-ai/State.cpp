#include "State.h"
#include <iostream>

// a lot of the functions here were left over from earlier projects in the semseter
// as such not all will be used for solving this problem

State::State(){
	cur_m = None;
}

void
State::setState(int a, int b, int c, int d, int e, int f, int g, int h, int i) {
	s.push_back(a); s.push_back(b); s.push_back(c);
	s.push_back(d); s.push_back(e); s.push_back(f);
	s.push_back(g); s.push_back(h); s.push_back(i);
}

void
State::setState(std::vector<int> board) {
	//copies over values of vector using assign
	s.assign(board.begin(), board.end());
}

void 
State::setState(std::string st) {
	//loops through the first 9 and pushes back
	//converts char to int by subtracting '0'
	std::vector<int> temp;
	for (int i = 0; i < st.size(); i++) {
		temp.push_back(st.at(i) - '0');
	}
	s.assign(temp.begin(), temp.end());
}

std::string
State::getStringState() const{
	std::string temp;
	for (int i = 0; i < n; i++) {
		temp += (s[i] + '0');
	}
	return temp;
}

std::vector<int>
State::getVector() const {
	return s;
}

void
State::print() {
	for (int i = 0; i < 9; i++) {
		std::cout << s[i];
	}
	std::cout << std::endl;
}

bool
State::validState() {
	int lm = s[1] - '0'; //ez convert to int
	int lc = s[2] - '0';
	int rm = s[3] - '0';
	int rc = s[4] - '0';

	//greater than means the canibals can overpower the missionaries and thats no good
	if (lm != 0 && lc > lm) return false;
	if (rm != 0 && rc > rm) return false;

	return true;
}

bool State::operator==(const State& st) const{
	if (st.getVector() == this->getVector()) return true;
	return false;
}

bool
State::operator<(const State& st) const {
	return this->getStringState() < st.getStringState();
}

void
State::setMove(MoveType m) {
	cur_m = m;
}

std::string
State::returnMove() {
    std::string temp;
    switch (cur_m) {
    case None:
        temp = "None";
        break;
	case Up:
        temp = "Up";
        break;
    case Left:
        temp = "Left";
        break;
    case Down:
        temp = "Down";
        break;
    case Right:
        temp = "Right";
        break;
	default:
		temp = "STRT";
		break;
    }
	return temp;
}

void
State::setSize(int size) {
	n = size;
}

int
State::getSize() {
	return n;
}