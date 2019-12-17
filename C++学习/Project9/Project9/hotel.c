#include <stdio.h>
#include "hotel.h"
int menu(void)
{
	int code, status;

	printf("\n%s%s\n", STARS, STARS);
	printf("enter the number of the desired hotel:\n");
	printf("1) Fairfield Arms			2) Hotel Olympic\n");
	printf("3) Chertworthy Plaza		2) The Stockton\n");
	printf("5) quit\n");
	printf("%s%s\n", STARS, STARS);
	while ((status = scanf_s("%d", &code)) != 1 || (code < 1 || code>5))
	{
		if (status != 1)
			scanf_s("%*s");
		printf("enter an integer from 1 to 5, please.\n");
	}

	return code;
}

int getnights(void)
{
	int nights;
	printf("how many nights are needed? ");
	while (scanf_s("%d", &nights) != 1)
	{
		scanf_s("%*s");
		printf("please enter an integer, such as 2.\n");
	}
	return nights;
}

void showprice(double rate, int nights)
{
	int n;
	double total = 0.0;
	double factor = 1.0;

	for (n = 1; n <= nights; n++, factor *= DISCOUNT)
		total += rate * factor;
	printf("the total cost will be $%0.2f.\n", total);
}