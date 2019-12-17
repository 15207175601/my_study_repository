/*#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

#define STACK_INIT_SIZE 20
#define STACKINCREMENT	10
#define MAXBUFFER		10

typedef double ElemType;
typedef struct {
	ElemType *base;
	ElemType *top;
	int stackSize;
}sqStack;

void InitStack(sqStack *s)
{
	s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if (!s->base)
		exit(0);
	s->top = s->base;
	s->stackSize = STACK_INIT_SIZE;
}
void Push(sqStack *s, ElemType e)
{
	if (s->top - s->base >= s->stackSize)
	{
		s->base = (ElemType *)realloc(s->base, (s->stackSize + STACKINCREMENT) * sizeof(ElemType));
		if (!s->base)
			exit(0);
	}

	*(s->top) = e;
	s->top++;
}
void Pop(sqStack *s, ElemType *e)
{
	if (s->top == s->base)
		return;
	*e = *--(s->top);
}
int stackLen(sqStack s)
{
	return (s.top - s.base) / sizeof(ElemType);
}

int main(void)
{
	sqStack p;
	ElemType value,e1,e2;
	int i=0,len;
	char c,str[MAXBUFFER];

	InitStack(&p);
	printf("输入逆波兰表达式：");
	while ((c=getchar()) != '#') {
		switch (c)
		{
		case '+':
			Pop(&p, &e2);
			Pop(&p, &e1);
			Push(&p, e1 + e2);
			break;
		case '-':
			Pop(&p, &e2);
			Pop(&p, &e1);
			Push(&p, e1 - e2);
			break;
		case '*':
			Pop(&p, &e2);
			Pop(&p, &e1);
			Push(&p, e1 * e2);
			break;
		case '/':
			Pop(&p, &e2);
			Pop(&p, &e1);
			if (e2 != 0)
				Push(&p, e1 / e2);
			else
				printf("\nERROR!\n");
			break;
		}
		while (isdigit(c) ||c== '.')
		{
			str[i++] = c;
			str[i] = '\0';
			if (i >= 10)
			{
				printf("输入单个数据过大");
				return -1;
			}
			scanf_s("%c", &c);
			if (c == ' ')
			{
				value = atof(str);
				Push(&p, value);
				i = 0;
				break;
			}
		}

		
	}
	Pop(&p, &value);
	printf("结果是： %lf", value);
	getchar();
	getchar();
	return 0;
}*/