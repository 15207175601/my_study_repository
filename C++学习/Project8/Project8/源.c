#include<stdio.h>
/*int main(void) {
	char ch;
	int num = 0;

	while ((ch = getchar()) != EOF)
	{
		if (ch >= ' ')
			putchar(ch);
		else if (ch == '\n')
			printf("\\n");
		else if (ch == '\t')
			printf("\\t");
		else
		{
			printf("^");
			putchar(ch + 64);
		}
		printf(": %d	", ch);
		num++;
		if (num % 10 == 0)
			printf("\n");
	}
	printf("\nthe number of the char is: %d", num);
	getchar();
	return 0;
}*/
/*#include<ctype.h>
#include<stdbool.h>
int main(void) {
	char ch;
	int low = 0, up = 0;

	while ((ch = getchar()) != EOF)
	{
		if (ch>='a'&&ch<='z')
		//if(islower(ch))
			low++;
		else if (isupper(ch))
			up++;
	}
	printf("the number of lower is %d\n", low);
	printf("the number of upper is %d\n", up);
	getchar();
	return 0;
}*/
/*#include<ctype.h>
#include<stdbool.h>
int main(void) {
	int ch;
	int num=0,times = 0;
	float sum = 0;

	while ((ch = getchar()) != EOF)
	{
		while (islower(ch)|| isupper(ch))
		{
			num++;
			ch = getchar();
		}
		if (ch == EOF)

			break;
		if (num > 0)
		{
			sum += num;
			times++;
			num = 0;
		}

	}
	printf("the average of the %d words is: %.2f\n",times,(float) (sum/times));
	getchar();
	return 0;
}*/
/*int main(void) {
	int guess = 50,max=100,min=0;
	char response;

	printf("pick an integer from 1 to 100. i will try to guess ");
	printf("it.\nrespond with a y if my guess is right and with");
	printf("\nan s if it is smaller or b if it is bigger.\n");
	printf("Uh...is your number %d?\n", guess);
	while ((response=getchar()) != 'y')
	{
		if (response == 's')
		{
			min = guess;
			guess = (max + min) / 2;
			printf("well, then, is it %d?\n", guess);
		}
		else if(response=='b')
		{
			max = guess;
			guess = (max + min) / 2;
			printf("well, then, is it %d?\n", guess);
		}
		else
			printf("sorry, i understand only y, s or b.\n");
		while (getchar() != '\n')
			continue;
	}
		
	printf("i knew i could do it !\n");

	getchar();
	getchar();
	return 0;
}*/
/*#include<ctype.h>
char get_first(void);
int main() {
	int ch;

	ch = get_first();

	putchar(ch);

	getchar();
	getchar();
	return 0;
}
char get_first(void)
{
	int ch;

	while (isspace(ch=getchar()))
		continue;
	while (getchar() != '\n')
		continue;

	return ch;

}*/
/*#define SALARY	salary()
#define SALARY1	8.75
#define SALARY2	9.33
#define SALARY3	10.00
#define SALARY4	11.20
#define OSALARY	1.5*SALARY
#define OTIME	40.0
#define PSALARY	OTIME*SALARY
#define TAX1	0.15
#define TAX2	0.20
#define TAX3	0.25
#define TAX1_2	300
#define TAX2_3	150
#define FEE1_2	TAX1*TAX1_2
#define FEE2_3	TAX2*TAX2_3

int main(void)
{
	float time, p_salary,tax_fee,a_salary;

	printf("please enter your working time: ");
	scanf_s("%f", &time);
	if (time < OTIME)
		p_salary = time * SALARY;
	else
		p_salary = PSALARY + (time - OTIME)*SALARY;
	if (p_salary < TAX1_2)
		tax_fee = TAX1 * p_salary;
	else if (p_salary < TAX1_2 + TAX2_3)
		tax_fee = FEE1_2 + TAX2 * (p_salary - TAX1_2);
	else
		tax_fee = FEE1_2 + FEE2_3 + TAX3 * (p_salary - TAX1_2 - TAX2_3);
	a_salary = p_salary - tax_fee;
	printf("working time	p_salary	tax_fee		a_salary\n");
	printf("%.2f		%.2f		%.2f		%.2f\n", time, p_salary, tax_fee, a_salary);

	getchar();
	getchar();
	return 0;
}
float salary() {
	int ch;
	double salary1;

	printf("enter the number corresponding to the desired pay rate or action:\n");
	printf("a)$8.75/hr				b)$9.33/hr\n");
	printf("c)$10.00/hr				d)$11.20/hr\n");
	printf("q)quit\n");

	l:switch (ch=getchar())
	{
	case 'a':
		salary1 = SALARY1;
		break;
	case 'b':
		salary1 = SALARY2;
		break;
	case 'c':
		salary1 = SALARY3;
		break;
	case 'd':
		salary1 = SALARY4;
		break;
	case 'q':
		break;
	default:
		goto l;
		break;
	}
	return salary1;
}
*/
/*#define SALARY1	8.75
#define SALARY2	9.33
#define SALARY3	10.00
#define SALARY4	11.20
#define OTIME	40.0
#define TAX1	0.15
#define TAX2	0.20
#define TAX3	0.25
#define TAX1_2	300
#define TAX2_3	150
#define FEE1_2	TAX1*TAX1_2
#define FEE2_3	TAX2*TAX2_3

int main(void)
{
	float a;
	a = salary();
	printf("%f", a);

	getchar();
	getchar();
	return 0;
}
float salary(void) {
	int ch;
	float salary1;

	printf("enter the number corresponding to the desired pay rate or action:\n");
	printf("a)$8.75/hr				b)$9.33/hr\n");
	printf("c)$10.00/hr				d)$11.20/hr\n");
	printf("q)quit\n");
	while ((ch = getchar()) != 'q') {
		switch (ch)
		{
		case 'a':
			salary1 = SALARY1;
			break;
		case 'b':
			salary1 = SALARY2;
			break;
		case 'c':
			salary1 = SALARY3;
			break;
		case 'd':
			salary1 = SALARY4;
			break;
		default:
			printf("please enter a b c d or q.\n");
			break;
		}
	}
  return salary1;
}*/
/*
int main(void)
{
	float time, p_salary, tax_fee, a_salary,salary1;

	salary1 = salary();
	printf("please enter your working time: ");
	scanf_s("%f", &time);
	if (time < OTIME)
		p_salary = time * salary1;
	else
		p_salary = OTIME*salary1 + (time - OTIME)*salary1*1.5;
	if (p_salary < TAX1_2)
		tax_fee = TAX1 * p_salary;
	else if (p_salary < TAX1_2 + TAX2_3)
		tax_fee = FEE1_2 + TAX2 * (p_salary - TAX1_2);
	else
		tax_fee = FEE1_2 + FEE2_3 + TAX3 * (p_salary - TAX1_2 - TAX2_3);
	a_salary = p_salary - tax_fee;
	printf("working time	p_salary	tax_fee		a_salary\n");
	printf("%.2f		%.2f		%.2f		%.2f\n", time, p_salary, tax_fee, a_salary);

	getchar();
	getchar();
	return 0;
}
float salary() {
	int ch;
	float salary1;

	printf("enter the number corresponding to the desired pay rate or action:\n");
	printf("a)$8.75/hr				b)$9.33/hr\n");
	printf("c)$10.00/hr				d)$11.20/hr\n");
	printf("q)quit\n");

l:switch (ch = getchar())
{
case 'a':
	salary1 = SALARY1;
	break;
case 'b':
	salary1 = SALARY2;
	break;
case 'c':
	salary1 = SALARY3;
	break;
case 'd':
	salary1 = SALARY4;
	break;
case 'q':
	break;
default:
	goto l;
	break;
}

  return salary1;
}*/
/*#include <stdio.h>
#define BASE1 8.75
#define BASE2 9.33
#define BASE3 10.00
#define BASE4 11.20
//四种等级的基本工资
#define TIME 40			//超过40h为加班
#define	MUL	1.5		//加班时间算作平时的1.5倍
#define	RATE1 0.15		//前300美元的税率
#define RATE2 0.2			//300-450美元的税率
#define RATE3 0.25		//大于450美元的税率
#define BREAK1 300		//税率的第一个分界点
#define BREAK2 450		//税率的第二个分界点
#define LENGTH 65		//*的长度

char get_choice(void);
void calculate(double base);
int main(void)
{
	double base;
	char choice;

	while ((choice = get_choice()) != 'q')
	{
		switch (choice)
		{
		case 'a': base = BASE1;
			break;
		case 'b': base = BASE2;
			break;
		case 'c': base = BASE3;
			break;
		case 'd': base = BASE4;
			break;
		default: printf("Please respond with a, b, c, d or q.\n");
			break;
		}
		if (choice >= 'a' && choice <= 'd')
			calculate(base);
	}

	return 0;
}

//计算和输出结果的函数
void calculate(double base)
{
	double hour, gross, tax;

	printf("Input your work hours in a week: ");
	scanf_s("%lf", &hour);
	while (getchar() != '\n')
		continue;					//跳过回车
	if (hour <= TIME)
		gross = hour * base;
	else
		gross = TIME * base + (hour - TIME) * MUL * base;
	//计算总收入
	if (gross <= BREAK1)
		tax = gross * RATE1;
	else if (gross <= BREAK2)
		tax = BREAK1 * RATE1 + (gross - BREAK1) * RATE2;
	else
		tax = BREAK1 * RATE1 + (BREAK2 - BREAK1) * RATE2
		+ (gross - BREAK2) * RATE3;
	//计算税金
	printf("Your gross income is $%.2lf\nYour tax is $%.2lf\n"
		"Your net income is $%.2lf\n",
		gross, tax, (gross - tax));
	printf("\n");
}

//打印选择界面并让用户输入的函数
char get_choice(void)
{
	char ch;
	int count;

	for (count = 0; count < LENGTH; count++)
		printf("*");
	printf("\nEnter the letter corresponding to the desired pay rate or action:\n");
	printf("%-36s%s", "a) $8.75/hr", "b) $9.33/hr\n");
	printf("%-36s%s", "c) $10.00/hr", "d) $11.20/hr\n");
	printf("%s\n", "q) quit");
	for (count = 0; count < LENGTH; count++)
		printf("*");
	printf("\n");

	ch = getchar();
	while (getchar() != '\n')
		continue;					//跳过输出行剩余内容

	return ch;
}
*/