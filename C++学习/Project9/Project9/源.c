#include<stdio.h>
/*#define SIZE 50
int main(void)
{
	float list[SIZE];

	readlist(list, SIZE);
	sort(list, SIZE);
	average(list, SIZE);
	bargraph(list, SIZE);

	getchar();
	return 0;
}*/
/*#define NAME "GIGATHINK,	INC."
#define ADDRESS "101 Megabuck Plaza"
#define PLACE "Megapolis, CA 94904"
#define WIDTH 40

void starbar(void);

int main(void)
{
	starbar();
	printf("%s\n", NAME);
	printf("%s\n", ADDRESS);
	printf("%s\n", PLACE);
	starbar();

	getchar();
	getchar();
	return 0;
}

void starbar(void) {
	int count;

	for (count = 1; count <= WIDTH; count++)
		putchar('*');
	putchar('\n');
}*/
/*#include<string.h>
#define NAME "GIGATHINK,	INC."
#define ADDRESS "101 Megabuck Plaza"
#define PLACE "Megapolis, CA 94904"
#define WIDTH 40
#define SPACE ' '

void show_n_char(char ch, int num);

int main(void)
{
	int spaces;

	show_n_char('*', WIDTH);
	putchar('\n');
	show_n_char(SPACE, 12);
	printf("%s\n", NAME);
	spaces = (WIDTH - strlen(ADDRESS)) / 2;

	show_n_char(SPACE, spaces);
	printf("%s\n", ADDRESS);

	show_n_char(SPACE, (WIDTH - strlen(PLACE)) / 2);
	printf("%s\n", PLACE);

	show_n_char('*', WIDTH);
	putchar('\n');

	getchar();
	getchar();
	return 0;
}

void show_n_char(char ch,int num) {
	int count;

	for (count = 1; count <= num; count++)
		putchar(ch);
}*/
/*int imin(int, int);

int main(void)
{
	int evil1, evil2;

	printf("enter a pair of integers (q to quit):\n");
	while (scanf_s("%d %d", &evil1, &evil2) == 2)
	{
		printf("the lesser of %d and %d is %d.\n",
			evil1, evil2, imin(evil1, evil2));
		printf("enter a pair of integers (q to quit):\n");
	}
	printf("bye.\n");

	return 0;
}

int imin(int n, int m)
{
	int min;

	if (n < m)
		min = n;
	else
		min = m;

	return min;
}*/
/*int imax();

int main(void)
{
	printf("the maximum of %d and %d is %d.\n", 3, 5, imax(3));
	printf("the maximum of %d and %d is %d.\n", 3, 5, imax(3.0, 5.0));

	getchar();
	return 0;
}

int imax(n, m)
int n, m;
{
	return (n > m ? n : m);
}*/
/*int imax(int, int);
int main(void)
{
	printf("the maximum of %d and %d is %d.\n",
		3, 5, imax(3,5));
	printf("the maximum of %d and %d is %d.\n",
		3, 5, imax(3.0,5.0));
	
	getchar();
	getchar();
	return 0;
}

int imax(int n, int m)
{
	return (n > m ? n : m);
}*/
/*void up_and_down(int);
int main(void)
{
	up_and_down(1);
	getchar();
	return 0;
}

void up_and_down(int n)
{
	printf("level %d: n location %p\n", n, &n);
	if (n < 4)
		up_and_down(n + 1);
	printf("LEVEL %d: n location %p\n", n, &n);
}*/
/*long fact(int n);
long rfact(int n);
int main(void)
{
	int num;

	printf("this program calculates factorials.\n");
	printf("enter a value in the range 0-12 (q to quit):\n");
	while (scanf_s("%d", &num) == 1)
	{
		if (num < 0)
			printf("no negative numbers,please.\n");
		else if (num > 12)
			printf("keep input under 13.\n");
		else
		{
			printf("loop: %d factorial = %ld\n", num, fact(num));
			printf("recursion: %d factorial = %ld\n", num, rfact(num));
		}
		printf("enter a value in the range 0-12(q to quit):\n");
	}
	printf("bye.\n");

	getchar();
	getchar();
	return 0;
}

long fact(int n)
{
	long ans;

	for (ans = 1; n > 1; n--)
		ans *= n;

	return ans;
}

long rfact(int n)
{
	long ans;

	if (n > 0)
		ans = n * rfact(n - 1);
	else
		ans = 1;

	return ans;
}*/
/*void to_binary(unsigned long n);				//计算二进制

int main(void)
{
	unsigned long number;

	printf("enter an integer(q to quit):\n");
	while (scanf_s("%lu", &number) == 1) {
		printf("binary equivalent: ");
		to_binary(number);
		putchar('\n');
		printf("enter an integer(q to quit):\n");
	}
	printf("done!\n");

	getchar();
	getchar();
	return 0;
}

void to_binary(unsigned long n)
{
	int r;
	r = n % 2;
	if (n >= 2)
		to_binary(n / 2);
	putchar(r == 0 ? '0' : '1');

	return;
}*/
#include "hotel.h"

int main(void)
{
	int nights;
	double hotel_rate;
	int code;

	while ((code = menu()) != QUIT)
	{
		switch (code)
		{
		case 1:hotel_rate = HOTEL1;
			break;
		case 2:hotel_rate = HOTEL2;
			break;
		case 3:hotel_rate = HOTEL3;
			break;
		case 4:hotel_rate = HOTEL4;
			break;
		default:
			hotel_rate = 0.0;
			printf("Oops!\n");
			break;
		}
		nights = getnights();
		showprice(hotel_rate, nights);
	}
	printf("thank you and goodbye.\n");

	getchar();
	getchar();
	return 0;
}