#include "snake.hpp"

std::pair<int, int> Snake::next() const {
	auto temp = gethead();
	switch (getstatus()) {
	case Status::up:
		return{ temp.first,temp.second-1 };
	case Status::down:
		return{ temp.first,temp.second + 1 };
	case Status::right:
		return{ temp.first+1,temp.second };
	case Status::left:
		return{ temp.first - 1,temp.second };
	default:
		return temp;
	}
}
bool Snake::check(std::pair<int,int>& p) const{
	if (p.first < 0 || p.first > 4 || p.second < 0 || p.second>4 ||
		vvc[p.first][p.second] == body_smb)
		return false;
	return true;
}

void Snake::eat(Food& food) {
	auto temp = next();
	if (check(temp)) {
		body.push_front(temp);
		if (temp.first == food.x && temp.second == food.y)
			food.flag = false;
		else 
			body.pop_back();
	}
	else {
		alive = false;
		return;
	}
}

void Snake::setstatus(char c){
	switch (c)
	{
	case 72:
		this->stat=Status::up;
		break;
	case 80:
		this->stat=Status::down;
		break;
	case 75:
		this->stat=Status::left;
		break;
	case 77:
		this->stat=Status::right;
		break;
	default:
		break;
	}
}