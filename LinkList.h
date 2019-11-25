#pragma once
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
int listTraverse1(LinkList, int (*visit)(int));