#pragma once
typedef struct QNode {
	int data;
	struct QNode* next;
}QNode, * QueuePtr;

typedef struct {
	QueuePtr front;     //��ͷָ��
	QueuePtr rear;      //βָ��
}LinkQueue;

int initQueue(LinkQueue&);
int destroyQueue(LinkQueue&);
int clearQueue(LinkQueue&);
int queueEmpty(LinkQueue);
int queueLength(LinkQueue);
int getHead(LinkQueue, int&);
int enQueue(LinkQueue&, int);  //�����β
int deQueue(LinkQueue&, int&); //���в��գ�ɾ����ͷ��e����
int queueTraverse(LinkQueue, int (*visit)(int));