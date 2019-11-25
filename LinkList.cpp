#include "malloc.h"
#include <stdio.h>

typedef struct LNode
{
	int data;
	struct LNode* next;
}*Link, * Position;

typedef struct
{
	Link head, tail;
	int len;
}LinkList;

int makeNode1(Link&, int);
void freeNode1(Link&);

int initList1(LinkList&);
int destroyList1(LinkList&);
int clearList1(LinkList&);
int insFirst1(Link, Link); // 已知h指向线性表的头节点，将s所指节点插入在第一个结点之前
int delFirst1(Link, Link&); // 已知h指向线性表的头节点，删除链表中的第一个节点并以q返回
int append1(LinkList&, Link);//将指针s所指（彼此以指针相连）的一串节点链接在线性链表L的最后一个节点，
							//之后改变链表L的尾指针指向新的尾节点
int remove1(LinkList&, Link&);//删除尾节点
int insBefore1(LinkList&, Link&, Link);//已知p指向线性链表L中的一个节点，将s所指节点插入在p所指节点之前，并修改p指向新插入的节点
int insAfter1(LinkList&, Link&, Link);//已知p指向线性链表L中的一个节点，将s所指节点插入在p所指节点之后，并修改p指向新插入的节点
int setCurElem1(Link&, int); //用e更新p所指结点中数据元素的值
int getCurElem1(Link); //返回p所指向节点中元素的值
int listEmpty1(LinkList);
int listLength1(LinkList);
Position getHead1(LinkList); //返回L头节点的位置
Position getLast1(LinkList); //返回L尾节点的位置
Position priorPos1(LinkList, Link);//p前驱的位置，若无返回null
Position nextPos1(LinkList, Link);//p后缀
int locatePos1(LinkList, int, Link&); //返回第i个节点的位置并返回ok，i值不合法返回ok
int listTraverse1(LinkList, int (*visit)());

int makeNode1(Link& p, int e)
{
	p = (Link)malloc(sizeof(Link));
	p->data = (int)malloc(sizeof(int));
	if (!p->data)
		return 0;
	p->data = e;
	return 1;
}

void freeNode1(Link& p)
{
	free(p);
}

int initList1(LinkList& L)
{
	L.head = (Link)malloc(sizeof(Link));
	L.tail = (Link)malloc(sizeof(Link));
	if (!L.head || !L.tail)
		return 0;
	L.head->data = (int)malloc(sizeof(int));
	L.head->data = (int)malloc(sizeof(int));
	L.len = 0;
	return 1;
}

int destroyList1(LinkList& L)
{
	L.head = L.tail = 0;
	L.len = 0;
	return 1;
}

int clearList1(LinkList& L)
{
	free(L.head);
	free(L.tail);
	L.len = 0;
	L.head = (Link)malloc(sizeof(Link));
	L.tail = (Link)malloc(sizeof(Link));
	if (!L.head || !L.tail)
		return 0;
	L.head->data = (int)malloc(sizeof(int));
	L.head->data = (int)malloc(sizeof(int));
	return 1;
}

int insFirst1(Link h, Link s)
{
	s->next = h;
	return 1;
}

int delFirst1(Link h, Link& q)
{
	q = h;
	h->next = NULL;
	return 1;
}

int append1(LinkList& L, Link s)
{
	Link p = s;
	int len = 0;
	L.tail->next = s;
	while (p->next != NULL)
		p = p->next, len++;
	L.tail = p;
	L.len += len;
	return 1;
}

int remove1(LinkList& L, Link& q)
{
	Link p = L.head;
	while (p->next != L.tail)
		p = p->next;
	L.tail = p;
	q = p->next;
	p->next = NULL;
	L.len--;
	return 1;
}

int insBefore1(LinkList& L, Link& p, Link s)
{
	Link temp = L.head;
	while (temp->next != p)
		temp = temp->next;
	s->next = temp->next;
	temp->next = s;
	p = s;
	L.len++;
	return 1;
}

int insAfter1(LinkList& L, Link& p, Link s)
{
	Link temp = L.head;
	while (temp != p)
		temp = temp->next;
	s->next = temp->next;
	temp->next = s;
	p = s;
	L.len++;
	return 1;
}

int setCurElem1(Link& p, int e)
{
	p->data = e;
	return 1;
}

int getCurElem1(Link p)
{
	return p->data;
}

int listEmpty1(LinkList L)
{
	return (L.len == 0) ? 1 : 0;
}

int listLength1(LinkList L)
{
	return L.len;
}

Position getHead1(LinkList L)
{
	Position pos = L.head;
	return pos;
}

Position getLast1(LinkList L)
{
	Position pos = L.tail;
	return pos;
}

Position priorPos1(LinkList L, Link p)
{
	if (p == L.head)
		return NULL;
	Position pos;
	pos = L.head;
	while (pos->next != p && pos != L.tail)
		pos = pos->next;
	return pos;
}

Position nextPos1(LinkList L, Link p)
{
	if (p == L.tail)
		return NULL;
	Position pos;
	pos = L.head;
	while (pos != p)
		pos = pos->next;
	pos = pos->next;
	return pos;
}

int locatePos1(LinkList L, int i, Link& p)
{
	int len = 1;
	Link temp = L.head;
	if (i < 1 || i > L.len)
		return 0;
	while (len < i && temp->next != NULL)
		len++, temp = temp->next;
	p = temp;
	return 1;
}

Position locateElem1(LinkList L, int e, int (*cmp)(int x, int y))
{
	Link p = L.head;
	while (p != L.tail && !cmp(p->data, e))
		p = p->next;
	if (p == L.tail && !cmp(p->data, e))
		return NULL;
	else if (p == L.tail && !cmp(p->data, e))
		return L.tail;
	else
		return p;
}

int listTraverse1(LinkList L, int (*visit)(int x))
{
	Link p = L.head;
	while (p != L.tail)
	{
		if (!visit(p->data))
			return 0;
		p = p->next;
	}
	return 1;
}