/*�����ʾͼ*/
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#define INFINITY 0x7fffffff
#define MAX_VERTEX_NUM 20
typedef struct ArcCell
{
	int adj;                                                 //����Ȩͼ��1��0��ʾ������񣬶��ڴ�Ȩͼ��ΪȨֵ
	int* info;                                               //�������Ϣ
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];         //ʵ�ʴ洢ʱ�����������Ϣ���ɴ��n*n������
typedef struct
{
	int vexs[MAX_VERTEX_NUM];//�����������洢�������
	AdjMatrix arcs;			 //�ٽӾ���
	int vexnum, arcnum;      //ͼ�ĵ�ǰ�������ͻ���
	int kind;                //1-����ͼ��2-��������3-����ͼ��4-������
}MGraph;

int createGraph(MGraph&);
int createUDN(MGraph&);//����������
int createUDG(MGraph&);//��������ͼ
int createDG(MGraph&);//��������ͼ
int createDN(MGraph&); //����������
int locateVex(MGraph, int);

int createGraph(MGraph& G)
{
	printf("������ͼ�����ͣ�\nDG-����ͼ��DN-��������UDG-����ͼ��UDN-������\n");
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
	int IncInfo;//=0��ʾ�ڵ㲻��������Ϣ
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
