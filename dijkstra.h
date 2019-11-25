#pragma once
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