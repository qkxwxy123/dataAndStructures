#pragma once
#include "stdio.h"
#include "stdlib.h"
#define MAXQSIZE 30
#define MAX_VERTEX_NUM 20
#include "string.h"
typedef struct ArcNode
{
	int adjvex;            //该弧所指向的顶点的位置
	struct ArcNode* nextarc;  //指向下一条弧的指针
	int* info;
}ArcNode;

typedef struct VNode
{
	int data;
	ArcNode* firstarc;   //指向第一条依赖该顶点的弧的指针
}VNode, AdjList[MAX_VERTEX_NUM];

typedef struct
{
	AdjList vertices;
	int vexnum, arcnum; //图的当前顶点数和弧数
	int kind;           //0无向图，1有向图
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
int firstAdjVex(ALGraph, int);  //求图中某个顶点的第一个临接顶点
int nextAdjVex(ALGraph, int, int);   //求某一顶点的下个顶点