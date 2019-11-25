#define _CRT_SECURE_NO_WARNINGS
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

bool vis2[MAX_VERTEX_NUM];

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

void createGraph(ALGraph& G)
{
	printf("请输入图的种类：\n1-有向图，2-无向图\n");
	scanf("%d", &G.kind);
	printf("请输入图的节点数和弧数\n");
	scanf("%d %d", &G.vexnum, &G.arcnum);
	int i;
	int start, end;
	ArcNode* s;
	for (int i = 1; i <= G.vexnum; i++)
		G.vertices[i] = { 0, NULL };
	for (int i = 1; i <= G.arcnum; i++)
	{
		scanf("%d %d", &start, &end);
		s = (ArcNode*)malloc(sizeof(ArcNode));
		s->nextarc = G.vertices[start].firstarc;
		s->adjvex = end;
		G.vertices[start].firstarc = s;
		if (G.kind == 0)
		{
			s = (ArcNode*)malloc(sizeof(ArcNode));
			s->nextarc = G.vertices[end].firstarc;
			s->adjvex = start;
			G.vertices[end].firstarc = s;
		}
	}
}

void dfsTraverse(ALGraph G)
{
	int i;
	printf("dfsTraverse:\n");
	memset(vis2, 0, sizeof(vis2));
	for (int i = 1; i <= G.vexnum; i++)
	{
		if (!vis2[i])
			dfs(G, i);
	}
	printf("\b\b   \n");
}

void dfs(ALGraph G, int e)
{
	int w;
	vis2[e] = 1;
	printf("%d->", e);
	for (w = firstAdjVex(G, e); w; w = nextAdjVex(G, e, w))
	{
		if (!vis2[w])
			dfs(G, w);
	}
}

void bfsTraverse(ALGraph G)
{
	int i, u, w;
	SqQueue q;
	init(q);
	printf("bfsTraverse:\n");
	memset(vis2, 0, sizeof(vis2));
	for (int i = 1; i <= G.vexnum; i++)
	{
		if (!vis2[i])
		{
			vis2[i] = 1;
			printf("%d->", i);
			enQueue(q, i);
			while (!queueEmpty(q))
			{
				deQueue(q, u);
				for (w = firstAdjVex(G, u); w; w = nextAdjVex(G, u, w))
				{
					if (!vis2[w])
					{
						vis2[w] = 1;
						printf("%d->", w);
						enQueue(q, w);
					}
				}
			}
		}
	}
	printf("\b\b   \n");
}

void init(SqQueue& q)
{
	q.front = q.rear = 0;
}



int firstAdjVex(ALGraph G, int e)
{
	if (!G.vertices[e].firstarc)
		return 0;
	return G.vertices[e].firstarc->adjvex;
}

int nextAdjVex(ALGraph G, int v, int w)
{
	ArcNode* p;
	p = G.vertices[v].firstarc;
	while (p->adjvex != w)
		p = p->nextarc;
	if (p->nextarc == NULL)
		return 0;
	else
		return p->nextarc->adjvex;
}

bool queueEmpty(SqQueue q)
{
	if (q.front == q.rear)
		return 1;
	else
		return 0;
}

bool enQueue(SqQueue& q, int e)
{
	if ((q.rear + 1) % MAXQSIZE == q.front)
		return 0;
	q.elem[q.rear] = e;
	q.rear = (q.rear + 1) % MAXQSIZE;
	return 1;
}

bool deQueue(SqQueue& q, int& ch)
{
	if (q.front == q.rear)
		return 0;
	ch = q.elem[q.front];
	q.front = (q.front + 1) % MAXQSIZE;
	return 1;
}