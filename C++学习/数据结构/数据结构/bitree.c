/*#include<stdio.h>

typedef char ElemType;

typedef struct BiTNode
{
	char data;
	struct BiThrNode *lchild, *rchild;
}BiTNode,*BiTree;


//������������ǰ�������������
CreateBiThrTree(BiTree *T)
{
	char c;

	scanf_s("%c", &c);
	if (' ' == c)
	{
		*T = NULL;
	}
	else
	{
		*T = (BiTNode*)malloc(sizeof(BiTNode));
		(*T)->data = c;

		CreateBiThrTree(&(*T)->lchild);
		CreateBiThrTree(&(*T)->rchild);
	}
		
	
}

//���ʶ�����
visit(char c,int level)
{
	printf("%c is %d level\n", c, level);
}

//����������
PreOrderTeaverse(BiTree T, int level)
{
	if (T)
	{
		visit(T->data, level);
		PreOrderTeaverse(T->lchild, level + 1);
		PreOrderTeaverse(T->rchild, level + 1);
	}
}

int main()
{
	int level = 1;
	BiTree T = NULL;

	CreateBiThrTree(&T);
	PreOrderTeaverse(T, level);

	getchar();
	getchar();
	return  0;
}  */