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
	printf("链表的元素依次为：");
	while (t2 != NULL)
	{
		printf("%d ", t2->data);
		t2 = t2->next;
	}
	printf("\n");
}

void SqListTest()
{
	/*线性表测试*/
	SqList L;
	int e;
	initList(L);
	clearList(L);
	printf("线性表是否为空?%d\n", listEmpty(L));
	printf("线性表的长度为:%d\n", listLength(L));
	listInsert(L, 1, 5);
	listInsert(L, 1, 2);
	listInsert(L, 1, 1);
	printf("线性表的长度为:%d\n", listLength(L));
	getElem(L, 2, e);
	printf("线性表位置为2的元素值为:%d\n", e);
	printf("线性表中值为5的第一个元素位置为:%d\n", locateElem(L, 5, cmp));
	priorElem(L, 2, e);
	printf("线性表中值2的前驱元素为:%d\n", e);
	nextElem(L, 2, e);
	printf("线性表中值2的后继元素为:%d\n", e);
	listDelete(L, 2, e);
	printf("线性表中1位置删除的元素为:%d\n", e);
	printf("线性表的长度为:%d\n", listLength(L));
	getElem(L, 0, e);
	printf("线性表位置为0的元素值为:%d\n", e);
	getElem(L, 1, e);
	printf("线性表位置为1的元素值为:%d\n", e);
	printf("测试函数：%d\n", listTraverse(L, visit));
}

void LinkListTest()
{
	/*链表测试*/
	printf("\n接下来是链表测试\n");
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

	printf("链表的长度为：%d\n", Lq.len);
	locatePos1(Lq, 1, p);
	locatePos1(Lq, 2, q);
	locatePos1(Lq, 3, r);
	printf("链表的元素依次为：%d %d %d\n", p->data, q->data, r->data);

	Link t1 = Lq.head;
	Lq.head = Lq.head->next;
	delFirst1(t1, p);
	printf("链表被删除的元素为：%d\n", p->data);

	locatePos1(Lq, 1, p);
	locatePos1(Lq, 2, q);
	printf("链表的元素依次为：%d %d\n", p->data, q->data);

	Link a, b, c;

	makeNode1(a, 1);
	makeNode1(b, 2);
	makeNode1(c, 3);
	a->next = b, b->next = c, c->next = NULL;
	append1(Lq, a);

	showLq(Lq);

	printf("链表的尾节点是：%d\n", Lq.tail->data);
	Link delRes;
	remove1(Lq, delRes);
	printf("链表的删除的尾元素为：%d\n", delRes->data);
	printf("删除尾节点后链表的尾节点是：%d\n", Lq.tail->data);

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

	printf("获取链表中第5个元素的值：%d\n", getCurElem1(t3));

	printf("链表Lq是否为空？%d\n", listEmpty1(Lq));
	LinkList LTest;
	initList1(LTest);
	printf("链表LTest是否为空？%d\n", listEmpty1(LTest));

	Link tt;
	makeNode1(tt, 9);
	LTest.head = LTest.tail = tt;
	LTest.len++;
	printf("销毁链表LTest是否成功？%d\n", destroyList1(LTest));
	printf("链表LTest长度为：%d\n", listLength1(LTest));

	printf("Lq头节点的data为：%d\n", getHead1(Lq)->data);
	printf("Lq尾节点的data为：%d\n", getLast1(Lq)->data);
	printf("p的前驱data为：%d\n", priorPos1(Lq, t4)->data);
	printf("p的后继data为：%d\n", nextPos1(Lq, t4)->data);

	Link t5;
	locatePos1(Lq, 5, t5);
	printf("第5个节点的位置为:%d\n", t5);
	printf("测试函数：%d\n", listTraverse1(Lq, visit));
}

void KMPTest()
{
	printf("\nKMP算法验证");
	SString S, T;
	printf("请输入主串和模式串:\n");
	scanf("%s", S);
	scanf("%s", T);
	printf("模式串的位置为：%d\n", indexKMP(S, T, 0));
}

void stackTest()
{
	/*栈测试*/
	printf("\n接下来是栈测试\n");
	SqStack s;
	int res1, res2, res3;
	initStack(s);
	printf("栈是否为空？%d\n", stackEmpty(s));
	push(s, 5);
	push(s, 4);
	push(s, 3);
	getTop(s, res1);
	printf("栈顶元素为:%d\n", res1);
	printf("栈的长度为:%d\n", stackLength(s));
	pop(s, res2);
	getTop(s, res3);
	printf("pop弹出元素为:%d\n", res2);
	printf("栈顶元素为:%d\n", res3);
	printf("栈的长度为:%d\n", stackLength(s));
	printf("函数测试 ： %d\n", stackTraverse(s, visit));
}

void queueTest()
{
	/*队列测试*/
	printf("\n接下来是队列测试\n");
	LinkQueue Q;
	int x;
	initQueue(Q);
	printf("队列是否为空？%d\n", queueEmpty(Q));
	enQueue(Q, 5);
	enQueue(Q, 4);
	enQueue(Q, 3);
	printf("队列是否为空？%d\n", queueEmpty(Q));
	printf("队列的长度为: %d\n", queueLength(Q));
	getHead(Q, x);
	printf("队列的头元素为: %d\n", x);
	deQueue(Q, x);
	printf("删除的队列头元素为：%d\n", x);
	getHead(Q, x);
	printf("队列的头元素为: %d\n", x);
	printf("队列的长度为: %d\n", queueLength(Q));
	clearQueue(Q);
	printf("队列的长度为: %d\n", queueLength(Q));
	printf("函数测试：%d\n", queueTraverse(Q, visit));
	destroyQueue(Q);
}

void BiTreeTest()
{
	/*树的链式存储*/
	printf("------------\n树的链式存储测试\n");
	printf("请按顺序输入树的节点\n");
	BiTree BT;
	int f = createBiTree(BT);
	printf("创建二叉树是否成功？ %d\n\n", f);
	printf("先序遍历二叉树:\n");
	preOrderTraverse(BT, visit);
	printf("\n-----------------\n");
	printf("中序遍历二叉树:\n");
	inOrderTraverse(BT, visit);
	printf("\n-----------------\n");
	printf("后序遍历二叉树:\n");
	postOrderTraverse(BT, visit);
	printf("\n-----------------\n");
}

void arrayTest()
{
	/*数组测试*/
	printf("接下来是数组测试\n");
	Array A;
	initArray(A, 2, 3, 3);
	for (int i = 1; i <= 2; i++)
		for (int j = 1; j <= 3; j++)
			assign(A, 0, i, j);
	assign(A, 2, 2, 1);
	int eeeee;
	eeeee = value(A, 2, 1);
	printf("获得位于[2][1]的值%d\n", eeeee);
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
	/*稀疏矩阵测试*/
	printf("----------------\n稀疏矩阵测试\n");
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
		printf("创建成功!\n");
	else
		printf("创建失败!\n");
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
