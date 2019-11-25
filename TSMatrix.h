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

int createSMatrix(TSMatrix&); //创建稀疏矩阵
int destroySMatrix(TSMatrix&); // 销毁
int printSMatrix(TSMatrix); //输出
int copySMatrix(TSMatrix, TSMatrix&); //复制
int addSMatrix(TSMatrix, TSMatrix, TSMatrix&); // 矩阵求和
int subtMatrix(TSMatrix, TSMatrix, TSMatrix&); //矩阵求差
int multSMatrix(TSMatrix, TSMatrix, TSMatrix&); //矩阵乘积
int transposeSMatrix(TSMatrix, TSMatrix&); //求转置
int fastTransposeSMatrix(TSMatrix, TSMatrix&); //快速转置