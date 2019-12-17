/*#include <vector>
#include <cmath>
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include<algorithm>
#include "graphics.h"      // 引用图形库头文件
#include <conio.h>
using namespace std;
const int num = 200;
//double T0 = 18000;
//double T0 = 1e-4;
//double T0 = 1e-7;
double T0 = 1e-3;
double T1 = 1e-9;
//double T0 = 100;
//double T0 = 100000;
//double T1 = 1;
double r = 0.98;
int len = 1000;
double mp[num + 3][num + 3];
struct node {
	double x, y;
}point[num + 3];
double dis(int u, int v) {
	double x = point[u].x - point[v].x;
	double y = point[u].y - point[v].y;
	return sqrt(x*x + y * y);
}
void init_map() {//初始化边的情况
	for (int i = 0; i < num; ++i) {
		//scanf_s("%lf%lf", &point[i].x, &point[i].y);
		//srand(time(0));
		//point[i].x = rand()%200;
		//srand(i);
		//point[i].y = rand()%200;
		static int j = 1;
		srand(i*i + j);
		point[i].x = rand() % 1000;
		j++;
		srand(i + 3*j*j);
		point[i].y = rand() % 1000;
		j = j + i;
		if(i%2==0)
			printf("point[%d]:	x = %.2lf;	y = %.2lf\t", i, point[i].x, point[i].y);
		else
			printf("point[%d]:	x = %.2lf;	y = %.2lf\n", i, point[i].x, point[i].y);
		putpixel(point[i].x, point[i].y, RED);
	}
	for (int i = 0; i < num; ++i) {
		for (int j = 0; j < num; ++j) {
			mp[i][j] = dis(i, j);
		}
	}
}
double cal_distance(vector<int>x) {//计算染色体的距离
	double res = mp[x[0]][x[num - 1]];
	for (int i = 0; i < num - 1; ++i)
		res += mp[x[i]][x[i + 1]];
	return res;
}
void change(vector<int>&v) {
	int x = rand() % num;
	int y = rand() % num;
	while (y == x) y = rand() % num;
	for (int i = 0; i + x <= (x + y >> 1); ++i)
		swap(v[i + x], v[y - i]);
	//printf("times.");
}
int main() {
	//freopen("a.txt", "r", stdin);
	//reopen("3.txt", "w", stdout);
	srand(time(0));
	vector<int>ans;
	initgraph(1000, 1000);	 // 创建绘图窗口，大小为 640x480 像素
	init_map();
//	printpoint();
	int icount = 0, cnt = 0;
	//int icount = 0;
	for (int i = 0; i < num; ++i) ans.push_back(i);
	random_shuffle(ans.begin(), ans.end());
	while (T0 > T1) {
		for (int i = 0; i < len; ++i) {
			vector<int>tmp = ans;
			change(tmp);
			double pre = cal_distance(ans);//前
			double cur = cal_distance(tmp);//后
			if (cur < pre || exp(-(cur - pre) / T0) >((double)rand()) / RAND_MAX) {
				ans = tmp;
			}
		}
		++icount;
		T0 *= r;
	}
	//printf("run %d %d times\n", icount, cnt);
	printf("run %d times\n", icount);
	printf("distance = %f\n", cal_distance(ans));
	for (int i : ans) 
	{
		static int count = 0;
		static int temp = i;
		if (count == 0)
			cnt = i;
		if (count > 0)
			line(point[temp].x, point[temp].y, point[i].x, point[i].y);
		printf("%d ", i);
		count++;
		temp = i;
	}
	line(point[ans[0]].x, point[ans[0]].y, point[ans[num-1]].x, point[ans[num - 1]].y);
	printf("%d", ans[0]);
	_getch();              // 按任意键继续
	closegraph();          // 关闭绘图窗口
	return 0;
}*/