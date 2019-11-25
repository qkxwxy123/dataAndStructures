#include "stdio.h"
#include "stdarg.h"
#include "malloc.h"
#define MAX_ARRAY_DIM 8         //数组维数最大为8

typedef struct {
	int* base;                  //数组元素基址   由InitArray分配
	int dim;                    //数组维数
	int* bounds;                //数组维界基址   由InitArray分配
	int* constants;             //数组映像函数常量基址，由InitArray分配
}Array;

int initArray(Array& A, int dim, ...);     //构造相应数组A，返回ok
int destroyArray(Array& A);                //销毁数组
int value(Array A, ...);                   //若A是n维数组，随后是n个下标，若下标不越界，返回元素值
int assign(Array& A, int e, ...);          //赋值
int locate(Array, va_list, int&);          //该元素在A中的相对地址
 
int initArray(Array& A, int dim, ...)
{
	int eletotal = 1;
	if (dim < 1 || dim > MAX_ARRAY_DIM)
		return 0;
	A.dim = dim;
	A.bounds = (int *)malloc(dim * sizeof(int));
	if (!A.bounds)
		return 0;
	va_list ap;
	va_start(ap, dim);
	for (int i = 0; i < dim; i++)
	{
		A.bounds[i] = va_arg(ap, int);           //bounds存这一维多长
		if (A.bounds[i] < 0)
			return -1;
		eletotal *= A.bounds[i];
	}
	va_end(ap);
	
	A.base = (int*)malloc(eletotal * sizeof(int));
	if (!A.base)
		return 0;
	A.constants = (int*)malloc(dim * sizeof(int));          //几维就有几个空间
	if (!A.constants)
		return 0;
	A.constants[dim - 1] = 1;                                //L  存储单元
	for (int i = dim - 2; i >= 0; i--)
		A.constants[i] = A.bounds[i + 1] * A.constants[i + 1];  // c[i-1] = c[i] * b[i]
	return 1;
}

int destroyArray(Array& A)
{
	if (!A.base)
		return 0;
	free(A.base);
	if (!A.bounds)
		return 0;
	free(A.bounds);
	if (!A.constants)
		return 0;
	free(A.constants);
	return 1;
}

int locate(Array A, va_list ap, int& off) //该元素在A中的相对地址
{
	off = 0;
	for (int i = 0; i < A.dim; i++)
	{
		int ind = va_arg(ap, int);
		if (ind < 0 || ind >= A.bounds[i])
			return 0;
		off += A.constants[i] * ind;        //第几维往后取几个单元
	}
	return 1;
}

int value(Array A, ...)
{
	int result, off;
	va_list ap;
	va_start(ap, A);
	if ((result = locate(A, ap, off)) <= 0)
		return result;
	return *(A.base + off);
}

int assign(Array& A, int e, ...)
{
	int result;
	int off;
	va_list ap;
	va_start(ap, e);
	if ((result = locate(A, ap, off)) <= 0)
		return result;
	*(A.base + off) = e;
	return 1;
}