#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"

#define MAX_TREE_SIZE 110

typedef struct BiTNode
{
	char data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

int createBiTree(BiTree&);
int preOrderTraverse(BiTree, int (*visit)(char));
int inOrderTraverse(BiTree, int (*visit)(char));
int postOrderTraverse(BiTree, int (*visit)(char));
int levelOrderTraverse(BiTree, int (*visit)(char));
int visit(char);


int createBiTree(BiTree& T)
{
	char temp;
	getchar();
	scanf("%c", &temp);
	//getchar();
	if (temp == '!') T = NULL;
	else
	{
		T = (BiTree)malloc(sizeof(BiTree));
		if (!T)
			return 0;
		T->data = temp;
		createBiTree(T->lchild);
		createBiTree(T->rchild);
	}
	return 1;
}

int preOrderTraverse(BiTree T, int (*visit)(char))
{
	if (T)
	{
		if (visit(T->data))
			if (preOrderTraverse(T->lchild, visit))
				if (preOrderTraverse(T->rchild, visit))
					return 1;
		return 0;
	}
	else
		return 1;
}

int inOrderTraverse(BiTree T, int (*visit)(char))
{
	if (T)
	{
		if (inOrderTraverse(T->lchild, visit))
			if (visit(T->data))
				if (inOrderTraverse(T->rchild, visit))
					return 1;
		return 0;
	}
	else
		return 1;
}

int postOrderTraverse(BiTree T, int (*visit)(char))
{
	if (T)
	{
		if (postOrderTraverse(T->lchild, visit))
			if (postOrderTraverse(T->rchild, visit))
				if (visit(T->data))
					return 1;
		return 0;
	}
	else
		return 1;
}

int visit(char e)
{
	printf("%c ", e);
	return 1;
}
