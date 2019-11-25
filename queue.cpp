#include "malloc.h"

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

int initQueue(LinkQueue& Q)
{
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.front)
		return 0;
	Q.front->next = NULL;
	return 1;
}

int destroyQueue(LinkQueue& Q)
{
	while (Q.front)
	{
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	return 1;
}

int clearQueue(LinkQueue& Q)
{
	free(Q.front);
	free(Q.rear);
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.front)
		return 0;
	Q.front->next = NULL;
	return 1;
}

int queueEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear)
		return 1;
	return 0;
}

int queueLength(LinkQueue Q)
{
	if (Q.front == Q.rear)
		return 0;
	QueuePtr temp = Q.front->next;
	int len = 0;
	while (temp != Q.rear)
		temp = temp->next, len++;
	len++;
	return len;
}

int getHead(LinkQueue Q, int& e)
{
	if (Q.front == Q.rear)
		return 0;
	e = Q.front->next->data;
	return 1;
}

int enQueue(LinkQueue& Q, int e)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)
		return 0;
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return 1;
}

int deQueue(LinkQueue& Q, int& e)
{
	if (Q.front == Q.rear)
		return 0;
	QueuePtr p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.front = Q.rear;
	return 1;
}

int queueTraverse(LinkQueue Q, int (*visit)(int x))
{
	return 1;
}