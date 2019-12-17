/*#include <iostream>
#include <cmath>
#include <vector>
#include<stdlib.h>
#include <time.h>
#include<algorithm>
#include "graphics.h"      // 引用图形库头文件
#include <conio.h>
using namespace std;
#define LARGE 10000
const int nums = 200;
double mp[nums + 3][nums + 3],mp1[nums+3][nums+3];
double dist = 0;
struct Point {
	double x;
	double y;
}point[nums+3];
double dis(Point u, Point v)
{
	double dx = u.x - v.x;
	double dy = u.y - v.y;
	return sqrt((dx) * (dx) + (dy) * (dy));
}
void initmap()
{
	for (int i = 0; i < nums; ++i) {
		//scanf_s("%lf%lf", &point[i].x, &point[i].y);
		//srand(time(0));
		//point[i].x = rand()%200;
		//srand(i);
		//point[i].y = rand()%200;
		static int j = 1;
		srand(i * i + j);
		point[i].x = rand() % 1000;
		j++;
		srand(i + 3 * j * j);
		point[i].y = rand() % 1000;
		j = j + i;
		if (i % 2 == 0)
			printf("point[%d]:	x = %.2lf;	y = %.2lf\t", i, point[i].x, point[i].y);
		else
			printf("point[%d]:	x = %.2lf;	y = %.2lf\n", i, point[i].x, point[i].y);
		putpixel(point[i].x, point[i].y, RED);
	}
	for (int i = 0; i < nums; i++)
	{
		for (int j = 0; j < nums; j++)
		{
			if (j == i)
				mp1[i][j]=mp[i][j] = LARGE;
			else
				mp1[i][j]=mp[i][j] = dis(point[i], point[j]);
		}
	}
}
int main() {
	srand(time(0));
	int ans[nums + 3];
	initgraph(1000, 1000);	 // 创建绘图窗口，大小为 640x480 像素
	initmap();
	int icount = 0,cnt=0;
	int k = rand() % nums;
	for (int i = 0; i < nums; i++)		//有问题
	{
		double ans1;
		int temp=k;
		ans[i] = k;
		ans1 = mp1[k][0];
		for (int j = 0; j < nums; j++)
		{
			if (mp1[k][j] < ans1)
			{
				ans1 = mp1[k][j];
				temp = j;
				icount++;
			}	
			else
			{
				if (ans1==mp1[k][0])
				{
					temp = 0;
				}
			}
		}
		for (int zi = 0; zi < nums; zi++)
		{
			mp1[zi][k]=mp1[k][zi] = LARGE;
		}
		dist += ans1;
		k = temp;
	}
	printf("run %d times\n", icount);
	printf("distance:%.2f\n", dist);
	for (int i=0;i<nums;i++)
	{
		static int count = 0;
		static int temp = i;
		if (count == 0)
			cnt = i;
		if (count > 0)
			line(point[ans[temp]].x, point[ans[temp]].y, point[ans[i]].x, point[ans[i]].y);
		printf("%d ", ans[i]);
		count++;
		temp = i;
	}
	line(point[ans[0]].x, point[ans[0]].y, point[ans[nums - 1]].x, point[ans[nums - 1]].y);
	printf("%d", ans[0]);
	_getch();              // 按任意键继续
	closegraph();          // 关闭绘图窗口
	return 0;
}*/