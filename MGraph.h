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