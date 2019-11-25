#pragma once
#include "stdio.h"
#define MAXSIZE 12500
typedef struct
{
	int i, j;
	int e;
}Triple;

typedef struct
{
	Triple data[MAXSIZE + 1];
	int mu, nu, tu;
}TSMatrix;

int createSMatrix(TSMatrix&); //����ϡ�����
int destroySMatrix(TSMatrix&); // ����
int printSMatrix(TSMatrix); //���
int copySMatrix(TSMatrix, TSMatrix&); //����
int addSMatrix(TSMatrix, TSMatrix, TSMatrix&); // �������
int subtMatrix(TSMatrix, TSMatrix, TSMatrix&); //�������
int multSMatrix(TSMatrix, TSMatrix, TSMatrix&); //����˻�
int transposeSMatrix(TSMatrix, TSMatrix&); //��ת��
int fastTransposeSMatrix(TSMatrix, TSMatrix&); //����ת��