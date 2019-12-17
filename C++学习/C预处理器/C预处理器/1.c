/*#include <stdio.h>
#define TWO 2
#define OW "consistency is the last refuge of the unimagina\
tive. - Oscar Wilde"

#define FOUR TWO*TWO
#define PX printf("X is %d.\n",x)
#define FMT "X is %d.\n"

int main(void)
{
	int x = TWO;

	PX;
	x = FOUR;
	printf(FMT, x);
	printf("%s\n", OW);
	printf("TWO: OW\n");

	return 0;
}*/

/*#include <stdio.h>
#define SQUARE(X) X*X
#define PR(X) printf("the result is %d.\n",X)

int main(void)
{
	int x = 5;
	int z;
	printf("x=%d\n", x);
	z = SQUARE(x);
	printf("evaluating SQUARE(x): ");
	PR(z);
	z = SQUARE(2);
	printf("evaluating SQUARE(2): ");
	PR(z);
	printf("evaluating SQUARE(x+2): ");
	PR(SQUARE(x+2));
	printf("x is %d.\n", x);
	printf("evaluating SQUARE(++x): ");
	PR(SQUARE(++x));
	printf("after incrementing, x is %x.\n", x);
	return 0;
}*/

/*#include<stdio.h>
#define PSQR(x) printf("the squre of " #x " is %d.\n",((x)*(x)))

int main(void)
{
	int y = 5;
	PSQR(y);
	PSQR(4 + 2);

	return 0;
}*/

/*#include <stdio.h>
#define XNAME(n) x ## n
#define PRINT_XN(n) printf("x" #n " = %d\n",x##n)

int main(void)
{
	int XNAME(1) = 14;
	int XNAME(2) = 20;
	int x3 = 30;
	PRINT_XN(1);
	PRINT_XN(2);
	PRINT_XN(3);
	return 0;
}*/

/*#include<stdio.h>
#include<math.h>
#define PR(X,...) printf("message " #X ": " __VA_ARGS__)

int main(void)
{
	double x = 48;
	double y;

	y = sqrt(x);
	PR(1, "x = %g\n", x);
	PR(2, "x = %.2f,y = %.4f\n", x, y);

	return 0;
}*/

/*#include<stdio.h>
#include "name.h"
int main(void)
{
	names candidate;

	get_names(&candidate);
	printf("let's welcome ");
	show_names(&candidate);
	printf(" to this program!\n");
	return 0;
}*/

/*#include <stdio.h>
int MaxSubsqequenceSum(const int A[], int N);
int main(void)
{
	int A[100],ans, N=0,i=0;
	printf("please enter an array(int): ");
	while (scanf_s("%d", A[i]))
	{
		i++;
		N++;
	}
	ans=MaxSubsqequenceSum(A[N], N);
	printf("the answer is: %d", ans);
	return 0;
}*/

/*#include <stdio.h>
int MaxSubsqequenceSum1(const int A[], int N);
int MaxSubsqequenceSum2(const int A[], int N);
int main(void)
{
	int A[10] = {-2,11,-4,13,-5,-2}, ans, N = 6, i = 0;
	ans = MaxSubsqequenceSum1(A, N);
	printf("the answer is: %d", ans);
	ans = MaxSubsqequenceSum2(A, N);
	printf("the answer is: %d", ans);
	getchar();
	return 0;
}*/