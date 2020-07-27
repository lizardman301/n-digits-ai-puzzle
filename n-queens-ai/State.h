#ifndef STATE_H
#define STATE_H

#include <string>
#include <vector>

enum MoveType { None, Up, Left, Down, Right }; //UNUSED

class State {
public:
	State();
	void setState(int, int, int, int, int, int, int, int ,int);//overloading
	void setState(std::vector<int>);
	void setState(std::string);
	std::string getStringState() const;
	std::vector<int> getVector() const;
	void print();
	bool validState();
	bool operator==(const State&) const;
	bool operator<(const State&) const;
	void setMove(MoveType);
	void setSize(int);
	int getSize();
	std::string returnMove();
private:
	std::vector<int> s;
	MoveType cur_m; // usually used to record what move was done to get there OR what move is next (UNUSED)
	int n;
};

#endif