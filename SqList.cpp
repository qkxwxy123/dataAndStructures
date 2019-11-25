#include "malloc.h"
#define LIST_INIT_SIZE 100
#define LISTINCREAMENT 10
typedef struct {
	int* elem;
	int length;
	int listSize;
}SqList;



int visit(int);

int initList(SqList&);
int destroyList(SqList);
int clearList(SqList&);
int listEmpty(SqList);
int listLength(SqList);
int getElem(SqList, int, int&);
int locateElem(SqList, int, int(*cmp)(int, int));
int priorElem(SqList, int , int& );
int nextElem(SqList, int, int&);
int listInsert(SqList&, int, int);
int listDelete(SqList&, int, int&);
int listTraverse(SqList, int(*visit)(int));

int initList(SqList& L)
{
	L.elem = (int*)malloc(LIST_INIT_SIZE * sizeof(int));
	if (!L.elem)
		return 0;
	L.length = 0;
	L.listSize = LIST_INIT_SIZE;
	return 1;
}

int destroyList(SqList& L)
{
	free(L.elem);
	L.length = 0;
	L.listSize = 0;
	return 1;
}

int clearList(SqList& L)
{
	free(L.elem);
	L.elem = (int*)malloc(LIST_INIT_SIZE * sizeof(int));
	if (!L.elem)
		return 0;
	L.length = 0;
	L.listSize = LIST_INIT_SIZE;
	return 1;
}

int listEmpty(SqList L)
{
	if (L.length == 0)
		return 1;
	else
		return 0;
}

int listLength(SqList L)
{
	return L.length;
}

int getElem(SqList L, int i, int& e)
{
	int loc = 1;
	int* p = L.elem;
	while (loc <= i)
		loc++, p++;
	e = *p;
	return 1;
}

int locateElem(SqList L, int e, int (*cmp)(int , int))
{
	int i = 0;
	int* p = L.elem;
	while (i < L.length && !(cmp)(*p++, e))i++;
	if (i <= L.length)
		return i;
	return 0;
}

int priorElem(SqList L, int cur_e, int& pre_e)
{
	int* p = L.elem;
	int pre = *p;
	int i = 1;
	while (i < L.length && *p != cur_e)
	{
		pre_e = pre;
		pre = *p;
		p++;
		i++;
	}
	if (i >= L.length)
		return 0;
	return 1;
}

int nextElem(SqList L, int cur_e, int& next_e)
{
	int* p = L.elem;
	int i = 1;
	while (i < L.length && *p != cur_e)
	{
		p++;
		i++;
	}
	if (*p == cur_e)
		p++;
	next_e = *p;
	if (i >= L.length)
		return 0;
	return 1;
}

int listInsert(SqList& L, int i, int e)
{
	if (i > L.length + 1 || i < 1)
		return 0;
	if (L.length >= L.listSize)
	{
		int* newBase = (int*)realloc(L.elem, (L.listSize + LISTINCREAMENT) * sizeof(int));
		if (!newBase)
			return 0;
		L.elem = newBase;
		L.listSize += LISTINCREAMENT;
	}
	int* q = &(L.elem[i - 1]), * p;
	for(p = &(L.elem[L.length - 1]); p >= q; --p)
		* (p + 1) = *p;
	*q = e;
	L.length++;
	return 1;
}

int listDelete(SqList& L, int i, int& e)
{
	if (i < 1 || i > L.length)
		return 0;
	int* p = &(L.elem[i - 1]);
	e = *p;
	int* q = L.elem + L.length - 1;
	for (p++; p <= q; p++)
		*(p - 1) = *p;
	L.length--;
	return 1;
}

int listTraverse(SqList L, int (*visit)(int ex))
{
	int* p = L.elem;
	int* q = L.elem + L.length - 1;
	for (; p <= q; p++)
		if (!visit(*p))
			return 0;
	return 1;
}