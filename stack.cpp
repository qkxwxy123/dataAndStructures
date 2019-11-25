#include "malloc.h"
#define STACK_INIT_SIZE 100
#define STACKINCREAMENT 10

typedef struct {
	int* top;
	int* base;
	int stackSize;
}SqStack;

int initStack(SqStack&);
int destroyStack(SqStack&);
int clearStack(SqStack&);
int stackEmpty(SqStack);
int stackLength(SqStack);
int getTop(SqStack, int&);
int push(SqStack&, int);
int pop(SqStack&, int&);
int stackTraverse(SqStack, int(*visit)());

int initStack(SqStack& S)
{
	S.base = (int*)malloc(STACK_INIT_SIZE * sizeof(int));
	if (!S.base)
		return 0;
	S.top = S.base;
	S.stackSize = STACK_INIT_SIZE;
	return 1;
}

int destroyStack(SqStack& S)
{
	S.top = S.base = NULL;
	S.stackSize = 0;
	return 1;
}

int clearStack(SqStack& S)
{
	free(S.base);
	free(S.top);
	S.stackSize = STACK_INIT_SIZE;
	S.base = (int*)malloc(STACK_INIT_SIZE * sizeof(int));
	if (!S.base)
		return 0;
	S.top = S.base;
	return 1;
}

int stackEmpty(SqStack S)
{
	if (S.base == S.top)
		return 1;
	return 0;
}

int stackLength(SqStack S)
{
	int len = 0;
	if (S.top == S.base)
		return 0;
	while (S.top != S.base)
		len++, S.top--;
	return len;
}

int getTop(SqStack S, int& e)
{
	if (S.top == S.base)
		return 0;
	e = *(S.top - 1);
	return 1;
}

int push(SqStack& S, int e)
{
	if (S.top - S.base >= S.stackSize)
	{
		S.base = (int*)realloc(S.base, (S.stackSize + STACKINCREAMENT) * sizeof(int));
		if (!S.base)
			return 0;
		S.top = S.base + S.stackSize;
		S.stackSize += STACKINCREAMENT;
	}
	*S.top++ = e;
	return 1;
}

int pop(SqStack& S, int& e)
{
	if (S.top == S.base)
		return 0;
	e = *--S.top;
	return 1;
}

int stackTraverse(SqStack S, int(*visit)(int x))
{
	return 1;
}