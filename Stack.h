#pragma once
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
int stackTraverse(SqStack, int(*visit)(int));
