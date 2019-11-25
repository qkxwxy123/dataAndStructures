#pragma once
#include "stdio.h"
#include "stdlib.h"
#define MAXQSIZE 30
#define MAX_VERTEX_NUM 20
#include "string.h"
typedef struct ArcNode
{
	int adjvex;            //�û���ָ��Ķ����λ��
	struct ArcNode* nextarc;  //ָ����һ������ָ��
	int* info;
}ArcNode;

typedef struct VNode
{
	int data;
	ArcNode* firstarc;   //ָ���һ�������ö���Ļ���ָ��
}VNode, AdjList[MAX_VERTEX_NUM];

typedef struct
{
	AdjList vertices;
	int vexnum, arcnum; //ͼ�ĵ�ǰ�������ͻ���
	int kind;           //0����ͼ��1����ͼ
}ALGraph;

typedef struct
{
	int elem[MAXQSIZE];
	int front;
	int rear;
}SqQueue;

void createGraph(ALGraph&);
void dfsTraverse(ALGraph);
void dfs(ALGraph, int);
void bfsTraverse(ALGraph);
void init(SqQueue&);
bool queueEmpty(SqQueue);
bool enQueue(SqQueue&, int);
bool deQueue(SqQueue&, int&);
int firstAdjVex(ALGraph, int);  //��ͼ��ĳ������ĵ�һ���ٽӶ���
int nextAdjVex(ALGraph, int, int);   //��ĳһ������¸�����