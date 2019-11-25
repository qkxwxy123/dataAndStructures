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
int insFirst1(Link, Link); // ��֪hָ�����Ա��ͷ�ڵ㣬��s��ָ�ڵ�����ڵ�һ�����֮ǰ
int delFirst1(Link, Link&); // ��֪hָ�����Ա��ͷ�ڵ㣬ɾ�������еĵ�һ���ڵ㲢��q����
int append1(LinkList&, Link);//��ָ��s��ָ���˴���ָ����������һ���ڵ���������������L�����һ���ڵ㣬
							//֮��ı�����L��βָ��ָ���µ�β�ڵ�
int remove1(LinkList&, Link&);//ɾ��β�ڵ�
int insBefore1(LinkList&, Link&, Link);//��֪pָ����������L�е�һ���ڵ㣬��s��ָ�ڵ������p��ָ�ڵ�֮ǰ�����޸�pָ���²���Ľڵ�
int insAfter1(LinkList&, Link&, Link);//��֪pָ����������L�е�һ���ڵ㣬��s��ָ�ڵ������p��ָ�ڵ�֮�󣬲��޸�pָ���²���Ľڵ�
int setCurElem1(Link&, int); //��e����p��ָ���������Ԫ�ص�ֵ
int getCurElem1(Link); //����p��ָ��ڵ���Ԫ�ص�ֵ
int listEmpty1(LinkList);
int listLength1(LinkList);
Position getHead1(LinkList); //����Lͷ�ڵ��λ��
Position getLast1(LinkList); //����Lβ�ڵ��λ��
Position priorPos1(LinkList, Link);//pǰ����λ�ã����޷���null
Position nextPos1(LinkList, Link);//p��׺
int locatePos1(LinkList, int, Link&); //���ص�i���ڵ��λ�ò�����ok��iֵ���Ϸ�����ok
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