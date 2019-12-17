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
	sqStack q;
	ElemType value, e1, e2;
	int i = 0, len;
	char c,e;

	InitStack(&q);
	printf("ÊäÈë¼ÆËãÊ½£º");
	while ((c = getchar()) != '#') {
		if (c >= '0'&&c <= '9')
			printf("%c ", c);
		else if (')' == c)
		{
			Pop(&q, &e);
			while ('(' != e)
			{
				printf("%c ", e);
				Pop(&q, &e);
			}
		}
		else if ('+' == c || '-' == c)
		{
			if (!stackLen(q))
			{
				Push(&q, c);
			}
			else
			{
				do
				{
					Pop(&q, &e);
					if ('(' == e)
						Push(&q, e);
					else
						printf("%c ", e);
				} while (stackLen(q) && '(' != e);
				Push(&q, c);
			}
		}
		else if ('*' == c || '/' == c || '(' == c)
			Push(&q, c);
		else
		{ 
			printf("\nERROR\n");
			return -1;
		}
		
	}

	while (stackLen(q))
	{
		Pop(&q, &e);
		printf("%c", e);
	}
	getchar();
	getchar();
	return 0;
}*/