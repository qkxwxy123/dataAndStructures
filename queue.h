#pragma once
typedef struct QNode {
	int data;
	struct QNode* next;
}QNode, * QueuePtr;

typedef struct {
	QueuePtr front;     //队头指针
	QueuePtr rear;      //尾指针
}LinkQueue;

int initQueue(LinkQueue&);
int destroyQueue(LinkQueue&);
int clearQueue(LinkQueue&);
int queueEmpty(LinkQueue);
int queueLength(LinkQueue);
int getHead(LinkQueue, int&);
int enQueue(LinkQueue&, int);  //插入队尾
int deQueue(LinkQueue&, int&); //队列不空，删除队头，e返回
int queueTraverse(LinkQueue, int (*visit)(int));