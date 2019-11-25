#include "stdio.h"
#include "malloc.h"

typedef enum {ATOM, LIST}ElemTag; //原子，子表
typedef struct GLNode
{
	ElemTag tag;
	union
	{
		int atom;                                //atom是原子节点的值域
		struct { struct GLNode* hp, * tp; }ptr;  //ptr是表节点的指针域，ptr.hp和ptr.tp分别指向表头和表尾
	};
}*GList;

int initGList(GList&);                        //创建空的广义表
int createGList(GList&, char*);               //由字符数组S创建广义表L
int destroyGList(GList&);                     //销毁广义表L
int copyGList(GList&, GList);                 //由广义表L复制广义表T
int GListLength(GList);                       //求广义表L的长度， 即元素个数
int GListDepth(GList);                        //求广义表L的深度
int GListEmpty(GList);                        //判断广义表是否为空
int getHead(GList);                           //取广义表L的头
int getTail(GList);                           //取广义表L的尾
int insrtFirst_GL(GList&, int );              //插入元素e作为广义表L的第一元素
int deleteFirst_GL(GList&, int&);             //删除广义表L的第一元素，并用e返回
int traverse_GL(GList, int (*visit)());       //遍历

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