#include <stdio.h>
/*int main(void)
{
	printf("Hello world!.\n");
	getchar();
	return 0;
}*/
/*int main()
{
	int x = 100;
	printf("dec = %d; octal = %o; hex = %x\n", x, x, x);
	printf("dec = %d; octal = %#o; hex = %#x\n", x, x, x);
	getchar();

	return 0;
}*/
/*int main(void)
{
	unsigned int un = 3000000000;
	short end = 200;
	long big = 65537;
	long long verybig = 12345678908642;

	printf("un = %u and not %d\n",un,un);
	printf("end = %hd and %d\n",end,end);
	printf("bog = %ld and mot %hd\n",big,big);
	printf("bog = %lld and mot %ld\n",verybig,verybig);

	getchar();
	return 0;
}*/
/*int main(void)
{
	char ch;

	printf("please enter a character.\n");
	scanf_s("%c", &ch);
	printf("The code for %c is %d.\n",ch,ch);

	getchar();
	getchar();

	return 0;
}*/
/*#include<inttypes.h>
int main(void)
{
	int32_t me32;

	me32 = 45933945;
	printf("first,assume int32_t is int: ");
	printf("me32 = %d\n",me32);
	printf("next, let's not make any assumptions.\n");
	printf("instead, use a \"macro\" from inttypes.h: ");
	printf("me32 = %" PRId32 "\n",me32);

	getchar();

	return 0;
}*/
/*int main(void)
{
	float aboat = 32000.0;
	double abet = 2.14e9;
	long double dip = 5.32e-5;

	printf("%f can be written %e\n",aboat,aboat);
	printf("and it's %.3a in hexadecimal, powers of 2 notation\n", aboat);
	printf("%f can be written %e\n",abet,abet);
	printf("%Lf can be written %Le\n",dip,dip);

	getchar();

	return 0;
}*/
/*int main(void)
{
	float toobig = 3.4e38*100.0f;

	printf("%e\n", toobig);

	getchar();

	return 0;
}*/
/*void jolly(void);
void deny(void);
int main(void)
{
	jolly();
	jolly();
	jolly();
	deny();

	getchar();

	return 0;
}
void jolly(void)
{
	printf("for he's a jolly good fellow!\n");
	return 0;
}
void deny(void)
{
	printf("which nobody can deny!\n");
	return 0;
}*/
/*void br(void);
void ic(void);
int main(void)
{
	br();
	printf(", ");
	ic();
	printf("\n");
	ic();
	printf(",\n");
	br();

	getchar();
	return 0;
}
void br(void)
{
	printf("Brazil, Russia");
	return 0;
}
void ic(void)
{
	printf("India, China");
	return 0;
}*/
/*int main()
{
	int toes = 10;

	printf("toes = %d and twice of toes = %d and square = %d",toes,2*toes,toes*toes);
	
	getchar();
	return 0;
}*/
/*void smile(void);
int main()
{
	smile();
	smile();
	smile();
	printf("\n");
	smile();
	smile();
	printf("\n");
	smile();

	getchar();
	return 0;
}
void smile(void)
{
	printf("smile!");
	return 0;
}*/
/*void one_three(void);
void two(void);
int main(void)
{
	printf("starting now:\n");
	one_three();
	printf("done!\n");

	getchar();
	return 0;
}
void one_three(void)
{
	printf("one\n");
	two();
	printf("three\n");

	return 0;
}
void two(void)
{
	printf("two\n");

	return 0;
}*/
/*int main(void)
{
	int ch;
	scanf_s("%d", &ch);
	printf("%c",ch);

	getchar();
	getchar();

	return 0;
}*/
/*3.2Ê§°Ü*/
/*int main(void)
{
	printf("\aStartled by the sudden sound, sally shouted,\n");
	printf("\"by the great pumpkin, what was that!\"\n");

	getchar();
	return 0;
}*/
/*int main(void)
{
	float num;
	
	printf("enter a floating-point value: ");
	scanf_s("%f",&num);
	printf("fixed-point notation: %f\n",num);
	printf("exponential notation: %e\n",num);
	printf("p notation: %a\n",num);

	getchar();
	long double age;

	printf("please enter your age: ");
	scanf_s("%lf",&age);
	printf("the second of your age is: %lf",age*3.156e7);

	getchar();
	getchar();
	return 0;
}*/
/*int main(void)
{
	double kuatuo;
	scanf_s("%lf", &kuatuo);
	printf("%e", kuatuo*950/3.0e-23);

	getchar();
	getchar();

	return 0;
}*/
/*int main(void)
{
	float tall;
	printf("please enter your tall(inch): ");
	scanf_s("%f", &tall);
	printf("your height is %f cm.", tall*2.54);

	getchar();
	getchar();

	return 0;
}*/
int main(void)
{
	float cups,pints,angs,soups,scoups;

	printf("please enter the cups: ");
	scanf_s("%f", &cups);
	pints = cups / 2;
	angs = cups * 8;
	soups = angs * 2;
	scoups = soups * 3;
	printf("pints = %f\nangs = %f\nsoups = %f\nscoups = %f\n", pints,angs,soups,scoups);

	getchar();
	getchar();

	return 0;
}