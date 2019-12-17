#include<stdio.h>
/*#define REAT1 0.13230
#define REAT2 0.15040
#define REAT3 0.30025
#define REAT4 0.34025   //四个阶段的费率
#define BREAK1 360.0
#define BREAK2 468.0
#define BREAK3 720.0    //三个分界点
#define BASE1 (REAT1*BREAK1)
#define BASE2 (BASE1+(REAT2*(BREAK2-BREAK1)))
#define BASE3 (BASE1+BASE2+(REAT3*(BREAK3-BREAK2)))    //使用电量至三个分界点时的费用
int main() {
	double kwh;		//千瓦时
	double bill;	//电费

	printf("please enter the kwh used.\n");
	scanf_s("%lf", &kwh);
	if (kwh < BREAK1)
		bill = REAT1 * kwh;
	else if (kwh <= BREAK2)
		bill = BASE1 + REAT2 * (kwh - BREAK1);
	else if (kwh <= BREAK3)
		bill = BASE2 + REAT3 * (kwh - BREAK2);
	else
		bill = BASE3 + REAT4 * (kwh - BREAK3);
	printf("the charge for %.1f kwh is $%1.2f.\n", kwh, bill);

	getchar();
	getchar();
	return 0;
}*/
/*#include<stdbool.h>
int main(void) {
	unsigned long num;
	unsigned long div;
	bool isPrime;
	printf("please enter an integer for analysis; ");
	printf("enter q to quit.\n");
	while (scanf_s("%lu", &num) == 1)
	{
		for (div = 2, isPrime = true; (div*div) <= num; div++)
		{
			if (num%div == 0)
			{
				if ((div*div) != num)
					printf("%lu is divisible by %lu and %lu.\n", num, div, num / div);
				else
					printf("%lu is divisible by %lu.\n", num, div);
				isPrime = false;
			}
		}
		if (isPrime)
			printf("%lu is prime.\n", num);
		printf("please enter another integer for analysis; ");
		printf("enter q to quit.\n");
	}
	printf("bye!\n");

	getchar();
	getchar();
	getchar();
	return 0;
}*/
/*#define PERIOD '.'
int main(void) {
	char ch;
	int charcount = 0;

	while ((ch=getchar()) != PERIOD)
	{
		if (ch != '"'&&ch != '\'')
			charcount++;
	}
	printf("there are %d non-quote characters.\n", charcount);

	getchar();
	getchar();
	getchar();
	return 0;
}*/
/*#include<ctype.h>
#include<stdbool.h>
#define STOP '|'
int main(void) {
	char c;					//读取的字符
	char prev;				//读取的前一个字符
	long n_chars = 0L;		//字符数
	long n_lines = 0;		//行数
	long n_words = 0;		//单词数
	long p_lines = 0;		//不完整的行数
	bool inword = false;	//c在单词中，inword=false

	printf("enter text to be analyzed (| to terminate):\n");
	prev = '\n';
	while ((c = getchar()) != STOP)
	{
		n_chars++;
		if (c == '\n')
			n_lines++;
		if (!isspace(c) && !inword)
		{
			inword = true;
			n_words++;
		}
		if (isspace(c) && inword)
			inword = false;
		prev = c;
	}
	if (prev != '\n')
		p_lines = 1;
	printf("characters = %ld, words = %d, lines = %d, ", n_chars, n_words, n_lines);
	printf("partial lines = %d\n", p_lines);

	getchar();
	getchar();
	getchar();
	return 0;
}*/
/*#define COVERAGE 350
int main(void) {
	int sq_feet;
	int cans;

	printf("enter number of square feet to be painted:\n");
	while (scanf_s("%d", &sq_feet) == 1) {
		cans = sq_feet / COVERAGE;
		cans += ((sq_feet%COVERAGE) == 0) ? 0 : 1;
		printf("you need %d %s of paint.\n", cans, cans == 1 ? "can" : "cans");
		printf("enter next value (q to quit):\n");
	}

	getchar();
	getchar();
	getchar();
	return 0;
}*/
/*int main(void) {
	float length, width;

	printf("enter the length of the rectangle:\n");
	while (scanf_s("%f", &length) == 1) {
		printf("length = %0.2f:\n",length);
		printf("enter its width:\n");
		if (scanf_s("%f", &width) != 1)
			break;
		printf("width = %0.2f:\n", width);
		printf("area = %0.2f:\n", length*width);
		printf("enter the length of the rectangle:\n");
	}
	printf("done.\n");

	getchar();
	getchar();
	getchar();
	return 0;
}*/
/*#include <ctype.h>
int main(void) {
	char ch;

	printf("give me a letter of the alphabet, and i will give ");
	printf("an animal name\nbeginning with that letter.\n");
	printf("please type in a letter; type # to end my act.\n");
	while ((ch=getchar())!='#') {
		if ('\n' == ch)
			continue;
		if (islower(ch))
			switch (ch)
			{
			case 'a':
				printf("argali, a wild sheep of asia\n");
				break;
			case 'b':
				printf("babirusa, a wild pig of malay\n");
				break;
			case 'c':
				printf("coati, racoonlike mammal\n");
				break;
			case 'd':
				printf("desman, aquatic, molelike critter\n");
				break;
			case 'e':
				printf("echidna, the spiny anteater\n");
				break;
			case 'f':
				printf("fisher, brownish marten\n");
				break;
			default:
				printf("that's a stumper!\n");
			}
		else
			printf("i recognize only lowercase letters.\n");
		while (getchar() != '\n')
			continue;
		printf("please type another letter or a #.\n");
	}
	printf("bye!\n");

	getchar();
	getchar();
	getchar();
	return 0;
}*/
/*int main(void) {
	char ch;
	int a_ct, e_ct, i_ct, o_ct, u_ct;
	a_ct = e_ct = i_ct = o_ct = u_ct = 0;

	printf("enter some text; enter # to quit.\n");
	while ((ch = getchar()) != '#') {
		switch (ch)
		{
		case 'a':
		case 'A':a_ct++;
			break;
		case 'e':
		case 'E':e_ct++;
			break;
		case 'i':
		case 'I':i_ct++;
			break;
		case 'o':
		case 'O':o_ct++;
			break;
		case 'u':
		case 'U':u_ct++;
			break;
		default:
			break;
		}
	}
	printf("number of vowels:	A	E	I	O	U\n");
	printf("			%4d	%4d	%4d	%4d	%4d\n", a_ct, e_ct, i_ct, o_ct, u_ct);

	getchar();
	getchar();
	getchar();
	return 0;
} */				
int main(void) {				//swithch语句读取空格数，换行数和其他字符的数量
	char ch;
	int space, alpabet, change;
	space = alpabet = change = 0;

	printf("please enter alpabet until enter '#' to quit.\n");
	/*while (scanf_s("%c", &ch) == 1) {
		if ('#' == ch)
			break;*/
	while ((ch=getchar()) != '#') {
		switch(ch) {
			case ' ':space++;
				break;
			case '\n':change++;
				break;
			default:alpabet++;
				break;
		}
	}
	printf("alpabet = %d, space = %d, change = %d", alpabet, space, change);

	getchar();
	getchar();
	return 0;
}