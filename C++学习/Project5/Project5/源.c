#include<stdio.h>
#include<math.h>
#include<string.h>
/*#define SIZE 10
#define PAR 72
#define LAC 5
double power(double n, int p);*///注释
/*int main(void) {
	long num;
	long sum = 0L;
	int status;
	
	printf("please enter an integer to be summed ");
	printf("(q to quit): ");
	status = scanf_s("%ld", &num);
	while (status == 1) {
		sum = sum + num;
		printf("please enter next integer(q to quit): ");
		status= scanf_s("%ld", &num);
	}
	printf("those integers sum to %ld.\n", sum);

	getchar();
	getchar();
	getchar();
	return 0;
}*/  
/*int main(void) {
	const double ANSWER = 3.14159;
	double response;

	printf("what is the value of the pi?\n");
	scanf_s("%lf", &response);
	while (fabs(response-ANSWER) > 0.00001) {
		printf("try again!\n");
		scanf_s("%lf", &response);
	}
	printf("colse enough!\n");

	getchar();
	getchar();
	return 0;
} */
/*int main(void) {
	int n = 3;

	while (n)
		printf("%2d is true\n",n--);
	printf("%2d is false\n",n);

	n = -3;
	while (n)
		printf("%2d is true\n", n++);
	printf("%2d is false\n", n);

	getchar();
	return 0;
}*/
/*int main(void) {
	long num;
	long sum = 0L;
	_Bool input_is_good;

	printf("please enter an integer to be summed ");
	printf("(q to quit): ");
	input_is_good = (scanf_s("%ld", &num)==1);
	while (input_is_good) {
		sum = sum + num;
		printf("please enter next integer(q to quit): ");
		input_is_good = (scanf_s("%ld", &num) == 1);
	}
	printf("those integers sum to %ld.\n", sum);

	getchar();
	getchar();
	getchar();
	return 0;
}*/
/*int main(void) {
	const int NUMBER = 22;
	int count;

	for (count = 1; count <= NUMBER; count++)
		printf("be my valentine!\n");

	getchar();
	return 0;
}*/
/*int main(void) {
	int index, score[SIZE];
	int sum = 0;
	float average;

	printf("enter %d golf scores:\n", SIZE);
	for (index = 0; index < SIZE; index++) {
		scanf_s("%d", &score[index]);
		while (score[index] < 0 || score[index]>100)
		{
			printf("error! please enter a score again:\n");
			scanf_s("%d", &score[index]);
		}
	}
	
	printf("the scores read in are as follow:\n");
	for (index = 0; index < SIZE; index++)
		printf("%5d", score[index]);
	printf("\n");
	for (index = 0; index < SIZE; index++) 
		sum = sum + score[index];
	average = (float)sum / SIZE;
	printf("sum of scores = %d, average = %.2f\n", sum, average);
	printf("that's a handicap of %.0f.\n", average - PAR);

	getchar();
	getchar();
	return 0;
}*/
/*int main(void) {
	double x, xpow;
	int exp;

	printf("please enter a number and the positive integer power"
	"to which\nthe number will be raised. enter q to quit.\n");
	while (scanf_s("%lf%d", &x, &exp) == 2)
	{
		xpow = power(x, exp);
		printf("%.3g to the power %d is %.5g\n", x, exp, xpow);
		printf("enter next pair of numbers or q to quit.\n");
	}
	printf("hope you enjoyed this power trip --bye!\n");

	getchar();  
	getchar();
	return 0;
}
double power(double n, int p)
{
	double pow = 1;
	int i;
	if (p < 0)
	{
		for (i = 1; i <= -p; i++)
			pow *= n;
		pow = 1 / pow;
	}
	else for (i = 1; i <= p; i++)
		pow *= n;
	return pow;
}*/
/*int main(void) {
	char alphabet[26];
	int i;
	
	for (i = 0; i < 26; i++)
		alphabet[i] = 'a' + i;
	for (i = 0; i < 26; i++)
		printf("%c", alphabet[i]);

	getchar();
	return 0;
}*/
/*int main(void) {
	int i,j;

	for (i = LAC; i >=1; i--) {
		for (j = i; j <= LAC; j++)
			printf("$");
		printf("\n");
	}


	getchar();
	return 0;
}*/
/*int main(void) {
	char a;
	int i, j;

	for (i = LAC; i >= 0; i--) {
		for (j = LAC; j >= i; j--) {
			a = 'A' + j;
			printf("%c", a);
		}
		printf("\n");
	}


	getchar();
	return 0;
}*/
/*int main(void) {
	char a;
	int i, j;

	for (i = 0; i <= LAC; i++) {
		for (j = 0; j <= i; j++) {
			a = 'F' - j;
			printf("%c", a);
		}
		printf("\n");
	}


	getchar();
	return 0;
}*/
/*int main(void) {
	char a='A'-1;
	int i, j;

	for (i = 0; i <= LAC; i++) {
		for (j = 0; j <= i; j++) {
			a = a + 1;
			printf("%c", a);
		}
		printf("\n");
	}


	getchar();
	return 0;
}*/
/*int main(void) {
	char a = 'A' ,b,x;
	int c,i,j;

	printf("please enter a alphabet:");
	scanf_s("%c", &b);
	c = b - a;
	for (i = 0; i <= c; i++) {
		for (j = i; j < c; j++) {
			printf(" ");
		}
		for (j = 0; j <= i; j++) {
			x = a + j;
			printf("%c", x);
		}
		for (j = i; j > 0; j--) {
			x = a + j-1;
			printf("%c", x);
		}
		printf("\n");
	}


	getchar();
	getchar();
	return 0;
}*/
/*int main(void) {
	char  a[20];
	int c, i, j=0;

	printf("please enter a alphabet:");
	for (i = 0; i < 20; i++) {
		scanf_s("%c", &a[i]);
		j++;
		while (a[i] == '#')
			i = 20;
	}
	for (i = 0; i <j; i++) {
		printf("%c",a[i]);
	}
	printf("\n");
	c = strl;
	printf("%d", c);


	getchar();
	getchar();
	return 0;
} */
/*int main() {
	int eight[8], i, a = 1;
	for(i = 0; i < 8; i++) {
		eight[i] = 2 * a;
		a = 2 * a;
	}
	i = 0;
	do {
		printf("%d\t", eight[i]);
		i++;
	} while (i < 8);
	
	getchar();
	return 0;
}*/
/*int main() {
	double a[8], b[8];
	int i, j=0;
	for (i = 0; i < 8; i++)
	{
		printf("please enter the %d number:\n", i+1);
		scanf_s("%lf", &a[i]);
		j += a[i];
		b[i] = j;
	}
	printf("a:\t");
	for (i = 0; i < 8; i++) 
		printf("%.4lf\t", a[i]);
	printf("\nb:\t");
	for (i = 0; i < 8; i++)
		printf("%.4lf\t", b[i]);
	getchar();
	getchar();
	return 0;
}*/
/*int main() {
	char a[255];
	int i,j;

	for (j = 0, scanf_s("%c",&a[0]); a[j] != '\n'; j++){     //判别式有要求时候应该给初值
		i = j + 1;
		scanf_s("%c", &a[i]);
	}
	for (int k = i; k >= 0; k--)
		printf("%c", a[k]);
	getchar();
	return 0;
}*/
/*int main(void) {
	const int FREEZING = 0;
	float temperature;
	int cold_days=0;
	int all_days=0;

	printf("enter the list of daily low temperatures.\n");
	printf("use celsius, and enter q to quit.\n");
	while (scanf_s("%f", &temperature) == 1) {
		all_days++;
		if (temperature < FREEZING)
			cold_days++;
	}
	if (all_days != 0)
		printf("%d days total: %.1f%% were below freezing.\n",
			all_days, 100 * (float)cold_days / all_days);
	if (all_days == 0)
		printf("no data entered!\n");

	getchar();
	getchar();
	getchar();
	return 0;
} */
/*#define SPACE ' '
int main(void) {
	char ch;

	ch = getchar();
	while (ch!='\n') {
		if (ch == SPACE)
			putchar(ch);
		else
			putchar(ch + 1);
		ch = getchar();
	}
	putchar(ch);

	getchar();


	return 0;
}*/
