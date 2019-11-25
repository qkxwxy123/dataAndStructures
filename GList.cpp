#include "stdio.h"
#include "malloc.h"

typedef enum {ATOM, LIST}ElemTag; //ԭ�ӣ��ӱ�
typedef struct GLNode
{
	ElemTag tag;
	union
	{
		int atom;                                //atom��ԭ�ӽڵ��ֵ��
		struct { struct GLNode* hp, * tp; }ptr;  //ptr�Ǳ�ڵ��ָ����ptr.hp��ptr.tp�ֱ�ָ���ͷ�ͱ�β
	};
}*GList;

int initGList(GList&);                        //�����յĹ����
int createGList(GList&, char*);               //���ַ�����S���������L
int destroyGList(GList&);                     //���ٹ����L
int copyGList(GList&, GList);                 //�ɹ����L���ƹ����T
int GListLength(GList);                       //������L�ĳ��ȣ� ��Ԫ�ظ���
int GListDepth(GList);                        //������L�����
int GListEmpty(GList);                        //�жϹ�����Ƿ�Ϊ��
int getHead(GList);                           //ȡ�����L��ͷ
int getTail(GList);                           //ȡ�����L��β
int insrtFirst_GL(GList&, int );              //����Ԫ��e��Ϊ�����L�ĵ�һԪ��
int deleteFirst_GL(GList&, int&);             //ɾ�������L�ĵ�һԪ�أ�����e����
int traverse_GL(GList, int (*visit)());       //����

int initGList(GList& L)
{
	L->ptr.hp = (GLNode*)malloc(sizeof(GLNode));
	L->ptr.tp = (GLNode*)malloc(sizeof(GLNode));
	if (!L->ptr.hp || !L->ptr.tp)
		return 0;
	return 1;
}

int createGList(GList& L, char* S)
{
	return 1;
}