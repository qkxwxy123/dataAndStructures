/*数组表示图*/
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#define INFINITY 0x7fffffff
#define MAX_VERTEX_NUM 20
typedef struct ArcCell
{
	int adj;                                                 //对无权图，1或0表示相邻与否，对于带权图，为权值
	int* info;                                               //弧相关信息
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];         //实际存储时若不用相关信息，可存成n*n的数组
typedef struct
{
	int vexs[MAX_VERTEX_NUM];//顶点向量，存储顶点序号
	AdjMatrix arcs;			 //临接矩阵
	int vexnum, arcnum;      //图的当前顶点数和弧数
	int kind;                //1-有向图，2-有向网，3-无向图，4-无向网
}MGraph;

int createGraph(MGraph&);
int createUDN(MGraph&);//构造无向网
int createUDG(MGraph&);//构造无向图
int createDG(MGraph&);//构造有向图
int createDN(MGraph&); //构造有向网
int locateVex(MGraph, int);

int createGraph(MGraph& G)
{
	printf("请输入图的类型：\nDG-有向图，DN-有向网，UDG-无向图，UDN-无向网\n");
	scanf("%d", &G.kind);
	switch (G.kind)
	{
	case 1:
		return createDG(G);
	case 2:
		return createDN(G);
	case 3:
		return createUDG(G);
	case 4:
		return createUDN(G);
	default:
		return 0;
	}
}

int createUDN(MGraph& M)
{
	int IncInfo;//=0表示节点不含其他信息
	scanf("%d %d %d", &M.vexnum, &M.arcnum, &IncInfo);
	for (int i = 0; i < M.vexnum; i++)
		scanf("%d", &M.vexs[i]);
	for (int i = 0; i < M.vexnum; i++)
		for (int j = 0; j < M.vexnum; j++)
			M.arcs[i][j] = { INFINITY, NULL };
	for (int k = 0; k < M.arcnum; k++)
	{
		int v1, v2, w, i, j;
		scanf("%d %d %d", &v1, &v2, &w);
		i = locateVex(M, v1), j = locateVex(M, v2);
		M.arcs[i][j].adj = w;
		if (IncInfo)
			scanf("%d", M.arcs[i][j].info);
		M.arcs[j][i] = M.arcs[i][j];
	}
	return 1;
}

int createUDG(MGraph& G)
{
	int IncInfo;
	scanf("%d %d %d", &G.vexnum, &G.arcnum, &IncInfo);
	for (int i = 0; i < G.vexnum; i++)
		scanf("%d", &G.vexs[i]);
	for (int i = 0; i < G.vexnum; i++)
		for (int j = 0; j < G.vexnum; j++)
			G.arcs[i][j] = { INFINITY, NULL };
	for (int k = 0; k < G.arcnum; k++)
	{
		int v1, v2, i, j;
		scanf("%d %d", &v1, &v2);
		i = locateVex(G, v1), j = locateVex(G, v2);
		G.arcs[i][j].adj = 1;
		if (IncInfo)
			scanf("%d", G.arcs[i][j].info);
		G.arcs[i][j] = G.arcs[j][i];
	}
	return 1;
}

int createDG(MGraph& G)
{
	int IncInfo;
	scanf("%d %d %d", &G.vexnum, &G.arcnum, &IncInfo);
	for (int i = 0; i < G.vexnum; i++)
		scanf("%d", &G.vexs[i]);
	for (int i = 0; i < G.vexnum; i++)
		for (int j = 0; j < G.vexnum; j++)
			G.arcs[i][j] = { INFINITY, NULL };
	for (int k = 0; k < G.arcnum; k++)
	{
		int v1, v2, i, j;
		scanf("%d %d", &v1, &v2);
		i = locateVex(G, v1), j = locateVex(G, v2);
		if (IncInfo)
			scanf("%d", G.arcs[i][j].info);
		G.arcs[i][j].adj = 1;
	}
	return 1;
}

int createDN(MGraph& G)
{
	int IncInfo;
	scanf("%d %d %d", &G.vexnum, &G.arcnum, &IncInfo);
	for (int i = 0; i < G.vexnum; i++)
		scanf("%d", &G.vexs[i]);
	for (int i = 0; i < G.vexnum; i++)
		for (int j = 0; j < G.vexnum; j++)
			G.arcs[i][j] = { INFINITY, NULL };
	for (int k = 0; k < G.arcnum; k++)
	{
		int v1, v2, i, j, w;
		scanf("%d %d %d", &v1, &v2, &w);
		i = locateVex(G, v1), j = locateVex(G, v2);
		if (IncInfo)
			scanf("%d", G.arcs[i][j].info);
		G.arcs[i][j].adj = w;
	}
	return 1;
}

int locateVex(MGraph G, int u)
{
	for (int i = 0; i < G.vexnum; i++)
		if (G.vexs[i] == u)
			return i;
	return -1;
}
