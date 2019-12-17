/*#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10

typedef char ElemType;
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
	return (s.top-s.base)/sizeof(ElemType);
}

int main(void)
{
	ElemType c;
	sqStack s;
	int len, i, sum = 0;

	InitStack(&s);
	printf("please enter an bin interger(\"#\" to quit): \n");
	scanf_s("%c", &c);
	while (c != '#')
	{
		Push(&s, c);
		scanf_s("%c", &c);
		while (c == '\n')
			scanf_s("%c", &c);
	}
	getchar();

	len = stackLen(s);
	printf("the memory of stack is: %d\n", len);

	for (i = 0; i < len; i++)
	{
		Pop(&s, &c);
		sum += (c - 48)*pow(2, i);
	}
	printf("the dec number is: %d", sum);

	getchar();
	return 0;
}*/