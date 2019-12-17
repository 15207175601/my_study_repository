/*#include<stdio.h>

int Fib(int i)
{
	if (i < 2)
		return i == 0 ? 0 : 1;
	else
		return Fib(i - 1) + Fib(i - 2);
}

void print()
{
	char a;
	scanf_s("%c", &a);
	if (a != '#')
		print();
	if (a != '#')
		printf("%c", a);
}
int main(void) {
	int n = 10;


	printf("%d\n",Fib(n));
	print();

	getchar();
	getchar();
	return 0;
}*/