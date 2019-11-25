#define _CRT_SECURE_NO_WARNINGS
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


int createSMatrix(TSMatrix& M)
{
	int i, j, e, count = 0, mu, nu;
	printf("请输入矩阵的行数，列数\n");
	scanf("%d %d", &mu, &nu);
	M.mu = mu;
	M.nu = nu;
	while (count <=MAXSIZE)
	{
		printf("请输入矩阵的元素 i，j，e表示行列值， 按-1结束\n");
		scanf("%d", &i);
		if (i == -1)
			break;
		scanf("%d %d", &j, &e);
		if (i <= 0 || j <= 0)
		{
			printf("坐标不合法！\n");
			continue;
		}
		M.data[count].i = i;
		M.data[count].j = j;
		M.data[count].e = e;
		count++;
	}
	M.tu = count;
	return 1;
}

int destroySMatrix(TSMatrix& M)
{
	M.mu = M.nu = M.tu = 0;
	return 1;
}

int printSMatrix(TSMatrix M)
{
	int pi = 1, pj = 1, i = 0;
	while(pi <= M.mu && pj <= M.nu)
	{
		if (M.data[i].i == pi && M.data[i].j == pj)
		{
			printf("%d ", M.data[i].e);
			pj++;
			i++;
			if (pj > M.nu)
			{
				pj = 1;
				pi++;
				printf("\n");
			}
		}
		else if((i >= M.tu) || (M.data[i].i == pi && M.data[i].j > pj) || (M.data[i].i > pi))
		{
			if (i < M.tu)
			{
				if (M.data[i].i == pi && M.data[i].j > pj)
				{
					while (M.data[i].i == pi && M.data[i].j > pj)
					{

						printf("0 ");
						pj++;
						if (pj > M.nu)
						{
							pj = 1;
							pi++;
							printf("\n");
						}
					}
				}
				else if (M.data[i].i >= pi)
				{
					while (M.data[i].i > pi)
					{

						printf("0 ");
						pj++;
						if (pj > M.nu)
						{
							pj = 1;
							pi++;
							printf("\n");
						}
					}
				}
			}
			else
			{
				while (pi <= M.mu && pj <= M.nu)
				{
					pj++;
					printf("0 ");
					if (pj > M.nu)
					{
						pj = 1;
						pi++;
						printf("\n");
					}
				}
			}
		}
	}
	printf("---------over-------\n");
	return 1;
}

int copySMatrix(TSMatrix M, TSMatrix& T)
{
	T.mu = M.mu;
	T.nu = M.nu;
	T.tu = M.tu;
	for (int i = 0; i < M.tu; i++)
		T.data[i] = M.data[i];
	return 1;
}

int addSMatrix(TSMatrix M, TSMatrix T, TSMatrix& Q)
{
	bool flag = 1;
	int count = 0;
	Q.mu = M.mu;
	Q.nu = M.nu;
	for (int i = 0; i < T.tu; i++)
	{
		flag = 1;
		for (int j = 0; j < M.tu; j++)
		{
			if (T.data[i].i == M.data[j].i && T.data[i].j == M.data[j].j)
			{
				T.data[i].e += M.data[j].e;
				if (T.data[i].e == 0)
				{
					for (int t = j; t < T.tu - 1; t++)
					{
						T.data[t].i = T.data[t + 1].i;
						T.data[t].j = T.data[t + 1].j;
						T.data[t].e = T.data[t + 1].e;
					}
					T.tu--;
				}
				flag = 0;
				break;
			}
		}

		if (flag)
		{
			int k = T.tu;
			T.data[k].i = M.data[i].i;
			T.data[k].j = M.data[i].j;
			T.data[k].e = M.data[i].e;
			T.tu++;
		}

		for (int i = 0; i < T.tu - 1; i++)
		{
			for (int j = i; j < T.tu; j++)
			{
				if (T.data[i].i > T.data[j].i)
				{
					int tmp = T.data[i].i;
					T.data[i].i = T.data[j].i;
					T.data[j].i = tmp;
					tmp = T.data[i].j;
					T.data[i].j = T.data[j].j;
					T.data[j].j = tmp;
					tmp = T.data[i].e;
					T.data[i].e = T.data[j].e;
					T.data[j].e = tmp;
				}
			}
		}

		for (int i = 0; i < T.tu - 1; i++)
		{
			for (int j = 0; j < T.tu + 1; j++)
			{
				if (T.data[i].i == T.data[j].i && T.data[i].j == T.data[j].j)
				{
					int tmp = T.data[i].j;
					T.data[i].j = T.data[j].j;
					T.data[j].j = tmp;
					tmp = T.data[i].e;
					T.data[i].e = T.data[j].e;
					T.data[j].e = tmp;
				}
			}
		}
	}

	copySMatrix(T, Q);
	return 1;
}

int subtMatrix(TSMatrix T, TSMatrix M, TSMatrix& Q)
{
	bool flag = 1;
	int count = 0;
	Q.mu = M.mu;
	Q.nu = M.nu;
	for (int i = 0; i < T.tu; i++)
	{
		flag = 1;
		for (int j = 0; j < M.tu; j++)
		{
			if (T.data[i].i == M.data[j].i && T.data[i].j == M.data[j].j)
			{
				T.data[i].e -= M.data[j].e;
				if (T.data[i].e == 0)
				{
					for (int t = j; t < T.tu - 1; t++)
					{
						T.data[t].i = T.data[t + 1].i;
						T.data[t].j = T.data[t + 1].j;
						T.data[t].e = T.data[t + 1].e;
					}
					T.tu--;
				}
				flag = 0;
				break;
			}
		}

		if (flag)
		{
			int k = T.tu;
			T.data[k].i = M.data[i].i;
			T.data[k].j = M.data[i].j;
			T.data[k].e = M.data[i].e;
			T.tu++;
		}

		for (int i = 0; i < T.tu - 1; i++)
		{
			for (int j = i; j < T.tu; j++)
			{
				if (T.data[i].i > T.data[j].i)
				{
					int tmp = T.data[i].i;
					T.data[i].i = T.data[j].i;
					T.data[j].i = tmp;
					tmp = T.data[i].j;
					T.data[i].j = T.data[j].j;
					T.data[j].j = tmp;
					tmp = T.data[i].e;
					T.data[i].e = T.data[j].e;
					T.data[j].e = tmp;
				}
			}
		}

		for (int i = 0; i < T.tu - 1; i++)
		{
			for (int j = 0; j < T.tu + 1; j++)
			{
				if (T.data[i].i == T.data[j].i && T.data[i].j == T.data[j].j)
				{
					int tmp = T.data[i].j;
					T.data[i].j = T.data[j].j;
					T.data[j].j = tmp;
					tmp = T.data[i].e;
					T.data[i].e = T.data[j].e;
					T.data[j].e = tmp;
				}
			}
		}
	}

	copySMatrix(T, Q);
	return 1;
}

int mulSMatrix(TSMatrix M, TSMatrix T, TSMatrix& Q)
{
	int sum = 0, tagi = 1, tagj = 1, count = 0;
	for (int i = 0; i < M.tu; i++)
	{
		if (M.data[i].i != tagi)
		{
			tagi = M.data[i].i;
			sum = 0;
			tagj = 1;
		}
		while (tagj <= T.nu)
		{
			for (int j = 0; j < T.tu; j++)
			{
				if (M.data[i].j == T.data[j].i && T.data[j].j == tagj)
				{
					sum += M.data[i].e * T.data[j].e;
				}
			}
			Q.data[count].e = sum;
			Q.data[count].i = tagi;
			Q.data[count++].j = tagj;
			sum = 0;
			tagj++;
		}
	}
	return 1;
}

int transposeSMatrix(TSMatrix M, TSMatrix& T)
{
	T.mu = M.nu;
	T.nu = M.mu;
	T.tu = M.tu;
	if (M.tu)
	{
		int q = 1;
		for (int col = 1; col <= M.nu; col++)
		{
			for (int p = 1; p <= M.tu; p++)
			{
				if (M.data[p].j == col)
				{
					T.data[q].i = M.data[p].j;
					T.data[q].j = M.data[p].i;
					T.data[q].e = M.data[p].e;
					++q;
				}
			}
		}
	}
	return 1;
}

int fastTranseposeSMatrix(TSMatrix M, TSMatrix& T)
{
	T.mu = M.nu;
	T.nu = M.mu;
	T.tu = M.tu;
	int num[10000] = { 0 };
	int cpot[10000] = { 0 };
	if (T.tu)
	{
		for (int t = 1; t <= M.tu; t++)
			++num[M.data[t].j];
		cpot[1] = 1;
		for (int col = 2; col <= T.nu; col++)
			cpot[col] = cpot[col - 1] + num[col - 1];
		for (int p = 1; p <= M.tu; p++)
		{
			int col = M.data[p].j;
			int q = cpot[col];
			T.data[q].i = M.data[p].j;
			T.data[q].j = M.data[p].i;
			T.data[q].e = M.data[p].e;
			cpot[col]++;          //col列有效元在M中的位置，每次copy完往后加
		}
	}
	return 1;
}