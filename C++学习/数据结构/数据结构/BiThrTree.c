/*#include <stdio.h>
#include<stdlib.h>

typedef char ElemType;
//�����洢��־λ
//link��0����ʾָ�����Һ��ӵ�ָ��
//Thread��1����ʾָ��ǰ����̵�����
typedef enum {Link,Thread} PointerTag;

typedef struct BiThrNode
{
	char data;
	struct BiThrNode *lchild, *rchild;
	PointerTag ltag;
	PointerTag rtag;
}BiThrNode,*BiThrTree;
//������������ǰ�����
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