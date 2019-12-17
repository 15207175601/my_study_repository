/*#include <stdio.h>
#include<stdlib.h>

typedef char ElemType;
//线索存储标志位
//link（0）表示指向左右孩子的指针
//Thread（1）表示指向前驱后继的线索
typedef enum {Link,Thread} PointerTag;

typedef struct BiThrNode
{
	char data;
	struct BiThrNode *lchild, *rchild;
	PointerTag ltag;
	PointerTag rtag;
}BiThrNode,*BiThrTree;
//创建二叉树，前序遍历
CreateBiThrTree(BiThrTree *T)
{
	char c;

	scanf_s("%c", &c);
	if (' ' == c)
	{
		*T = NULL;
	}
	else
	{
		*T = (BiThrNode*)malloc(sizeof(BiThrNode));
		(*T)->data = c;
		(*T)->ltag = Link;
		(*T)->rtag = Link;

		CreateBiThrTree(&(*T)->lchild);
		CreateBiThrTree(&(*T)->rchild);
	}
}*/