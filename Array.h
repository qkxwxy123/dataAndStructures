#pragma once
typedef struct {
	int* base;                  //����Ԫ�ػ�ַ   ��InitArray����
	int dim;                    //����ά��
	int* bounds;                //����ά���ַ   ��InitArray����
	int* constants;             //����ӳ����������ַ����InitArray����
}Array;

int initArray(Array& A, int dim, ...);
int destroyArray(Array& A);
int value(Array A, ...);
int assign(Array& A, int e, ...);