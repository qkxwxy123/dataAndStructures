//用带行逻辑的矩阵存储，快速计算矩阵乘法
#define _CRT_SECURE_NO_WARNINGS
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

int RLmultSMatrix(RLSMatrix M, RLSMatrix N, RLSMatrix& Q)
{
	int tp, t;
	if (M.nu != N.mu)
		return 0;
	Q.mu = M.mu;
	Q.nu = N.nu;
	Q.tu = 0;
	if(M.tu * N.tu != 0)                //非零矩阵
	{
		for (int arow = 1; arow <= M.mu; arow++)  //扫描M的每一行
		{
			int atmp[MAXRC + 1] = { 0 };         //行值累加器
			Q.rpos[arow] = Q.tu + 1;
			if (arow < M.mu)
				tp = M.rpos[arow + 1];           //列上限
			else
				tp = M.tu + 1;                   //最后一行的最后一个元素位置为Q.tu
			for (int p = M.rpos[arow]; p < tp; p++)  //当前行在M中的位置p
			{
				int brow = M.data[p - 1].j;               //brow为对应行列
				if (brow < N.mu)
					t = N.rpos[brow + 1];             //t为N中下一行元素所在位置
				else
					t = N.tu + 1;
				for (int q = N.rpos[brow]; q < t; q++) //同步计算，以ccol记录是哪一列，最后一起压缩
				{
					int ccol = N.data[q - 1].j;        //乘积求和后Q中的列
					atmp[ccol] += M.data[p - 1].e * N.data[q - 1].e;
				}
			}

			for (int ccol = 1; ccol < Q.nu; ccol++)
			{
				if (atmp[ccol])
				{
					if (++Q.tu > MAXSIZE)
						return 0;
					Q.data[Q.tu - 1] = { arow, ccol, atmp[ccol] };
				}
			}
		}
	}
	return 1;
}

int initRLSMatrix(RLSMatrix& M)
{
	int i, j, e, count = 0, mu, nu;
	int num[MAXRC + 1] = { 0 };
	printf("请输入矩阵的行数，列数\n");
	scanf("%d %d", &mu, &nu);
	M.mu = mu;
	M.nu = nu;
	while (count <= MAXSIZE)
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

	for (int i = 0; i < M.tu; i++)
	{
		++num[M.data[i].i];
	}

	M.rpos[1] = 1;

	for (int i = 2; i <= M.mu; i++)
	{
		M.rpos[i] = M.rpos[i - 1] + num[i - 1];
	}
	return 1;
}

int showRLSMatrix(RLSMatrix M)
{
	int pi = 1, pj = 1, i = 0;
	while (pi <= M.mu && pj <= M.nu)
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
		else if ((i >= M.tu) || (M.data[i].i == pi && M.data[i].j > pj) || (M.data[i].i > pi))
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