#include "stdio.h"
#include "stdarg.h"
#include "malloc.h"
#define MAX_ARRAY_DIM 8         //����ά�����Ϊ8

typedef struct {
	int* base;                  //����Ԫ�ػ�ַ   ��InitArray����
	int dim;                    //����ά��
	int* bounds;                //����ά���ַ   ��InitArray����
	int* constants;             //����ӳ����������ַ����InitArray����
}Array;

int initArray(Array& A, int dim, ...);     //������Ӧ����A������ok
int destroyArray(Array& A);                //��������
int value(Array A, ...);                   //��A��nά���飬�����n���±꣬���±겻Խ�磬����Ԫ��ֵ
int assign(Array& A, int e, ...);          //��ֵ
int locate(Array, va_list, int&);          //��Ԫ����A�е���Ե�ַ
 
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
		A.bounds[i] = va_arg(ap, int);           //bounds����һά�೤
		if (A.bounds[i] < 0)
			return -1;
		eletotal *= A.bounds[i];
	}
	va_end(ap);
	
	A.base = (int*)malloc(eletotal * sizeof(int));
	if (!A.base)
		return 0;
	A.constants = (int*)malloc(dim * sizeof(int));          //��ά���м����ռ�
	if (!A.constants)
		return 0;
	A.constants[dim - 1] = 1;                                //L  �洢��Ԫ
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

int locate(Array A, va_list ap, int& off) //��Ԫ����A�е���Ե�ַ
{
	off = 0;
	for (int i = 0; i < A.dim; i++)
	{
		int ind = va_arg(ap, int);
		if (ind < 0 || ind >= A.bounds[i])
			return 0;
		off += A.constants[i] * ind;        //�ڼ�ά����ȡ������Ԫ
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