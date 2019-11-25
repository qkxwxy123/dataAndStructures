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