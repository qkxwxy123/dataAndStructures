#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#define INFINITY 30000
#define MAX_VERTEX_NUM 20
typedef struct
{
	int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	int vexnum, arcnum;
}Graph;

void createDJGraph(Graph&);
void shortestPathDij(Graph, int, int[][MAX_VERTEX_NUM], int[]);
void printShortestPath(Graph, int, int[][MAX_VERTEX_NUM], int[]);

void createDJGraph(Graph& G)
{
	int i, j, start, end, weight;
	printf("请输入顶点数和弧数：\n");
	scanf("%d %d", &G.vexnum, &G.arcnum);
	for (int i = 1; i <= G.vexnum; i++)
		for (int j = 1; j <= G.vexnum; j++)
			G.arcs[i][j] = INFINITY;
	printf("请输入边的起点，终点和权值\n");
	int u, v, w;
	for (int i = 1; i <= G.arcnum; i++)
	{
		scanf("%d %d %d", &u, &v, &w);
		G.arcs[u][v] = w;
	}
}

void shortestPathDij(Graph G, int v0, int P[][MAX_VERTEX_NUM], int D[]) //最短路线P和路径长度D
{
	int i, j, w, v;
	bool fnl[MAX_VERTEX_NUM]; //fnl[v]为true表示找到v0到v的最短路径
	int minn;
	for (v = 1; v <= G.vexnum; v++)      //初始化
	{
		fnl[v] = 0;
		D[v] = G.arcs[v0][v];
		for (i = 0; i <= G.vexnum; i++)
			P[v][i] = 0;
	}
	D[v0] = 0, fnl[v0] = 1;
	for (int i = 1; i <= G.vexnum; i++)    //从v0开始,找其余vexnum-1个点
	{
		v = 0;
		minn = INFINITY;
		for (w = 1; w <= G.vexnum; w++)      //找到v0到其他点的最小值
		{
			if (!fnl[w] && (D[w] < minn))
			{
				v = w;
				minn = D[w];
			}
		}
		if (!v)
			break;
		fnl[v] = 1;
		for (j = 0; P[v][j] != 0; j++);      //找路径
		P[v][j] = v;                         //存储路径的下一个结点v
		for(w = 0; w <= G.vexnum; w++)       //更新
			if (!fnl[w] && (minn + G.arcs[v][w]) < D[w])
			{
				D[w] = minn + G.arcs[v][w];
				for (j = 0; P[v][j] != 0; j++)
					P[w][j] = P[v][j];
			}
	}
}

void printShortestPath(Graph G, int v0, int P[][MAX_VERTEX_NUM], int D[])
{
	int v, j;
	printf("The shortest path from Vertex %d to the other Vertex:\n", v0);
	for (v = 1; v <= G.vexnum; v++)
	{
		if (P[v][0] == 0)
			continue; //无通路
		printf("%-4d", D[v]);
		printf("%d->", v0);
		for (int j = 0; P[v][j] != 0; j++)
			printf("%d->", P[v][j]);
		printf("\b\b  \n");
	}
}

