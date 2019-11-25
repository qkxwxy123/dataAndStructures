#pragma once
typedef struct {
	int* elem;
	int length;
	int listSize;
}SqList;


int initList(SqList&);
int destroyList(SqList);
int clearList(SqList&);
int listEmpty(SqList);
int listLength(SqList);
int getElem(SqList, int, int&);
int locateElem(SqList, int, int(*cmp)(int, int));
int priorElem(SqList, int, int&);
int nextElem(SqList, int, int&);
int listInsert(SqList&, int, int);
int listDelete(SqList&, int, int&);
int listTraverse(SqList, int(*visit)(int));