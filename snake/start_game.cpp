
#include<ctime>
//#include<conio.h>
#include<sys/select.h>
#include "snake.hpp"
using namespace std;
//fd_set readfds;
//char c;

void print_all(vector<vector<char>>&);
void print_game_over(Snake&);
void delay(int time){
    // FD_ZERO(&readfds);
    // FD_SET(0,&readfds);
    clock_t now=clock();
    while(clock()-now<time){
        // if (_kbhit()) {
		// 	c = _getch();
		// }
        /*int count=select(0,&readfds,nullptr,nullptr,nullptr);
        if(count>0){
            if(FD_ISSET(0,&readfds)){
                c=getchar();
                continue;
            }
        }*/
    }
}

int main() {
	Snake snake;
	auto beg = snake.gethead();
	auto end = snake.gettail();
	Food food;
	while (snake.size() < max_size&&snake.live()) {
		vvc[beg.first][beg.second] = body_smb;
		//system("cls");//windows
        system("printf \"\\033c\"");
		while (vvc[food.x][food.y] == body_smb || food.eated())
			food.reset();
		vvc[food.x][food.y] = food_smb;
		print_all(vvc);
		delay(1000);
		snake.eat(food);
		beg = snake.gethead();
		if (end != snake.gettail()) {
			vvc[end.first][end.second] = ' ';
			end = snake.gettail();
		}
	}
    print_game_over(snake);
	return 0;
}