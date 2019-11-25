#pragma once
#include "TSMatrix.h"
#define MAXRC 10000
typedef struct
{
	Triple data[MAXSIZE + 1];
	int mu, nu, tu;
	int rpos[MAXRC + 1];    //ÿ���ھ����е����λ��
}RLSMatrix;

int initRLSMatrix(RLSMatrix&);
int RLmultSMatrix(RLSMatrix, RLSMatrix, RLSMatrix&);
int showRLSMatrix(RLSMatrix);
