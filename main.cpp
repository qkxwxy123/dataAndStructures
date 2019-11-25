#define _CRT_SECURE_NO_WARNINGS
#include "SqList.h"
#include "stdio.h"
#include "LinkList.h"
#include "malloc.h"
#include "cKMP.h"
#include "Stack.h"
#include "queue.h"
#include "BiTree.h"
#include "Array.h"
#include "TSMatrix.h"
#include "RLSMatrix.h"
#include "MGraph.h"
#include "ALGraph.h"
#include "dijkstra.h"

int cmp(int x, int y)
{
	return (x == y) ? 1 : 0;
}

int visit(int x)
{
	return 1;
}

void showLq(LinkList Lq)            //add &&&&&
{
	Link t2 = Lq.head;
	printf("�����Ԫ������Ϊ��");
	while (t2 != NULL)
	{
		printf("%d ", t2->data);
		t2 = t2->next;
	}
	printf("\n");
}

void SqListTest()
{
	/*���Ա����*/
	SqList L;
	int e;
	initList(L);
	clearList(L);
	printf("���Ա��Ƿ�Ϊ��?%d\n", listEmpty(L));
	printf("���Ա�ĳ���Ϊ:%d\n", listLength(L));
	listInsert(L, 1, 5);
	listInsert(L, 1, 2);
	listInsert(L, 1, 1);
	printf("���Ա�ĳ���Ϊ:%d\n", listLength(L));
	getElem(L, 2, e);
	printf("���Ա�λ��Ϊ2��Ԫ��ֵΪ:%d\n", e);
	printf("���Ա���ֵΪ5�ĵ�һ��Ԫ��λ��Ϊ:%d\n", locateElem(L, 5, cmp));
	priorElem(L, 2, e);
	printf("���Ա���ֵ2��ǰ��Ԫ��Ϊ:%d\n", e);
	nextElem(L, 2, e);
	printf("���Ա���ֵ2�ĺ��Ԫ��Ϊ:%d\n", e);
	listDelete(L, 2, e);
	printf("���Ա���1λ��ɾ����Ԫ��Ϊ:%d\n", e);
	printf("���Ա�ĳ���Ϊ:%d\n", listLength(L));
	getElem(L, 0, e);
	printf("���Ա�λ��Ϊ0��Ԫ��ֵΪ:%d\n", e);
	getElem(L, 1, e);
	printf("���Ա�λ��Ϊ1��Ԫ��ֵΪ:%d\n", e);
	printf("���Ժ�����%d\n", listTraverse(L, visit));
}

void LinkListTest()
{
	/*�������*/
	printf("\n���������������\n");
	LinkList Lq;
	Link p, q, r;
	initList1(Lq);
	makeNode1(p, 1);
	Lq.head = Lq.tail = p;
	Lq.len++;
	makeNode1(q, 2);
	makeNode1(r, 3);
	p->next = q;
	q->next = r;
	insFirst1(Lq.head, q);
	Lq.head = q;
	Lq.len++;
	insFirst1(Lq.head, r);
	Lq.head = r;
	Lq.len++;

	printf("����ĳ���Ϊ��%d\n", Lq.len);
	locatePos1(Lq, 1, p);
	locatePos1(Lq, 2, q);
	locatePos1(Lq, 3, r);
	printf("�����Ԫ������Ϊ��%d %d %d\n", p->data, q->data, r->data);

	Link t1 = Lq.head;
	Lq.head = Lq.head->next;
	delFirst1(t1, p);
	printf("����ɾ����Ԫ��Ϊ��%d\n", p->data);

	locatePos1(Lq, 1, p);
	locatePos1(Lq, 2, q);
	printf("�����Ԫ������Ϊ��%d %d\n", p->data, q->data);

	Link a, b, c;

	makeNode1(a, 1);
	makeNode1(b, 2);
	makeNode1(c, 3);
	a->next = b, b->next = c, c->next = NULL;
	append1(Lq, a);

	showLq(Lq);

	printf("�����β�ڵ��ǣ�%d\n", Lq.tail->data);
	Link delRes;
	remove1(Lq, delRes);
	printf("�����ɾ����βԪ��Ϊ��%d\n", delRes->data);
	printf("ɾ��β�ڵ�������β�ڵ��ǣ�%d\n", Lq.tail->data);

	Link t3;
	makeNode1(t3, 5);
	insBefore1(Lq, b, t3);
	showLq(Lq);

	Link t4;
	makeNode1(t4, 6);
	insAfter1(Lq, t3, t4);
	showLq(Lq);

	setCurElem1(t4, 10);
	showLq(Lq);

	printf("��ȡ�����е�5��Ԫ�ص�ֵ��%d\n", getCurElem1(t3));

	printf("����Lq�Ƿ�Ϊ�գ�%d\n", listEmpty1(Lq));
	LinkList LTest;
	initList1(LTest);
	printf("����LTest�Ƿ�Ϊ�գ�%d\n", listEmpty1(LTest));

	Link tt;
	makeNode1(tt, 9);
	LTest.head = LTest.tail = tt;
	LTest.len++;
	printf("��������LTest�Ƿ�ɹ���%d\n", destroyList1(LTest));
	printf("����LTest����Ϊ��%d\n", listLength1(LTest));

	printf("Lqͷ�ڵ��dataΪ��%d\n", getHead1(Lq)->data);
	printf("Lqβ�ڵ��dataΪ��%d\n", getLast1(Lq)->data);
	printf("p��ǰ��dataΪ��%d\n", priorPos1(Lq, t4)->data);
	printf("p�ĺ��dataΪ��%d\n", nextPos1(Lq, t4)->data);

	Link t5;
	locatePos1(Lq, 5, t5);
	printf("��5���ڵ��λ��Ϊ:%d\n", t5);
	printf("���Ժ�����%d\n", listTraverse1(Lq, visit));
}

void KMPTest()
{
	printf("\nKMP�㷨��֤");
	SString S, T;
	printf("������������ģʽ��:\n");
	scanf("%s", S);
	scanf("%s", T);
	printf("ģʽ����λ��Ϊ��%d\n", indexKMP(S, T, 0));
}

void stackTest()
{
	/*ջ����*/
	printf("\n��������ջ����\n");
	SqStack s;
	int res1, res2, res3;
	initStack(s);
	printf("ջ�Ƿ�Ϊ�գ�%d\n", stackEmpty(s));
	push(s, 5);
	push(s, 4);
	push(s, 3);
	getTop(s, res1);
	printf("ջ��Ԫ��Ϊ:%d\n", res1);
	printf("ջ�ĳ���Ϊ:%d\n", stackLength(s));
	pop(s, res2);
	getTop(s, res3);
	printf("pop����Ԫ��Ϊ:%d\n", res2);
	printf("ջ��Ԫ��Ϊ:%d\n", res3);
	printf("ջ�ĳ���Ϊ:%d\n", stackLength(s));
	printf("�������� �� %d\n", stackTraverse(s, visit));
}

void queueTest()
{
	/*���в���*/
	printf("\n�������Ƕ��в���\n");
	LinkQueue Q;
	int x;
	initQueue(Q);
	printf("�����Ƿ�Ϊ�գ�%d\n", queueEmpty(Q));
	enQueue(Q, 5);
	enQueue(Q, 4);
	enQueue(Q, 3);
	printf("�����Ƿ�Ϊ�գ�%d\n", queueEmpty(Q));
	printf("���еĳ���Ϊ: %d\n", queueLength(Q));
	getHead(Q, x);
	printf("���е�ͷԪ��Ϊ: %d\n", x);
	deQueue(Q, x);
	printf("ɾ���Ķ���ͷԪ��Ϊ��%d\n", x);
	getHead(Q, x);
	printf("���е�ͷԪ��Ϊ: %d\n", x);
	printf("���еĳ���Ϊ: %d\n", queueLength(Q));
	clearQueue(Q);
	printf("���еĳ���Ϊ: %d\n", queueLength(Q));
	printf("�������ԣ�%d\n", queueTraverse(Q, visit));
	destroyQueue(Q);
}

void BiTreeTest()
{
	/*������ʽ�洢*/
	printf("------------\n������ʽ�洢����\n");
	printf("�밴˳���������Ľڵ�\n");
	BiTree BT;
	int f = createBiTree(BT);
	printf("�����������Ƿ�ɹ��� %d\n\n", f);
	printf("�������������:\n");
	preOrderTraverse(BT, visit);
	printf("\n-----------------\n");
	printf("�������������:\n");
	inOrderTraverse(BT, visit);
	printf("\n-----------------\n");
	printf("�������������:\n");
	postOrderTraverse(BT, visit);
	printf("\n-----------------\n");
}

void arrayTest()
{
	/*�������*/
	printf("���������������\n");
	Array A;
	initArray(A, 2, 3, 3);
	for (int i = 1; i <= 2; i++)
		for (int j = 1; j <= 3; j++)
			assign(A, 0, i, j);
	assign(A, 2, 2, 1);
	int eeeee;
	eeeee = value(A, 2, 1);
	printf("���λ��[2][1]��ֵ%d\n", eeeee);
	printf("show Matrix\n");
	for (int i = 1; i <= 2; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			printf("%d ", value(A, i, j));
		}
		printf("\n");
	}
	destroyArray(A);
}

void TSMatrixTest()
{
	/*ϡ��������*/
	printf("----------------\nϡ��������\n");
	TSMatrix M;
	createSMatrix(M);
	printf("show Matrix\n");
	printSMatrix(M);
	RLSMatrix MRL, NRL, QRL;
	initRLSMatrix(MRL);
	initRLSMatrix(NRL);
	if (!RLmultSMatrix(MRL, NRL, QRL))
		printf("error!\n");
	else
		showRLSMatrix(QRL);
}

void MGraphTest()
{
	MGraph G;
	if (createGraph(G))
		printf("�����ɹ�!\n");
	else
		printf("����ʧ��!\n");
}

void ALGraphTest()
{
	ALGraph G;
	createGraph(G);
	dfsTraverse(G);
	bfsTraverse(G);
	printf("OK!\n");
}

void dijkstraTest()
{
	int P[20][20], D[20], fro;
	Graph G;
	scanf("%d", &fro);
	createDJGraph(G);
	shortestPathDij(G, fro, P, D);
	printShortestPath(G, fro, P, D);
}

int main()
{
	dijkstraTest();
	return 0;
}
