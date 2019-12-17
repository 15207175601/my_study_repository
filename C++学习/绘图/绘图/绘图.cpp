#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>

/*int main()//直线
{
	int gdriver = DETECT, gmode;
	//initgraph(&gdriver, &gmode, "");
	initgraph(540, 450);
	line(150, 350, 350, 350);
	getchar();
	line(370, 100, 370, 350);
	getchar();
	lineto(250, 250);
	getchar();
	closegraph();
	system("pause");
	return 0;
}*/
/*int main(void)//矩形，线型
{
	
	for (int i = 0; i <= 10; i++)
	{
		initgraph(700, 700);
		setcolor(RED);
		setlinestyle(3, 3, 0, 3);
		rectangle(100, 100, 550, 350);
		getchar();
		closegraph();
	}
	getchar();
	
}*/
/*int main(void)//网格
{
	initgraph(700, 700);
	cleardevice();
	for(int i=120;i<=400;i+=40)
		for (int j = 120; j < 400; j++)
		{
			putpixel(i, j, YELLOW);
			putpixel(j, i, YELLOW);
		}
	getchar();
	closegraph();
}*/
/*void window_3d(int, int, int, int, int, int);
int main(void)
{
	directvideo = 0;
	initgraph(700, 700);
	textmode(3);

}*/
int main(void)
{
	initgraph(500, 500);
	ellipse(0, 300, 200, 100);
	getchar();
	cleardevice();
	setbkcolor(GREEN);
	setcolor(RED);
	arc(getmaxx() / 2, getmaxy() / 2, 50,100,0, 120);
	getchar();
	closegraph();
}