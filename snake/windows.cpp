#include "snake.hpp"
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
using std::string;

std::default_random_engine dre;
std::uniform_int_distribution<int> di(0, 4);
vector<vector<char>> vvc
    (width - 2, vector<char>(width - 2, ' '));

void print(vector<char>& vc) {
	cout << wall_smb;
	for (auto p = vc.begin(); p != vc.end(); ++p) {
		cout << ' ' << *p;
	}
	cout<< ' '<< wall_smb << endl;
}

void print_all(vector<vector<char>>& vvc) {
	cout << string(2 * width - 1, wall_smb) << endl;
	for (int i = 0; i < (width - 2); ++i)
		print(vvc[i]);
	cout << string(2 * width - 1, wall_smb) << endl;
}

void print_game_over(Snake& snake){
    if(snake.live())
        cout<<"you are the winner"<<endl;
    else
        cout << "your grade is " << snake.size() - 1 << endl;
    
}