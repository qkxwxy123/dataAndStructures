#pragma once
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