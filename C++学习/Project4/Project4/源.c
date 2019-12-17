#include <stdio.h>
/*int main(void) {
	int count, sum,days;

	count = 0;
	sum = 0;
	printf("please enter days: ");
	scanf_s("%d", &days);
	while (count++ < days) {
		sum = sum + count;
		printf("sum = %d\n", sum);
	}

	getchar();
	getchar();
	return 0;
}*/
/*int main(void) {
	int count, sum, days;

	count = 0;
	sum = 0;
	printf("please enter days: ");
	scanf_s("%d", &days);
	while (count++ < days) {
		sum = sum + count*count;
		printf("sum = %d\n", sum);
	}

	getchar();
	getchar();
	return 0;
}*/
/*double cube(double x);
int main() {
	double a;
	printf("please enter a number:");
	scanf_s("%lf", &a);
	printf("the cube of the number is: %lf", cube(a));

	getchar();
	getchar();
	return 0;
}
double cube(double x) {
	double x_x_x = x * x*x;
	return x_x_x;
}*/
/*int main(void) {
	int first, second, days;

	printf("this program computes moduli.\n");
	printf("enter an integer to serve as the second operand: ");
	scanf_s("%d", &second);
	printf("now enter the first operand: ");
	scanf_s("%d", &first);

	while (first>0) {
		printf("%d %% %d is %d\n", first, second, first%second);
		printf("now enter the first operand: ");
		scanf_s("%d", &first);
	}
	printf("done!");

	getchar();
	getchar();
	return 0;
}*/
void Temperature(double x);
int main(void) {
	double f, t, k;
	int c;

	printf("this program transform temperature.\n");
	printf("enter an degree(F): ");
	c=scanf_s("%lf", &f);

	while (c==1) {
		Temperature(f);
		c = scanf_s("%lf", &f);
	}
	printf("done!");

	getchar();
	getchar();
	getchar();
	return 0;
}
void Temperature(double x) {
	const double K = 273.16;
	const double F = 32.0;
	double y, z;

	y = 5.0 / 9.0*(x - F);
	z = x + K;
	printf("f = %.2lf t = %.2lf k = %.2lf \n", x, y,z);
}