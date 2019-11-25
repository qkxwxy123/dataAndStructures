#pragma once
#include "TSMatrix.h"
#define MAXRC 10000
typedef struct
{
	Triple data[MAXSIZE + 1];
	int mu, nu, tu;
	int rpos[MAXRC + 1];    //每行在矩阵中的相对位置
}RLSMatrix;

int initRLSMatrix(RLSMatrix&);
int RLmultSMatrix(RLSMatrix, RLSMatrix, RLSMatrix&);
int showRLSMatrix(RLSMatrix);
