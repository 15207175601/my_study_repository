#ifndef __SNAKE
#define __SNAKE
#include<deque>
#include "food.hpp"

const int width = 7;
const int max_size = (width - 2) * (width - 2);
const char wall_smb = '#';
const char body_smb = '*';
const char food_smb = 'o';
const int birth = (width / 2) - 1;

extern std::vector<std::vector<char>> vvc;

enum Status {
	up, down, left, right
};

class Snake {
private:
	std::deque<std::pair<int, int>> body;
	Status stat = Status::up;
	bool alive = true;
public:
	Snake() :body({ std::pair<int, int>(birth, birth) }) {}

	size_t getstatus()  const {return stat;}
	std::pair<int, int> gethead()const { return body.front(); }
	std::pair<int, int> gettail()const {return body.back();}
	bool live() const { return alive; }
	size_t size() const { return body.size(); }

	void setstatus(char c);

	std::pair<int, int> next() const;
	bool check(std::pair<int,int>& p) const;

	void eat(Food& food);
};

#endif //__SNAKE